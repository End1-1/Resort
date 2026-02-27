#include "baseuid.h"
#include <QDebug>
#include <QFile>
#include <QHostInfo>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QSqlError>
#include "utils.h"
#include <doubledatabase.h>
//#include <QRandomGenerator>

#define SRC QString("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ")
#define len 8
#define low 0
#define high 35
#define maxtries 200

QString BaseUIDX::fAirDbName;
QString BaseUIDX::fAirHost;
QString BaseUIDX::fAirUser;
QString BaseUIDX::fAirPass;

int BaseUIDX::fUserId = 0;
int _IDGENMODE_ = 0;

BaseUIDX::BaseUIDX()
{
}

QString BaseUIDX::genID(const QString &prefix)
{
    return (_IDGENMODE_ == 0 ? INTID(prefix) : ID(prefix));
}

QString BaseUIDX::ID(const QString &vaucher)
{
    DoubleDatabase d;
    d.setDatabase(fAirHost, fAirDbName, fAirUser, fAirPass);
    d.setNoSqlErrorLogMode(true);
    int idlen = 8;

    if(vaucher == "DR") {
        idlen = 10;
    }

    if(vaucher == "PS") {
        idlen = 8;
    }

    if(vaucher == "RV") {
        idlen = 9;
    }

    QString errstr;

    if(!d.open()) {
        QMessageBox::critical(nullptr, "ID ERROR",
                              QString("<H1><font color=\"red\">RANDOM ID GENERATOR FAIL (CANNOT OPEN DB) </font></h1>")
                              + "<br>" + fAirHost + ":" + fAirDbName
                              + "<br>" + d.fLastError);
        exit(0);
    }

    QString src2;
    QString result;

    for(int i = 0; i < idlen; i++) {
        QString src1 = SRC;

        for(int j = 0; j < idlen; j++) {
            int i1 = QRandomGenerator::global()->generate() % ((high + 1) - low) + low;
            int i2 = QRandomGenerator::global()->generate() % ((high + 1) - low) + low;
            QChar temp = src1.at(i1);
            src1[i1] = src1[i2];
            src1[i2] = temp;
        }

        src2 += src1;
    }

    QString src3;
    int shiftLeft = QRandomGenerator::global()->generate() % 11;

    for(int i = 0; i < shiftLeft; i++) {
        src3 += src2.at(0);
        src2.remove(0, 1);
    }

    src2 += src3;
    int trynum = 1;
    int totaltrynum = 1;
    int h = src2.length() ;
    bool find = false;

    while(result.length() < idlen && trynum < maxtries) {
        while(result.length() < idlen) {
            result += src2.at(QRandomGenerator::global()->generate() % h);
        }

        for(int i = 0; i < result.length(); i++) {
            bool dr = d.exec(
                          QString("insert into airwick.f_id (f_value, f_try, f_comp, f_user, f_date, f_time, f_db) values ('%1-%2', %3, '%4', '%5', '%6', '%7', database())")
                          .arg(vaucher.toUpper())
                          .arg(result).arg(totaltrynum)
                          .arg(QHostInfo::localHostName().toUpper())
                          .arg(fUserId)
                          .arg(QDate::currentDate().toString("yyyy-MM-dd"))
                          .arg(QTime::currentTime().toString("HH:mm:ss")));

            if(!dr) {
                QString err = d.fLastError;
                errstr = err;

                if(err.toLower().contains("duplicate entry")) {
                    totaltrynum++;
                    QChar ch = result.at(0);
                    result.remove(0, 1);
                    result += ch;
                    continue;
                } else {
                    goto DONE;
                }
            } else {
                find = true;
                goto DONE;
            }
        }

        trynum++;
        result = "";
    }

DONE:

    if(!find) {
        QMessageBox::critical(nullptr, "ID ERROR", QString("<H1><font color=\"red\">RANDOM ID GENERATOR FAIL </font></h1>")
                              + "<br>" + errstr);
        exit(0);
    }

    d.close();
    return vaucher.toUpper() + "-" + result;
}

QString BaseUIDX::INTID(const QString &prefix)
{
    DoubleDatabase db(fAirHost, fAirDbName, fAirUser, fAirPass);
    int totaltrynum = 0;
    bool done = false;
    QString result;

    do {
        QString query = QString("select f_max, f_zero from serv_id_counter where f_id='%1' for update").arg(prefix);

        if(!db.exec(query)) {
            QMessageBox::critical(nullptr, "ID ERROR",
                                  "<H1><font color=\"red\">COUNTER ID GENERATOR FAIL</font></h1><br>" + db.fLastError + "<br>"
                                  + QString("Host: %1, Schema: %2").arg(fAirHost, fAirDbName));
            exit(0);
        }

        if(db.nextRow()) {
            int max = db.getInt(0) + 1;
            int zero = db.getInt(1);
            db[":f_max"] = max;
            db[":f_id"] = prefix;
            query = "update serv_id_counter set f_max=:f_max where f_id=:f_id";
            db.exec(query);
            result = QString("%1").arg(max, zero, 10, QChar('0'));
        } else {
            query = "insert into serv_id_counter (f_id, f_max, f_zero) values (" + ap(prefix.toUpper()) + ", 0, 6)";
            db.exec(query);
            totaltrynum++;
            continue;
        }

        db.exec(QString("insert into airwick.f_id (f_value, f_try, f_comp, f_user, f_date, f_time, f_db) values ('%1-%2', %3, '%4', '%5', '%6', '%7', database())")
                .arg(prefix.toUpper())
                .arg(result).arg(totaltrynum)
                .arg(QHostInfo::localHostName().toUpper())
                .arg(fUserId)
                .arg(QDate::currentDate().toString("yyyy-MM-dd"))
                .arg(QTime::currentTime().toString("HH:mm:ss")));

        if(db.fLastError.toLower().contains("duplicate entry")) {
            totaltrynum++;
        } else {
            done = true;
        }

        if(totaltrynum > 20) {
            QMessageBox::critical(nullptr, "ID ERROR", "<H1><font color=\"red\">COUNTER ID GENERATOR FAIL, GIVE UP</font></h1>");
            exit(0);
        }
    } while(!done);

    return prefix + "-" + result;
}
