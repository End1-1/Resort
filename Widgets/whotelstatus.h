#ifndef WHOTELSTATUS_H
#define WHOTELSTATUS_H

#include "basewidget.h"

class QTableWidget;
class PPrintScene;
class PPrintPreview;
class PTextRect;

namespace Ui {
class WHotelStatus;
}

class WHotelStatus : public BaseWidget
{
    Q_OBJECT

public:
    explicit WHotelStatus(QWidget *parent = nullptr);
    ~WHotelStatus();
    virtual void setup();

private slots:
    void on_btnPrint_clicked();

private:
    Ui::WHotelStatus *ui;
    void printTable(PPrintPreview *pp, PPrintScene *&ps, int &top, int &page,
                    QTableWidget *table, const QString &title, bool withHeader,
                    PTextRect &th, PTextRect &thHead, int rowHeight);
};

#endif // WHOTELSTATUS_H
