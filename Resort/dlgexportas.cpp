#include "dlgexportas.h"
#include "ui_dlgexportas.h"
#include "utils.h"
#include "message.h"
#include <QUuid>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlError>

DlgExportAS::DlgExportAS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgExportAS)
{
    ui->setupUi(this);
    ui->leAsConnectionString->setText(__s.value("asconnectionstring").toString());
    ui->lePartnerCode->setText(__s.value("partnercode").toString());
    ui->leVat->setText(__s.value("asvat").toString());
    ui->leStore->setText(__s.value("asstorecode").toString());
    ui->leServiceExpenseAcc->setText(__s.value("asserviceexpenseacc").toString());
    ui->leServiceIncomeAcc->setText(__s.value("asserviceincomeacc").toString());
    ui->leVatInvoice->setText(__s.value("asvatinv").toString());
    ui->leServiceExpenseAccInvoice->setText(__s.value("asserviceexpenseaccinv").toString());
    ui->leServiceIncomeAccInvoice->setText(__s.value("asserviceincomeaccinv").toString());
    ui->leExportPaymentAVCredit->setText(__s.value("leExportPaymentAVCredit").toString());
    ui->leExportPaymentAVDebet->setText(__s.value("leExportPaymentAVDebet").toString());
    ui->leExportPaymentRVCredit->setText(__s.value("leExportPaymentRVCredit").toString());
    ui->leExportPaymentRVDebet->setText(__s.value("leExportPaymentRVDebet").toString());
}

DlgExportAS::~DlgExportAS()
{
    delete ui;
}

void DlgExportAS::getAsDataMap(QMap<int, QMap<QString, QVariant> > &partnersMap,
                               QMap<QString, QMap<QString, QVariant> > &servicesMap,
                               QMap<QString, QMap<QString, QVariant> > &goodsMap,
                               QMap<QString, QMap<QString, QVariant> > &unitsMap)
{
    QSqlDatabase dbas = QSqlDatabase::addDatabase("QODBC3", "as3");
    dbas.setDatabaseName(__s.value("asconnectionstring").toString());
    if (!dbas.open()) {
        message_error(dbas.lastError().databaseText());
        return;
    }

    QSqlQuery q(dbas);
    q.setForwardOnly(true);

    DoubleDatabase::logEvent("export to as: fetch materials from as");
    q.exec("select fMTCODE, fMTID, fCAPTION, fUNIT from MATERIALS");
    QSqlRecord r = q.record();
    QStringList fields;
    for (int i = 0; i < r.count(); i++) {
        fields.append(r.fieldName(i).toLower());
    }
    while (q.next()) {
        QMap<QString, QVariant> temp;
        recordToMap(temp, q, fields);
        goodsMap[q.value(0).toString()] = temp;
    }
    fields.clear();

    DoubleDatabase::logEvent("export to as: get services list from as");
    q.exec("select fSERVID, fSERVCODE, fCAPTION, fFULLCAPTION, fUNIT from SERVICES");
    r = q.record();
    for (int i = 0; i < r.count(); i++) {
        fields.append(r.fieldName(i).toLower());
    }
    while (q.next()) {
        QMap<QString, QVariant> temp;
        recordToMap(temp, q, fields);
        servicesMap[q.value(1).toString()] = temp;
    }
    fields.clear();

    DoubleDatabase::logEvent("export to as: fetch units from as");
    q.exec("select fCODE, fBRIEF from QNTUNIT");
    while (q.next()) {
        QMap<QString, QVariant> temp;
        recordToMap(temp, q, fields);
        unitsMap[q.value(0).toString()] = temp;
    }
    fields.clear();

    DoubleDatabase::logEvent("export to as: fetch partner from as");
    q.exec("select fPARTID, fPARTCODE, fCAPTION, fFULLCAPTION from PARTNERS");
    r = q.record();
    for (int i = 0; i < r.count(); i++) {
        fields.append(r.fieldName(i).toLower());
    }
    while (q.next()) {
        QMap<QString, QVariant> temp;
        recordToMap(temp, q, fields);
        partnersMap[q.value(1).toInt()] = temp;
    }

    DoubleDatabase::logEvent("export to as: fetch from as complete");
}

