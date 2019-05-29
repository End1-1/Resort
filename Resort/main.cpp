#include "mainwindow.h"
#include "login.h"
#include "logging.h"
#include "utils.h"
#include "dlgexitbyversion.h"
#include <QApplication>
#include <QFontDatabase>
#include <QFile>
#include <QStyleFactory>
#include <QTranslator>
#include <QMessageBox>
#include <QDir>

int main(int argc, char *argv[])
{
#ifndef QT_DEBUG
    QStringList libPath;
    libPath << "./";
    libPath << "./platforms";
    libPath << "./sqldrivers";
    QCoreApplication::setLibraryPaths(libPath);
#endif

    def_station = "SmartHotel: ";
    Utils::initNumbersWords();
    QApplication a(argc, argv);
    Preferences p;
    p.initFromConfig();

    a.setStyle(QStyleFactory::create("fusion"));
    a.setFont(QFont("Arial", 9));

    QFile styleFile("./style.css");
    if (styleFile.exists()) {
        styleFile.open(QIODevice::ReadOnly);
        a.setStyleSheet(styleFile.readAll());
        styleFile.close();
    }

    QStringList params;
    for (int i = 0; i < argc; i++) {
        params << argv[i];
    }
    if (params.contains("logging")) {
        logEnabled = true;
        writelog("Logging enabled");
        QDir d;
        QMessageBox::information(nullptr, "Logging", "Logging is enabled into " + d.homePath() + "/" + _APPLICATION_ + "/log.txt");
    }
    if (params.contains("noversion")) {
        QMessageBox::information(nullptr, "No version", "No check version mode");
        DO_NOT_CHECK_VERSION = true;
    }
#ifdef QT_DEBUG
    logEnabled = true;
    writelog("Logging enabled");
#endif

    a.setWindowIcon(QIcon(":/images/app.ico"));
    MainWindow w;
    p.setDefaultParentForMessage(&w);
    w.show();
    //w.show(); 778842034
    a.processEvents();
    w.login();
    a.exec();
    p.saveConfig();
    return 0;
}
