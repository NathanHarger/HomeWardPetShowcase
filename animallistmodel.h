#ifndef ANIMALLISTMODEL_H
#define ANIMALLISTMODEL_H
#include <QApplication>
#include <list>

#include <QAbstractListModel>
class AnimalListModel
{
public:
    AnimalListModel();
    enum AnimalType{
        Cat,
        Dog
    };

private:
    QString shelterId;
    QString animalID;
    QString animalName;

    AnimalType animalType;
    QString animalDescription;
    std::list<QString> animalPhotos;
};

#endif // ANIMALLISTMODEL_H
