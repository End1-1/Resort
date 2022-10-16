#ifndef PPRINTINVOICE_H
#define PPRINTINVOICE_H

#include "basewidget.h"

class PPrintInvoice : BaseWidget
{
    Q_OBJECT
public:
    PPrintInvoice(const QString &id, int side, const QStringList &ids, bool noPreview, const QString &currName, double rate, bool printMeal, QWidget *parent = nullptr);
private:
    QString fId;
    int fSide;
    QString fSelection;
    bool fNoPreview;
    QString fCurrName;
    double fRate;
    bool fPrintMeal;
    void previewInvoice();
};

#endif // PPRINTINVOICE_H
