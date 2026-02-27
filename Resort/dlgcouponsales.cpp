#include "dlgcouponsales.h"
#include "ui_dlgcouponsales.h"
#include "cachestorepartners.h"
#include "cachecouponseria.h"

static const int SEL_PARTNER = 1;
static const int HINT_COUPON = 2;

DlgCouponSales::DlgCouponSales(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgCouponSales)
{
    ui->setupUi(this);
    ui->lePartnerCode->setSelector(this, cache(cid_store_partners), ui->lePartnerName);
    ui->leSeriaNum->setSelector(this, cache(cid_coupon_seria), ui->leSeraiName, HINT_COUPON);
}

DlgCouponSales::~DlgCouponSales()
{
    delete ui;
}


void DlgCouponSales::sale()
{
    DlgCouponSales *d = new DlgCouponSales(fPreferences.getDefaultParentForMessage());
    d->exec();
    delete d;
}

void DlgCouponSales::on_btnCancel_clicked()
{
    reject();
}

void DlgCouponSales::on_btnSave_clicked()
{
    if (ui->leSeriaNum->asInt() == 0) {
        message_error(tr("Coupon seria is not defined"));
        return;
    }
    if (ui->leQty->asInt() == 0) {
        message_error(tr("Coupon count must be greater than 0"));
        return;
    }
    if (ui->lePartnerCode->asInt() == 0) {
        message_error(tr("Partner is not defined"));
        return;
    }

    DoubleDatabase fDD;
    fDD[":f_seria"] = ui->leSeriaNum->asInt();
    fDD.exec("select f_id from d_coupon where f_seria=:f_seria and (f_partner=0 or f_partner is null) and f_used=0");
    if (fDD.rowCount() < ui->leQty->asInt()) {
        message_error(tr("No enough coupons avaiable"));
        return;
    }

    if (ui->leCode->asInt() == 0) {
        fDD[":f_id"] = 0;
        ui->leCode->setInt(fDD.insert("d_coupon_sale"));
    } else {
        message_error(tr("This sale cannot be saved"));
        return;
    }

    for (int i = 0; i < fDD.rowCount(); i++) {
        fDD[":f_id"] = fDD.getValue(i, "f_id");
        fDD[":f_partner"] = ui->lePartnerCode->asInt();
        fDD.exec("update d_coupon set f_partner=:f_partner where f_id=:f_id");
        fDD[":f_doc"] = ui->leCode->asInt();
        fDD[":f_coupon"] = fDD.getValue(i, "f_id");
        fDD.insert("d_coupon_sale_member");
        if (i == ui->leQty->asInt() - 1) {
            break;
        }
    }

    fDD[":f_date"] = ui->deDate->date();
    fDD[":f_partner"] = ui->lePartnerCode->asInt();
    fDD[":f_payment"] = ui->cbPayment->currentData();
    fDD[":f_seria"] = ui->leSeriaNum->asInt();
    fDD[":f_qty"] = ui->leQty->asInt();
    fDD[":f_amount"] = ui->leAmount->asDouble();
    fDD.update("d_coupon_sale", where_id(ui->leCode->asInt()));

    message_info(tr("Saved"));
}

void DlgCouponSales::on_leQty_textChanged(const QString &arg1)
{
    CacheCouponSeria ci;
    if (!ci.get(ui->leSeriaNum->text())) {
        ui->leAmount->setDouble(0);
        return;
    }
    ui->leAmount->setDouble(arg1.toDouble() * ci.fPrice());
}
