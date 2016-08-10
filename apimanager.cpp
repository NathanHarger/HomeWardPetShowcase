#include "apimanager.h"


void ApiManager::populateShelterModel(Shelter* sm, QString shelter, QString devKey)
{
    this->s = sm;

    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this, SLOT(shelterGetFinished(QNetworkReply*)));

    QString apiUrl = "http://api.petfinder.com/shelter.get?key=" + devKey + "&id=" + shelter + "&format=json";
    manager->get(QNetworkRequest(QUrl(apiUrl)));
}

void ApiManager::populateAnimalModel(ModelManager* modelManager, QString shelter, QString devKey)
{
    QNetworkConfigurationManager networkConfM;


    this->modelManager = modelManager;


    if (networkConfM.isOnline())
    {
        manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply*)),
                 this, SLOT(petsGetFinished(QNetworkReply*)));
        QString apiUrl = "http://api.petfinder.com/shelter.getPets?key=" + devKey + "&id=" + shelter + "&format=json";
        manager->get(QNetworkRequest(QUrl(apiUrl)));

    } else {

        // if there is no internet
        QFile file(QCoreApplication::applicationDirPath() +     "petJson");

        file.open(file.ReadOnly);
        QTextStream in(&file);   // we will serialize the data into the file


        QString binaryRep = in.readAll();



        QJsonDocument save = QJsonDocument::fromJson(binaryRep.toUtf8());// QJsonDocument::fromBinaryData(binaryRep, QJsonDocument::BypassValidation);
        QJsonArray oldPets = save.array();
        this->createAnimals(oldPets);
    }

}

void ApiManager::shelterGetFinished(QNetworkReply *reply) //this slot called when we have responce
{
    QByteArray json = reply->readAll();
    QJsonDocument jsonDoc =  QJsonDocument::fromJson(json);
    QJsonObject doc = jsonDoc.object();
    QJsonObject petFinder = doc.find("petfinder").value().toObject();
    QJsonObject shelter = petFinder.find("shelter").value().toObject();
    s->setName(getJsonAttribute("name", shelter));
    s->setEmail( getJsonAttribute("email", shelter));
   s->setPhoneNumber(getJsonAttribute("phone", shelter));


    QString address1 = getJsonAttribute("address1", shelter);
    QString city = getJsonAttribute("city", shelter);
    QString state  =  getJsonAttribute("state", shelter);

    QString zip = getJsonAttribute("zip", shelter);

    QString fullAddress = address1 + city +state + zip;
    s->setAddress(fullAddress);


}

void ApiManager::petsGetFinished(QNetworkReply *reply) //this slot called when we have responce
{

    QByteArray jsonDoc = reply->readAll(); //we read result and print it(also you can save it in some variable and use in code
   // qDebug() << json;


    QJsonArray petJson = parseJSON(jsonDoc , modelManager);
    createAnimals(petJson);
    QJsonDocument save(petJson);
    QByteArray binaryRepresentation = save.toJson();

    this->file = binaryRepresentation;

    QFile file(QCoreApplication::applicationDirPath() +     "petJson");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << binaryRepresentation;


}

void ApiManager::createAnimals(QJsonArray petArray)
{


    for (int i = 0; i < petArray.size(); i++)
    {
        Animal curr;
        QJsonObject currentJsonPet = petArray.at(i).toObject();

        //read options
        curr.setOptions(getOptionsFromJson( currentJsonPet));

        //read status
        curr.setStatus(getJsonAttribute("status", currentJsonPet).at(0));

        //read age
        curr.setAge(getJsonAttribute("age", currentJsonPet));

        // read media
        curr.setMedia(getPhotosFromJson( currentJsonPet)); //NO

        // read id
        curr.setId(getJsonAttribute("id", currentJsonPet));


        // read breeds
        curr.setBreeds(getBreedsFromJson( currentJsonPet)); //NO


        // read name
        curr.setName(getJsonAttribute("name", currentJsonPet));

        // read sex
        curr.setSex(getJsonAttribute("sex", currentJsonPet));

        // read description
        curr.setDesc(getJsonAttribute("description", currentJsonPet));

        // read mix
        curr.setMix(getJsonAttribute("mix", currentJsonPet));

        // read animal type
        curr.setType(getJsonAttribute("animal", currentJsonPet));
        this->modelManager->addAnimal(curr, curr.getType());
    }
}

QJsonArray ApiManager::parseJSON(QByteArray json, ModelManager* m)
{
    QJsonDocument jsonDoc =  QJsonDocument::fromJson(json);
    QJsonObject doc = jsonDoc.object();
    QJsonObject petFinder = doc.find("petfinder").value().toObject();
    QJsonObject petsObject = petFinder.find("pets").value().toObject();
    QJsonArray petsArray = petsObject.find("pet").value().toArray();
    return petsArray;
}

// returns an attribute from an object thas has only one value
QString ApiManager::getJsonAttribute(QString attribute, QJsonObject jsonObject)
{
    QStringList result;
    QJsonValueRef val = jsonObject.find(attribute).value();
    if(val.isArray())
    {
        return ""; // inner json is an array
    }
    QJsonObject obj = val.toObject();
    if (obj.contains("$t"))
        return obj.find("$t").value().toString();
    return ""; // inner json is a complex object like breeds
}


QStringList ApiManager::getPhotosFromJson(QJsonObject object)
{
    QStringList result;
    QJsonObject mediaObject = object.find("media").value().toObject();
   QJsonObject photosObject = mediaObject.find("photos").value().toObject();

    QJsonArray photoArray = photosObject.find("photo").value().toArray();
    for (int i = 0; i < photoArray.size(); i++)
    {

        QJsonObject currentObject = photoArray.at(i).toObject();

        // skip photos that are not the largest size
        if (!(currentObject.find("@size").value().toString() == "x"))
        {
            continue;
        }
        else
        {
            result += currentObject.find("$t").value().toString();
        }
    }
    return result;
}

QStringList ApiManager::getOptionsFromJson(QJsonObject object)
{
    QStringList result;
    QJsonObject innerObject = object.find("options").value().toObject();
    QJsonArray optionArray = innerObject.find("option").value().toArray();
    for (int i = 0; i < optionArray.size(); i++)
    {
        QJsonObject option = optionArray.at(i).toObject();
        QString optionString = option.find("$t").value().toString();
        result += optionString;
    }
    return result;
}

QStringList ApiManager::getBreedsFromJson(QJsonObject object)
{
    QStringList result;
    QJsonObject innerObject = object.find("breeds").value().toObject();

    QJsonArray breedArray = innerObject.find("breed").value().toArray();
    for (int i = 0; i < breedArray.size(); i++)
    {
        QJsonObject breed = breedArray.at(i).toObject();
        QString breedString = breed.find("$t").value().toString();
        result += breedString;
    }
    return result;
}
