#include "animallistmodel.h"


int AnimalListModel::rowCount(const QModelIndex &parent) const{
Q_UNUSED(parent);
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

QString AnimalListModel::getQmlObject(const QModelIndex mI) const
{
    Animal animal = animals.at(mI.row());

    QString innerObject;

    //innerObject.append( "\"name\":", "\"",animal.getName() ,"\"" , ",");
   // innerObject += "\"desc\":" += "\"" += animal.getDesc() += "\"";

  //  QString result = "{" + innerObject + "}";
   // return result;

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
    roles[AnimalRole] = "animal";
    return roles;
}




QVariant AnimalListModel::data(const QModelIndex &index, int role) const{
    if (index.row() < 0 || index.row() >= animals.size())
        return QVariant();

    Animal animal = animals.at(index.row());
     if (role == ImageRole)
        return animal.getImage();
    else if (role == NameRole)
        return animal.getName();
    else if (role == DescriptionRole)
        return animal.getDesc();
     else if(role == AnimalRole){
         return animal.getStringList();
     }

    return QVariant();
}




