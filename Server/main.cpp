#include "dlgmain.h"
#include "logging.h"
#include <QApplication>
#include <QIcon>
#include <QTextCodec>

int main(int argc, char *argv[])
{
#ifdef QT_DEBUG
    logEnabled = true;
#endif

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/server.png"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8") );

    DlgMain w;
    w.exec();

    return a.exec();
}
