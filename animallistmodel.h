#ifndef ANIMALLISTMODEL_H
#define ANIMALLISTMODEL_H
#include <QApplication>

#include <QAbstractListModel>
#include<animal.h>
class AnimalListModel :public QAbstractListModel
{
public:

    AnimalListModel(const std::vector<Animal*>& animals,QObject* parent =0);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    std::vector<Animal*> animals;
    Animal::AnimalType animalType;

};

#endif // ANIMALLISTMODEL_H
