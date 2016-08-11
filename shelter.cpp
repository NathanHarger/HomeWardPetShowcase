#include "shelter.h"


	QString Shelter::getPhoneNumber()
	{
        return this->phoneNumber;
	}

	QString Shelter::getEmail()
	{
        return this->email;
	}

	QString Shelter::getAddress()
	{
       // qDebug() << "getter" + this->address;
        return this->address;
	}
    Shelter::Shelter(){
        this->address = "";
        this->email = "";
        this->name = "";
        this->phoneNumber = "";
    }

    QString Shelter::getName(){
        return name;
    }




//    QHash<int, QByteArray> Shelter::roleNames() const {
//        QHash<int, QByteArray> roles;

//        roles[NameRole] = "name";
//        roles[AddressRole] = "address";
//        roles[EmailRole] = "email";
//        roles[PhoneRole] = "phone";

//        return roles;
//    }
//    int Shelter::rowCount(const QModelIndex &parent) const
//    {
//        return 1;
//    }
//    QVariant Shelter::data(const QModelIndex &index, int role) const{
//        if (index.row() < 0 || index.row() > 1)
//            return QVariant();

//         if (role == NameRole)
//            return this->name;
//        else if (role == AddressRole)
//            return this->address;
//        else if (role == EmailRole)
//            return email;
//         else if (role == PhoneRole)
//             return this->phoneNumber;
//        return QVariant();
//    }
    void Shelter::setPhoneNumber(QString phoneNumber)
    {
        this->phoneNumber = phoneNumber;
    }
    void Shelter::setEmail(QString email)
    {
     this->email = email;
    }
    void Shelter::setAddress(QString address)
    {
        this->address = address;
    }
    void Shelter::setDesc(QString desc)
    {
        this->desc = desc;
    }
    void Shelter::setName(QString name)
    {
            this->name = name;
    }



