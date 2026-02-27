#include "storedoc.h"
#include "ui_storedoc.h"
#include "defstore.h"
#include "rerestdish.h"
#include "cachecashdoc.h"
#include "pprintstoredoc.h"
#include "cachereststore.h"
#include "cachestoredoc.h"
#include "cachedish.h"
#include "cachestoredocstate.h"
#include "cachestorepartners.h"
#include <QInputDialog>

#define HINT_DOC_TYPE 10
#define HINT_PARTNER 2
#define HINT_DISH 3

StoreDoc::StoreDoc(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::StoreDoc)
{
    ui->setupUi(this);
    fFirstTab = ui->tabWidget->widget(0);
    fGoodsTab = ui->tabWidget->widget(1);
    fAccTab = ui->tabWidget->widget(2);
    ui->leStore->setSelector(this, cache(cid_rest_store), ui->leStore);
    ui->leStoreout->setSelector(this, cache(cid_rest_store), ui->leStoreout);
    ui->leAction->setSelector(this, cache(cid_store_doc_type), ui->leAction, HINT_DOC_TYPE);
    ui->lePartnerCode->setSelector(this, cache(cid_store_partners), ui->lePartnerName, HINT_PARTNER);
    Utils::tableSetColumnWidths(ui->tblGoods, ui->tblGoods->columnCount(),
                                0, 100, 300, 80, 80, 80);
    ui->wAcc->docType(CASHDOC_STORE);
    ui->wAcc->setSaveVisible(false);
    ui->wAcc->cashOp(CASHOP_OUT);
}

StoreDoc::~StoreDoc()
{
    delete ui;
}

void StoreDoc::callback(int sel, const QString &code)
{
    switch (sel) {
        case HINT_PARTNER: {
            CacheStorePartners c;
            if (c.get(code)) {
                ui->wAcc->partner(c.fCode().toInt());
            } else {
                ui->wAcc->partner(0);
            }
            break;
        }
        case HINT_DOC_TYPE: {
            prepareDoc();
            break;
        }
    }
}

void StoreDoc::setup()
{
    setupTabTextAndIcon(tr("New store document"), ":/images/storage.png");
}

void StoreDoc::openStoreDocument(const QString &id)
{
    StoreDoc *s = addTab<StoreDoc>();
    if (!id.isEmpty()) {
        s->loadDoc(id);
    }
}

