#ifndef ANIMAL_H
#define ANIMAL_H
#include<string>
#include <list>
#include <QApplication>

class Animal
{
public:
    static const QString animalTypeString[];

    enum AnimalType{
        Cat ,
        Dog
    };

QString getName() const;
    QString getImage() const;

    Animal(QString name);
private:

    QString shelterId;
   QString animalID;
    QString animalName;

    AnimalType animalType;
    QString animalDescription;
    std::list<QString> animalPhotos;
};

#endif // ANIMAL_H
