#include "dlghdmviewer.h"
#include "ui_dlghdmviewer.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLocale>

#define float_str(value, f) \
    QLocale() \
        .toString(value, 'f', f) \
        .remove(QRegularExpression("(?!\\d[\\.\\,][1-9]+)0+$")) \
        .remove(QRegularExpression("[\\.\\,]$"))

DlgHDMViewer::DlgHDMViewer(const QString &fiscal, const QString &jsonText, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgHDMViewer)
{
    ui->setupUi(this);
    QJsonObject jo = QJsonDocument::fromJson(jsonText.toUtf8()).object();
    ui->leFiscal->setText(fiscal);
    ui->leAmountCash->setText(float_str(jo["paidAmount"].toDouble(), 2));
    ui->leAmountCard->setText(float_str(jo["paidAmountCard"].toDouble(), 2));
    ui->leAmountPrepaid->setText(float_str(jo["prePaymentAmount"].toDouble(), 2));
    QJsonArray ja = jo["items"].toArray();
    for (int i = 0; i < ja.count(); i++) {
        QJsonObject ji = ja[i].toObject();
        int r = ui->tbl->rowCount();
        ui->tbl->setRowCount(r + 1);
        ui->tbl->setItem(r, 0, new QTableWidgetItem(ji["productCode"].toString()));
        ui->tbl->setItem(r, 1, new QTableWidgetItem(ji["adgCode"].toString()));
        ui->tbl->setItem(r, 2, new QTableWidgetItem(ji["productName"].toString()));
        ui->tbl->setItem(r, 3, new QTableWidgetItem(float_str(ji["qty"].toDouble(), 2)));
        ui->tbl->setItem(r, 4, new QTableWidgetItem(ji["unit"].toString()));
        ui->tbl->setItem(r, 5, new QTableWidgetItem(float_str(ji["totalPrice"].toDouble() / ji["qt"].toDouble(), 2)));
        ui->tbl->setItem(r, 6, new QTableWidgetItem(float_str(ji["totalPrice"].toDouble(), 2)));
        ui->tbl->setItem(r, 7, new QTableWidgetItem(ji["dep"].toString()));
    }
    ui->tbl->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

DlgHDMViewer::~DlgHDMViewer()
{
    delete ui;
}
