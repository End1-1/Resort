#ifndef WROOMCHARTTEMPRECTDLG_H
#define WROOMCHARTTEMPRECTDLG_H

#include "basedialog.h"

namespace Ui {
class WRoomChartTempRectDlg;
}

class WRoomChartTempRectDlg : public BaseDialog
{
    Q_OBJECT

public:
    explicit WRoomChartTempRectDlg(QWidget *parent = nullptr);
    ~WRoomChartTempRectDlg();
    void setDates(const QDate &d1, const QDate &d2);

private slots:
    void on_btnCancel_clicked();

private:
    Ui::WRoomChartTempRectDlg *ui;
};

#endif // WROOMCHARTTEMPRECTDLG_H
