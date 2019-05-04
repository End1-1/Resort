#include "dlgprintvoucherasinvoice.h"
#include "ui_dlgprintvoucherasinvoice.h"
#include "message.h"
#include "dlgseachfromdatabase.h"
#include "pprintpreview.h"
#include "ptextrect.h"
#include "paymentmode.h"
#include "cachevatmode.h"
#include "pimage.h"

DlgPrintVoucherAsInvoice::DlgPrintVoucherAsInvoice(QWidget *parent) :
    BaseWidget (parent),
    ui(new Ui::DlgPrintVoucherAsInvoice)
{
    ui->setupUi(this);
    ui->tblTotal->addRow();
    Utils::tableSetColumnWidths(ui->tbl, ui->tbl->columnCount(), 100, 100, 300, 100, 100, 200, 0);
    Utils::tableSetColumnWidths(ui->tblTotal, ui->tblTotal->columnCount(), 100, 100, 300, 100, 100, 100, 200, 0);
}

DlgPrintVoucherAsInvoice::~DlgPrintVoucherAsInvoice()
{
    delete ui;
}

void DlgPrintVoucherAsInvoice::setup()
{
    setupTabTextAndIcon(tr("Voucher invoice"), ":/images/invoice.png");
}

void DlgPrintVoucherAsInvoice::addVoucher(const QString &id)
{
    DoubleDatabase dd(true, false);
    dd[":f_id"] = id;
    dd.exec("select m.f_id, m.f_wdate, m.f_finalname, m.f_amountamd, cl.f_name, m.f_sign, pm.f_en, m.f_remarks, m.f_paymentMode "
            "from m_register m "
            "left join f_city_ledger cl on cl.f_id=m.f_cityledger "
            "left join f_payment_type pm on pm.f_id=m.f_paymentmode "
            " where m.f_id=:f_id");
    if (dd.nextRow()) {
        addRow(dd.fDbRows.at(0));
        countTotal();
    } else {
        message_error(tr("Incorrect voucher id") + "<BR>" + id);
    }
}

