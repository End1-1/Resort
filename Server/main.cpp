#include "dlgmain.h"
#include "logging.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
#ifdef QT_DEBUG
    logEnabled = true;
#endif

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/server.png"));
    DlgMain w;
    w.exec();

    return a.exec();
}
