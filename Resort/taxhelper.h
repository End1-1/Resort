#ifndef TAXHELPER_H
#define TAXHELPER_H

#include <QObject>
#include <QMap>

typedef struct {
    int id;
    QString ip;
    int port;
    QString password;
    QString dept;
    QString name;
    QString opcode;
    QString oppin;
    QString extPos;
} TaxPoint;

class TaxHelper : public QObject
{
    Q_OBJECT
public:
    explicit TaxHelper(QObject *parent = nullptr);

    static void init();

    static TaxHelper *fInstance;

    QMap<int, TaxPoint> fTaxPoints;

    QMap<int, int> fTaxVAT;

    QMap<int, int> fTaxNoVAT;

};

#endif // TAXHELPER_H
