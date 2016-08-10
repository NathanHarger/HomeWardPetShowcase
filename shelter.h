#include <QApplication>
#include <QAbstractListModel>


class Shelter : public QAbstractListModel
{

public:
    Shelter();
    QString getPhoneNumber();
    QString getEmail();
    QString getAddress();
    QStringList getStringModel();
    enum ShelterRoles
    {
        NameRole = Qt::UserRole +1,
        AddressRole,
        EmailRole,
        PhoneRole
    };
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

    void setPhoneNumber(QString);
    void setEmail(QString);
    void setAddress(QString);
    void setDesc(QString);
    void setName(QString);
protected:
    QHash<int, QByteArray> roleNames() const;


private:

    QString phoneNumber;
    QString email;
    QString address;
    QString desc;
    QString name;
};




