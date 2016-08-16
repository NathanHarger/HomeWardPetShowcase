//Model that stores info about pet from Petfinder
#ifndef ANIMALLISTMODEL_H
#define ANIMALLISTMODEL_H
#include <QApplication>
#include <QAbstractListModel>
#include "animal.h"
class AnimalListModel: public QAbstractListModel
{

public:
    // AnimalListModel(QObject* parent =0);
     AnimalListModel(QString);
     AnimalListModel(QString, QList<Animal>);
    enum AnimalRoles {
        ImageRole = Qt::UserRole + 1,
        NameRole,
        DescriptionRole,
        AnimalRole
    };


    Q_INVOKABLE QObject* getAnimal(const int row);


    void setModelName(QString);
     QString getModelName() const;

    void addAnimal(const Animal &animal);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

    QString getQmlObject(const QModelIndex) const;
protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QString modelName;
    QList<Animal> animals;
};

#endif // ANIMALLISTMODEL_H
