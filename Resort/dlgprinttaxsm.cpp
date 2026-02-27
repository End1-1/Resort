#include "dlgprinttaxsm.h"
#include "ui_dlgprinttaxsm.h"
#include "taxhelper.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QRandomGenerator>

static int debug_tax_number = 0;

DlgPrintTaxSM::DlgPrintTaxSM(int taxid, QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgPrintTaxSM)
{
    ui->setupUi(this);
    fTaxCode = 0;
    fCashAmount = 0;
    fCardAmount = 0;
    fPrepaid = 0;
    fTaxID = taxid;
    fPrintTax = new PrintTaxN("", 1025, "", "", "1234", "1234", this);
    if (debug_tax_number == 0) {
        unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
        std::mt19937 gen(ms);
        std::uniform_int_distribution<> uid(1022, 102222);
        debug_tax_number = uid(gen);
    }
}

DlgPrintTaxSM::~DlgPrintTaxSM()
{
    delete ui;
}

void DlgPrintTaxSM::addGoods(const QString &dep, const QString &adgt, const QString &code, const QString &name,
                             double price, double qty)
{
    fPrintTax->addGoods(dep.toInt(), adgt, code, name, price, qty, 0.00);
}

int DlgPrintTaxSM::exec()
{
    fPrintMode = tm_receipt;
    connect( &fTimer, &QTimer::timeout, [this]() {
        load();
    });
    fTimer.start(2000);
    return BaseExtendedDialog::exec();
}

int DlgPrintTaxSM::execAdvance()
{
    fPrintMode = tm_advance;
    connect( &fTimer, &QTimer::timeout, [this]() {
        loadAdvance();
    });
    fTimer.start(2000);
    return BaseExtendedDialog::exec();
}

int DlgPrintTaxSM::execTaxback()
{
    fPrintMode = tm_taxback;
    connect( &fTimer, &QTimer::timeout, [this]() {
        loadTaxback();
    });
    fTimer.start(2000);
    return BaseExtendedDialog::exec();
}

bool DlgPrintTaxSM::printAdvance(int taxid, double amountCash, double amountCard, const QString &invoice,
                                 const QString &vaucher, int &taxCode, QString &json)
{
    DlgPrintTaxSM *d = new DlgPrintTaxSM(taxid, fPreferences.getDefaultParentForMessage());
    d->ui->teResult->setPlainText(tr("Printing advance") + " " + vaucher);
    d->fOrder = vaucher;
    d->fCashAmount = amountCash;
    d->fCardAmount = amountCard;
    bool result = d->execAdvance() == TAX_OK;
    taxCode = d->fTaxCode;
    json = d->fJson;
    TrackControl::insert(2, "Print fiscal", taxCode, "", vaucher, invoice);
    delete d;
    return result;
}

int DlgPrintTaxSM::printTaxback(int taxid, int number, const QString &vaucher, int &taxCode)
{
    DlgPrintTaxSM *d = new DlgPrintTaxSM(taxid, fPreferences.getDefaultParentForMessage());
    d->ui->teResult->setPlainText(tr("Tax back") + " " + vaucher);
    d->fOrder = vaucher;
    d->fTaxback = QString::number(number);
    bool result = d->execTaxback() == TAX_OK;
    taxCode = d->fTaxCode;
    delete d;
    return result;
}

void DlgPrintTaxSM::load()
{
    fTimer.stop();
    TaxPoint tp = TaxHelper::fInstance->fTaxPoints[fTaxID];
    fPrintTax->setParams(tp.ip, tp.port, tp.password, tp.opcode, tp.oppin, tp.extPos);
    QString inJson, outJson, err;
    int result = fPrintTax->makeJsonAndPrint(fCardAmount, fPrepaid, inJson, outJson, err);
    DoubleDatabase v;
    v.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass);
    v.open();
    v[":f_date"] = QDate::currentDate();
    v[":f_time"] = QTime::currentTime();
    v[":f_db"] = 1;
    v[":f_order"] = fOrder;
    v[":f_queryCode"] = opcode_print_receipt;
    v[":f_queryJson"] = inJson;
    v[":f_replyJson"] = outJson;
    v[":f_replyResult"] = result;
    v[":f_replyJson"] = outJson;
    v[":f_replyText"] = err;
    v[":f_replyTaxCode"] = "-";
    int id = v.insert("tax_print", true);
#ifdef QT_DEBUG
    qDebug() << outJson << err;
    result = pt_err_ok;
    outJson = QString("{\"rseq\":%1,\"crn\":\"63219817\",\"sn\":\"V98745506068\",\"tin\":\"01588771\",\"taxpayer\":\"«Ռոգա էնդ կոպիտա ՍՊԸ»\",\"address\":\"Արշակունյանց 34\",\"time\":1527853613000.0,\"fiscal\":\"98198105\",\"lottery\":\"00000000\",\"prize\":0,\"total\":1540.0,\"change\":0.0}").arg(
                  debug_tax_number++);
#endif
    if (result == pt_err_ok) {
        fJson = outJson;
        QString ofirm, ohvhh, ofiscal, onumber, osn, oaddress, odevnum, otime;
        QJsonObject jo = QJsonDocument::fromJson(outJson.toUtf8()).object();
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
    TaxPoint tp = TaxHelper::fInstance->fTaxPoints[fTaxID];
    fPrintTax->setParams(tp.ip, tp.port, tp.password, tp.opcode, tp.oppin, tp.extPos);
    QString inJson;
    QString outJson;
    QString err;
    int result = fPrintTax->printAdvanceJson(fCashAmount, fCardAmount, inJson, outJson, err);
    DoubleDatabase v;
    v.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass);
    v.open();
    v[":f_date"] = QDate::currentDate();
    v[":f_time"] = QTime::currentTime();
    v[":f_db"] = 1;
    v[":f_order"] = fOrder;
    v[":f_queryCode"] = opcode_print_receipt;
    v[":f_queryJson"] = inJson;
    v[":f_replyJson"] = outJson;
    v[":f_replyResult"] = result;
    v[":f_replyJson"] = outJson;
    v[":f_replyText"] = err;
    v[":f_replyTaxCode"] = "-";
    int id = v.insert("tax_print", true);
    if (result == pt_err_ok) {
        fJson = outJson;
        QString ofirm, ohvhh, ofiscal, onumber, osn, oaddress, odevnum, otime;
        QJsonObject jo = QJsonDocument::fromJson(outJson.toUtf8()).object();
        fTaxCode = jo["rseq"].toInt();
        v[":f_replyTaxCode"] = jo["rseq"].toInt();
        v[":f_id"] = id;
        v.exec("update tax_print set f_replyTaxCode=:f_replyTaxCode where f_id=:f_id");
        DoubleDatabase fDD;
        fDD[":f_fiscal"] = fTaxCode;
        fDD[":f_fiscaldate"] = QDate::currentDate();
        fDD[":f_fiscaltime"] = QTime::currentTime();
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
    TaxPoint tp = TaxHelper::fInstance->fTaxPoints[fTaxID];
    fPrintTax->setParams(tp.ip, tp.port, tp.password, tp.opcode, tp.oppin, tp.extPos);
    QString inJson;
    QString outJson;
    QString err;
    DoubleDatabase v;
    v.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass);
    v.open();
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
    result = fPrintTax->printTaxback(fTaxback.toInt(), crn, inJson, outJson, err);
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
