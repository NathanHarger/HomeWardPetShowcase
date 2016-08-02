#include "animal.h"
#include <QApplication>
Animal::Animal(QString name)
{

this->animalName = name;
}
Animal::Animal()
{

}

QString Animal::getName() const{
    return this->animalName;
}

QString Animal::getImage() const{
    return "";
}

QString Animal::getDesc() const{
    return this->animalDescription;
}
