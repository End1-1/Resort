#include "wguest.h"
#include "ui_wguest.h"
#include "cacheguest.h"
#include "cacheguesttitle.h"
#include "cachenation.h"
#include <QInputDialog>

WGuest::WGuest(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_GUEST, parent),
    ui(new Ui::WGuest)
{
    ui->setupUi(this);
    ui->btnRemove->setVisible(r__(cr__super_correction));
    ui->leTitle->setSelector(this, cache(cid_guest_title), ui->leTitle);
    ui->leNationalityCode->setSelector(this, cache(cid_nation), ui->leNationality);
    ui->cbSex->setCurrentIndex(-1);
    ui->deBirth->clear();
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

void WGuest::setValues()
{
    RowEditorDialog::setValues();
    if (fValues.count()) {
        ui->leTitle->setInitialValue(fValues.at(1).toString());
    }
}

WGuest *WGuest::guest(QList<QVariant> &values, bool noCheckNation, bool fromReader)
{
    WGuest *w = new WGuest(values, fPreferences.getDefaultParentForMessage());
    w->fFromReaderFlag = fromReader;
    w->fNoCheckNation = noCheckNation;
    if (fromReader) {
        w->on_btnReadFromDevice_clicked();
    }
    return w;
}

void WGuest::on_btnCancel_clicked()
{
    reject();
}

void WGuest::on_btnOk_clicked()
{
    DoubleDatabase fDD;
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
    DoubleDatabase fDD;
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
    fTrackControl->insert("Guest removed",
                          ui->leGuestCode->text() + " " + ui->leFirstname->text() + " " + ui->leLastname->text(), "");
    fTrackControl->saveChanges();
    message_info(tr("Guest was removed"));
    reject();
}

void WGuest::on_btnReadFromDevice_clicked()
{
    QString src = QInputDialog::getText(this, tr("Guest info"), tr("Read from device"));
    if (src.isEmpty()) {
        return;
    }
    QString docType = src.mid(0, 2);
    QString country = src.mid(2, 3);
    QString rawName = src.mid(5, 39);
    QString rawDocNum = src.mid(44, 9);
    QString nat = src.mid(54, 3);
    if (country == "D<<") {
        country = "DEU";
    }
    QString dobRaw = src.mid(57, 6);
    QStringList names = rawName.split("<<", Qt::SkipEmptyParts);
    QString year = dobRaw.mid(0, 2);
    QString month = dobRaw.mid(2, 2);
    QString day = dobRaw.mid(4, 2);
    QString sex = src.mid(64, 1);
    QString currYear = QDate::currentDate().toString("yyyy.DD.mm").mid(2, 2);
    if (year.toInt() > currYear.toInt()) {
        year = "19" + year;
    } else {
        year = "20" + year;
    }
    ui->deBirth->setDate(QDate::fromString(QString("%1/%2/%3").arg(day, month, year), "dd/MM/yyyy"));
    DoubleDatabase dd;
    dd[":f_alpha3"] = country;
    dd.exec("select f_short from f_nationality where f_alpha3=:f_alpha3");
    if (dd.nextRow() == false) {
        message_error(tr("Invalid nationality code") + "<br>" + country);
        return;
    }
    ui->leNationalityCode->setInitialValue(dd.getString("f_short"));
    ui->lePassport->setText(rawDocNum);
    if (names.count() > 0) {
        if (names.at(0).contains("<")) {
            QStringList fnames = names.at(0).split("<", Qt::SkipEmptyParts);
            ui->leLastname->setText(fnames.join(" "));
        } else {
            ui->leLastname->setText(names.at(0));
        }
        if (names.count() > 1) {
            if (names.at(1).contains("<")) {
                names = names.at(1).split("<", Qt::SkipEmptyParts);
                ui->leFirstname->setText(names.join(" "));
            } else {
                ui->leFirstname->setText(names.at(1));
                if (names.count() > 2) {
                    if (names.at(2).contains("<")) {
                    } else {
                        ui->leFirstname->setText(ui->leFirstname->text() + " " + names.at(2));
                    }
                }
            }
        }
    }
    ui->cbSex->setCurrentIndex(sex.toUpper() == "M" ? 0 : 1);
    ui->leTitle->setInitialValue(sex.toUpper() == "M" ? "MR." : "MRS.");
    if (fFromReaderFlag) {
        on_btnOk_clicked();
    }
}
