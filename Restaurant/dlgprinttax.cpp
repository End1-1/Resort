#include "dlgprinttax.h"
#include "ui_dlgprinttax.h"
#include <QJsonDocument>
#include <QJsonObject>

DlgPrintTax::DlgPrintTax(QWidget *parent) :
    BaseDialog(parent),
    ui(new Ui::DlgPrintTax)
{
    ui->setupUi(this);
    connect(&fTimer, &QTimer::timeout, [this]() {
        load(fDep, fOrder);
    });
    fTaxCode = 0;
}

DlgPrintTax::~DlgPrintTax()
{
    delete ui;
}

int DlgPrintTax::printTax(const QString &dep, const QString &order, double cardAmount, int &taxCode, const QString &taxPayer)
{
    DlgPrintTax *d = new DlgPrintTax(fPreferences.getDefaultParentForMessage());
    d->ui->teResult->setPlainText(QString("%1: %2").arg(tr("Printing")).arg(order));
    d->fOrder = order;
    d->fDep = dep;
    d->fCardAmount = cardAmount;
    d->fTaxPayer = taxPayer;
    int result = d->exec();
    taxCode = d->fTaxCode;
    delete d;
    return result;
}

int DlgPrintTax::exec()
{
    fTimer.start(2000);
    return BaseDialog::exec();
}

void DlgPrintTax::load(const QString &dep, const QString &order)
{
    fTimer.stop();
    PrintTaxN pt(fPreferences.getDb(def_tax_address).toString(),
                fPreferences.getDb(def_tax_port).toInt(),
                fPreferences.getDb(def_tax_password).toString(), "true", "3", "3");
    pt.fPartnerTin = fTaxPayer;
    DoubleDatabase fDD(true, doubleDatabase);
    fDD[":f_header"] = order;
    fDD[":f_state"] = DISH_STATE_READY;
    
    fDD.exec("select d.f_adgt, od.f_dish, d.f_am, od.f_price, od.f_qty "
                   "from o_dish od "
                   "left join r_dish d on d.f_id=od.f_dish "
                   "where od.f_header=:f_header and od.f_state=:f_state "
                   "and (f_complex=0 or (f_complex>0 and f_complexId=0))");
    for (int i = 0; i < fDD.rowCount(); i++) {
        pt.addGoods(dep, fDD.getValue(i, "f_adgt").toString(), fDD.getValue(i, "f_code").toString(),
                      fDD.getValue(i, "f_am").toString(), fDD.getValue(i, "f_price").toDouble(), fDD.getValue(i, "f_qty").toDouble(), 0);
    }
    QString inJson, outJson, err;
    int result = pt.makeJsonAndPrint(fCardAmount, 0, inJson, outJson, err);

    QString ofirm, ohvhh, ofiscal, onumber, osn, oaddress, odevnum, otime;
    PrintTaxN::parseResponse(outJson, ofirm, ohvhh, ofiscal, onumber, osn, oaddress, odevnum, otime);
    DoubleDatabase air;
    air.setDatabase(BaseUIDX::fAirHost, BaseUIDX::fAirDbName, BaseUIDX::fAirUser, BaseUIDX::fAirPass, 1);
    air.open(true, false);
    air[":f_date"] = QDate::currentDate();
    air[":f_time"] = QTime::currentTime();
    air[":f_db"] = 1;
    air[":f_order"] = fOrder;
    //air[":f_queryCode"] = opcode_PrintTaxN;
    air[":f_queryJson"] = inJson;
    air[":f_replyJson"] = outJson;
    air[":f_replyResult"] = result;
    air[":f_replyJson"] = outJson;
    air[":f_replyText"] = err;
    air[":f_replyTaxCode"] = onumber;
    int id = air.insert("tax_print");
    air.close();

    if (result == pt_err_ok) {
#ifdef QT_DEBUG
        outJson = "{\"rseq\":38432,\"crn\":\"53208770\",\"sn\":\"V90413501919\",\"tin\":\"02596277\",\"taxpayer\":\"«ՊԼԱԶԱ ՍԻՍՏԵՄՍ»\",\"address\":\"ԵՐԵՎԱՆ Ամիրյան 4/3\",\"time\":1522831916000.0,\"fiscal\":\"18371620\",\"lottery\":\"00000000\",\"prize\":0,\"total\":20.0,\"change\":0.0}";
#endif
        int pos = outJson.indexOf("\"rseq\":") + 7;
        int pos2 = outJson.indexOf(",", pos );
        QString rseq = outJson.mid(pos, pos2 - pos);
        pos = outJson.indexOf("\"fiscal\":") + 9;
        pos2 = outJson.indexOf(",", pos + 1);
        QString fiscal = outJson.mid(pos, pos2 - pos);
        fiscal.replace("\"\"", "");
        pos = outJson.indexOf("\"tin\":") + 6;
        pos2 = outJson.indexOf(",", pos + 1);
        QString hvhh = outJson.mid(pos, pos2 - pos);
        hvhh.replace("\"", "");
        fTaxCode = rseq.toInt();

        DoubleDatabase dair;
        dair.setDatabase(__dd1Host, __dd1Database, __dd1Username, __dd1Password, 1);
        dair.open(true, false);
        dair[":f_replyTaxCode"] = QString::number(fTaxCode);
        dair[":f_id"] = id;
        dair.exec("update tax_print set f_replyTaxCode=:f_replyTaxCode where f_id=:f_id");
        fDD[":f_tax"] = fTaxCode;
        fDD.update("o_header", ap(fOrder));
        done(TAX_OK);
        return;
    }
    ui->teResult->setPlainText(outJson + "\r\n\r\n" + err);
    ui->btnRetry->setEnabled(true);
    ui->btnNoNeed->setEnabled(true);
}

void DlgPrintTax::on_btnCancel_clicked()
{
    done(TAX_FAIL);
}

void DlgPrintTax::on_btnRetry_clicked()
{
    ui->btnRetry->setEnabled(false);
    ui->btnNoNeed->setEnabled(false);
    ui->teResult->setPlainText(QString("%1: %2").arg(tr("Retry printing")).arg(fOrder));
    qApp->processEvents();
    load(fDep, fOrder);
}

void DlgPrintTax::on_btnNoNeed_clicked()
{
    done(TAX_NONEED);
}
