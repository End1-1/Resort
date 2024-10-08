#include "renationalityfile.h"
#include "ui_renationalityfile.h"
#include "wreportgrid.h"
#include "cachenation.h"

RENationalityFile::RENationalityFile(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_NATIONALITY_FILE, parent),
    ui(new Ui::RENationalityFile)
{
    ui->setupUi(this);
    addWidget(ui->leCode, "Code");
    addWidget(ui->leShort, "Short");
    addWidget(ui->leName, "Name");
    fTable = "f_nationality";
    fCacheId = cid_nation;
}

RENationalityFile::~RENationalityFile()
{
    delete ui;
}

void RENationalityFile::openEditor()
{
    QList<int> widths;
    widths << 100
           << 100
           << 100;
    QStringList fields;
    fields << "f_id"
           << "f_short"
           << "f_name";
    QStringList titles;
    titles << tr("Code")
           << tr("Short")
           << tr("Name");
    QString title = tr("Nationality file");
    QString icon = ":/images/guests.png";
    QString query = "select f_id, f_short, f_name from f_nationality";
    WReportGrid *r = addTab<WReportGrid>();
    r->fullSetup<RENationalityFile>(widths, fields, titles, title, icon, query);
}

void RENationalityFile::on_btnCancel_clicked()
{
    reject();
}

void RENationalityFile::on_btnSave_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_short"] = ui->leShort->text();
    fDD.exec("select f_id from f_nationality where f_short=:f_short");
    QString err;
    if (fDD.nextRow()) {
        if (ui->leCode->asInt() > 0) {
            if (ui->leCode->asInt() != fDD.getInt(0)) {
                err += tr("Nationality short name exists") + "<br>";
            }
        } else {
            err += tr("Nationality short name exists") + "<br>";
        }
    }
    if (ui->leName->isEmpty()) {
        err += tr("Naionality name is empty") + "<br>";
    }
    if (ui->leShort->isEmpty()) {
        err += tr("Naionality short name is empty")  + "<br>";
    }
    if (err.length() > 0) {
        message_error(err);
        return;
    }
    save();
}
