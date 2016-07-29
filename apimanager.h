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


 class ApiManager: public QObject
{
 public:
      void populateModel(ModelManager* );
     QNetworkAccessManager *manager;
 private slots:

   void downloadFinished(QNetworkReply*);
    private:
   Q_OBJECT


};

#endif // APIMANAGER_H
