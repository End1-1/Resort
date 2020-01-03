#include "froomarrangement.h"
#include "ui_froomarrangement.h"
#include "wreportgrid.h"

FRoomArrangement::FRoomArrangement(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FRoomArrangement)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Room arrangement"), ":/images/graph.png");
}

FRoomArrangement::~FRoomArrangement()
{
    delete ui;
}

QString FRoomArrangement::reportTitle()
{
    return QString("%1 %2")
            .arg(tr("Room arrangement"))
            .arg(ui->cbYear->currentText());
}

QWidget *FRoomArrangement::firstElement()
{
    return ui->cbYear;
}

QWidget *FRoomArrangement::lastElement()
{
    return ui->cbYear;
}

void FRoomArrangement::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "", tr("Month"))
            .setColumn(100, "", tr("B/O"))
            .setColumn(100, "", tr("B/B"));
    bool f = true;
    QList<int> monthList;
    QString c;
    if (ui->ch1->isChecked()) {
        monthList << 1;
    }
    if (ui->ch2->isChecked()) {
        monthList << 2;
    }
    if (ui->ch3->isChecked()) {
        monthList << 3;
    }
    if (ui->ch4->isChecked()) {
        monthList << 4;
    }
    if (ui->ch5->isChecked()) {
        monthList << 5;
    }
    if (ui->ch6->isChecked()) {
        monthList << 6;
    }
    if (ui->ch7->isChecked()) {
        monthList << 7;
    }
    if (ui->ch8->isChecked()) {
        monthList << 8;
    }
    if (ui->ch9->isChecked()) {
        monthList << 9;
    }
    if (ui->ch10->isChecked()) {
        monthList << 10;
    }
    if (ui->ch11->isChecked()) {
        monthList << 11;
    }
    if (ui->ch12->isChecked()) {
        monthList << 12;
    }
    foreach (int m, monthList) {
        if (f) {
            f = false;
        } else {
            c += ",";
        }
        c += QString::number(m);
    }
    if (f) {
        message_error(tr("No month is selected"));
        return;
    }
    QString sql = QString("select extract(month from m.f_wdate), count(bo.f_id), count(bb.f_id) "
            "from m_register m "
            "left join f_reservation bo on bo.f_invoice=m.f_inv and bo.f_arrangement=1 and bo.f_state in (1,3) "
            "left join f_reservation bb on bb.f_invoice=m.f_inv and bb.f_arrangement=2 and bb.f_state in (1,3) "
            "where m.f_itemCode in (" + fPreferences.getDb(def_room_charge_id).toString() + ") "
            "and extract(year from m.f_wdate)=%1 and extract(month from m.f_wdate) in (%2) "
            " and m.f_canceled=0 group by 1").arg(ui->cbYear->currentText()).arg(c);
            ;
    rg->fModel->setSqlQuery(sql);
    rg->fModel->apply(rg);
}
