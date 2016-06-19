#include "modelmanager.h"
ModelManager::ModelManager(QStringList animalTypes)
{
    for (int i = 0; i < animalTypes.length(); i++)
    {
         AnimalListModel *d = new AnimalListModel(animalTypes.at(i));
        models.append(d);
    }

}


// m.modelName must be unique
void ModelManager::addModel(AnimalListModel* m)
{
}

// get model corrisponding to s
AnimalListModel ModelManager::getModel(QString s)
{
}

QList<AnimalListModel*> ModelManager::getModels()
{
    return models;
}

void ModelManager::addAnimal(const Animal &animal, QString modelName)
{
}

