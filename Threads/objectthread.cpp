#include "objectthread.h"
#include <QThread>

ObjectThread::ObjectThread() :
    QObject()
{

}

ObjectThread::~ObjectThread()
{

}

void ObjectThread::start()
{
    QThread *t = new QThread();
    moveToThread(t);
    connect(t, SIGNAL(finished()), this, SLOT(deleteLater()));
    connect(t, SIGNAL(started()), this, SLOT(process()));
    connect(this, SIGNAL(finished()), t, SLOT(quit()));
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
    t->start();
}
