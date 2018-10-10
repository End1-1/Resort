#ifndef QSOCKETTEXTTHREAD_H
#define QSOCKETTEXTTHREAD_H

#include <QThread>


class QSocketTextThread : public QThread
{
    Q_OBJECT
public:
    QSocketTextThread(QObject *parent = 0);

    ~QSocketTextThread();

protected:
    virtual void run();
};

#endif // QSOCKETTEXTTHREAD_H
