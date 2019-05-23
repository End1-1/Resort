#include "datahandler.h"

DataHandler::DataHandler(const QByteArray &data, QObject *parent) :
    QObject(parent),
    fData(data)
{

}

DataHandler::~DataHandler()
{

}
