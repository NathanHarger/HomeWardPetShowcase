#-------------------------------------------------
#
# Project created by QtCreator 2015-12-08T00:22:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homewardpetshowcase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    animallistmodel.cpp \
    apimanager.cpp

HEADERS  += mainwindow.h \
    animallistmodel.h \
    apimanager.h

FORMS    += mainwindow.ui

DISTFILES += \
    animalview.qml \
    FindShelterId.py
