#include "animal.h"
#include <QApplication>

Animal::Animal(QString name)
{

this->animalName = name;
}


QString Animal::getName() const{
    return this->animalName;
}

QString Animal::getImage() const{

}
