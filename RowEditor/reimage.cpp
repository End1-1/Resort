#include "reimage.h"
#include "ui_reimage.h"
#include "appimages.h"
#include "message.h"
#include "preferences.h"

#include <QFile>
#include <QFileDialog>
#include <QPixmap>

REImage::REImage(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_COMMON, parent),
    ui(new Ui::REImage)
{
    ui->setupUi(this);
    fTable = "f_images";
    ui->cbPurpose->addItem(tr("Report logo"), AppImages::PurposeReportLogo);
    ui->cbPurpose->addItem(tr("Welcome logo"), AppImages::PurposeWelcomeLogo);
    addWidget(ui->leCode, "Code")
            .addWidget(ui->cbPurpose, "Purpose")
            .addWidget(ui->leVersion, "Version");
}

REImage::~REImage()
{
    delete ui;
}

void REImage::setValues()
{
    RowEditorDialog::setValues();
    fImageData.clear();
    loadPreviewFromCacheOrDb();
    showPreview();
    const bool canEdit = (WORKING_USERGROUP == 1);
    ui->btnOk->setEnabled(canEdit);
    ui->btnLoad->setEnabled(canEdit);
    ui->btnRemove->setEnabled(canEdit && ui->leCode->asInt() > 0);
    ui->cbPurpose->setEnabled(canEdit && isNew);
    if (!canEdit) {
        setWindowTitle(tr("Image (read only)"));
    }
}

void REImage::showPreview()
{
    if (fImageData.isEmpty()) {
        ui->lbPreview->setPixmap(QPixmap());
        ui->lbPreview->setText(tr("No image"));
        return;
    }
    QPixmap px;
    if (!px.loadFromData(fImageData)) {
        ui->lbPreview->setText(tr("Cannot load image"));
        return;
    }
    ui->lbPreview->setText(QString());
    ui->lbPreview->setPixmap(px.scaled(ui->lbPreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void REImage::loadPreviewFromCacheOrDb()
{
    const int purpose = ui->cbPurpose->currentData().toInt();
    if (purpose <= 0) {
        return;
    }
    const QString path = AppImages::localPath(purpose);
    QFile f(path);
    if (f.exists() && f.open(QIODevice::ReadOnly)) {
        fImageData = f.readAll();
        f.close();
        if (!fImageData.isEmpty()) {
            return;
        }
    }
    DoubleDatabase db;
    fImageData = AppImages::loadFromDb(db, purpose);
}

void REImage::on_btnCancel_clicked()
{
    reject();
}

void REImage::on_btnLoad_clicked()
{
    if (WORKING_USERGROUP != 1) {
        message_error(tr("Access denied"));
        return;
    }
    const QString fileName = QFileDialog::getOpenFileName(
                this, tr("Open image"), QString(),
                tr("Images (*.png *.jpg *.jpeg *.bmp *.gif);;All files (*.*)"));
    if (fileName.isEmpty()) {
        return;
    }
    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly)) {
        message_error(tr("Cannot open file"));
        return;
    }
    fImageData = f.readAll();
    f.close();
    showPreview();
}

void REImage::on_btnOk_clicked()
{
    if (WORKING_USERGROUP != 1) {
        message_error(tr("Access denied"));
        return;
    }
    if (fImageData.isEmpty()) {
        message_error(tr("Load an image first"));
        return;
    }
    const int purpose = ui->cbPurpose->currentData().toInt();
    if (purpose != AppImages::PurposeReportLogo && purpose != AppImages::PurposeWelcomeLogo) {
        message_error(tr("Select purpose"));
        return;
    }

    DoubleDatabase db;
    if (isNew) {
        db[":f_purpose"] = purpose;
        if (db.exec("select f_id from f_images where f_purpose=:f_purpose") && db.nextRow()) {
            if (message_confirm(tr("Image for this purpose already exists. Replace?")) != RESULT_YES) {
                return;
            }
        }
    }

    QString err;
    const int id = AppImages::saveToDb(db, purpose, fImageData, &err);
    if (id == 0) {
        message_error(err.isEmpty() ? tr("Save failed") : err);
        return;
    }
    ui->leCode->setText(QString::number(id));
    ui->leVersion->setText(QString::number(AppImages::localVersion(purpose)));
    widgetsToValues();
    accept();
}

void REImage::on_btnRemove_clicked()
{
    if (WORKING_USERGROUP != 1) {
        message_error(tr("Access denied"));
        return;
    }
    if (ui->leCode->asInt() == 0) {
        reject();
        return;
    }
    if (message_yesnocancel(tr("Are you sure to delete this image?")) != RESULT_YES) {
        return;
    }
    const int purpose = ui->cbPurpose->currentData().toInt();
    DoubleDatabase db;
    db[":f_id"] = ui->leCode->asInt();
    if (!db.exec("delete from f_images where f_id=:f_id")) {
        message_error(db.fLastError);
        return;
    }
    QFile::remove(AppImages::localPath(purpose));
    AppImages::setLocalVersion(purpose, 0);
    accept();
    message_info(tr("Image removed, refresh the report"));
}
