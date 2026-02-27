#include "user.h"

User::User()
{
    fValid = false;
}

User::User(const QString &password, QObject *parent) :
    QObject(parent),
    Base()
{
    QString query = "select f_id, f_group, concat(f_firstName, ' ', f_lastName) from users where f_altPassword=md5(:pass) and f_state=1 ";
    DoubleDatabase fDD;
    fDD[":pass"] = password;
    fDD.exec(query);
    if (!fDD.nextRow()) {
        fValid = false;
    } else {
        fId = fDD.getInt(0);
        fGroup = fDD.getInt(1);
        fName = fDD.getString(2);
        fValid = true;
    }
}

bool User::isValid()
{
    return fValid;
}

void User::loadUser()
{

}
