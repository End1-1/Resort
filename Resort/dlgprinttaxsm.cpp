#include "dlgprinttaxsm.h"
#include "ui_dlgprinttaxsm.h"
#include <QJsonDocument>
#include <QJsonObject>

DlgPrintTaxSM::DlgPrintTaxSM(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgPrintTaxSM)
{
    ui->setupUi(this);
    fTaxCode = 0;
}

DlgPrintTaxSM::~DlgPrintTaxSM()
{
    delete ui;
}

void DlgPrintTaxSM::addGoods(const QString &dep, const QString &adgt, const QString &code, const QString &name, double price, double qty)
{
    fPrintTax.addGoods(dep, adgt, code, name, price, qty);
}

int DlgPrintTaxSM::exec()
{
    fPrintMode = tm_receipt;
    connect(&fTimer, &QTimer::timeout, [this](){
       load();
    });
    fTimer.start(2000);
    return BaseExtendedDialog::exec();
}

int DlgPrintTaxSM::execAdvance()
{
    fPrintMode = tm_advance;
    connect(&fTimer, &QTimer::timeout, [this](){
       loadAdvance();
    });
    fTimer.start(2000);
    return BaseExtendedDialog::exec();
}

int DlgPrintTaxSM::execTaxback()
{
    fPrintMode = tm_taxback;
    connect(&fTimer, &QTimer::timeout, [this]() {
        loadTaxback();
    });
    fTimer.start(2000);
    return BaseExtendedDialog::exec();
}

bool DlgPrintTaxSM::printAdvance(double amountCash, double amountCard, const QString &vaucher, int &taxCode)
{
    DlgPrintTaxSM *d = new DlgPrintTaxSM(fPreferences.getDefaultParentForMessage());
    d->ui->teResult->setPlainText(tr("Printing advance") + " " + vaucher);
    d->fOrder = vaucher;
    d->fCashAmount = amountCash;
    d->fCardAmount = amountCard;
    bool result = d->execAdvance() == TAX_OK;
    taxCode = d->fTaxCode;
    delete d;
    return result;
}

int DlgPrintTaxSM::printTaxback(int number, const QString &vaucher, int &taxCode)
{
    DlgPrintTaxSM *d = new DlgPrintTaxSM(fPreferences.getDefaultParentForMessage());
    d->ui->teResult->setPlainText(tr("Tax back") + " " + vaucher);
    d->fOrder = vaucher;
    d->fTaxback = number;
    bool result = d->execTaxback() == TAX_OK;
    taxCode = d->fTaxCode;
    delete d;
    return result;
}

void DlgPrintTaxSM::load()
{
    fTimer.stop();
    fPrintTax.setParams(fPreferences.getDb(def_tax_address).toString(),
                fPreferences.getDb(def_tax_port).toInt(),
                fPreferences.getDb(def_tax_password).toString());
    QString inJson, outJson, err;
    int result = fPrintTax.makeJsonAndPrint(fCardAmount, fPrepaid, inJson, outJson, err);

    DoubleDatabase v;
    v.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass, 1);
    v.open(true, false);
    v[":f_date"] = QDate::currentDate();
    v[":f_time"] = QTime::currentTime();
    v[":f_db"] = 1;
    v[":f_order"] = fOrder;
    v[":f_queryCode"] = opcode_PrintTaxN;
    v[":f_queryJson"] = inJson;
    v[":f_replyJson"] = outJson;
    v[":f_replyResult"] = result;
    v[":f_replyJson"] = outJson;
    v[":f_replyText"] = err;
    v[":f_replyTaxCode"] = "-";
    int id = v.insert("tax_print", true);

    if (result == pt_err_ok) {
        QJsonDocument jd = QJsonDocument::fromJson(outJson.toUtf8());
        QJsonObject jo = jd.object();
        fTaxCode = jo["rseq"].toInt();
        v[":f_replyTaxCode"] = QString::number(fTaxCode);
        v[":f_id"] = id;
        v.exec("update tax_print set f_replyTaxCode=:f_replyTaxCode where f_id=:f_id");
        done(TAX_OK);
        return;
    }
    v.close();
    ui->teResult->setPlainText(outJson + "\r\n\r\n" + err);
    ui->btnRetry->setEnabled(true);
    //ui->btnNoNeed->setEnabled(true);
}

