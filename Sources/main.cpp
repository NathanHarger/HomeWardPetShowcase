#include "../Headers/animallistmodel.h"
#include "../Headers/mainwindow.h"
#include "../Headers/animal.h"
#include "../Headers/configuration.h"
#include <QGuiApplication>
#include<QtQml>
#include<QtQuick>
#include <qqmlengine.h>
#include<QtQuick/QQuickItem>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Configuration c;

    AnimalListModel model;

    AnimalListModel cats;
    cats.addAnimal( Animal("Cheese Pizza"));
    cats.addAnimal( Animal("Mocha"));
    cats.addAnimal( Animal("Bob"));

    model.addAnimal( Animal("Wolf"));
    model.addAnimal( Animal("Polar bear"));
    model.addAnimal( Animal("Quoll"));
    model.addAnimal( Animal("Wolf"));
    model.addAnimal( Animal("Polar bear"));
    model.addAnimal( Animal("Quoll"));
    model.addAnimal( Animal("Wolf"));
    model.addAnimal( Animal("Polar bear"));
    model.addAnimal( Animal("Quoll"));



    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *ctxt = view.rootContext();


    ctxt->setContextProperty("animalTypes", c.getAnimalTypes());

    ctxt->setContextProperty("dogModel", &model);
    ctxt->setContextProperty("catModel", &cats);

//problem with this line!!!
   view.setSource(QUrl("qrc:animalview.qml"));
    view.show();

    return app.exec();
   }
