#include "animal.h"
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
    if (animalPhotos.size() >= 1)
    return this->animalPhotos.at(0);
    else
        return "";
}

QStringList Animal::getStringList()
{
    QStringList result;
    result << this->getImage() << this->getDesc();
    return result;
}



QString Animal::getDesc() const{
    return this->animalDescription;
}

QString Animal::getType() const
{
    return this->animalType;
}


void Animal::setOptions(QStringList options)
{
    this->options = options;
}


void Animal::setStatus(QString status)
{
    adoptionStatus = status;
}
void Animal::setAge(QString age)
{
    this->age = age;
}

void Animal::setMedia(QStringList media)
{
    this->animalPhotos = media;
}
void Animal::setId(QString id)
{
    this->animalID = id;
}
void Animal::setBreeds(QStringList breeds)
{
    this->breeds  = breeds;
}
void Animal::setName(QString name)
{
    animalName = name;
}
void Animal::setSex(QString gender)
{
 sex = gender;
}
void Animal::setDesc(QString desc)
{
    this->animalDescription = desc;
}
void Animal::setMix(QString mixString)
{
    mix = mixString == "yes";



}
void Animal::setType(QString type)
{
    animalType = type;
}
