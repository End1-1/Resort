#ifndef QTCPPUSHBUTTON_H
#define QTCPPUSHBUTTON_H

#include <QPushButton>
#include <QTcpSocket>

class QTcpPushButton : public QPushButton
{
public:
    QTcpPushButton(QTcpSocket *s);
    QTcpSocket *fSocket;
signals:
    void kick(QTcpSocket *socket);
};

#endif // QTCPPUSHBUTTON_H