void DlgExportAS::exportInvoiceToAs(const QString &invoice,
                                    const QMap<int, QMap<QString, QVariant> > &partnersMap,
                                    const QMap<QString, QMap<QString, QVariant> > &servicesMap,
                                    const QMap<QString, QMap<QString, QVariant> > &unitsMap,
                                    bool forceMove)
{
    QSqlDatabase dbas = QSqlDatabase::addDatabase("QODBC3", "asss");
    dbas.setDatabaseName(__s.value("asconnectionstring").toString());
    if (!dbas.open()) {
        message_error(dbas.lastError().databaseText());
        return;
    }

    DoubleDatabase dd(true, false);
    dd[":f_inv"] = invoice;
    dd.exec("select * from m_register where f_inv=:f_inv and f_source='RV' and f_paymentmode=4 ");
    if (dd.nextRow() == false) {
        message_error(QString("%1: %2").arg(tr("No checkout for cityledger for this invoice exists")).arg(invoice));
        return;
    }
    QDate checkoutDate = dd.getDate("f_wdate");
    int cityledger = dd.getInt("f_cityledger");
    QString guest = dd.getString("f_guest");
    QString docid = QUuid::createUuid().toString().replace("{", "").replace("}", "");

    if (forceMove == false) {
        dd[":f_id"] = cityledger;
        dd.exec("select f_alwaysinvoice from f_city_ledger where f_id=:f_id");
        if (dd.nextRow()) {
            DoubleDatabase::logEvent("export to as: Cityledger not automatically move to as");
            if (dd.getInt(0) == 0) {
                return;
            }
        } else {
            message_error(tr("Invalid cityledger code"));
            return;
        }
    }

    dd[":f_inv"] = invoice;
    dd.exec("select f_itemcode, f_finalname, f_amountamd "
            "from m_register "
            "where f_paymentmode=9 and f_finance=1 and f_side=1 and f_inv=:f_inv and f_fiscal=0 and f_source in ('RM', 'CH', 'PS')");
    double total = 0;
    QList<QMap<QString, QVariant> > items;
    while (dd.nextRow()) {
        QMap<QString, QVariant> tmp;
        tmp["f_itemcode"] = dd.getString("f_itemcode");
        tmp["f_finalname"] = dd.getString("f_finalname");
        tmp["f_amountamd"] = dd.getDouble("f_amountamd");
        items.append(tmp);
        total += dd.getDouble("f_amountamd");
    }
    if (items.count() == 0) {
        message_error(tr("Empty invoice"));
        return;
    }

    QSqlQuery q(dbas);
    dbas.transaction();
    if (q.prepare("insert into DOCUMENTS ("
                  "fISN, fDOCTYPE, fDOCSTATE, fDATE, fORDERNUM, fDOCNUM, fCUR, fSUMM, fCOMMENT, fBODY, fPARTNAME, "
                  "fUSERID, fPARTID, fCRPARTID, fMTID, fEXPTYPE, fINVN, fENTRYSTATE, "
                  "fEMPLIDRESPIN, fEMPLIDRESPOUT, fVATTYPE, fSPEC, fCHANGEDATE,fEXTBODY,fETLSTATE) VALUES ("
                  ":fISN, :fDOCTYPE, :fDOCSTATE, '" + checkoutDate.toString("yyyy-MM-dd") + "', "
                  ":fORDERNUM, :fDOCNUM, :fCUR, :fSUMM, :fCOMMENT, :fBODY, :fPARTNAME, "
                  ":fUSERID, :fPARTID, :fCRPARTID, :fMTID, '', :fINVN, :fENTRYSTATE, "
                  ":fEMPLIDRESPIN, :fEMPLIDRESPOUT, :fVATTYPE, :fSPEC, current_timestamp,'', '')") == false) {
        dbas.rollback();
        message_error(q.lastError().databaseText());
        return;
    }
    q.bindValue(":fISN", docid);
    q.bindValue(":fDOCTYPE", 5);
    q.bindValue(":fDOCSTATE", 1);
    q.bindValue(":fORDERNUM", "");
    q.bindValue(":fDOCNUM", "");
    q.bindValue(":fCUR", "AMD");
    q.bindValue(":fSUMM", total);
    q.bindValue(":fCOMMENT", QString("%1 %2, %3").arg(tr("Invoice"), invoice, guest));
    q.bindValue(":fBODY", QString("\r\nPREPAYMENTACC:5231\r\nVATACC:5243\r\nSUMMVAT:%2\r\nBUYERACC:2211\r\nCUREXCHNG:1.0000\r\nCOURSECOUNT:1.0000\r\nBUYCHACCPOST:Գլխավոր հաշվապահ \r\nMAXROWID:%1\r\n")
            .arg(items.count())
            .arg(__s.value("asvatinv").toString().toDouble() > 0.001 ? (__s.value("asvatinv").toString().toDouble() / 100) * total : 0));
    q.bindValue(":fPARTNAME", partnersMap[cityledger]["fcaption"]); // set to kamar
    q.bindValue(":fUSERID", 0);
    q.bindValue(":fPARTID", partnersMap[cityledger]["fpartid"]);
    q.bindValue(":fCRPARTID", -1);
    q.bindValue(":fMTID", -1);
    q.bindValue(":fINVN", "");
    q.bindValue(":fENTRYSTATE", 0);
    q.bindValue(":fEMPLIDRESPIN", -1);
    q.bindValue(":fEMPLIDRESPOUT", -1);
    q.bindValue(":fVATTYPE", "2");
    q.bindValue(":fSPEC", "                    00"); // <--- Tax receipt id
//        if (card > 0.001) {
//            dbas[":fBODY"] = dbas[":fBODY"].toString() +
//                    QString("BANKACQUIRINGACCOUNT:%1\r\nSUMMPLCARD:%2\r\n")
//                    .arg(bankacc)
//                    .arg(float_str(card, 2).replace(",", "").replace(" ", ""));
//        }
    if (!q.exec()) {
        dbas.rollback();
        message_error(q.lastError().databaseText());
        return;
    }

    int rowid = 1;
    for (QList<QMap<QString, QVariant> >::const_iterator bi = items.constBegin(); bi != items.constEnd(); bi++) {
        q.prepare("insert into MTINVOICELIST (fISN, fROWNUM, fITEMTYPE, fITEMID, fITEMNAME, "
                    "fUNITBRIEF, fSTORAGE, fQUANTITY, fINITPRICE, fDISCOUNT, fPRICE, fSUMMA, fSUMMA1, "
                    "fENVFEEPERCENT, fENVFEESUMMA, fVAT, fEXPMETHOD, fACCEXPENSE, fACCINCOME, fPARTYMETHOD, fROWID) "
                    "VALUES (:fISN, :fROWNUM, :fITEMTYPE, :fITEMID, :fITEMNAME, "
                    ":fUNITBRIEF, :fSTORAGE, :fQUANTITY, :fINITPRICE, :fDISCOUNT, :fPRICE, :fSUMMA, :fSUMMA1, "
                    ":fENVFEEPERCENT, :fENVFEESUMMA, :fVAT, :fEXPMETHOD, :fACCEXPENSE, :fACCINCOME, :fPARTYMETHOD, :fROWID)");
        q.bindValue(":fISN", docid);
        q.bindValue(":fROWNUM", rowid);
        q.bindValue(":fITEMTYPE", 2);
        q.bindValue(":fITEMID", servicesMap[(*bi)["f_itemcode"].toString()]["fservid"]);
        q.bindValue(":fITEMNAME", (*bi)["f_finalname"]);
        //q.bindValue(":fITEMNAME", servicesMap[(*bi)["f_itemcode"].toString()]["fcaption"]);
        q.bindValue(":fUNITBRIEF", unitsMap[servicesMap[(*bi)["f_itemcode"].toString()]["funit"].toString()]);
        q.bindValue(":fSTORAGE", "   ");
        q.bindValue(":fQUANTITY", 1);
        q.bindValue(":fINITPRICE", (*bi)["f_amountamd"]);
        q.bindValue(":fDISCOUNT", 0);
        q.bindValue(":fPRICE", (*bi)["f_amountamd"]);
        q.bindValue(":fSUMMA", (*bi)["f_amountamd"]);
        q.bindValue(":fSUMMA1", 0);
        q.bindValue(":fENVFEEPERCENT", 0);
        q.bindValue(":fENVFEESUMMA", 0);
        q.bindValue(":fVAT", 1);
        q.bindValue(":fEXPMETHOD", 1);
        q.bindValue(":fACCEXPENSE", __s.value("asserviceexpenseaccinv", "").toString());
        q.bindValue(":fACCINCOME", __s.value("asserviceincomeaccinv", "").toString());
        q.bindValue(":fPARTYMETHOD", 0);
        q.bindValue(":fROWID", rowid++);
        if (q.exec() == false) {
            dbas.rollback();
            message_error(q.lastError().databaseText()
                          + "<br>"
                          + invoice
                          + "<br>"
                          + (*bi)["f_finalname"].toString());
            return;
        }
    }
    dbas.commit();
}

