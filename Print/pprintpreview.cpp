#include "pprintpreview.h"
#include <QGraphicsPixmapItem>
#include <QPrinterInfo>
#include <QResizeEvent>
#include <QScrollBar>
#include <QShowEvent>
#include "pdefaults.h"
#include "ui_pprintpreview.h"
#include "utils.h"

PPrintPreview::PPrintPreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PPrintPreview)
{
    fScaleFactor = 1.0;
    fPageNumber = 1;
    ui->setupUi(this);
    ui->lePages->setVisible(false);
    ui->gv->horizontalScrollBar()->blockSignals(true);
    ui->gv->verticalScrollBar()->blockSignals(true);
    setPageLayout(QPageLayout::Portrait);
    ui->cbPrinters->addItems(QPrinterInfo::availablePrinterNames());
    ui->cbPrinters->setCurrentIndex(ui->cbPrinters->findText(QPrinterInfo::defaultPrinterName()));
    ui->chCloseAfterPrint->setChecked(__s.value("closeprintpreviewafterprint").toBool());
}

PPrintPreview::~PPrintPreview()
{
    qDeleteAll(fPrintScene);
    delete ui;
}

PPrintScene *PPrintPreview::addScene(int tmpl, QPageLayout::Orientation po)
{
    PPrintScene *ps = nullptr;
    switch (tmpl) {
    case 0:
        ps = new PPrintScene(po, this);
        break;
    case 1:
        ps = new PPrintScene(this);
        break;
    }
    QSize s = po == QPageLayout::Portrait ? sizePortrait : sizeLandscape;
    QSize wSize = s;
    wSize.setWidth(sizePortrait.width() / 3);
    wSize.setHeight(wSize.width());
    QPixmap p = QPixmap("./logo_transp.png");
    QGraphicsPixmapItem *pi = ps->addPixmap(p);
    pi->setPos((s.width() / 2) - (wSize.width() / 2), (s.height() / 2) - (wSize.height() / 2));
    fPrintScene.append(ps);
    return ps;
}

int PPrintPreview::exec(bool noPreview)
{
    if (fPrintScene.count() > 0) {
        setPage();
    }
    ui->cbZoom->setCurrentIndex(4);
    on_cbZoom_currentIndexChanged(4);
    bool multiPage = fPrintScene.count() > 1;
    ui->btnBack->setEnabled(multiPage);
    ui->btnLast->setEnabled(multiPage);
    ui->btnFirst->setEnabled(multiPage);
    ui->btnNext->setEnabled(multiPage);
    if (noPreview) {
        on_btnPrint_clicked();
        return QDialog::Accepted;
    } else {
        return  QDialog::exec();
    }
}

void PPrintPreview::showEvent(QShowEvent *e)
{
    QDialog::showEvent(e);
}

void PPrintPreview::setPage()
{
    ui->lbPage->setText(QString("%1 %2 %3 %4")
                        .arg(tr("Page"))
                        .arg(fPageNumber)
                        .arg(tr("of"))
                        .arg(fPrintScene.count()));
    ui->gv->setScene(fPrintScene.at(fPageNumber - 1));
    ui->btnFirst->setEnabled(fPageNumber > 1);
    ui->btnBack->setEnabled(fPageNumber > 1);
    ui->btnLast->setEnabled(fPageNumber < fPrintScene.count());
    ui->btnNext->setEnabled(fPageNumber < fPrintScene.count());
}

void PPrintPreview::setPageLayout(QPageLayout::Orientation po)
{
    QSize s(po == QPageLayout::Portrait ? sizePortrait : sizeLandscape);
    s.setWidth(s.width() * 1.500);
    s.setHeight(s.height() * 1.500);
    ui->gv->setMinimumSize(s);
    ui->gv->setMaximumSize(s);
}

void PPrintPreview::on_btnPrint_clicked()
{
    QList<int> printPages;
    switch (ui->cbPrintSelection->currentIndex()) {
    case 0:
        for (int i = 0; i < fPrintScene.count(); i++) {
            printPages << i;
        }
        break;
    case 1:
        printPages << fPageNumber - 1;
        break;
    case 2: {
        QStringList p = ui->lePages->text().replace(" ", "").split(",", Qt::SkipEmptyParts);
        foreach (QString s, p) {
            int page = s.toInt() - 1;
            if (page < 0 || page > fPrintScene.count() - 1) {
                continue;
            }
            printPages << page;
        }
        break;
    }
    }

    QPrinter prn;
    prn.setPageSize(QPageSize(QPageSize::A4));

    prn.setPrinterName(ui->cbPrinters->currentText());
    prn.setPageOrientation(fPrintScene.at(printPages.at(0))->fPageLayout);
    QPainter painter(&prn);
    for (int i = 0; i < printPages.count(); i++) {
        if (i > 0) {
            prn.setPageOrientation(fPrintScene.at(printPages.at(i))->fPageLayout);
            prn.newPage();
        }
        fPrintScene.at(printPages.at(i))->render(&painter);
    }
    if (ui->chCloseAfterPrint->isChecked()) {
        accept();
    }
}

void PPrintPreview::on_btnZoomOut_clicked()
{
    if (ui->cbZoom->currentIndex() == ui->cbZoom->count() - 1) {
        return;
    }
    ui->cbZoom->setCurrentIndex(ui->cbZoom->currentIndex() + 1);
}

void PPrintPreview::on_cbZoom_currentIndexChanged(int index)
{
    qreal prevScaleFactor = fScaleFactor;
    fScaleFactor = (index + 1) / 1.5;
    qreal deltaScaleFactor =  prevScaleFactor / fScaleFactor;
    QSize size(fPrintScene.at(fPageNumber - 1)->fPageLayout == QPageLayout::Portrait
                   ? sizePortrait
                   : sizeLandscape);
    size.setWidth((size.width() / fScaleFactor) * 1.500);
    size.setHeight((size.height() / fScaleFactor) * 1.500);
    ui->gv->setMinimumSize(size);
    ui->gv->setMaximumSize(size);
    ui->gv->scale(deltaScaleFactor, deltaScaleFactor);
}

void PPrintPreview::on_btnZoopIn_clicked()
{
    if (ui->cbZoom->currentIndex() == 0) {
        return;
    }
    ui->cbZoom->setCurrentIndex(ui->cbZoom->currentIndex() - 1);
}

void PPrintPreview::on_btnBack_clicked()
{
    if (fPageNumber == 1)
        return;
    fPageNumber--;
    setPage();
}

void PPrintPreview::on_btnNext_clicked()
{
    if (fPageNumber == fPrintScene.count()) {
        return;
    }
    fPageNumber++;
    setPage();
}

void PPrintPreview::on_btnFirst_clicked()
{
    fPageNumber = 1;
    setPage();
}

void PPrintPreview::on_btnLast_clicked()
{
    fPageNumber = fPrintScene.count();
    setPage();
}

void PPrintPreview::on_cbPrintSelection_currentIndexChanged(int index)
{
    ui->lePages->setVisible(index == 2);
}

void PPrintPreview::on_chCloseAfterPrint_clicked(bool checked)
{
    __s.setValue("closeprintpreviewafterprint", checked);
}
