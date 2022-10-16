#ifndef PRINTTAX_HD
#define PRINTTAX_HD

#include "baseextendeddialog.h"
#include <QTimer>

namespace Ui {
class PrintTaxD;
}

class PrintTaxD : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit PrintTaxD(int taxid, QWidget *parent = nullptr);
    ~PrintTaxD();
    QString fAmountPre;
    QString fAmountCash;
    QString fAmountCard;
    QString fInvoice;
    QStringList fDept;
    QStringList fRecList;
    QStringList fCodeList;
    QStringList fNameList;
    QStringList fQtyList;
    QStringList fPriceList;
    QStringList fAdgCode;
    QStringList fTaxNameList;
    int fTaxID;
    void setPrepaid(const QString &amount);
    void build();
    bool print();
    int exec2();

private slots:
    void timeout();
    void on_btnCancel_clicked();
    void on_btnPrint_clicked();
    void on_tblData_clicked(const QModelIndex &index);
    void on_leCard_textEdited(const QString &arg1);
    void on_leCash_textEdited(const QString &arg1);
    void on_lePre_textEdited(const QString &arg1);
    void on_chCheckUncheckAll_clicked(bool checked);
    void on_tblFilter_clicked(const QModelIndex &index);
    void on_btnClearFilter_clicked();

private:
    Ui::PrintTaxD *ui;
    QString fFilter;
    QTimer fTimer;
    void correctAmounts(EQLineEdit *l1, EQLineEdit *l2, EQLineEdit *l3);
    void countAmount();
    void filter();
    int fTaxCode;
};

#endif // PRINTTAX_H
