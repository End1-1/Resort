#ifndef FSTOREDOCS_H
#define FSTOREDOCS_H

#include "wfilterbase.h"

namespace Ui {
class FStoreDocs;
}

class FStoreDocs : public WFilterBase
{
    Q_OBJECT

public:
    explicit FStoreDocs(QWidget *parent = 0);
    ~FStoreDocs();
    virtual QWidget *firstElement();
    virtual QString reportTitle();
    virtual void apply(WReportGrid *rg);
    static void openReport();
private slots:
    void copyDoc();
    void doubleClicked(const QList<QVariant> &row);
    void on_btnDateLeft_clicked();

    void on_btnDateRight_clicked();

private:
    Ui::FStoreDocs *ui;
};

#endif // FSTOREDOCS_H
