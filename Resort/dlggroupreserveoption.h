#ifndef DLGGROUPRESERVEOPTION_H
#define DLGGROUPRESERVEOPTION_H

#include "basedialog.h"

namespace Ui {
class DlgGroupReserveOption;
}

class DlgGroupReserveOption : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgGroupReserveOption(QWidget *parent = nullptr);
    ~DlgGroupReserveOption();
    static void addRemove(const QString &id);

private slots:
    void on_btnAddToGroup_clicked();
    void on_bgtnRemoveFromGroup_clicked();

private:
    Ui::DlgGroupReserveOption *ui;
};

#endif // DLGGROUPRESERVEOPTION_H
