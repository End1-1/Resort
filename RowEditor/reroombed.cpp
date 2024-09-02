#include "reroombed.h"
#include "ui_reroombed.h"

RERoomBed::RERoomBed(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_ROOM_BED, parent),
    ui(new Ui::RERoomBed)
{
    ui->setupUi(this);
    addWidget(ui->leCode, "Code");
    addWidget(ui->leName, "Name");
    fTable = "f_room_bed";
}

RERoomBed::~RERoomBed()
{
    delete ui;
}

void RERoomBed::on_btnCancel_clicked()
{
    reject();
}

void RERoomBed::on_btnOk_clicked()
{
    DoubleDatabase fDD;
    fDD[":f_id"] = ui->leCode->text();
    fDD[":f_name"] = ui->leName->text();
    if (isNew) {
        fDD.insert("f_room_bed");
    } else {
        fDD.update("f_room_bed", where_id(ap(fTrackControl->oldValue(ui->leCode))));
    }
    fTrackControl->saveChanges();  //TODO tracking by qstring
    accept();
}

void RERoomBed::valuesToWidgets()
{
    RowEditorDialog::valuesToWidgets();
    fTrackControl->resetChanges();
}
