#include "recarclient.h"
#include "ui_recarclient.h"
#include "wreportgrid.h"
#include "cachecar.h"
#include "dlggposorderinfo.h"

#define SEL_CAR 1

RECarClient::RECarClient(QList<QVariant> &values, QWidget *parent) :
    RowEditorDialog(values, TRACK_CAR_CLIENT, parent),
    ui(new Ui::RECarClient)
{
    ui->setupUi(this);
    addWidget(ui->leCode, "Code");
    addWidget(ui->leCarmodel, "Model");
    addWidget(ui->leCargovnumber, "Gov. number");
    addWidget(ui->leCostumer, "Costumer");
    addWidget(ui->leInfo, "Info");
    addWidget(ui->leCardcode, "Card code");
    fTable = "d_car_client";
    //fCacheId = 0;

    ui->leCarmodel->setSelector(this, cache(cid_car), ui->leModel);
}

RECarClient::~RECarClient()
{
    delete ui;
}

void RECarClient::openReport()
{
    QList<int> widths;
    widths << 100
           << 200
           << 100
           << 300
           << 300
           << 150;
    QStringList fields;
    fields << "f_id"
           << "f_model"
           << "f_govNumber"
           << "f_name"
           << "f_info"
           << "f_card";
    QStringList titles;
    titles << tr("Code")
           << tr("Model")
           << tr("Gov. number")
           << tr("Name")
           << tr("Info")
           << tr("Card code");
    QString title = tr("Costumers");
    QString icon = ":/images/car.png";
    QString query = "select f_id, f_model, f_govNumber, f_name, f_info, f_card from d_car_client";
    WReportGrid *r = addTab<WReportGrid>();
    RECarClient *rc = r->fullSetup<RECarClient>(widths, fields, titles, title, icon, query);
    connect(r, SIGNAL(doubleClickOnRow(QList<QVariant>())), rc, SLOT(dobleClickOnRow(QList<QVariant>())));
}

void RECarClient::valuesToWidgets()
{
    RowEditorDialog::valuesToWidgets();
    DoubleDatabase fDD;
    fDD[":f_id"] = ui->leCode->text();
    fDD.exec("select f_mode from d_car_client where f_id=:f_id");
    if (fDD.rowCount() > 0) {
        QStringList s = fDD.getValue("f_mode").toString().split(";");
        switch(s.at(0).toInt()) {
        case 1:
            ui->rbMode1->setChecked(true);
            break;
        case 2:
            ui->rbMode2->setChecked(true);
            break;
        case 3:
            ui->rbMode3->setChecked(true);
            break;
        }
        ui->leVisits->setText(s.at(1));
        ui->leValue->setText(s.at(2));
        ui->leItems->setText(s.at(3));
    }
}

void RECarClient::on_btnSave_clicked()
{
    QString mode;
    if (ui->rbMode1->isChecked()) {
        mode = "1;";
    }  else if (ui->rbMode2->isChecked()) {
        mode = "2;";
    } else if (ui->rbMode3->isChecked()) {
        mode = "3;";
    } else {
        message_error(tr("Mode of discount was not selected"));
        return;
    }
    if (ui->leItems->isEmpty()) {
        ui->leItems->setText("*");
    }
    if (ui->leValue->isEmpty()) {
        ui->leValue->setText("0");
    }
    mode += ui->leVisits->text() + ";";
    mode += ui->leValue->text() + ";";
    mode += ui->leItems->text() + ";";
    if (ui->leCarmodel->asInt() == 0) {
        ui->leCarmodel->setText("0");
    }
    saveOnly();
    DoubleDatabase fDD;
    fDD[":f_mode"] = mode;
    fDD.update("d_car_client", where_id(ui->leCode->asInt()));
    message_info(tr("Saved"));
}

void RECarClient::on_btnReject_clicked()
{
    reject();
}

void RECarClient::doubleClickOnRow(const QList<QVariant> &v)
{
    if (v.count() == 0) {
        return;
    }
    DlgGPOSOrderInfo *d = new DlgGPOSOrderInfo(this);
    d->setOrder(v.at(0).toString());
    d->exec();
    delete d;
}
