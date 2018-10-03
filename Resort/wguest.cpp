#include "wguest.h"
#include "ui_wguest.h"
#include "cacheguest.h"
#include "cacheguesttitle.h"
#include "cachenation.h"

WGuest::WGuest(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_GUEST, parent),
    ui(new Ui::WGuest)
{
    ui->setupUi(this);
    ui->btnRemove->setVisible(r__(cr__super_correction));

    ui->leTitle->setSelector(this, cache(cid_guest_title), ui->leTitle);
    ui->leNationalityCode->setSelector(this, cache(cid_nation), ui->leNationality);

    addWidget(ui->leGuestCode, "Code")
            .addWidget(ui->leTitle, "Title")
            .addWidget(ui->leFirstname, "First name")
            .addWidget(ui->leLastname, "Last name")
            .addWidget(ui->cbSex, "Sex")
            .addWidget(ui->deBirth, "Birth date")
            .addWidget(ui->lePlaceBirth, "Place of birth")
            .addWidget(ui->leNationalityCode, "")
            .addWidget(ui->leNationality, "Nationality")
            .addWidget(ui->lePassport, "Passport")
            .addWidget(ui->leAddress, "Address")
            .addWidget(ui->leTel1, "Tel.1")
            .addWidget(ui->leTel2, "Tel.2")
            .addWidget(ui->leEmail, "Email")
            .addWidget(ui->lePostBox, "Postbox")
            .addWidget(ui->teRemarks, "Remarks");
    fTable = "f_guests";
    fCacheId = cid_guest;
}

WGuest::~WGuest()
{
    delete ui;
}


WGuest *WGuest::guest(QList<QVariant> &values, bool noCheckNation)
{
    WGuest *w = new WGuest(values, fPreferences.getDefaultParentForMessage());
    w->fNoCheckNation = noCheckNation;
    return w;
}

void WGuest::on_btnCancel_clicked()
{
    reject();
}

void WGuest::on_btnOk_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
    if (!ui->lePassport->isEmpty()) {
        fDD[":f_passport"] = ui->lePassport->text();
        fDD.exec("select f_id from f_guests where f_passport=:f_passport");
        if (fDD.nextRow()) {
            if (ui->leGuestCode->asInt() == 0) {
                message_error(tr("Duplicate passport record, the guest exists"));
                return;
            }
            if (fDD.getInt(0) != ui->leGuestCode->asInt()) {
                message_error(tr("Duplicate passport record, the guest exists"));
                return;
            }
        }
    }
    if (!fNoCheckNation) {
        CacheNation n;
        if (!n.get(ui->leNationalityCode->text())) {
            message_error(tr("Nationality not selected"));
            return;
        }
        if (n.fName() == "-") {
            message_error(tr("Nationality not selected"));
            return;
        }
    }

    save();
}

void WGuest::on_btnRemove_clicked()
{
    DoubleDatabase fDD(true, doubleDatabase);
    if (ui->leGuestCode->asInt() == 0) {
        return;
    }
    fDD[":f_guest"] = ui->leGuestCode->asInt();
    fDD.exec("select f_id from f_reservation_guests where f_guest=:f_guest");
    if (fDD.rowCount() > 0) {
        message_error(tr("Cannot remove this guest. Name in use"));
        return;
    }
    fDD[":f_id"] = ui->leGuestCode->asInt();
    fDD.exec("delete from f_guests where f_id=:f_id");
    BroadcastThread::cmdRefreshCache(cid_guest, ui->leGuestCode->text());
    fTrackControl->insert("Guest removed", ui->leGuestCode->text() + " " + ui->leFirstname->text() + " " + ui->leLastname->text(), "");
    fTrackControl->saveChanges();
    message_info(tr("Guest was removed"));
    reject();
}