void DlgPrintTaxSM::loadAdvance()
{
    fTimer.stop();
    fPrintTax.setParams(fPreferences.getDb(def_tax_address).toString(),
                fPreferences.getDb(def_tax_port).toInt(),
                fPreferences.getDb(def_tax_password).toString());
    QString inJson;
    QString outJson;
    QString err;
    int result = fPrintTax.printAdvanceJson(fCashAmount, fCardAmount, inJson, outJson, err);

    DoubleDatabase v;
    v.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass, 1);
    v.open(true, false);
    v[":f_date"] = QDate::currentDate();
    v[":f_time"] = QTime::currentTime();
    v[":f_db"] = 1;
    v[":f_order"] = fOrder;
    v[":f_queryCode"] = opcode_PrintTaxN;
    v[":f_queryJson"] = inJson;
    v[":f_replyJson"] = outJson;
    v[":f_replyResult"] = result;
    v[":f_replyJson"] = outJson;
    v[":f_replyText"] = err;
    v[":f_replyTaxCode"] = "-";
    int id = v.insert("tax_print", true);

    if (result == pt_err_ok) {
        QJsonDocument jd = QJsonDocument::fromJson(outJson.toUtf8());
        QJsonObject jo = jd.object();
        fTaxCode = jo["rseq"].toInt();
        v[":f_replyTaxCode"] = QString::number(fTaxCode);
        v[":f_id"] = id;
        v.exec("update tax_print set f_replyTaxCode=:f_replyTaxCode where f_id=:f_id");
        DoubleDatabase fDD(true, doubleDatabase);
        fDD[":f_fiscal"] = fTaxCode;
        fDD.update("m_register", where_id(ap(fOrder)));
        done(TAX_OK);
        return;
    }
    v.close();
    ui->teResult->setPlainText(outJson + "\r\n\r\n" + err);
    ui->btnRetry->setEnabled(true);
}

void DlgPrintTaxSM::loadTaxback()
{
    fTimer.stop();
    fPrintTax.setParams(fPreferences.getDb(def_tax_address).toString(),
                fPreferences.getDb(def_tax_port).toInt(),
                fPreferences.getDb(def_tax_password).toString());
    QString inJson;
    QString outJson;
    QString err;

    DoubleDatabase v;
    v.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass, 1);
    v.open(true, false);
    v[":f_replyTaxCode"] = fTaxback;
    v.exec("select * from airwick.tax_print where f_replyTaxCode=:f_replyTaxCode");
    QString crn;
    int result = pt_err_ok;
    if (v.rowCount() == 0) {
        result = pt_err_no_tax_in_db;
        err = tr("The given tax number not exists in databases");
        done(result);
        return;
    } else {
        QJsonDocument jDoc = QJsonDocument::fromJson(v.getValue("f_replyJson").toString().toUtf8());
        QJsonObject jObj = jDoc.object();
        crn = jObj["crn"].toString();
        if (crn.isEmpty()) {
            message_error(tr("Crn is empty") + "<br>" + v.getValue("f_replyJson").toString());
            result = pt_err_no_tax_in_db;
            err = tr("The given tax number not exists in databases");
            done(result);
            return;
        }
    }

    result = fPrintTax.printTaxback(fTaxback, crn, inJson, outJson, err);

    v[":f_date"] = QDate::currentDate();
    v[":f_time"] = QTime::currentTime();
    v[":f_db"] = 1;
    v[":f_order"] = fOrder;
    v[":f_queryCode"] = opcode_taxback;
    v[":f_queryJson"] = inJson;
    v[":f_replyJson"] = outJson;
    v[":f_replyResult"] = result;
    v[":f_replyJson"] = outJson;
    v[":f_replyText"] = err;
    v[":f_replyTaxCode"] = "-";
    int id = v.insert("tax_print", true);

    if (result == pt_err_ok) {
        QJsonDocument jd = QJsonDocument::fromJson(outJson.toUtf8());
        QJsonObject jo = jd.object();
        fTaxCode = jo["rseq"].toInt();
        v[":f_replyTaxCode"] = QString::number(fTaxCode);
        v[":f_id"] = id;
        v.exec("update tax_print set f_replyTaxCode=:f_replyTaxCode where f_id=:f_id");
        done(TAX_OK);
        return;
    }
    ui->teResult->setPlainText(outJson + "\r\n\r\n" + err);
    ui->btnRetry->setEnabled(true);
}

void DlgPrintTaxSM::on_btnCancel_clicked()
{
    done(TAX_FAIL);
}

void DlgPrintTaxSM::on_btnRetry_clicked()
{
    ui->btnRetry->setEnabled(false);
    //ui->btnNoNeed->setEnabled(false);
    ui->teResult->setPlainText(QString("%1: %2").arg(tr("Retry printing")).arg(fOrder));
    qApp->processEvents();
    switch (fPrintMode) {
    case tm_receipt:
        load();
        break;
    case tm_advance:
        loadAdvance();
        break;
    case tm_taxback:
        loadTaxback();
        break;
    }
}

void DlgPrintTaxSM::on_btnNoNeed_clicked()
{
    done(TAX_NONEED);
}