void DlgExportAS::on_btnUploadPostCharges_clicked()
{
    __s.setValue("partnercode", ui->lePartnerCode->text());
    __s.setValue("asvat", ui->leVat->text());
    __s.setValue("asstorecode", ui->leStore->text());
    __s.setValue("asserviceexpenseacc", ui->leServiceExpenseAcc->text());
    __s.setValue("asserviceincomeacc", ui->leServiceIncomeAcc->text());

    DoubleDatabase::logEvent("starting export to as");
    QSqlDatabase dbas = QSqlDatabase::addDatabase("QODBC3", "as");
    dbas.setDatabaseName(ui->leAsConnectionString->text());
    if (!dbas.open()) {
        message_error("Could not open database<br>" + dbas.lastError().databaseText());
        return;
    }
    QSqlQuery q(dbas);
    QMap<int, QMap<QString, QVariant> > partnersMap;
    QMap<QString, QMap<QString, QVariant> > servicesMap;
    QMap<QString, QMap<QString, QVariant> > goodsMap;
    QMap<QString, QMap<QString, QVariant> > unitsMap;
    getAsDataMap(partnersMap, servicesMap, goodsMap, unitsMap);

    DoubleDatabase::logEvent("export to as: get list of saled items");
    QMap<QDate, QList<QMap<QString, QVariant> > > exportData;
    QMap<QDate, double> totals;
    DoubleDatabase dd(true, false);
    dd[":f_date1"] = ui->deStart->date();
    dd[":f_date2"] = ui->deEnd->date();
    dd.exec("select f_fiscaldate, f_itemcode, f_finalname, f_amountamd, f_fiscal, f_inv "
            "from m_register "
            "where f_fiscal>0 and f_fiscaldate between :f_date1 and :f_date2 and f_source in ('PS', 'CH', 'RM')");
    while (dd.nextRow()) {
        QMap<QString, QVariant> ed;
        ed["f_itemcode"] = dd.getString("f_itemcode");
        ed["f_finalname"] = dd.getString("f_finalname");
        ed["f_amountamd"] = dd.getString("f_amountamd");
        ed["f_fiscal"] = dd.getString("f_fiscal");
        ed["f_inv"] = dd.getString("f_inv");
        exportData[dd.getDate("f_date")].append(ed);
        totals[dd.getDate("f_date")] = totals[dd.getDate("f_date")] + dd.getDouble("f_amountamd");
    }

    DoubleDatabase::logEvent("export to as: starting doc create");
    for (QMap<QDate, QList<QMap<QString, QVariant> > >::const_iterator it = exportData.constBegin(); it != exportData.constEnd(); it++) {
        QString docid = QUuid::createUuid().toString().replace("{", "").replace("}", "");
        dbas.transaction();
        DoubleDatabase::logEvent("export to as: create header");
        if (!q.prepare("insert into DOCUMENTS ("
                      "fISN, fDOCTYPE, fDOCSTATE, fDATE, fORDERNUM, fDOCNUM, fCUR, fSUMM, fCOMMENT, fBODY, fPARTNAME, "
                      "fUSERID, fPARTID, fCRPARTID, fMTID, fEXPTYPE, fINVN, fENTRYSTATE, "
                      "fEMPLIDRESPIN, fEMPLIDRESPOUT, fVATTYPE, fSPEC, fCHANGEDATE,fEXTBODY,fETLSTATE) VALUES ("
                      ":fISN, :fDOCTYPE, :fDOCSTATE, '" + it.key().toString("yyyy-MM-dd") + "', "
                      ":fORDERNUM, :fDOCNUM, :fCUR, :fSUMM, :fCOMMENT, :fBODY, :fPARTNAME, "
                      ":fUSERID, :fPARTID, :fCRPARTID, :fMTID, '', :fINVN, :fENTRYSTATE, "
                      ":fEMPLIDRESPIN, :fEMPLIDRESPOUT, :fVATTYPE, :fSPEC, current_timestamp,'', '')")) {
            message_error("Prepare insert to documents<br>" + q.lastError().databaseText() + "<br>"  + dbas.lastError().databaseText());
            return;
        }
        q.bindValue(":fISN", docid);
        q.bindValue(":fDOCTYPE", 20);
        q.bindValue(":fDOCSTATE", 1);
        q.bindValue(":fORDERNUM", "");
        q.bindValue(":fDOCNUM", "");
        q.bindValue(":fCUR", "AMD");
        q.bindValue(":fSUMM", totals[it.key()]);
        q.bindValue(":fCOMMENT", QString("%1 %2").arg(tr("Revenue"), it.key().toString(def_date_format)));
        q.bindValue(":fBODY", QString("\r\nPREPAYMENTACC:5231\r\nVATACC:5243\r\nSUMMVAT:%2\r\nBUYERACC:2211\r\nBUYCHACCPOST:Գլխավոր հաշվապահ \r\nMAXROWID:%1\r\n")
                .arg(it.value().count())
                .arg(ui->leVat->text().toDouble() > 0.001 ? (ui->leVat->text().toDouble() / 100) * totals[it.key()] : 0));
        q.bindValue(":fPARTNAME", partnersMap[ui->lePartnerCode->text().toInt()]["fcaption"]); // set to kamar
        q.bindValue(":fUSERID", 0);
        q.bindValue(":fPARTID", partnersMap[ui->lePartnerCode->text().toInt()]["fpartid"]);
        q.bindValue(":fCRPARTID", -1);
        q.bindValue(":fMTID", -1);
        q.bindValue(":fINVN", "");
        q.bindValue(":fENTRYSTATE", 0);
        q.bindValue(":fEMPLIDRESPIN", -1);
        q.bindValue(":fEMPLIDRESPOUT", -1);
        q.bindValue(":fVATTYPE", "1");
        q.bindValue(":fSPEC", "                    00"); // <--- Tax receipt id
//        if (card > 0.001) {
//            dbas[":fBODY"] = dbas[":fBODY"].toString() +
//                    QString("BANKACQUIRINGACCOUNT:%1\r\nSUMMPLCARD:%2\r\n")
//                    .arg(bankacc)
//                    .arg(float_str(card, 2).replace(",", "").replace(" ", ""));
//        }
        if (!q.exec()) {
            dbas.rollback();
            message_error("Exec insert to documents<br>" + q.lastError().databaseText());
            return;
        }
        DoubleDatabase::logEvent("export to as: create body");
        int rowid = 0;
        for (QList<QMap<QString, QVariant> >::const_iterator bi = it.value().constBegin(); bi != it.value().constEnd(); bi++) {
            if (!q.prepare("insert into MTINVOICELIST (fISN, fROWNUM, fITEMTYPE, fITEMID, fITEMNAME, "
                        "fUNITBRIEF, fSTORAGE, fQUANTITY, fINITPRICE, fDISCOUNT, fPRICE, fSUMMA, fSUMMA1, "
                        "fENVFEEPERCENT, fENVFEESUMMA, fVAT, fEXPMETHOD, fACCEXPENSE, fACCINCOME, fPARTYMETHOD, fROWID) "
                        "VALUES (:fISN, :fROWNUM, :fITEMTYPE, :fITEMID, :fITEMNAME, "
                        ":fUNITBRIEF, :fSTORAGE, :fQUANTITY, :fINITPRICE, :fDISCOUNT, :fPRICE, :fSUMMA, :fSUMMA1, "
                        ":fENVFEEPERCENT, :fENVFEESUMMA, :fVAT, :fEXPMETHOD, :fACCEXPENSE, :fACCINCOME, :fPARTYMETHOD, :fROWID)")) {
                dbas.rollback();
                message_error("Prepare insert to invoice list<br>" + q.lastError().databaseText());
                return;
            }
            q.bindValue(":fISN", docid);
            q.bindValue(":fROWNUM", rowid);
            q.bindValue(":fITEMTYPE", 2);
            q.bindValue(":fITEMID", servicesMap[(*bi)["f_itemcode"].toString()]["fservid"]);
            q.bindValue(":fITEMNAME", servicesMap[(*bi)["f_itemcode"].toString()]["fcaption"]);
            q.bindValue(":fUNITBRIEF", unitsMap[servicesMap[(*bi)["f_itemcode"].toString()]["funit"].toString()]);
            q.bindValue(":fSTORAGE", ui->leStore->text());
            q.bindValue(":fQUANTITY", 1);
            q.bindValue(":fINITPRICE", (*bi)["f_amountamd"]);
            q.bindValue(":fDISCOUNT", 0);
            q.bindValue(":fPRICE", (*bi)["f_amountamd"]);
            q.bindValue(":fSUMMA", (*bi)["f_amountamd"]);
            q.bindValue(":fSUMMA1", 0);
            q.bindValue(":fENVFEEPERCENT", 0);
            q.bindValue(":fENVFEESUMMA", 0);
            q.bindValue(":fVAT", 1);
            q.bindValue(":fEXPMETHOD", 1);
            q.bindValue(":fACCEXPENSE", ui->leServiceExpenseAcc->text());
            q.bindValue(":fACCINCOME", ui->leServiceIncomeAcc->text());
            q.bindValue(":fPARTYMETHOD", 0);
            q.bindValue(":fROWID", rowid++);
            if (q.exec() == false) {
                dbas.rollback();
                message_error("Exec insert to invoice list<br>" + q.lastError().databaseText());
                return;
            }
            DoubleDatabase::logEvent(DoubleDatabase::lastQuery(&q));
        }
        DoubleDatabase::logEvent("export to as: end of doc");
        dbas.commit();
    }
    DoubleDatabase::logEvent("export to as: end of task");
    message_info("Done!");
}

