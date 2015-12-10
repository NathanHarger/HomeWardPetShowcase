#ifndef ANIMAL_H
#define ANIMAL_H
#include<string>
#include <list>

class Animal
{
public:
    enum AnimalType{
        Cat,
        Dog
    };

    Animal();
private:

    std::string shelterId;
    std::string animalID;
    std::string animalName;

    AnimalType animalType;
    std::string animalDescription;
    std::list<std::string> animalPhotos;
};

#endif // ANIMAL_H
