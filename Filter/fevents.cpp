#include "fevents.h"
#include "ui_fevents.h"
#include "wreportgrid.h"
#include "vauchers.h"
#include <QInputDialog>

FEvents::FEvents(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FEvents)
{
    ui->setupUi(this);
    fQuery = "select e.f_id, f_wdate, f_time, h.f_name, i.f_" + def_lang + ","
            "e.f_comment, "
            "e.f_pax, e.f_price, e.f_total, e.f_tax, ii.f_" + def_lang + ", "
            "e.f_paymentDetails "
            "from o_event e "
            "left join r_hall h on h.f_id=e.f_hall "
            "left join f_invoice_item i on i.f_id=e.f_itemCode "
            "left join f_payment_type ii on ii.f_id=e.f_paymentMode "
            "left join f_credit_card cr on cr.f_id=e.f_creditCard "
            "left join f_city_ledger cl on cl.f_id=e.f_cityLedger "
            "where e.f_wdate between :f_wdate1 and :f_wdate2 and f_canceled=0 and f_state=1 ";
    fReportGrid->addToolBarButton(":/images/garbage.png", tr("Remove"), SLOT(removeEvent()), this)->setFocusPolicy(Qt::NoFocus);
    QToolButton *b = fReportGrid->addToolBarButton(":/images/biohazard.png", tr("Eliminate"), SLOT(eliminate()), this);
    b->setFocusPolicy(Qt::NoFocus);
    b->setVisible(r__(cr__super_correction));
    fReportGrid->setupTabTextAndIcon(tr("Events"), ":/images/banket.png");
}

FEvents::~FEvents()
{
    delete ui;
}

QWidget *FEvents::firstElement()
{
    return ui->deStart;
}

QString FEvents::reportTitle()
{
    return "Events";
}

QWidget *FEvents::lastElement()
{
    return ui->deEnd;
}

void FEvents::apply(WReportGrid *rg)
{
    rg->fModel->clearColumns();
    rg->fModel->setColumn(0, "", tr("Code"))
            .setColumn(100, "", tr("Date"))
            .setColumn(80, "", tr("Time"))
            .setColumn(100, "", tr("Hall"))
            .setColumn(300, "", tr("Name"))
            .setColumn(200, "", tr("Comment"))
            .setColumn(50, "", tr("Pax"))
            .setColumn(80, "", tr("Price"))
            .setColumn(80, "", tr("Total"))
            .setColumn(30, "", tr("Tax"))
            .setColumn(100, "", tr("Mode of payment"))
            .setColumn(200, "", tr("Payment details"))
            ;
    QString query = fQuery;
    query.replace(":f_wdate1", ui->deStart->dateMySql()).replace(":f_wdate2", ui->deEnd->dateMySql());
    rg->fModel->setSqlQuery(query);
    rg->fModel->apply(rg);
    QList<int> cols;
    QList<double> vals;
    cols << 6 << 8;
    rg->fModel->sumOfColumns(cols, vals);
    rg->setTblTotalData(cols, vals);
}

void FEvents::open()
{
    WReportGrid *rg = addTab<WReportGrid>();
    FEvents *e = new FEvents(rg);
    rg->addFilterWidget(e);
    e->apply(rg);
}

void FEvents::removeEvent()
{
    QList<QVariant> out;
    if (fReportGrid->fillRowValuesOut(out) < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    if (message_confirm(tr("Confirm removal")) != QDialog::Accepted) {
        return;
    }
    QString reason = QInputDialog::getText(this, tr("Reason"), tr("Input reason"));
    DoubleDatabase fDD;
    fDD.startTransaction();
    fDD[":f_canceled"] = 1;
    fDD[":f_cancelUser"] = WORKING_USERID;
    fDD[":f_cancelDate"] = QDateTime::currentDateTime();
    fDD[":f_cancelReason"] = reason;
    fDD.update("o_event", where_id(out.at(0).toInt()));

    fDD[":f_source"] = VAUCHER_EVENT_N;
    fDD[":f_doc"] = out.at(0).toInt();
    fDD.exec("select f_id from m_register where f_source=:f_source and f_doc=:f_doc");
    if (!fDD.nextRow()) {
        message_error("Application error. Contact to developer. Message: row count == 0, remove event");
        return;
    }

    int recid = fDD.getInt(0);

    fDD[":f_canceled"] = 1;
    fDD[":f_cancelUser"] = WORKING_USERID;
    fDD[":f_cancelDate"] = QDateTime::currentDateTime();
    fDD[":f_cancelReason"] = reason;
    fDD.update("m_register", where_id(recid));
    fDD.commit();

}

void FEvents::eliminate()
{
    QList<QVariant> out;
    int row = fReportGrid->fillRowValuesOut(out);
    if (row < 0) {
        message_info(tr("Nothing was selected"));
        return;
    }
    if (message_confirm(tr("THIS WILL REMOVE PERMANENTLY EVENT DATE!")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_id"] =out.at(0);
    fDD.exec("delete from o_event where f_id=:f_id");
    fDD[":f_id"] =out.at(0);
    fDD.exec("delete from m_register where f_id=:f_id");
    fReportGrid->fModel->removeRow(row);
}
