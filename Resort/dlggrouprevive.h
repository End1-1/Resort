#ifndef DLGGROUPREVIVE_H
#define DLGGROUPREVIVE_H

#include "basedialog.h"

namespace Ui {
class DlgGroupRevive;
}

class DlgGroupRevive : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgGroupRevive(QWidget *parent = nullptr);
    ~DlgGroupRevive();
    void addRow(const QString &code, int room, const QDate &entry, const QDate &departure, const QString &guest);

private slots:
    void on_btnCancel_clicked();
    void on_btnRevive_clicked();

private:
    Ui::DlgGroupRevive *ui;
};

#endif // DLGGROUPREVIVE_H
