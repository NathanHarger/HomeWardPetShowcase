#include "animallistmodel.h"

AnimalListModel::AnimalListModel(const std::vector<Animal *> &animals, QObject *parent) : QAbstractListModel(parent){
    this->animals = animals;
}


    int AnimalListModel::rowCount(const QModelIndex &parent) const{
       if(parent.isValid()){
        return this->animals.size();
       } else{
           return 0;
       }
    }

    QVariant AnimalListModel::data(const QModelIndex &index, int role) const{

    }

