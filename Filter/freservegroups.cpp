#include "freservegroups.h"
#include "ui_freservegroups.h"
#include "wreportgrid.h"
#include "dlggroupreservationfuck.h"
#include <QInputDialog>

FReserveGroups::FReserveGroups(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FReserveGroups)
{
    ui->setupUi(this);
    fReportGrid->setupTabTextAndIcon(tr("Reservation groups"), ":/images/bed.png");
    if (r__(cr__super_correction)) {
        fReportGrid->addToolBarButton(":/images/garbage.png", tr("Remove group"), SLOT(removeGroup()), this)->setFocusPolicy(Qt::NoFocus);
    }
    if (r__(cr__reservation_group_reservation)) {
        fReportGrid->setBtnNewVisible(true);
    }
    connect(fReportGrid, SIGNAL(doubleClickOnRow(QList<QVariant>)), this, SLOT(doubleClick(QList<QVariant>)));
    connect(fReportGrid, SIGNAL(newBtn()), this, SLOT(newGroup()));
}

FReserveGroups::~FReserveGroups()
{
    delete ui;
}

QWidget *FReserveGroups::firstElement()
{
    return ui->deStart;
}

QWidget *FReserveGroups::lastElement()
{
    return ui->deEnd;
}

QString FReserveGroups::reportTitle()
{
    return QString("%1 %2 - %3")
            .arg(tr("Reservation groups"))
            .arg(ui->deStart->text())
            .arg(ui->deEnd->text());
}

void FReserveGroups::apply(WReportGrid *rg)
{
    QString dr = QString(" and :entrydeparture between %1 and %2 ")
            .arg(ui->deStart->dateMySql())
            .arg(ui->deEnd->dateMySql());
    dr.replace(":entrydeparture", ui->rbEntry->isChecked() ? "g.f_entry" : "g.f_departure");
    QString query = "select g.f_id, g.f_name, g.f_entry, g.f_departure, c.f_name, t.total, r.total, ch.total, ci.total, cc.total "
            "from f_reservation_group g "
            "left join f_cardex c on c.f_cardex=g.f_cardex "
            "left join (select rr.f_group, count(rr.f_id) as total from f_reservation rr where f_state in (1,2,3) group by 1) t on t.f_group=g.f_id "
            "left join (select rr.f_group, count(rr.f_id) as total from f_reservation rr where rr.f_state=2 group by 1) r on r.f_group=g.f_id "
            "left join (select rr.f_group, count(rr.f_id) as total from f_reservation rr where rr.f_state=3 group by 1) ch on ch.f_group=g.f_id "
            "left join (select rr.f_group, count(rr.f_id) as total from f_reservation rr where rr.f_state=1 group by 1) ci on ci.f_group=g.f_id "
            "left join (select rr.f_group, count(rr.f_id) as total from f_reservation rr where rr.f_state=6 group by 1) cc on cc.f_group=g.f_id "
            "where g.f_canceled=:canceled :dr ";
    query.replace(":canceled", ui->chCanceled->isChecked() ? "1" : "0");
    if (ui->rbShowAll->isChecked()) {
        query.replace(":dr", "");
    } else {
        query.replace(":dr", dr);
    }
    rg->fModel->clearColumns();
    rg->fModel->setColumn(100, "f_id", tr("Code"))
            .setColumn(200, "f_name", tr("Group name"))
            .setColumn(120, "f_entry", tr("Entry"))
            .setColumn(120, "f_departure", tr("Departure"))
            .setColumn(200, "f_cardex", tr("Cardex"))
            .setColumn(80, "", tr("Rooms"))
            .setColumn(80, "", tr("Reserved"))
            .setColumn(80, "", tr("Checkout"))
            .setColumn(80, "", tr("Check in"))
            .setColumn(80, "", tr("Canceled"));
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
}

void FReserveGroups::openReport()
{
    WReportGrid *rg = addTab<WReportGrid>();
    FReserveGroups *y = new FReserveGroups(rg);
    rg->addFilterWidget(y);
    y->apply(rg);
}

void FReserveGroups::doubleClick(const QList<QVariant> &row)
{
    if (row.count() == 0) {
        message_error(tr("Nothing is selected"));
        return;
    }
    DlgGroupReservationFuck *d = addTab<DlgGroupReservationFuck>();
    d->loadGroup(row.at(0).toInt());
}

void FReserveGroups::removeGroup()
{
    QList<QVariant> val;
    int row;
    if ((row = fReportGrid->fillRowValuesOut(val)) < 0) {
        message_error(tr("Nothing was selected"));
        return;
    }
    bool ok = false;
    QString reason = QInputDialog::getText(this, tr("Cancelation reason"), tr("Reason"), QLineEdit::Normal, "", &ok).trimmed();
    if (!ok) {
        return;
    }
    if (reason.isEmpty()) {
        message_error("Please, specify the reason on cancelation");
        return;
    }
    if (message_confirm(tr("Confirm remove group")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_canceled"] = 1;
    fDD[":f_cancelDate"] = QDateTime::currentDateTime();
    fDD[":f_cancelUser"] = WORKING_USERID;
    fDD[":f_cancelReason"] = reason;
    fDD.update("f_reservation_group", where_id(val.at(0).toInt()));
    fDD[":f_group"] = val.at(0).toInt();
    fDD[":f_state"] = RESERVE_RESERVE;
    fDD.exec("select f_id from f_reservation where f_group=:f_group and f_state=:f_state");
    QStringList rid;
    while (fDD.nextRow()) {
        rid.append(fDD.getString(0));
    }
    for (QString id: rid) {
        fDD[":f_state"] = RESERVE_REMOVED;
        fDD[":f_cancelDate"] = QDateTime::currentDateTime();
        fDD[":f_cancelUser"] = WORKING_USERID;
        fDD.update("f_reservation", where_id(ap(id)));
        fDD[":f_id"] = id;
        fDD[":f_reason"] = tr("Group") + ": " + reason;
        fDD.insert("f_reservation_cancel_reason", false);
    }
    fReportGrid->fModel->removeRow(row);
}

void FReserveGroups::newGroup()
{
    addTab<DlgGroupReservationFuck>();
}
