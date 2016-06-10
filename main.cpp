#include "../Headers/animallistmodel.h"
#include "../Headers/mainwindow.h"
#include "../Headers/animal.h"
#include "../Headers/configuration.h"
#include "../Headers/modelmanager.h"
#include <QGuiApplication>
#include<QtQml>
#include<QtQuick>
#include <qqmlengine.h>
#include<QtQuick/QQuickItem>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

class DataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(AnimalListModel color READ color WRITE setColor NOTIFY colorChanged)

};

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // setup configuration
    Configuration c;

    ModelManager m;
    AnimalListModel model;

   AnimalListModel* cats = m.getModel("cats");

   if(cats != NULL){
    cats->addAnimal( Animal("Cheese Pizza"));
    cats->addAnimal( Animal("Mocha"));
    cats->addAnimal( Animal("Bob"));
    }



    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *ctxt = view.rootContext();

    // add list of animals from config to qml animalTypes property
    ctxt->setContextProperty("animalTypes", c.getAnimalTypes());

    view.setSource(QUrl("qrc:animalview.qml"));
    view.show();

    return app.exec();
   }
