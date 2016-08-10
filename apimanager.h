//class with static api utility functions
#ifndef APIMANAGER_H
#define APIMANAGER_H
#include <QApplication>
#include <QtNetwork>
#include <QJsonDocument>
#include "animallistmodel.h"
#include "shelter.h"
#include "modelmanager.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QXmlStreamReader>


 class ApiManager: public QObject
{
 public:
      void populateAnimalModel(ModelManager* , QString, QString);
     QNetworkAccessManager *manager;
     void populateShelterModel(Shelter*, QString, QString);
 private slots:

   void petsGetFinished(QNetworkReply*);
   void shelterGetFinished(QNetworkReply*);
   private:
    ModelManager* modelManager;
    Shelter* s;

    //variable used to store data read from api call
    QByteArray jsonDoc;
    QString getJsonAttribute(QString, QJsonObject);
    QJsonArray parseJSON(QByteArray, ModelManager*);
    void createAnimals(QJsonArray);
    QStringList getPhotosFromJson(QJsonObject);
    QStringList getOptionsFromJson(QJsonObject);
    QStringList getBreedsFromJson(QJsonObject);
    QByteArray file;
   Q_OBJECT


};

#endif // APIMANAGER_H
