#include "dlgcardex.h"
#include "ui_dlgcardex.h"
#include "cachecityledger.h"
#include "cachecardex.h"
#include "cachevatmode.h"
#include "cachecardexgroup.h"

DlgCardex::DlgCardex(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_PARTNERS, parent),
    ui(new Ui::DlgCardex)
{
    ui->setupUi(this);
    ui->leCommision->setValidator(new QDoubleValidator(0, 999, 2));
    ui->leCLCode->setValidator(new QIntValidator());
    ui->leVATModeCode->setValidator(new QIntValidator());
    ui->btnRemove->setVisible(r__(cr__remove_cardex));
    addWidget(ui->leCode, "Code");
    addWidget(ui->leCardexGroupName, "Group");
    addWidget(ui->leCardexGroupCode, "");
    addWidget(ui->leCardex, "Cardex");
    addWidget(ui->leCLCode, "CityLedger");
    addWidget(ui->leName, "Name");
    addWidget(ui->leAddr1, "Addr1");
    addWidget(ui->leAddr2, "Addr2");
    addWidget(ui->leContact, "Contact");
    addWidget(ui->leContactPos, "Position");
    addWidget(ui->leEmail, "Email");
    addWidget(ui->leTel, "Tel");
    addWidget(ui->leFax, "Fax");
    addWidget(ui->deValidFrom, "Valid from");
    addWidget(ui->deValidTo, "Valid to");
    addWidget(ui->leCommision, "Commission");
    addWidget(ui->leVATModeCode, "");
    addWidget(ui->leVATModeName, "VAT");
    addWidget(ui->chBookingRequire, "Require booking");
    addWidget(ui->leExtra1, "Extra1");
    addWidget(ui->leExtra2, "Extra2");
    fTable = "f_cardex";
    ui->leVATModeCode->setSelector(this, cache(cid_vat_mode), ui->leVATModeName);
    ui->leVATModeCode->setInitialValue(VAT_INCLUDED);
    ui->leCardexGroupCode->setSelector(this, cache(cid_cardex_group), ui->leCardexGroupName);
}

DlgCardex::~DlgCardex()
{
    delete ui;
}

bool DlgCardex::isDataCorrect()
{
    DoubleDatabase fDD;
    fDD[":f_cardex"] = ui->leCardex->text();
    fDD.exec("select f_id from f_cardex where f_cardex=:f_cardex");
    if (fDD.nextRow()) {
        if (fDD.getInt(0) != ui->leCode->asInt()) {
            fDataErrors.append(tr("This cardex already exists"));
        }
    }
    if (ui->leVATModeCode->asInt() == 0) {
        fDataErrors.append(tr(""));
    }
    return fDataErrors.count() == 0;
}

void DlgCardex::setValues()
{
    RowEditorDialog::setValues();
    if (isNew) {
        ui->leVATModeCode->setInitialValue(VAT_INCLUDED);
        ui->deValidTo->setDate(QDate::currentDate().addDays(365));
    }
}

void DlgCardex::on_btnCancel_clicked()
{
    reject();
}

void DlgCardex::on_btnOk_clicked()
{
    DoubleDatabase fDD;
    DoubleDatabase did;
    did.open();
    if (ui->leCardexGroupCode->isEmpty()) {
        message_error(tr("Cardex group is not selected"));
        return;
    }
    if (ui->leVATModeCode->asInt() == 0) {
        message_error(tr("VAT mode is not selected"));
        return;
    }
    if (ui->chCityLedger->isChecked()) {
        fDD[":f_name"] = ui->leName->text();
        fDD[":f_address"] = ui->leAddr1->text();
        fDD[":f_phone"] = ui->leTel->text();
        fDD[":f_email"] = ui->leEmail->text();
        fDD[":f_extra1"] = ui->leExtra1->text();
        fDD[":f_extra2"] = ui->leExtra2->text();
        ui->leCLCode->setInt(did.insert("f_city_ledger"));
        fDD.update("f_city_ledger", where_id(ui->leCLCode->text()));
    }
    int groupMax = 0;
    if (isNew) {
        fDD[":f_id"] = ui->leCardexGroupCode->asInt();
        fDD.exec("select f_max from f_cardex_group where f_id=:f_id");
        if (fDD.nextRow()) {
            groupMax = fDD.getInt(0);
            ui->leCardex->setText(QString("%1%2").arg(ui->leCardexGroupName->text()).arg(groupMax, 3, 10, QChar('0')));
        }
        if (groupMax > 0) {
            fDD[":f_max"] = groupMax + 1;
            fDD.update("f_cardex_group", where_id(ui->leCardexGroupCode->asInt()));
        } else {
            message_error(tr("Application error. Contact to developer. Message: cardex group max = 0"));
        }
    }
    if (ui->leCode->asInt() == 0) {
        fDD[":f_id"] = 0;
        fDD[":f_cardex"] = ui->leCardex->text();
        ui->leCode->setInt(fDD.insert("f_cardex", true));
    }
    save();
    BroadcastThread::cmdRefreshCache(cid_city_ledger, ui->leCLCode->text());
    BroadcastThread::cmdRefreshCache(cid_cardex, ui->leCardex->text());
}

void DlgCardex::on_btnRemove_clicked()
{
    DoubleDatabase fDD;
    if (message_confirm(tr("Confirm to delete")) != QDialog::Accepted) {
        return;
    }
    fDD[":f_cardex"] = ui->leCardex->text();
    fDD.exec("select count(f_id) from f_reservation where f_cardex=:f_cardex");
    if (fDD.nextRow()) {
        if (fDD.getInt(0) > 0) {
            message_info(tr("This cardex in use and cannot be deleted"));
            return;
        }
    }
    fDD[":f_cardex"] = ui->leCardex->text();
    fDD.exec("delete from f_cardex where f_cardex=:f_cardex");
    message_info(tr("Deleted"));
    accept();
}
