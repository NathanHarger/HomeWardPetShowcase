#include "mainwindow.h"
#include "animallistmodel.h"
#include <animal.h>
#include <QGuiApplication>
#include<QApplication>
#include<QtQml>
#include<QtQuick>
#include <qqmlengine.h>
#include<QtQuick/QQuickItem>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>



int main(int argc, char *argv[])
{
    AnimalListModel model;
    model.addAnimal(Animal("Wolf"));
    model.addAnimal(Animal("Polar bear"));
    model.addAnimal(Animal("Quoll"));

    QApplication app(argc, argv);

    QQuickView view;
      QQmlContext *ctxt = view.rootContext();

      ctxt->setContextProperty("animalModel", &model);
      view.setSource(QUrl("qrc:animalview.qml"));
          view.show();

       return app.exec();
   }
