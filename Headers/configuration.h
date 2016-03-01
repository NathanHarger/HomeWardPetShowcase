#ifndef READCONFIGURATION_H
#define READCONFIGURATION_H
#include <QApplication>
using namespace std;
class Configuration
{
public:
    Configuration();

    string getDevKey();
    string getShelterID();
private:
    string DevKey;
    string ShelterID;
};

#endif // READCONFIGURATION_H
