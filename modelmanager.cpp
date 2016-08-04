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
    for (int i = 0; i < models.length(); i++)
    {
        if (models.at(i)->getModelName() == m->getModelName())
        {
            return;
        }
    }
    models.append(m);
}

// get model corrisponding to s
AnimalListModel* ModelManager::getModel(QString s)
{
    for (int i = 0; i < models.length(); i++)
    {
        if (models.at(i)->getModelName() == s)
        {
            return models.at(i);
        }
    }
}






QList<AnimalListModel*> ModelManager::getModels()
{
    return models;
}

void ModelManager::addAnimal(const Animal &animal, QString modelName)
{
    for (int i = 0; i < models.length(); i++)
    {
        if (models.at(i)->getModelName() == modelName)
        {
            models.at(i)->addAnimal(animal);
        }
    }

}

