#ifndef PPRINTINVOICE_H
#define PPRINTINVOICE_H

#include "basewidget.h"

class PPrintInvoice : BaseWidget
{
    Q_OBJECT
public:
    PPrintInvoice(const QString &id, int side, const QStringList &ids, bool noPreview, QWidget *parent = nullptr);
private:
    QString fId;
    int fSide;
    QString fSelection;
    bool fNoPreview;
    void previewInvoice();
};

#endif // PPRINTINVOICE_H
