#include "wstoreentry.h"
#include "ui_wstoreentry.h"
#include "pprintstoreentry.h"

#define SEL_DISH 1

WStoreEntry::WStoreEntry(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WStoreEntry)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                0, 0, 300, 80, 80, 80);
    ui->leStore->setSelector(this, cache(cid_dish), ui->leStoreName);
}

WStoreEntry::~WStoreEntry()
{
    delete ui;
}

void WStoreEntry::callback(int sel, const QString &code)
{
    switch (sel) {
        case SEL_DISH: {
            CacheDish c;
            if (c.get(code)) {
                newGoods(code);
                ui->tblData->setVisible(false);
                ui->tblData->setVisible(true);
                ui->tblData->scrollToBottom();
            }
            break;
        }
    }
}

void WStoreEntry::setup()
{
    setupTabTextAndIcon(tr("Store entry"), ":/images/storeentry.png");
}

void WStoreEntry::openDoc(int doc)
{
    WStoreEntry *s = addTab<WStoreEntry>();
    if (doc > 0) {
        s->load(doc);
    }
}

void WStoreEntry::load(int doc)
{
    ui->leDocNum->setInt(doc);
    DoubleDatabase fDD;
    fDD[":f_id"] = doc;
    fDD.exec("select * from st_header where f_id=:f_id");
    if (fDD.rowCount() == 0) {
        message_error(tr("Invalid document number"));
        return;
    }
    ui->leStore->setInitialValue(fDD.getValue("f_store").toInt());
    ui->leAmount->setDouble(fDD.getValue("f_amount").toDouble());
    ui->deDate->setDate(fDD.getValue("f_date").toDate());
    fDD[":f_doc"] = doc;
    fDD.exec("select st.f_id, st.f_goods, g.f_en, st.f_qty, st.f_amount from st_body st "
             "left join r_dish g on g.f_id=st.f_goods where f_doc=:f_doc");
    for (int i = 0; i < fDD.rowCount(); i++) {
        CacheDish d;
        if (!d.get(fDD.getValue(i, "f_goods").toString())) {
            message_error(tr("Program error. Please, contact with developer. Message: CI_Dish==0, loadDoc"));
            return;
        }
        newGoods(d.fCode());
        ui->tblData->setItemWithValue(i, 0, fDD.getValue(i, "f_id"));
        ui->tblData->lineEdit(i, 3)->setDouble(fDD.getValue(i, "f_qty").toDouble());
        if (fDD.getValue(i, "f_qty").toDouble() > 0.1) {
            ui->tblData->lineEdit(i, 4)->setDouble(fDD.getValue(i, "f_amount").toDouble() / fDD.getValue(i, "f_qty").toDouble());
        } else {
            ui->tblData->lineEdit(i, 4)->setDouble(0);
        }
        ui->tblData->lineEdit(i, 5)->setDouble(fDD.getValue(i, "f_amount").toDouble());
    }
}

void WStoreEntry::newGoods(const QString &code)
{
    CacheDish d;
    if (!d.get(code)) {
        return;
    }
    int row = ui->tblData->rowCount();
    ui->tblData->setRowCount(row + 1);
    ui->tblData->setItemWithValue(row, 0, "");
    ui->tblData->setItemWithValue(row, 1, d.fCode());
    ui->tblData->setItemWithValue(row, 2, d.fName());
    EQLineEdit *l = ui->tblData->addLineEdit(row, 3, false);
    l->setValidator(new QDoubleValidator(0, 10000, 4));
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(qtyChange(QString)));
    l = ui->tblData->addLineEdit(row, 4, false);
    l->setValidator(new QDoubleValidator(0, 1000000000, 2));
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(priceChange(QString)));
    l = ui->tblData->addLineEdit(row, 5, false);
    l->setValidator(new QDoubleValidator(0, 1000000000, 2));
    connect(l, SIGNAL(textChanged(QString)), this, SLOT(totalChange(QString)));
    ui->tblData->lineEdit(row, 3)->setFocus();
}

void WStoreEntry::countTotal()
{
    float total = 0;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        total += ui->tblData->lineEdit(i, 5)->asDouble();
    }
    ui->leAmount->setDouble(total);
}