void DlgExportAS::on_btnSaveAsSettings_clicked()
{
    __s.setValue("asconnectionstring", ui->leAsConnectionString->text());
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3", "astest");
    db.setDatabaseName(ui->leAsConnectionString->text());
    if (db.open()) {
        message_info("Connection success!");
    } else {
        message_error(db.lastError().databaseText());
    }
    db = QSqlDatabase::addDatabase("QODBC3");
    QSqlDatabase::removeDatabase("astest");
}

void DlgExportAS::recordToMap(QMap<QString, QVariant> &m, QSqlQuery &q, QStringList &fields)
{
    for (int i = 0; i < fields.count(); i++) {
        m[fields[i]] = q.value(i);
    }
}

void DlgExportAS::on_btnUploadInvoices_clicked()
{
    __s.setValue("asvatinv", ui->leVatInvoice->text());
    __s.setValue("asserviceexpenseaccinv", ui->leServiceExpenseAccInvoice->text());
    __s.setValue("asserviceincomeaccinv", ui->leServiceIncomeAccInvoice->text());

    QMap<int, QMap<QString, QVariant> > partnersMap;
    QMap<QString, QMap<QString, QVariant> > servicesMap;
    QMap<QString, QMap<QString, QVariant> > goodsMap;
    QMap<QString, QMap<QString, QVariant> > unitsMap;
    getAsDataMap(partnersMap, servicesMap, goodsMap, unitsMap);
    DoubleDatabase dd(true, false);
    dd[":f_date1"] = ui->deStart->date();
    dd[":f_date2"] = ui->deEnd->date();
    dd.exec("select distinct(f_inv) as f_inv "
            "from m_register m "
            "inner join f_reservation r on r.f_invoice=m.f_inv "
            "where f_wdate between :f_date1 and :f_date2 "
            "and f_source='RV' and f_paymentmode=4 and f_canceled=0");
    QStringList invoices;
    while (dd.nextRow()) {
        invoices.append(dd.getString("f_inv"));
    }
    ui->lbProgress->setText(QString("-"));
    for (int i = 0; i < invoices.count(); i++) {
        exportInvoiceToAs(invoices.at(i), partnersMap, servicesMap, unitsMap, false);
        ui->lbProgress->setText(QString("%1/%2").arg(i + 1).arg(invoices.count()));
    }
    message_info(tr("Done."));
}

