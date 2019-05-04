#ifndef DLGCONFIGGRID_H
#define DLGCONFIGGRID_H

#include "basedialog.h"

namespace Ui {
class DlgConfigGrid;
}

class GOWidget;

class DlgConfigGrid : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgConfigGrid(QWidget *parent = nullptr);
    ~DlgConfigGrid();
    static bool config(QString &fontName, int &fontSize, bool &fontBold, bool &readOnly, bool &reset, int &rowHeight, QWidget *parent);

private slots:
    void on_btnOK_clicked();
    void on_btnCancel_clicked();
    void on_btnReset_clicked();

private:
    Ui::DlgConfigGrid *ui;
    GOWidget *fAddWidget;
    bool fReset;
};

#endif // DLGCONFIGGRID_H