void StoreDoc::loadDoc(const QString &id)
{
    DoubleDatabase fDD;
    ui->leDocNumber->setText(id);
    fDD[":f_id"] = id;
    fDD.exec("select * from r_docs where f_id=:f_id");
    if (!fDD.nextRow()) {
        message_error(tr("Invalid document number"));
        return;
    }
    int state = fDD.getValue("f_state").toInt();
    ui->leAction->setInitialValue(fDD.getValue("f_type").toString());
    ui->lePartnerCode->setInitialValue(fDD.getValue("f_partner").toString());
    prepareDoc();
    ui->deDate->setDate(fDD.getValue("f_date").toDate());
    ui->leInvoiceNo->setText(fDD.getValue("f_inv").toString());
    ui->deInvoiceDate->setDate(fDD.getValue("f_invDate").toDate());
    ui->leComments->setText(fDD.getValue("f_remarks").toString());
    fDD[":f_doc"] = ui->leDocNumber->text();
    fDD.exec("select distinct(f_store) as f_store, f_sign from r_body where f_doc=:f_doc");
    if (fDD.nextRow()) {
        if (fDD.rowCount() == 1) {
            /*output and input */
            ui->leStore->setInitialValue(fDD.getString(1));
        } else {
            /* Movement */
            if (fDD.getValue(0, "f_sign").toInt() > 0) {
                ui->leStore->setInitialValue(fDD.getString(0));
            } else {
                ui->leStoreout->setInitialValue(fDD.getString(0));
            }
            fDD.nextRow();
            if (fDD.getValue(1, "f_sign").toInt() > 0) {
                ui->leStore->setInitialValue(fDD.getString(0));
            } else {
                ui->leStoreout->setInitialValue(fDD.getString(0));
            }
        }
    }
    fDD[":f_doc"] = ui->leDocNumber->text();
    QString add;
    if (ui->leAction->fHiddenText.toInt() == STORE_DOC_MOVE) {
        add = "and b.f_sign=1";
    }
    fDD.exec("select b.f_id, b.f_material, m.f_en, b.f_qty, b.f_price, b.f_total "
             "from r_body b "
             "left join r_dish m on m.f_id=b.f_material "
             "where b.f_doc=:f_doc " + add);
    for (int i = 0; i < fDD.rowCount(); i++) {
        CacheDish d;
        if (!d.get(fDD.getValue(i, "f_material").toString())) {
            message_error(tr("Program error. Please, contact with developer. Message: CI_Dish==0, loadDoc"));
            return;
        }
        newGoods(d.fCode());
        ui->tblGoods->setItemWithValue(i, 0, fDD.getValue(i, "f_id"));
        ui->tblGoods->lineEdit(i, 3)->setDouble(fDD.getValue(i, "f_qty").toDouble());
        ui->tblGoods->lineEdit(i, 4)->setDouble(fDD.getValue(i, "f_price").toDouble());
        ui->tblGoods->lineEdit(i, 5)->setDouble(fDD.getValue(i, "f_total").toDouble());
    }
    countTotal();
    bool v = state == 0;
    ui->wCommon->setEnabled(v);
    for (int j = 0; j < ui->tblGoods->rowCount(); j++) {
        ui->tblGoods->lineEdit(j, 3)->setReadOnly(!v);
        ui->tblGoods->lineEdit(j, 4)->setReadOnly(!v);
        ui->tblGoods->lineEdit(j, 5)->setReadOnly(!v);
    }
    ui->wGoodsOps->setEnabled(v);
}

void StoreDoc::copyDoc(const QString &id)
{
    loadDoc(id);
    ui->leDocNumber->clear();
    for (int i = 0; i < ui->tblGoods->rowCount(); i++) {
        ui->tblGoods->setItemWithValue(i, 0, 0);
    }
    ui->wCommon->setEnabled(true);
    for (int i = 0; i < ui->tabWidget->count(); i++) {
        ui->tabWidget->widget(i)->setEnabled(true);
    }
}

void StoreDoc::prepareDoc()
{
    switch (ui->leAction->fHiddenText.toInt()) {
        case STORE_DOC_IN:
            if (ui->tabWidget->count() == 1) {
                ui->tabWidget->insertTab(0, fFirstTab, QIcon(), tr("Common"));
                ui->tabWidget->insertTab(2, fAccTab, QIcon(), tr("Accounts"));
            }
            ui->leStoreout->setVisible(false);
            ui->lbStoreout->setVisible(false);
            break;
        case STORE_DOC_MOVE:
            if (ui->tabWidget->count() > 1) {
                ui->tabWidget->removeTab(0);
                ui->tabWidget->removeTab(1);
            }
            ui->tabCommon->setVisible(false);
            ui->leStoreout->setVisible(true);
            ui->lbStoreout->setVisible(true);
            ui->wAcc->disable();
            break;
        case STORE_DOC_OUT:
            if (ui->tabWidget->count() > 1) {
                ui->tabWidget->removeTab(0);
                ui->tabWidget->removeTab(1);
            }
            ui->tabCommon->setVisible(false);
            ui->leStoreout->setVisible(false);
            ui->lbStoreout->setVisible(false);
            ui->wAcc->disable();
            break;
        default:
            break;
    }
}

void StoreDoc::countTotal()
{
    float total = 0;
    for (int i = 0; i < ui->tblGoods->rowCount(); i++) {
        total += ui->tblGoods->lineEdit(i, 5)->asDouble();
    }
    ui->leTotal->setDouble(total);
}

