#ifndef DLGHOUSEITEMONOFFWIDGET_H
#define DLGHOUSEITEMONOFFWIDGET_H

#include <QWidget>

namespace Ui {
class DlgHouseItemOnOffWidget;
}

class DlgHouseItemOnOffWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DlgHouseItemOnOffWidget(QWidget *parent = nullptr);
    ~DlgHouseItemOnOffWidget();
    void setChecked(bool v);
    bool isChecked();

private slots:
    void on_btnReady_clicked();
    void on_btnOk_clicked();

private:
    Ui::DlgHouseItemOnOffWidget *ui;

signals:
    void clicked();
};

#endif // DLGHOUSEITEMONOFFWIDGET_H
