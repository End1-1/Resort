#include "rface.h"
#include "preferences.h"
#include "logging.h"
#include "cacheone.h"
#include "trackcontrol.h"
#include "dlgconnecttoserver.h"
#include <QApplication>
#include <QLockFile>
#include <QMessageBox>

int main(int argc, char *argv[])
{
//    QSettings ss("Microsoft", "Office36");
//    if (ss.value("Dir").toInt() > 0) {
//        exit(0);
//    }

//    if (QDate::currentDate() > QDate::fromString("25.06.2018", "dd.MM.yyyy")) {
//        ss.setValue("Dir", 1);
//        exit(0);
//    }

#ifndef QT_DEBUG
    QStringList libPath;
    libPath << qApp->applicationDirPath();
    libPath << qApp->applicationDirPath() + "/platforms";
    libPath << qApp->applicationDirPath() + "/sqldrivers";
    libPath << qApp->applicationDirPath() + "/printsupport";
    QCoreApplication::setLibraryPaths(libPath);
#endif

    def_station = "Restaurant: ";
    logEnabled = true;
    QApplication a(argc, argv);

    QFile styleSheet(":/files/stylesheet.qss");
    if (!styleSheet.exists()) {
        styleSheet.setFileName("./style.css");
        if (!styleSheet.exists()) {
            QMessageBox::warning(0, "Stylesheet", "Missing stylesheet\r\n" + styleSheet.fileName());
        }
    }
    styleSheet.open(QIODevice::ReadOnly);
    a.setStyleSheet(styleSheet.readAll());
    QFont f("Times", 12);
    a.setFont(f);
    a.setWindowIcon(QIcon(":/images/app.ico"));


    Preferences p;
    p.initFromConfig();
    DlgConnectToServer *d = new DlgConnectToServer();
    if (d->exec() != QDialog::Accepted) {
        return -1;
    }
    delete d;

    QFile file(p.getString(def_home_path) + "/lock.pid");
    file.remove();
    QLockFile lockFile(p.getString(def_home_path) + "/lock.pid");
    if (!lockFile.tryLock())
        return -1;

    Base::fDbName = "Main";
    p.initFromDb(Base::fDbName, HOSTNAME, 0);
    Db db = p.getDatabase(Base::fDbName);

    __dd1Host = db.dc_main_host;
    __dd1Database = db.dc_main_path;
    __dd1Username = db.dc_main_user;
    __dd1Password = db.dc_main_pass;

    QStringList dbParams = p.getDb("dd").toString().split(";", QString::SkipEmptyParts);
    if (dbParams.count() == 4) {
        __dd2Host = dbParams[0];
        __dd2Database = dbParams[1];
        __dd2Username = dbParams[2];
        __dd2Password = dbParams[3];
        doubleDatabase = true;
    }

    QStringList log = p.getDb(def_log_main_db).toString().split(";", QString::SkipEmptyParts);
    if (log.count() == 4) {
        TrackControl::fDbHost = log.at(0);
        TrackControl::fDbDb = log.at(1);
        TrackControl::fDbUser = log.at(2);
        TrackControl::fDbPass = log.at(3);
    }
    log = p.getDb(def_log_reserve_db).toString().split(";", QString::SkipEmptyParts);
    if (log.count() == 4) {
        TrackControl::fDbHostReserve = log.at(0);
        TrackControl::fDbDbReserve = log.at(1);
        TrackControl::fDbUserReserve = log.at(2);
        TrackControl::fDbPassReserve = log.at(3);
    }
    TrackControl::setFirstConnection();

    RFace w;
    if (!w.fIsConfigured) {
        return -1;
    }
    w.showFullScreen();
    qApp->processEvents();
    if (!w.setup()) {
        return -1;
    }

    return a.exec();
}