void StoreDoc::saveDoc(int docState)
{
    QString errors;
    if (ui->leAction->fHiddenText.toInt() == 1) {
        QString err;
        if (!ui->wAcc->isCorrent(err)) {
            errors += err;
        }
    }
    if (ui->leAction->fHiddenText.toInt() == 0) {
        errors += tr("Action must be selected.") + "<br>";
    }
    switch (ui->leAction->fHiddenText.toInt()) {
        case STORE_DOC_IN:
            if (ui->leStore->fHiddenText.toInt() == 0) {
                errors += tr("Input store must be selected.") + "<br>";
            }
            break;
        case STORE_DOC_OUT:
            if (ui->leStore->fHiddenText.toInt() == 0) {
                errors += tr("Output store must be selected.") + "<br>";
            }
            break;
        case STORE_DOC_MOVE:
            if (ui->leStore->fHiddenText.toInt() == 0) {
                errors += tr("Input store must be selected.") + "<br>";
            }
            if (ui->leStoreout->fHiddenText.toInt() == 0) {
                errors += tr("Output store must be selected.") + "<br>";
            }
            if (ui->leStore->fHiddenText.toInt() > 0) {
                if (ui->leStore->fHiddenText.toInt() == ui->leStoreout->fHiddenText.toInt()) {
                    errors += tr("Input and output storages cannot be same.");
                }
            }
            break;
    }
    if (docState == 1) {
        for (int i = 0; i < ui->tblGoods->rowCount(); i++) {
            if (ui->tblGoods->lineEdit(i, 3)->asDouble() < 0.001) {
                errors += tr("Check the quantity of goods.") + "<br>";
                break;
            }
        }
    }
    if (ui->tblGoods->rowCount() == 0) {
        errors += tr("Goods list cannot be empty.") + "<br>";
    }
    if (!errors.isEmpty()) {
        message_error(errors);
        return;
    }
    bool isNew = false;
    if (ui->leDocNumber->isEmpty()) {
        ui->leDocNumber->setText(uuidx("ST"));
        isNew = true;
    }
    DoubleDatabase fDD;
    fDD.startTransaction();
    if (isNew) {
        fDD[":f_id"] = ui->leDocNumber->text();
        if (!fDD.insert("r_docs", false)) {
            fDD.rollback();
            message_error(fDD.fLastError);
            return;
        }
    }
    fDD[":f_date"] = ui->deDate->date();
    fDD[":f_type"] = ui->leAction->fHiddenText.toInt();
    fDD[":f_state"] = docState;
    fDD[":f_partner"] = ui->lePartnerCode->asInt();
    fDD[":f_inv"] = ui->leInvoiceNo->text();
    fDD[":f_invDate"] = ui->leInvoiceNo->isEmpty() ? QVariant() : QVariant(ui->deInvoiceDate->date());
    fDD[":f_amount"] = ui->leTotal->asDouble();
    fDD[":f_remarks"] = ui->leComments->text();
    fDD[":f_op"] = WORKING_USERID;
    fDD[":f_fullDate"] = QDateTime::currentDateTime();
    fDD[":f_payment"] = ui->cbPayment->currentData();
    if (!fDD.update("r_docs", where_id(ap(ui->leDocNumber->text())))) {
        fDD.rollback();
        message_error(fDD.fLastError);
        return;
    }
    DoubleDatabase d2;
    d2.open();
    for (int i = 0; i < ui->tblGoods->rowCount(); i++) {
        if (ui->tblGoods->toInt(i, 0) == 0) {
            fDD[":f_id"] = 0;
            int newid = fDD.insert("r_body");
            if (newid < 0) {
                fDD.rollback();
                message_error(fDD.fLastError);
                return;
            }
            ui->tblGoods->setItemWithValue(i, 0, newid);
        }
        fDD[":f_doc"] = ui->leDocNumber->text();
        fDD[":f_store"] = ui->leStore->fHiddenText.toInt();
        fDD[":f_material"] = ui->tblGoods->toInt(i, 1);
        fDD[":f_sign"] = ui->leAction->fHiddenText.toInt() == STORE_DOC_OUT ? -1 : 1;
        fDD[":f_qty"] = ui->tblGoods->lineEdit(i, 3)->asDouble();
        fDD[":f_price"] = ui->tblGoods->lineEdit(i, 4)->asDouble();
        fDD[":f_total"] = ui->tblGoods->lineEdit(i, 5)->asDouble();
        fDD.getBindValues(d2.fBindValues);
        fDD.update("r_body", where_id(ui->tblGoods->toInt(i, 0)));
        if (ui->leAction->fHiddenText.toInt() == STORE_DOC_MOVE) {
            d2[":f_sign"] = -1;
            d2[":f_store"] = ui->leStoreout->fHiddenText.toInt();
            if (!d2.insert("r_body", false)) {
                fDD.rollback();
                message_error(fDD.fLastError);
                return;
            }
        }
    }
    if (ui->leAction->fHiddenText.toInt() == 1) {
        if (docState == 1) {
            ui->wAcc->docType(1);
            ui->wAcc->docNum(ui->leDocNumber->asInt());
            ui->wAcc->partner(ui->lePartnerCode->asInt());
            ui->wAcc->save();
        } else {
            fDD[":f_docType"] = CASHDOC_STORE;
            fDD[":f_docNum"] = ui->leDocNumber->text();
            if (!fDD.exec("delete from c_cash where f_docType=:f_docType and f_docNum=:f_docNum")) {
                fDD.rollback();
                message_error(fDD.fLastError);
                return;
            }
        }
    }
    fDD.commit();
    bool v = docState == 0;
    ui->wCommon->setEnabled(v);
    for (int j = 0; j < ui->tblGoods->rowCount(); j++) {
        ui->tblGoods->lineEdit(j, 3)->setReadOnly(!v);
        ui->tblGoods->lineEdit(j, 4)->setReadOnly(!v);
        ui->tblGoods->lineEdit(j, 5)->setReadOnly(!v);
    }
    ui->wGoodsOps->setEnabled(v);
    if (docState == 1 && ui->leAction->fHiddenText.toInt() == STORE_DOC_IN) {
        for (int i = 0; i < ui->tblGoods->rowCount(); i++) {
            fDD[":f_lastPrice"] = ui->tblGoods->lineEdit(i, 4)->asDouble();
            fDD.update("r_dish", where_id(ui->tblGoods->toInt(i, 1)));
        }
    }
    if (docState == 1) {
        message_info(tr("Saved"));
    } else {
        message_info(tr("Draft saved"));
    }
}

