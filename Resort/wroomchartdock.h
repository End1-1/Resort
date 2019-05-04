#ifndef WROOMCHARTDOCK_H
#define WROOMCHARTDOCK_H

#include <QDockWidget>

namespace Ui {
class WRoomChartDock;
}

class WRoomChartDock : public QDockWidget
{
    Q_OBJECT

public:
    explicit WRoomChartDock(QWidget *parent = nullptr);
    ~WRoomChartDock();
    void setData(const QMap<QString, QString> &data);

private slots:
    void on_btnReserve_clicked();
    void on_btnInvoice_clicked();
    void on_btnGroup_clicked();

private:
    Ui::WRoomChartDock *ui;
    int fGroup;
    int fReserveState;
};

#endif // WROOMCHARTDOCK_H
