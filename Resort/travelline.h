#ifndef TRAVELLINE_H
#define TRAVELLINE_H

#include "basewidget.h"
#include "travellineconfig.h"

namespace Ui {
class TravelLine;
}

class TravelLine : public BaseWidget
{
    Q_OBJECT

public:
    explicit TravelLine(QWidget *parent = nullptr);
    ~TravelLine();

protected:
    virtual void setupTab() override;

private slots:
    void on_btnSetRoomRate_clicked();

    void on_pushButton_clicked();

    void on_btnAddRoomType_clicked();

    void on_btnRemoveRoomType_clicked();

    void on_btnAddRatePlan_clicked();

    void on_btnRemoveRatePlan_clicked();

private:
    Ui::TravelLine *ui;
    TravelLineConfig fConfig;

    void saveConfig();
};

#endif // TRAVELLINE_H