void StoreDoc::qtyChange(const QString &arg1)
{
    Q_UNUSED(arg1)
    EQLineEdit *l = static_cast<EQLineEdit *>(sender());
    int row, col;
    if (!ui->tblGoods->findWidgetCell(l, row, col)) {
        return;
    }
    ui->tblGoods->lineEdit(row, 5)->setDouble(l->asDouble() *ui->tblGoods->lineEdit(row, 4)->asDouble());
    countTotal();
}

void StoreDoc::priceChange(const QString &arg1)
{
    Q_UNUSED(arg1)
    EQLineEdit *l = static_cast<EQLineEdit *>(sender());
    int row, col;
    if (!ui->tblGoods->findWidgetCell(l, row, col)) {
        return;
    }
    ui->tblGoods->lineEdit(row, 5)->setDouble(l->asDouble() *ui->tblGoods->lineEdit(row, 3)->asDouble());
    countTotal();
}

void StoreDoc::totalChange(const QString &arg1)
{
    Q_UNUSED(arg1)
    EQLineEdit *l = static_cast<EQLineEdit *>(sender());
    int row, col;
    if (!ui->tblGoods->findWidgetCell(l, row, col)) {
        return;
    }
    if (ui->tblGoods->lineEdit(row, 3)->asDouble() < 0.001) {
        return;
    }
    ui->tblGoods->lineEdit(row, 4)->setDouble(l->asDouble() / ui->tblGoods->lineEdit(row, 3)->asDouble());
    countTotal();
}

