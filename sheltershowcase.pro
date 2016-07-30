#-------------------------------------------------
#
# Project created by QtCreator 2015-12-08T00:22:38
#
#-------------------------------------------------

QT       += core gui
QT         += qml quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += quickwidgets
QT += network

TARGET = sheltershowcase
TEMPLATE = app


SOURCES +=animal.cpp \
    apimanager.cpp \
    configuration.cpp \
    main.cpp \
    mainwindow.cpp \
    animallistmodel.cpp \
    modelmanager.cpp

HEADERS  += animal.h \
    apimanager.h \
    configuration.h \
    mainwindow.h \
    animallistmodel.h \
    modelmanager.h

FORMS

DISTFILES +=

    FindShelterId.py

RESOURCES += \
    resources.qrc

FORMS += \
    mainwindow.ui