void WStoreEntry::qtyChange(const QString &arg1)
{
    Q_UNUSED(arg1)
    EQLineEdit *l = static_cast<EQLineEdit *>(sender());
    int row, col;
    if (!ui->tblData->findWidgetCell(l, row, col)) {
        return;
    }
    ui->tblData->lineEdit(row, 5)->setDouble(l->asDouble() *ui->tblData->lineEdit(row, 4)->asDouble());
    countTotal();
}

void WStoreEntry::priceChange(const QString &arg1)
{
    Q_UNUSED(arg1)
    EQLineEdit *l = static_cast<EQLineEdit *>(sender());
    int row, col;
    if (!ui->tblData->findWidgetCell(l, row, col)) {
        return;
    }
    ui->tblData->lineEdit(row, 5)->setDouble(l->asDouble() *ui->tblData->lineEdit(row, 3)->asDouble());
    countTotal();
}

void WStoreEntry::totalChange(const QString &arg1)
{
    Q_UNUSED(arg1)
    EQLineEdit *l = static_cast<EQLineEdit *>(sender());
    int row, col;
    if (!ui->tblData->findWidgetCell(l, row, col)) {
        return;
    }
    if (ui->tblData->lineEdit(row, 3)->asDouble() < 0.001) {
        return;
    }
    ui->tblData->lineEdit(row, 4)->setDouble(l->asDouble() / ui->tblData->lineEdit(row, 3)->asDouble());
    countTotal();
}

void WStoreEntry::on_toolButton_clicked()
{
    CacheInstance *ci = cache(cid_dish);
    QString code = ci->get("");
    newGoods(code);
}

void WStoreEntry::on_toolButton_2_clicked()
{
    QModelIndexList ml = ui->tblData->selectionModel()->selectedRows();
    QSet<int> rows;
    foreach (QModelIndex m, ml) {
        rows << m.row();
    }
    for (int i = rows.count() - 1; i > -1; i--) {
        ui->tblData->removeRow(rows.values().at(i));
    };
    countTotal();
}

void WStoreEntry::on_btnSave_clicked()
{
    if (ui->leStore->asInt() == 0) {
        message_error(tr("Store must be selected"));
        return;
    }
    DoubleDatabase fDD;
    if (ui->leDocNum->asInt() == 0) {
        fDD[":f_id"] = 0;
        ui->leDocNum->setInt(fDD.insert("st_header"));
    }
    fDD[":f_date"] = ui->deDate->date();
    fDD[":f_store"] = ui->leStore->asInt();
    fDD[":f_amount"] = ui->leAmount->asDouble();
    fDD.update("st_header", where_id(ui->leDocNum->asInt()));
    fDD[":f_doc"] = ui->leDocNum->asInt();
    fDD.exec("delete from st_body where f_doc=:f_doc");
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        fDD[":f_doc"] = ui->leDocNum->asInt();
        fDD[":f_goods"] = ui->tblData->toInt(i, 1);
        fDD[":f_qty"] = ui->tblData->lineEdit(i, 3)->asDouble();
        fDD[":f_amount"] = ui->tblData->lineEdit(i, 5)->asDouble();
        ui->tblData->setItemWithValue(i, 0, fDD.insert("st_body"));
    }
    message_info(tr("Saved"));
}

