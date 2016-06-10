//class with static api utility functions
#ifndef APIMANAGER_H
#define APIMANAGER_H
#include <QApplication>
#include "../Headers/animallistmodel.h"

class ApiManager
{
public:

    static void MakeApiCall();
    static AnimalListModel GetAnimals(QString shelterId, Animal::AnimalType animalType);
private:

};

#endif // APIMANAGER_H
