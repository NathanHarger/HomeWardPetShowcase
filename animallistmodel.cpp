#include "animallistmodel.h"


int AnimalListModel::rowCount(const QModelIndex &parent) const{

        return animals.length();

}

AnimalListModel::AnimalListModel(QString name)
{
    this->modelName = name;
}

AnimalListModel::AnimalListModel(QString name , QList<Animal> animals)
{
    this->modelName = name;

    for (int i =0 ; i < animals.length(); i++)
    {
        addAnimal(animals.at(i));
    }


}

void AnimalListModel::setModelName(QString){

}

QString AnimalListModel::getModelName() const
{
    return modelName;
}

void AnimalListModel::addAnimal( const Animal &animal)
{

        // begin Insert Rows not working?
        beginInsertRows(QModelIndex(), rowCount(), rowCount()+1);
        animals << animal;

        endInsertRows();
}



//![0]

QHash<int, QByteArray> AnimalListModel::roleNames() const {
    QHash<int, QByteArray> roles;

    roles[NameRole] = "name";
    roles[ImageRole] = "image";
    roles[DescriptionRole] = "desc";
    return roles;
}

QVariant AnimalListModel::data(const QModelIndex &index, int role) const{
    if (index.row() < 0 || index.row() >= animals.size())
        return QVariant();

    const Animal animal = animals.at(index.row());
    if (role == ImageRole)
        return animal.getImage();
    else if (role == NameRole)
        return animal.getName();
    else if (role == DescriptionRole)
        return animal.getDesc();
    return QVariant();
}




