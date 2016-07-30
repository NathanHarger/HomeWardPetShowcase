#ifndef ANIMAL_H
#define ANIMAL_H
#include<string>
#include <list>
#include <QApplication>

class Animal
{
public:

  

QString getName() const;
    QString getImage() const;
    QString getDesc() const;

    Animal(QString name);
private:

    QString shelterId;
   QString animalID;
    QString animalName;

    QString animalDescription;
    std::list<QString> animalPhotos;
    QStringList options;
    QStringList breeds;
    QString age;
    QString AnimalType;
    QString adoptionStatus;
    bool mix;
    QString sex;
    QString size;
};

#endif // ANIMAL_H
