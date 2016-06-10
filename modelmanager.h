// collection of animal models to QML repeater. Creates new models when passed a Qstring. Returns a model that corresponds to
// QString representing a type of animal. Reads animal types from file and initilizes to that set of animal.
// Uses json to setup animal objects into appripiate models
#include "../Headers/animallistmodel.h"
class ModelManager
{


public:
    ModelManager();

    AnimalListModel* getModel(QString animalType);
private:

};
