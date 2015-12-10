#include "configuration.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
Configuration::Configuration()
{
    fstream file;

    file.open("../conf/settings.txt");
    string devkey;
    char* devkeyCharpoint = &devkey[0];
    getline(file,devkey);
    this->DevKey = strtok(devkeyCharpoint,"=")[1];
    string shelterid;
    char *shelterCharPoint = &shelterid[0];
    getline(file, shelterid);
    this->ShelterID = strtok(shelterCharPoint,"=")[1];

}

