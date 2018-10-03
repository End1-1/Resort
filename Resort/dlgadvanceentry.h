#ifndef DLGADVANCEENTRY_H
#define DLGADVANCEENTRY_H

#include "roweditordialog.h"

namespace Ui {
class DlgAdvanceEntry;
}

class DlgAdvanceEntry : public RowEditorDialog
{
    Q_OBJECT

public:
    static void advance(const QString &code = "");

    ~DlgAdvanceEntry();

    virtual void callback(int sel, const QString &code);

protected:
    virtual bool isDataCorrect();

private slots:
    void on_btnCancel_clicked();

    void on_btnSave_clicked();

    void on_leAmount_textChanged(const QString &arg1);

    void on_btnPrint_clicked();

    void on_btnNew_clicked();

    void on_btnPrintTax_clicked();

private:
    explicit DlgAdvanceEntry(QList<QVariant> &values, QWidget *parent = 0);
    Ui::DlgAdvanceEntry *ui;
};

#endif // DLGADVANCEENTRY_H
