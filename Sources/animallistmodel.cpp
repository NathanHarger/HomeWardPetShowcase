#include "../Headers/animallistmodel.h"
static double itemHeight = 100;

AnimalListModel::AnimalListModel(QObject *parent) : QAbstractListModel(parent){

}


    int AnimalListModel::rowCount(const QModelIndex &parent) const{
        Q_UNUSED(parent);
        return animals.size();
    }

    void AnimalListModel::addAnimal( const Animal &animal)
    {

        // begin Insert Rows not working?
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        animals << animal;

        endInsertRows();
    }

//![0]

    QHash<int, QByteArray> AnimalListModel::roleNames() const {
        QHash<int, QByteArray> roles;

        roles[NameRole] = "name";
        roles[ImageRole] = "image";
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
        return QVariant();
    }


