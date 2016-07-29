#include "apimanager.h"


void ApiManager::populateModel(ModelManager* )
{
    manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("http://qt-project.org")));

   connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(downloadFinished(QNetworkReply*)));



}
void ApiManager::downloadFinished(QNetworkReply *reply) //this slot called when we have responce
{
//qDebug() << reply->readAll(); //we read result and print it(also you can save it in some variable and use in code
}