void DlgExportAS::on_btnUploadPayments_clicked()
{
    __s.setValue("leExportPaymentAVCredit", ui->leExportPaymentAVCredit->text());
    __s.setValue("leExportPaymentAVDebet", ui->leExportPaymentAVDebet->text());
    __s.setValue("leExportPaymentRVCredit", ui->leExportPaymentRVCredit->text());
    __s.setValue("leExportPaymentRVDebet", ui->leExportPaymentRVDebet->text());

    QSqlDatabase dbas = QSqlDatabase::addDatabase("QODBC3", "asss");
    dbas.setDatabaseName(__s.value("asconnectionstring").toString());
    if (!dbas.open()) {
        message_error(dbas.lastError().databaseText());
        return;
    }
    QSqlQuery q(dbas);
    dbas.transaction();
    QMap<QString, int> asPartnerMap;
    q.exec("select fPARTCODE, fPARTID from PARTNERS");
    while (q.next()) {
        asPartnerMap[q.value(0).toString()] = q.value(1).toInt();
    }

    QMap<int, QString> fpartners;
    DoubleDatabase dbs(true, false);
    dbs.exec("select f_id, f_aspartner from f_room");
    while (dbs.nextRow()) {
        fpartners[dbs.getInt(0)] = dbs.getString(1);
    }
    for (int i = 0, count = ui->deStart->date().daysTo(ui->deEnd->date()) + 1; i < count; i++) {
        QDate wdate = ui->deStart->date().addDays(i);
        double total = 0;
        dbs[":f_wdate"] = wdate;
        dbs.exec("SELECT sum(f_amountamd) FROM m_register WHERE f_canceled=0 and f_creditcard>0 AND f_source IN ('RV', 'AV') and f_wdate=:f_wdate");
        if (dbs.nextRow()) {
            total = dbs.getDouble(0);
        } else {
            continue;
        }

        bool header = false;
        QString docid = QUuid::createUuid().toString().replace("{", "").replace("}", "");
        dbs[":f_wdate"] = wdate;
        dbs.exec("SELECT * FROM m_register WHERE f_canceled=0 and f_creditcard>0 AND f_source IN ('RV', 'AV') and f_wdate=:f_wdate");
        int rowid = 1;
        while (dbs.nextRow()){
            if (!header) {
                header = true;
                if (q.prepare("insert into DOCUMENTS ("
                              "fISN, fDOCTYPE, fDOCSTATE, fDATE, fORDERNUM, fDOCNUM, fCUR, fSUMM, fCOMMENT, fBODY, fPARTNAME, "
                              "fUSERID, fPARTID, fCRPARTID, fMTID, fEXPTYPE, fINVN, fENTRYSTATE, "
                              "fEMPLIDRESPIN, fEMPLIDRESPOUT, fVATTYPE, fSPEC, fCHANGEDATE,fEXTBODY,fETLSTATE) VALUES ("
                              ":fISN, :fDOCTYPE, :fDOCSTATE, '" + wdate.toString("yyyy-MM-dd") + "', "
                              ":fORDERNUM, :fDOCNUM, :fCUR, :fSUMM, :fCOMMENT, :fBODY, :fPARTNAME, "
                              ":fUSERID, :fPARTID, :fCRPARTID, :fMTID, '', :fINVN, :fENTRYSTATE, "
                              ":fEMPLIDRESPIN, :fEMPLIDRESPOUT, :fVATTYPE, :fSPEC, current_timestamp,'', '')") == false) {
                    dbas.rollback();
                    message_error(q.lastError().databaseText());
                    return;
                }
                q.bindValue(":fISN", docid);
                q.bindValue(":fDOCTYPE", 1);
                q.bindValue(":fDOCSTATE", 1);
                q.bindValue(":fORDERNUM", "");
                q.bindValue(":fDOCNUM", "");
                q.bindValue(":fCUR", "AMD");
                q.bindValue(":fSUMM", total);
                q.bindValue(":fCOMMENT", "");
                q.bindValue(":fBODY", "\r\nRATE:1.0000\r\nRATEBASE:1.0000\r\n");
                q.bindValue(":fPARTNAME", ""); // set to kamar
                q.bindValue(":fUSERID", 0);
                q.bindValue(":fPARTID", -1);
                q.bindValue(":fCRPARTID", -1);
                q.bindValue(":fMTID", -1);
                q.bindValue(":fINVN", "");
                q.bindValue(":fENTRYSTATE", 0);
                q.bindValue(":fEMPLIDRESPIN", -1);
                q.bindValue(":fEMPLIDRESPOUT", -1);
                q.bindValue(":fVATTYPE", "2");
                q.bindValue(":fSPEC", "                    00"); // <--- Tax receipt id
                if (!q.exec()) {
                    dbas.rollback();
                    message_error(q.lastError().databaseText());
                    return;
                }
            }
            QString db, cr;
            if (dbs.getString("f_source") == "RV") {
                db = ui->leExportPaymentRVDebet->text();
                cr = ui->leExportPaymentRVCredit->text();
            } else {
                db = ui->leExportPaymentAVDebet->text();
                cr = ui->leExportPaymentAVCredit->text();
            }
            int partner = asPartnerMap[fpartners[dbs.getInt("f_room")]];
            if (partner == 0) {
#ifdef QT_DEBUG
                partner = 100000;
#else
                message_error(tr("Partner code undefined"));
                dbas.rollback();
                return;
#endif
            }
            q.prepare("insert into DRAFTENTRIES ( "
                      "fACCDB, fACCCR, fPARTDBID, fPARTCRID, fCURRCODEDB, fCURRCODECR, fSUMM, "
                      "fCURSUMM, fCOMMENT, fBASE, fOP, fTRANS, "
                      "fANALYTIC1DB, fANALYTIC1CR, fANALYTIC2DB, fANALYTIC2CR) values ("
                      ":fACCDB, :fACCCOR, :fPARTDBID, :fPARTCRID, 'AMD', 'AMD', :fSUMM, "
                      ":fCURSUMM, :fCOMMENT, :fBASE, 'M', :fTRANS, "
                      "'', '', '', '')");
            q.bindValue(":fACCDB", db);
            q.bindValue(":fACCCOR", cr);
            q.bindValue(":fPARTDBID", -1);
            q.bindValue(":fPARTCRID", partner);
            q.bindValue(":fSUMM", dbs.getDouble("f_amountamd"));
            q.bindValue(":fCURSUMM", dbs.getDouble("f_amountamd"));
            q.bindValue(":fBASE", docid);
            q.bindValue(":fCOMMENT", dbs.getString("f_finalname"));
            q.bindValue(":fTRANS", rowid++);
            if (!q.exec()) {
                message_error(q.lastError().databaseText());
                dbas.rollback();
                return;
            }
        }
    }
    dbas.commit();
    message_info(tr("Done."));
}
