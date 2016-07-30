#include "apimanager.h"


void ApiManager::populateModel(ModelManager* modelManager)
{
    this->modelManager = modelManager;
    manager = new QNetworkAccessManager(this);

   connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(downloadFinished(QNetworkReply*)));


   manager->get(QNetworkRequest(QUrl("http://api.petfinder.com/shelter.getPets?key=5091404606bbe6df399563fdb6b54cff&id=WA109&format=xml")));

}
void ApiManager::downloadFinished(QNetworkReply *reply) //this slot called when we have responce
{

    QByteArray xml = reply->readAll(); //we read result and print it(also you can save it in some variable and use in code

}

void ApiManager::parseXML(QByteArray xml, ModelManager* m)
{


        QXmlStreamReader xmlReader(xml);


        xmlReader.readNext(); //start reading inside petfinder element
        xmlReader.skipCurrentElement(); // skip header element
        xmlReader.readNext(); // start reading inside pets element

        while (!xmlReader.isEndDocument())
        {
            Animal current;

            while (!xmlReader.isEndElement()){

                    QString name = xmlReader.name().toString();

            xmlReader.readNext();
                }

            // animal has  been read in
        }
            if (xmlReader.hasError())
            {
                std::iostream::cout << "XML error: " << xmlReader.errorString().data() << std::endl;
            }

}
