#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>

class DataHandler : public QObject
{
    Q_OBJECT

public:
    explicit DataHandler(const QByteArray &data, QObject *parent = nullptr);
    ~DataHandler();

private:
    const QByteArray &fData;
};

#endif // DATAHANDLER_H
