#include "animallistmodel.h"
#include "modelmanager.h"
#include "mainwindow.h"
#include "animal.h"
#include "apimanager.h"
#include "configuration.h"
#include <QGuiApplication>
#include<QtQml>
#include<QtQuick>
#include <qqmlengine.h>
#include<QtQuick/QQuickItem>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QQuickWidget>

void setupUI(QList<AnimalListModel*> models, Shelter* s);


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // setup configuration
    Configuration c;
   ModelManager* models = new ModelManager(c.getAnimalTypes());
   Shelter* s = new Shelter();
    ApiManager am;

    am.populateShelterModel(s, c.getShelterID(), c.getDevKey());

     am.populateAnimalModel(models, c.getShelterID(), c.getDevKey());
     setupUI(models->getModels(), s);

    return app.exec();
   }


void setupUI(QList<AnimalListModel*> models, Shelter* s){
   QTabWidget* w = new QTabWidget();

   QQuickWidget* aboutView = new QQuickWidget();
   aboutView->engine()->rootContext()->setContextProperty("shelterModel", s);
  aboutView->setSource(QUrl("qrc:/aboutShelter.qml"));
   w->addTab(aboutView, "Shelter");

    for (int i =0 ; i < models.length(); i++){

        QQuickWidget* view = new QQuickWidget();

        // add list of animals from config to qml animalTypes property
        view->engine()->rootContext()->setContextProperty("animalModel", models.at(i));


        view->setSource(QUrl("qrc:/main.qml"));

        w->addTab( view,models.at(i)->getModelName());
    }
    w->show();

}
