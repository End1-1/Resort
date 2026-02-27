#include "dlgcalculateoutputofrestaurant.h"
#include "ui_dlgcalculateoutputofrestaurant.h"
#include "message.h"
#include "defstore.h"

DlgCalculateOutputOfRestaurant::DlgCalculateOutputOfRestaurant(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgCalculateOutputOfRestaurant)
{
    ui->setupUi(this);
}

DlgCalculateOutputOfRestaurant::~DlgCalculateOutputOfRestaurant()
{
    delete ui;
}

void DlgCalculateOutputOfRestaurant::openDialog()
{
    DlgCalculateOutputOfRestaurant *d = new DlgCalculateOutputOfRestaurant(fPreferences.getDefaultParentForMessage());
    d->exec();
    delete d;
}

void DlgCalculateOutputOfRestaurant::on_btnCancel_clicked()
{
    reject();
}

void DlgCalculateOutputOfRestaurant::on_btnGo_clicked()
{
    DoubleDatabase fDD;
    fDD[":d1"] = ui->deStart->date();
    fDD[":d2"] = ui->deEnd->date();
    fDD[":f_type"] = STORE_DOC_IN;
    fDD[":f_state"] = 1;
    fDD.exec("select b.f_material, sum(b.f_total)/sum(b.f_qty) as f_price "
              "from r_body b "
              "left join r_docs d on d.f_id=b.f_doc "
              "where d.f_date between :d1 and :d2 and d.f_type=:f_type and d.f_state=:f_state");
    for (int i = 0; i < fDD.rowCount(); i++) {
        fMiddlePrices[fDD.getValue(i, "f_material").toInt()] = fDD.getValue(i, "f_price").toDouble();
    }
    ui->pb->setValue(0);
    ui->pb->setMaximum(ui->deStart->date().daysTo(ui->deEnd->date()));
    for (QDate d = ui->deStart->date(); d < ui->deEnd->date().addDays(1); d = d.addDays(1)) {
        calculateForDate(d);
    }
    accept();
    message_info(tr("Done!"));
}

void DlgCalculateOutputOfRestaurant::calculateForDate(const QDate &date)
{
    DoubleDatabase fDD;
    /* remove old calculation */
    fDD[":f_dateCash"] = date;
    fDD.exec("delete from o_recipe where f_header in (select f_id from o_header where f_dateCash=:f_dateCash)");
    /* insert new calculation */
    fDD[":f_state1"] = DISH_STATE_READY;
    fDD[":f_state2"] = DISH_STATE_REMOVED_STORE;
    fDD[":f_hstate"] = ORDER_STATE_CLOSED;
    fDD[":f_dateCash"] = date;
    
    fDD.exec("select h.f_id as hid, o.f_id, o.f_dish, o.f_store, r.f_part, r.f_qty*o.f_qty as f_qty "
                       "from o_dish o "
                       "left join r_recipe r on o.f_dish=r.f_dish "
                       "left join o_header h on h.f_id=o.f_header "
                       "where h.f_dateCash=:f_dateCash and h.f_state=:f_hstate and (o.f_state=:f_state1 or o.f_state=:f_state2)");
    for (int i = 0; i < fDD.rowCount(); i++) {
        fDD[":f_header"] = fDD.getValue(i, "hid");
        fDD[":f_body"] = fDD.getValue(i, "f_id");
        fDD[":f_dish"] = fDD.getValue(i, "f_dish");
        fDD[":f_material"] = fDD.getValue(i, "f_part");
        fDD[":f_qty"] = fDD.getValue(i, "f_qty");
        fDD[":f_store"] = fDD.getValue(i, "f_store");
        fDD.insert("o_recipe");
    }
    /* and make output doc for store */
    fDD[":f_dateCash"] = date;
    fDD.exec("select distinct(r.f_store) as f_store "
              "from o_recipe r "
              "left join o_header oh on oh.f_id=r.f_header "
              "where oh.f_dateCash=:f_dateCash ");
    ui->pb->setMaximum(ui->pb->maximum() + fDD.rowCount());
    for (int i = 0; i < fDD.rowCount(); i++) {
        calculateForStore(fDD.getValue(i, "f_store").toInt(), date);
    }
}

void DlgCalculateOutputOfRestaurant::calculateForStore(int store, const QDate &date)
{
    DoubleDatabase fDD;
    ui->pb->setValue(ui->pb->value() + 1);
    fDD[":f_store"] = store;
    fDD[":f_date"] = date;
    
    fDD.exec("select f_id from r_docs where f_rest=1 and f_date=:f_date and f_id in (select f_doc from r_body where f_store=:f_store and f_date=:f_date)");
    for (int i = 0; i < fDD.rowCount(); i++) {
        fDD[":f_id"] = fDD.getValue(i, "f_id");
        fDD.exec("delete from r_docs where f_id=:f_id");
        fDD[":f_doc"] = fDD.getValue(i, "f_id");
        fDD.exec("delete from r_body where f_doc=:f_doc");
    }
    fDD[":f_dateCash"] = date;
    fDD[":f_store"] = store;
    fDD.exec("select r.f_material, sum(r.f_qty) as f_qty "
                   "from o_recipe r "
              "left join o_header oh on oh.f_id=r.f_header "
              "where oh.f_dateCash=:f_dateCash and r.f_store=:f_store "
              "group by 1 ");

    if (fDD.rowCount() == 1 && fDD.getValue("f_qty").toDouble() < 0.01) {
        return;
    }

    QString docId = uuidx("ST");
    fDD[":f_id"] = docId;
    fDD.insert("r_docs");
    fDD[":f_date"] = date;
    fDD[":f_type"] = STORE_DOC_OUT;
    fDD[":f_state"] = 1;
    fDD[":f_partner"] = 0;
    fDD[":f_inv"] = "";
    fDD[":f_invDate"] = QVariant();
    fDD[":f_amount"] = 0;
    fDD[":f_remarks"] = tr("Output of sale");
    fDD[":f_op"] = WORKING_USERID;
    fDD[":f_fullDate"] = QDateTime::currentDateTime();
    fDD[":f_rest"] = 1;
    fDD.update("r_docs", where_id(ap(docId)));

    for (int i = 0; i < fDD.rowCount(); i++) {
        if (fDD.getValue(i, "f_qty").toDouble() < 0.01) {
            continue;
        }
        fDD[":f_id"] = 0;
        int newid = fDD.insert("r_body");
        fDD[":f_doc"] = docId;
        fDD[":f_store"] = store;
        fDD[":f_material"] = fDD.getValue(i, "f_material");
        fDD[":f_sign"] = -1;
        fDD[":f_qty"] = fDD.getValue(i, "f_qty");
        if (fMiddlePrices.contains(fDD.getValue(i, "f_material").toInt())) {
            fDD[":f_price"] = fMiddlePrices[fDD.getValue(i, "f_material").toInt()];
            fDD[":f_total"] = fMiddlePrices[fDD.getValue(i, "f_material").toInt()] * fDD.getValue(i, "f_qty").toDouble() * -1;
        } else {
            fDD[":f_price"] = fLastPrices[fDD.getValue(i, "f_material").toInt()];
            fDD[":f_total"] = fLastPrices[fDD.getValue(i, "f_material").toInt()] * fDD.getValue(i, "f_qty").toDouble() * -1;
        }
        fDD.update("r_body", where_id(newid));
    }
}
