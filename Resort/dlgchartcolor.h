#ifndef DLGCHARTCOLOR_H
#define DLGCHARTCOLOR_H

#include <QDialog>

namespace Ui {
class DlgChartColor;
}

class DlgChartColor : public QDialog
{
    Q_OBJECT

public:
    explicit DlgChartColor(QWidget *parent = nullptr);
    ~DlgChartColor();

private slots:
    void selectColor();
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

    void on_chShowRoomDescription_clicked(bool checked);

private:
    Ui::DlgChartColor *ui;
};

#endif // DLGCHARTCOLOR_H
