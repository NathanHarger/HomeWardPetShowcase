#ifndef ANIMALLISTMODEL_H
#define ANIMALLISTMODEL_H
#include <QApplication>
#include <list>
#include <QAbstractListModel>
class AnimalListModel :public QAbstractListModel
{
public:
    AnimalListModel(const std::vector<Animal*>& animals,QObject* parent =0);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

    enum AnimalType{
        Cat,
        Dog
    };


private:
    std::vector<Animal*> animals;
    QString shelterId;
    QString animalID;
    QString animalName;

    AnimalType animalType;
    QString animalDescription;
    std::list<QString> animalPhotos;
};

#endif // ANIMALLISTMODEL_H
