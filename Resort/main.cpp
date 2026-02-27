#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFontDatabase>
#include <QMessageBox>
#include <QStyleFactory>
#include <QTranslator>
#include "appwebsocket.h"
#include "dlgexitbyversion.h"
#include "logging.h"
#include "mainwindow.h"
#include "utils.h"

#define DEMO_

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // Включить масштабирование DPI
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#ifndef QT_DEBUG
    QStringList libPath;
    libPath << QCoreApplication::libraryPaths();
    libPath << qApp->applicationDirPath();
    libPath << qApp->applicationDirPath() + "/platforms";
    libPath << qApp->applicationDirPath() + "/sqldrivers";
    libPath << qApp->applicationDirPath() + "/printsupport";
    QCoreApplication::setLibraryPaths(libPath);
#endif
#ifdef DEMO
    QDate cd = QDate::currentDate();
    QDate vd = QDate::fromString("01.04.2020", "dd.MM.yyyy");
    if (cd > vd) {
        return 0;
    }
#endif
    def_station = "SmartHotel: ";
    Utils::initNumbersWords();
    QApplication a(argc, argv);
    Preferences p;
    p.initFromConfig();
    a.setStyle(QStyleFactory::create("fusion"));
    a.setFont(QFont("Arial", 9));
    QStringList params;
    for (int i = 0; i < argc; i++) {
        params << argv[i];
    }
    if (params.contains("logging")) {
        logEnabled = true;
        writelog("Logging enabled");
        QDir d;
        QMessageBox::information(nullptr, "Logging",
                                 "Logging is enabled into " + d.homePath() + "/" + _APPLICATION_ + "/log.txt");
    }
    if (params.contains("noversion")) {
        QMessageBox::information(nullptr, "No version", "No check version mode");
        DO_NOT_CHECK_VERSION = true;
    }
    QFile styleFile("./style.css");
    if (styleFile.exists()) {
        if (styleFile.open(QIODevice::ReadOnly)) {
            a.setStyleSheet(styleFile.readAll());
            styleFile.close();
        }
    }
    if (params.contains("--touchscreen")) {
        QFile styleFile(a.applicationDirPath() + "/SmartHotelTouch.qss");
        if (styleFile.exists()) {
            if (styleFile.open(QIODevice::ReadOnly)) {
                a.setStyleSheet(styleFile.readAll());
                styleFile.close();
            }
        }
    }
#ifdef QT_DEBUG
    logEnabled = true;
    writelog("Logging enabled");
#endif
    AppWebSocket::initInstance();
    a.setWindowIcon(QIcon(":/images/app.ico"));
    MainWindow w(params.contains("--touchscreen"));
    p.setDefaultParentForMessage( &w);
    w.show();
    //w.show(); 778842034
    a.processEvents();
    w.login();
    a.exec();
    p.saveConfig();
    return 0;
}
