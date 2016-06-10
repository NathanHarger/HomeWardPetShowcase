// Reads from qrc:/settings.txt and stores dev key, shelter id and animal types
#ifndef READCONFIGURATION_H
#define READCONFIGURATION_H
#include <QApplication>
using namespace std;
class Configuration
{
public:
    Configuration();
    QStringList getAnimalTypes();
    string getDevKey();
    string getShelterID();
private:
    string DevKey;
    string ShelterID;
    QStringList AnimalTypes;

};

#endif // READCONFIGURATION_H
