#ifndef ANIMALLISTMODEL_H
#define ANIMALLISTMODEL_H
#include <QApplication>
#include <QAbstractListModel>
#include<animal.h>
class AnimalListModel :public QAbstractListModel
{

public:
    enum AnimalRoles {
        ImageRole = Qt::UserRole + 1,
        NameRole
    };
    AnimalListModel(QObject* parent =0);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    void addAnimal(const Animal &animal);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Animal> animals;
   //std::vector<Animal*> animals;
    Animal::AnimalType animalType;

};

#endif // ANIMALLISTMODEL_H
