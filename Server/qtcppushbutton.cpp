#include "qtcppushbutton.h"

QTcpPushButton::QTcpPushButton(QTcpSocket *s) :
    QPushButton("Kick")
{
    fSocket = s;
    connect(this, &QTcpPushButton::clicked, [this] () {
        fSocket->close();
    });
}
