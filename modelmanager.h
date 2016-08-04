#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "animallistmodel.h"


class ModelManager
{
public:
    ModelManager(QStringList animalTypes);

    // m.modelName must be unique
    void addModel(AnimalListModel* m);

    // get model corrisponding to s
    AnimalListModel* getModel(QString s);

    // get all models as a qlist of animallistmodel*
    QList<AnimalListModel*> getModels();

    void addAnimal(const Animal &animal, QString modelName);
    void saveModelsToDisk(QString filename);


private:
    QList< AnimalListModel*> models;


};

#endif // MODELMANAGER_H
