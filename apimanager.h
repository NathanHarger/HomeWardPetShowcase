//class with static api utility functions
#ifndef APIMANAGER_H
#define APIMANAGER_H
#include <QApplication>
#include <QtNetwork>
#include <QJsonDocument>
#include "animallistmodel.h"
#include "modelmanager.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QXmlStreamReader>


 class ApiManager: public QObject
{
 public:
      void populateModel(ModelManager* , QString, QString);
     QNetworkAccessManager *manager;
 private slots:

   void downloadFinished(QNetworkReply*);
   private:
    ModelManager* modelManager;

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
