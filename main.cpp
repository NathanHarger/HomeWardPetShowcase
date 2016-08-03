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

void setupUI(QList<AnimalListModel*> models);


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // setup configuration
    Configuration c;
   ModelManager* models = new ModelManager(c.getAnimalTypes());
    ApiManager am;
    setupUI(models->getModels());
    am.populateModel(models);

    return app.exec();
   }


void setupUI(QList<AnimalListModel*> models){
   QTabWidget* w = new QTabWidget();

    for (int i =0 ; i < models.length(); i++){

        QQuickWidget* view = new QQuickWidget();

        // add list of animals from config to qml animalTypes property
        view->engine()->rootContext()->setContextProperty("animalModel", models.at(i));


        view->setSource(QUrl("qrc:/shelterview.qml"));

        w->addTab( view,models.at(i)->getModelName());
    }
    w->show();

}
