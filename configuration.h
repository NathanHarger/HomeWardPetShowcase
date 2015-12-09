#ifndef READCONFIGURATION_H
#define READCONFIGURATION_H
#include <string.h>

class Configuration
{
public:
    Configuration();
    string DevKey{get};
    string ShelterID{get};
};

#endif // READCONFIGURATION_H
