#include "dlgmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{

#ifndef QT_DEBUG
    QStringList libPath;
    libPath << "./";
    libPath << "./platforms";
    libPath << "./sqldrivers";
    libPath << QCoreApplication::libraryPaths();
    QCoreApplication::setLibraryPaths(libPath);
#endif

    QApplication a(argc, argv);
    DlgMain w;
    w.show();

    return a.exec();
}