void DlgPrintVoucherAsInvoice::on_btnPrint_clicked()
{
    on_btnSave_clicked();

    int vatMode = 1;
    CacheVatMode cv;
    if (!cv.get(1)) {
        message_error(tr("Couild not get mode of VAT "));
        return;
    }
    PPrintPreview *pp = new PPrintPreview(this);
    PPrintScene *ps = pp->addScene(0, Portrait);
    QString invHeader = tr("SETTLEMENT / TAX INVOICE");
    PTextRect *trHeader = new PTextRect(20, 20, 2100, 200, invHeader, nullptr, QFont(qApp->font().family(), 50));
    trHeader->setBorders(false, false, false, false);
    trHeader->setTextAlignment(Qt::AlignHCenter);
    QString inv = QString("%1 #%2").arg(tr("S/N")).arg(ui->leInvoice->text());

    PTextRect *trInvoice = new PTextRect(20, trHeader->textHeight(), 2100, 80, inv, nullptr, QFont(qApp->font().family(), 30, 75));
    trInvoice->setTextAlignment(Qt::AlignHCenter);
    trInvoice->setBorders(false, false, false, false);
    PTextRect *trInfo = new PTextRect(1500, 20, 600, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
                                      nullptr, QFont(qApp->font().family(), 25));
    trInfo->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
    trInfo->setWrapMode(QTextOption::WordWrap);
    trInfo->setBorders(false, false, false, false);
    ps->addItem(trInfo);
    ps->addItem(trInvoice);
    ps->addItem(trHeader);
    PImage *logo = new PImage("logo_print.png");
    ps->addItem(logo);
    logo->setRect(QRectF(20, 10, 500, 300));
    PTextRect th;
    th.setBorders(false, false, false, false);
    QPen pline(Qt::SolidLine);
    pline.setWidth(3);
    QFont f(qApp->font().family(), 25);
    f.setBold(true);
    th.setFont(f);
    th.setRectPen(pline);
    int top = 310;
    int rowHeight = 60;
    //table header
    th.setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    th.setBorders(true, true, true, true);
    th.setBrush(QBrush(QColor::fromRgb(215, 215, 215), Qt::SolidPattern));
    PTextRect *r = ps->addTextRect(new PTextRect(20, top, 60, rowHeight * 2, tr("*"), &th, f));
    ps->addTextRect(new PTextRect(80, top, 200, rowHeight * 2, tr("Date"), &th, f));
    ps->addTextRect(new PTextRect(250, top, 850, rowHeight * 2, tr("Description"), &th, f));
    ps->addTextRect(new PTextRect(1100, top, 100, rowHeight * 2, tr("Cur"), &th, f));
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight * 2, tr("Debit\n") + " " + cv.fName(), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight * 2, tr("Credit"), &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight * 2, tr("Balance"), &th, f));
    //table data
    f.setBold(false);
    f.setPointSize(f.pointSize() - 2);
    th.setFont(f);
    top += (rowHeight * 2);
    th.setTextAlignment(Qt::AlignLeft);
    th.setWrapMode(QTextOption::NoWrap);
    th.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    int rowNum = 1;
    double lastBalance = 0;
    double totalVat = 0;
    double totalCredit = 0;
    double totalDebet = 0;
    double totalCash = 0;
    double totalCard = 0;
    double totalOther = 0;
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        double debet, credit;
        if (ui->tbl->toDouble(i, 3) > 0) {
            f.setBold(false);
            th.setFont(f);
            debet = ui->tbl->toDouble(i, 3);
            credit = 0;
        } else {
            f.setBold(true);
            th.setFont(f);
            debet = 0;
            credit = ui->tbl->toDouble(i, 4);
        }

        ps->addTextRect(new PTextRect(20, top, 60, rowHeight, QString::number(rowNum++), &th, f));
        ps->addTextRect(new PTextRect(80, top, 200, rowHeight, ui->deDate->text(), &th, f));
        ps->addTextRect(new PTextRect(250, top, 850, rowHeight, ui->tbl->toString(i, 2) + " " + ui->tbl->toString(i, 6), &th, f));
        ps->addTextRect(new PTextRect(1100, top, 100, rowHeight, "AMD", &th, f));

        switch (ui->tbl->toInt(i, 7)) {
        case PAYMENT_CARD:
            totalCard += credit;
            break;
        case PAYMENT_CASH:
            totalCash += credit;
            break;
        default:
            totalOther += credit;
            break;
        }

        totalVat += ui->tblTotal->toDouble(0, 3) / 1.1; //???????????????????????
        totalCredit += credit;
        totalDebet += debet;
        lastBalance -= -1 * ((debet) - credit);
        ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(debet), &th, f));
        ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_printout(credit), &th, f));
        ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_printout(lastBalance), &th, f));
        top += rowHeight;
        if (top > 2800) {
            top = 30;
            ps = pp->addScene(0, Portrait);
        }
    }
    top += (rowHeight / 2);
    f.setBold(true);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total amount"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(totalDebet), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_printout(totalCredit), &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_printout(lastBalance), &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;

        ps = pp->addScene(0, Portrait);
    }
    f.setBold(false);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total cash"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(totalCash), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, "", &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }

    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total cashless"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(totalCard + totalOther), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, "", &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }

    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Being the equivalent of USD"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_printout(totalDebet / def_usd), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_printout(totalCredit / def_usd), &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_printout(lastBalance / def_usd), &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }
    th.setTextAlignment(Qt::AlignRight);
    if (vatMode == VAT_INCLUDED) {
        ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("VAT 20%"), &th, f));
        th.setTextAlignment(Qt::AlignLeft);
        ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, "", &th, f));
        ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_printout(totalVat), &th, f));
        ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    }
    top += rowHeight;
    top += rowHeight;
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }
    th.setBorders(false, false, false, false);
    f.setBold(true);
    th.setFont(f);
    QPen boldPen;
    boldPen.setWidth(4);
    r = ps->addTextRect(new PTextRect(20, top, 400, rowHeight, tr("Guest signature"), &th, f));
    ps->addLine(400, top + r->textHeight(), 1000, top + r->textHeight(), boldPen);
    top += r->textHeight();
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }
    f.setBold(false);
    th.setFont(f);
    r = ps->addTextRect(new PTextRect(20, top, 2000, rowHeight, tr("The sum of only ") + Utils::numberToWords(totalCredit), &th, f));
    top += r->textHeight();
    top += r->textHeight();
    top += r->textHeight();
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0, Portrait);
    }
    f.setPointSize(f.pointSize() - 6);
    th.setFont(f);
    th.setWrapMode(QTextOption::WordWrap);
    ps->addTextRect(new PTextRect(20, top, 2000, rowHeight * 3, fPreferences.getDb(def_vouchers_invoice_footer).toString(), &th, f));
    TrackControl tc(0);
    tc.insert("Print invoice request", ui->leInvoice->text(), "");
    pp->exec();
    delete pp;
}

