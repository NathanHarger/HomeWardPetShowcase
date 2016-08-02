#include "apimanager.h"


void ApiManager::populateModel(ModelManager* modelManager)
{
    this->modelManager = modelManager;
    manager = new QNetworkAccessManager(this);

   connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(downloadFinished(QNetworkReply*)));


   manager->get(QNetworkRequest(QUrl("http://api.petfinder.com/shelter.getPets?key=5091404606bbe6df399563fdb6b54cff&id=WA109&format=json")));

}
void ApiManager::downloadFinished(QNetworkReply *reply) //this slot called when we have responce
{

    QByteArray json = reply->readAll(); //we read result and print it(also you can save it in some variable and use in code
   // qDebug() << json;
    parseJSON(json, modelManager);
}

void ApiManager::parseJSON(QByteArray json, ModelManager* m)
{
      QJsonDocument jsonDoc =  QJsonDocument::fromJson(json);
    QJsonObject doc = jsonDoc.object();
    QJsonObject::Iterator iter = doc.find("petfinder");

    QJsonValueRef petFinder = iter.value();
    QJsonObject petFinderObject = petFinder.toObject();
    QJsonObject petsObject = petFinderObject.find("pets").value().toObject();
    QJsonArray petsArray = petsObject.find("pet").value().toArray();
 //   QJsonArray petsArray = petfinderObject.find("pets");

       // QXmlStreamReader xmlReader(xml);


       // xmlReader.readElementText(); //start reading inside petfinder element
         //QStringRef name = xmlReader.name();
       //  qDebug() << name.string();
       // xmlReader.skipCurrentElement(); // skip header element
       // xmlReader.readNext(); // start reading inside pets element
       // qDebug() << xmlReader.name();
     /// /  if (xmlReader.hasError()) {
     //  /        qDebug() << "Error";
         }
       // while (!xmlReader.isEndDocument())
    //    {
       //     Animal current;

        //    while (!xmlReader.isEndElement()){
//
     //               QString name = xmlReader.name().toString();
//
        //    xmlReader.readNext();
      //          }

            // animal has  been read in
  //      }
//
//}