void StoreDoc::on_btnSaveDoc_clicked()
{
    saveDoc(1);
}

void StoreDoc::on_btnNewMaterial_clicked()
{
    QList<QVariant> values;
    RERestDish *d = new RERestDish(values, this);
    if (d->exec() == QDialog::Accepted) {
        newGoods(values.at(0).toString());
    }
}

void StoreDoc::newGoods(const QString &code)
{
    CacheDish c;
    if (!c.get(code)) {
        return;
    }
    int row = ui->tblGoods->rowCount();
    ui->tblGoods->setRowCount(row + 1);
    ui->tblGoods->setItemWithValue(row, 0, "");
    ui->tblGoods->setItemWithValue(row, 1, c.fCode());
    ui->tblGoods->setItemWithValue(row, 2, c.fName());
    EQLineEdit *l = ui->tblGoods->addLineEdit(row, 3, false);
    l->setValidator(new QDoubleValidator(0, 10000, 4));
    connect(l, SIGNAL(textEdited(QString)), this, SLOT(qtyChange(QString)));
    l = ui->tblGoods->addLineEdit(row, 4, false);
    l->setValidator(new QDoubleValidator(0, 1000000000, 2));
    connect(l, SIGNAL(textEdited(QString)), this, SLOT(priceChange(QString)));
    l = ui->tblGoods->addLineEdit(row, 5, false);
    l->setValidator(new QDoubleValidator(0, 1000000000, 2));
    connect(l, SIGNAL(textEdited(QString)), this, SLOT(totalChange(QString)));
    ui->tblGoods->lineEdit(row, 3)->setFocus();
}

void StoreDoc::on_btnAddMaterial_clicked()
{
    CacheInstance *ci = cache(cid_dish);
    QString dishCode = ci->get("");
    newGoods(dishCode);
}

void StoreDoc::on_btnDraftDoc_clicked()
{
    saveDoc(0);
}

void StoreDoc::on_btnRemoveDoc_clicked()
{
    if (message_confirm(tr("Confirm to delete document")) != QDialog::Accepted) {
        return;
    }
    DoubleDatabase fDD;
    fDD[":f_doc"] = ui->leDocNumber->text();
    fDD.exec("delete from r_body where f_doc=:f_doc");
    fDD[":f_id"] = ui->leDocNumber->text();
    fDD.exec("delete from r_docs where f_id=:f_id");
    fDD[":f_docType"] = CASHDOC_STORE;
    fDD[":f_docNum"] = ui->leDocNumber->text();
    fDD.exec("delete from c_cash where f_docType=:f_docType and f_docNum=:f_docNum");
    fMainWindow->fTab->removeTab(fMainWindow->fTab->indexOf(this));
    close();
}

void StoreDoc::on_btnRemoveMaterial_clicked()
{
    QModelIndexList ml = ui->tblGoods->selectionModel()->selectedRows();
    QSet<int> rows;
    foreach (QModelIndex m, ml) {
        rows << m.row();
    }
    QList<int> r = rows.values();
    DoubleDatabase fDD;
    for (int i = r.count() - 1; i > -1; i--) {
        fDD[":f_id"] = ui->tblGoods->toInt(r.at(i), 0);
        fDD.exec("delete from r_body where f_id=:f_id");
        ui->tblGoods->removeRow(r.at(i));
    };
    countTotal();
}

void StoreDoc::on_deDate_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->wAcc->date(ui->deDate->date());
}

void StoreDoc::on_leTotal_textChanged(const QString &arg1)
{
    ui->wAcc->amount(arg1.toDouble());
}

void StoreDoc::on_leComments_textChanged(const QString &arg1)
{
    ui->wAcc->comment(arg1);
}

void StoreDoc::on_btnPrintDoc_clicked()
{
    PPrintStoreDoc::print(ui->leDocNumber->text());
}