void WStoreEntry::on_btnRemove_clicked()
{
    if (message_confirm(tr("Confirm to delete document")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_id"] = ui->leDocNum->asInt();
    fDD.exec("delete from st_header where f_id=:f_id");
    fDD[":f_doc"] = ui->leDocNum->asInt();
    fDD.exec("delete from st_body where f_doc=:f_doc");
    fMainWindow->fTab->removeTab(fMainWindow->fTab->indexOf(this));
    close();
}

void WStoreEntry::on_btnCalculate_clicked()
{
    if (ui->leDocNum->asInt() == 0) {
        message_error(tr("Document must be saved first"));
        return;
    }
    if (ui->leStore->asInt() == 0) {
        message_error(tr("Store must be defined"));
        return;
    }
    QString query = "select f_id, f_en from r_dish ";
    DoubleDatabase fDD;
    fDD.exec(query);
    //get middle prices for input docs
    query = "select r.f_material, sum(r.f_qty*r.f_sign) as f_qty, sum(r.f_total*r.f_sign) as f_total from r_body r "
            "left join r_docs d on d.f_id=r.f_doc "
            "where d.f_state=1 and d.f_date between :date1 and :date2 and d.f_type in (1) and r.f_store=:f_store "
            "group by 1";
    DoubleDatabase drt;
    drt.open();
    drt[":date2"]  = ui->deDate->date();
    drt[":date1"] = ui->deLastDate->date();
    drt[":f_store"] = ui->leStore->asInt();
    drt.exec(query);
    //get middle prices from st_header
    query = "select r.f_goods, sum(r.f_qty) as f_qty, sum(r.f_amount) as f_total from st_body r "
            "left join st_header d on d.f_id=r.f_doc "
            "where d.f_date = :date1 and d.f_store=:f_store  "
            "group by 1";
    DoubleDatabase drt2;
    drt2[":date1"]  = ui->deLastDate->date().addDays(-1);
    drt2[":f_store"] = ui->leStore->asInt();
    drt2.exec(query);
    struct A {
        double qty;
        double total;
        A()
        {
            qty = 0.0;
            total = 0.0;
        }
    };
    QMap<int, A> goodsList;
    for (int i = 0; i < drt.rowCount(); i++) {
        if (!goodsList.contains(drt.getValue(i, "f_material").toInt())) {
            A a;
            goodsList[drt.getValue(i, "f_material").toInt()] = a;
        }
        goodsList[drt.getValue(i, "f_material").toInt()].qty = goodsList[drt.getValue(i,
            "f_material").toInt()].qty + drt.getValue(i, "f_qty").toDouble();
        goodsList[drt.getValue(i, "f_material").toInt()].total = goodsList[drt.getValue(i,
            "f_material").toInt()].total + drt.getValue(i, "f_total").toDouble();
    }
    for (int i = 0; i < drt2.rowCount(); i++) {
        if (!goodsList.contains(drt2.getValue(i, "f_material").toInt())) {
            A a;
            goodsList[drt2.getValue(i, "f_material").toInt()] = a;
        }
        goodsList[drt2.getValue(i, "f_material").toInt()].qty = goodsList[drt2.getValue(i,
            "f_material").toInt()].qty + drt2.getValue(i, "f_qty").toDouble();
        goodsList[drt2.getValue(i, "f_material").toInt()].total = goodsList[drt2.getValue(i,
            "f_material").toInt()].total + drt2.getValue(i, "f_total").toDouble();
    }
    //check for forgoted goods and insert that with 0 qty
    for (QMap<int, A>::const_iterator it = goodsList.begin(); it != goodsList.end(); it++) {
        bool found = false;
        for (int i = 0; i < ui->tblData->rowCount(); i++) {
            if (it.key() == ui->tblData->toInt(i, 1)) {
                found = true;
                break;
            }
        }
        if (!found) {
            newGoods(QString::number(it.key()));
        }
    }
    QMap<int, double> qty;
    QMap<int, double> price;
    //correct qty
    query = "select r.f_material, sum(r.f_qty*r.f_sign) as f_qty, sum(r.f_total*r.f_sign) as f_total from r_body r "
            "left join r_docs d on d.f_id=r.f_doc "
            "where d.f_state=1 and d.f_date between :date1 and :date2 and d.f_type in (3) "
            "group by 1";
    DoubleDatabase drtm;
    drtm[":date2"]  = ui->deDate->date();
    drtm[":date1"] = ui->deLastDate->date();
    drtm.exec(query);
    for (int j = 0; j < ui->tblData->rowCount(); j++) {
        bool f = false;
        for (QMap<int, A>::const_iterator it = goodsList.begin(); it != goodsList.end(); it++) {
            if (it.key() == ui->tblData->toInt(j, 1)) {
                f = true;
                if (it.value().qty > 0.001) {
                    price[it.key()] =  it.value().total / it.value().qty;
                } else {
                    price[it.key()] =  0;
                }
                qty[it.key()] = it.value().qty - ui->tblData->lineEdit(j, 3)->asDouble();
                for (int k = 0; k < drtm.rowCount(); k++) {
                    if (it.key() == drtm.getValue(k, "f_material").toInt()) {
                        qty[it.key()] = qty[it.key()] + drtm.getValue(k, "f_qty").toDouble();
                        break;
                    }
                }
                break;
            }
        }
        if (!f) {
            qty[ui->tblData->toInt(j, 1)] = ui->tblData->lineEdit(j, 3)->asDouble() * -1;
            price[ui->tblData->toInt(j, 1)] = 0;
        }
    }
    if (qty.count() == 0) {
        message_info(tr("Empry report"));
        return;
    }
    QString docId = uuidx("ST");
    fDD[":f_id"] = docId;
    fDD.insert("r_docs");
    fDD[":f_date"] = ui->deDate->date();
    fDD[":f_type"] = 3;
    fDD[":f_state"] = 1;
    fDD[":f_partner"] = 0;
    fDD[":f_inv"] = "";
    //fDD[":f_invDate"] = ui->leInvoiceNo->isEmpty() ? QVariant() : QVariant(ui->deInvoiceDate->date());
    fDD[":f_amount"] = 0;
    fDD[":f_remarks"] = "AUTO OUT";
    fDD[":f_op"] = WORKING_USERID;
    fDD[":f_fullDate"] = QDateTime::currentDateTime();
    fDD[":f_payment"] = 1;
    fDD.update("r_docs", where_id(ap(docId)));
    double total = 0;
    for (QMap<int, double>::const_iterator it = qty.begin(); it != qty.end(); it++) {
        if (it.value() == 0) {
            continue;
        }
        fDD[":f_id"] = 0;
        int newid = fDD.insert("r_body");
        fDD[":f_doc"] = docId;
        fDD[":f_store"] = ui->leStore->asInt();
        fDD[":f_material"] = it.key();
        fDD[":f_sign"] = -1;
        fDD[":f_qty"] = it.value();
        fDD[":f_price"] = price[it.key()];
        fDD[":f_total"] =  price[it.key()] * it.value();
        total += price[it.key()] * it.value();
        fDD.update("r_body", where_id(newid));
    }
    fDD[":f_amount"] = total;
    fDD.update("r_docs", where_id(ap(docId)));
    total = 0;
    for (int i = 0; i < ui->tblData->rowCount(); i++) {
        double amount = ui->tblData->lineEdit(i, 3)->asDouble() * price[ui->tblData->toInt(i, 1)];
        total += amount;
        ui->tblData->lineEdit(i, 5)->setDouble(amount);
        ui->tblData->lineEdit(i, 4)->setDouble(price[ui->tblData->toInt(i, 1)]);
        fDD[":f_amount"] = amount;
        fDD.update("st_body", where_id(ui->tblData->toInt(i, 0)));
    }
    fDD[":f_amount"] = total;
    fDD.update("st_header", where_id(ui->leDocNum->asInt()));
    /* missing prices from &*/
    for (QMap<int, A>::const_iterator it = goodsList.begin(); it != goodsList.end(); it++) {
        if (it.value().qty > 0.001) {
            price[it.key()] =  it.value().total / it.value().qty;
        } else {
            price[it.key()] =  0;
        }
    }
    /* ------------------- */
    fDD[":date2"]  = ui->deDate->date();
    fDD[":date1"] = ui->deLastDate->date();
    fDD[":f_store"] = ui->leStore->asInt();
    fDD.exec("select b.f_id, b.f_material from r_body b left join r_docs d on d.f_id=b.f_doc "
             "where d.f_type in (2, 3) and d.f_state=1 and d.f_date between :date1 and :date2 and f_store=:f_store ");
    for (int i = 0; i < fDD.rowCount(); i++) {
        fDD[":f_id"] = fDD.getValue(i, "f_id");
        fDD[":f_price"] = price[fDD.getValue(i, "f_material").toInt()];
        fDD.exec("update r_body set f_price=:f_price where f_id=:f_id");
        fDD[":f_id"] = fDD.getValue(i, "f_id");
        fDD.exec("update r_body set f_total=f_price*f_qty where f_id=:f_id");
    }
    fDD[":date2"]  = ui->deDate->date();
    fDD[":date1"] = ui->deLastDate->date();
    fDD.exec("select b.f_doc, sum(b.f_total) as f_total from r_body b left join r_docs d on d.f_id=b.f_doc "
             "where ((d.f_type in (2) and d.f_state=1 and b.f_sign=1) or (d.f_type in (3) and d.f_state=1 and b.f_sign=-1)) and d.f_date between :date1 and :date2 group by 1");
    for (int i = 0; i < fDD.rowCount(); i++) {
        fDD[":f_amount"] = fDD.getValue(i, "f_total");
        fDD.update("r_docs", where_id(ap(fDD.getValue(i, "f_doc").toString())));
    }
    message_info(tr("Saved"));
}

void WStoreEntry::on_btnPrint_clicked()
{
    PPrintStoreEntry::print(ui->leDocNum->text());
}
