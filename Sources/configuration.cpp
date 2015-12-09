#include "configuration.h"
#include <iostream>
#include <fstream>
using namespace std;
Configuration::Configuration()
{
    ofstream file;
    file.open("../conf/settings.txt");
    string devkey;
    getline(myfile, devkey);
    this->DevKey = strtok(devkey,"=")[1];
    string shelterid;
    getline(myfile, shelterid);
    this->ShelterID = strtok(shelterid,"=")[1];

}

