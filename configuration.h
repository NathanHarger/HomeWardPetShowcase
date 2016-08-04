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
    QString getDevKey();
    QString getShelterID();
private:
    QString devkey;
    QString shelterid;
    QStringList AnimalTypes;

};

#endif // READCONFIGURATION_H
