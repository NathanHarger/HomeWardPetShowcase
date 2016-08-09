#ifndef ANIMAL_H
#define ANIMAL_H
#include<string>
#include <list>
#include <QApplication>
             class Animal
{
public:

  Animal();

QString getName() const;
    QString getImage() const;
    QString getDesc() const;
    QString getType() const;
    void setOptions(QStringList);
   void setStatus(QString);
   void setAge(QString);
    void setMedia(QStringList);
   void setId(QString);
   void setBreeds(QStringList);
   void setName(QString);
   void setSex(QString);
   void setDesc(QString);
   void setMix(QString);
   void setType(QString);
    Animal(QString name);
private:

    QString shelterId;
   QString animalID;
    QString animalName;

    QString animalDescription;
    QStringList animalPhotos;
    QStringList options;
    QStringList breeds;
    QString age;
    QString animalType;
    QString adoptionStatus;
    bool mix;
    QString sex;
    QString size;
};

#endif // ANIMAL_H
