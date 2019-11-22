#ifndef OBJECTTHREAD_H
#define OBJECTTHREAD_H

#include <QObject>

class ObjectThread : public QObject
{
    Q_OBJECT
public:
    explicit ObjectThread();
    ~ObjectThread();
    void start();

public slots:
    virtual void process() = 0;

signals:
    void finished();
};

#endif // OBJECTTHREAD_H
