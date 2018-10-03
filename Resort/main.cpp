#include "mainwindow.h"
#include "login.h"
#include "logging.h"
#include "utils.h"
#include <QApplication>
#include <QFontDatabase>
#include <QFile>
#include <QStyleFactory>
#include <QTranslator>

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
    }
#ifdef QT_DEBUG
    logEnabled = true;
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