void DlgPrintVoucherAsInvoice::countTotal()
{
    ui->tblTotal->setItemWithValue(0, 3, ui->tbl->sumOfColumn(3));
    ui->tblTotal->setItemWithValue(0, 4, ui->tbl->sumOfColumn(4));
    ui->tblTotal->setItemWithValue(0, 5, ui->tblTotal->toDouble(0, 3) - ui->tblTotal->toDouble(0, 4));
}

void DlgPrintVoucherAsInvoice::addRow(const QList<QVariant> &v)
{
    if (v.at(5).toInt() == 0) {
        message_error(tr("This is not valid finance voucher"));
        return;
    }
    int row = ui->tbl->addRow();
    ui->tbl->setItemWithValue(row, 0, v.at(0));
    ui->tbl->setItemWithValue(row, 1, v.at(1));
    ui->tbl->setItemWithValue(row, 2, v.at(2));
    switch (v.at(5).toInt()) {
    case -1:
        ui->tbl->setItemWithValue(row, 3,v.at(3));
        ui->tbl->setItemWithValue(row, 4, 0);
        break;
    case 1:
        ui->tbl->setItemWithValue(row, 3, 0);
        ui->tbl->setItemWithValue(row, 4, v.at(3));
        break;
    }
    ui->tbl->setItemWithValue(row, 5, v.at(6));
    ui->tbl->setItemWithValue(row, 6, v.at(7));
    ui->tbl->setItemWithValue(row, 7, v.at(8));
}

void DlgPrintVoucherAsInvoice::on_btnAddVoucher_clicked()
{
    DlgSeachFromDatabase *d = new DlgSeachFromDatabase(this);
    d->fQuery = "select m.f_id, m.f_wdate, m.f_finalname, m.f_amountamd, cl.f_name, m.f_sign, pm.f_en, m.f_remarks, m.f_paymentMode "
            "from m_register m "
            "left join f_payment_type pm on pm.f_id=m.f_paymentmode "
            "left join f_city_ledger cl on cl.f_id=m.f_cityledger "
            "where f_canceled=0 and f_finance=1 and (f_inv is null or f_inv='')";
    d->fField = " and m.f_id like '%%1%' or f_finalname like '%%1%' or f_amountamd like '%%1%' or cl.f_name like '%%1%' and m.f_source='RV'";
    if (d->exec() == QDialog::Accepted) {
        DoubleDatabase dd(true, false);
        addRow(d->fResult);
        countTotal();
    }
    delete d;
}

void DlgPrintVoucherAsInvoice::on_btnSave_clicked()
{
    if (ui->leInvoice->isEmpty()) {
        ui->leInvoice->setText(uuidx("IN"));
    }
    DoubleDatabase dd(true, doubleDatabase);
    for (int i = 0; i < ui->tbl->rowCount(); i++) {
        dd[":f_id"] = ui->tbl->toString(i, 0);
        dd[":f_inv"] = ui->leInvoice->text();
        dd.exec("update m_register set f_inv=:f_inv where f_id=:f_id");
    }
}
