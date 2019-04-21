#ifndef FEXPORTRESERVATION_H
#define FEXPORTRESERVATION_H

#include "wfilterbase.h"

namespace Ui {
class FExportReservation;
}

class FExportReservation : public WFilterBase
{
    Q_OBJECT

public:
    explicit FExportReservation(QWidget *parent = nullptr);
    ~FExportReservation();
    virtual QString reportTitle();
    virtual QWidget *firstElement();
    virtual QWidget *lastElement();
    virtual void apply(WReportGrid *rg);

private slots:
    void openInvoice();
    void openReservation();
    void on_btnStartExport_clicked();
    void sortFinished();
    void on_chSelectAll_clicked(bool checked);

private:
    Ui::FExportReservation *ui;
    void exportReservation(const QString &id);
};

#endif // FEXPORTRESERVATION_H
