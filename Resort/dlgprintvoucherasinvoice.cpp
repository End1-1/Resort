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
    ui->tblTotal->addLineEdit(0, 3, false);
    ui->tblTotal->addLineEdit(0, 4, false);
    ui->tblTotal->addLineEdit(0, 5, false);
    fInvoice.setleInvoice(ui->leInvoice);
    fInvoice.setleDate(ui->deDate);
    fInvoice.setleCityLedger(ui->leCL, ui->leCLName);
    fInvoice.setleDebit(ui->tblTotal->lineEdit(0, 3));
    fInvoice.setleCredit(ui->tblTotal->lineEdit(0, 4));
    fInvoice.setleBalance(ui->tblTotal->lineEdit(0, 5));
}

DlgPrintVoucherAsInvoice::~DlgPrintVoucherAsInvoice()
{
    delete ui;
}

DlgPrintVoucherAsInvoice *DlgPrintVoucherAsInvoice::openInvoiceWindow(const QString &id)
{
    DlgPrintVoucherAsInvoice *w = nullptr;
    for (int i = 0; i < fMainWindow->fTab->count(); i++) {
        w = dynamic_cast<DlgPrintVoucherAsInvoice *>(fMainWindow->fTab->widget(i));
        if (w) {
            if (w->invoice() == id) {
                fMainWindow->fTab->setCurrentIndex(i);
                return w;
            }
        }
    }
    w = addTab<DlgPrintVoucherAsInvoice>();
    w->openInvoice(id);
    return w;
}

QString DlgPrintVoucherAsInvoice::invoice() const
{
    return ui->leInvoice->text();
}

void DlgPrintVoucherAsInvoice::setup()
{
    setupTabTextAndIcon(tr("Voucher invoice"), ":/images/invoice.png");
}

void DlgPrintVoucherAsInvoice::openInvoice(const QString &id)
{
    if (id.isEmpty()) {
        return;
    }
    DoubleDatabase d;
    if (!fInvoice.open(d, id)) {
        message_error(fInvoice.fError);
        return;
    }
    for (int i = 0; i < fInvoice.vouchersCount(); i++) {
        DBMRegister &r = fInvoice.voucher(i);
        addRow(r, false);
    }
}

void DlgPrintVoucherAsInvoice::addVoucher(const QString &id)
{
    DoubleDatabase dd;
    dd[":f_id"] = id;
    dd.exec(DBMRegister::voucherQuery() + " where m.f_id=:f_id");
    if (dd.nextRow()) {
        DBMRegister r;
        r.fetchData(dd);
        addRow(r, true);
        if (r.fCityLedger > 0) {
            ui->leCL->setUInt(r.fCityLedger);
            ui->leCLName->setText(r.fCityLedgerName);
        }
    } else {
        message_error(tr("Incorrect voucher id") + "<BR>" + id);
    }
}

void DlgPrintVoucherAsInvoice::on_btnPrint_clicked()
{
    if (!save()) {
        return;
    }
    int vatMode = 1;
    CacheVatMode cv;
    if (!cv.get(1)) {
        message_error(tr("Couild not get mode of VAT "));
        return;
    }
    PPrintPreview *pp = new PPrintPreview(this);
    PPrintScene *ps = pp->addScene(0,QPageLayout::Portrait);
    QString invHeader = tr("SETTLEMENT / TAX INVOICE");
    PTextRect *trHeader = new PTextRect(20, 20, 2100, 200, invHeader, nullptr, QFont(qApp->font().family(), 50));
    trHeader->setBorders(false, false, false, false);
    trHeader->setTextAlignment(Qt::AlignHCenter);
    QString inv = QString("%1 #%2").arg(tr("S/N")).arg(ui->leInvoice->text());
    PTextRect *trInvoice = new PTextRect(20, trHeader->textHeight(), 2100, 80, inv, nullptr, QFont(qApp->font().family(),
                                         30, 75));
    trInvoice->setTextAlignment(Qt::AlignHCenter);
    trInvoice->setBorders(false, false, false, false);
    PTextRect *trCL = new PTextRect(20, trHeader->textHeight() + 85, 2100, 80, ui->leCLName->text(), nullptr,
                                    QFont(qApp->font().family(), 30, 75));
    trCL->setTextAlignment(Qt::AlignHCenter);
    trCL->setBorders(false, false, false, false);
    PTextRect *trInfo = new PTextRect(1500, 20, 600, 400, fPreferences.getDb(def_vouchers_right_header).toString(),
                                      nullptr, QFont(qApp->font().family(), 25));
    trInfo->setTextAlignment(Qt::AlignTop | Qt::AlignRight);
    trInfo->setWrapMode(QTextOption::WordWrap);
    trInfo->setBorders(false, false, false, false);
    ps->addItem(trInfo);
    ps->addItem(trCL);
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
    int top = 340;
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
        ps->addTextRect(new PTextRect(250, top, 850, rowHeight, ui->tbl->toString(i, 2) + " " + ui->tbl->toString(i, 6), &th,
                                      f));
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
        ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_str(debet), &th, f));
        ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_str(credit), &th, f));
        ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_str(lastBalance), &th, f));
        top += rowHeight;
        if (top > 2800) {
            top = 30;
            ps = pp->addScene(0,QPageLayout::Portrait);
        }
    }
    top += (rowHeight / 2);
    f.setBold(true);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total amount"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_str(totalDebet), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_str(totalCredit), &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_str(lastBalance), &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0,QPageLayout::Portrait);
    }
    f.setBold(false);
    th.setFont(f);
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total cash"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_str(totalCash), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, "", &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0,QPageLayout::Portrait);
    }
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Total cashless"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_str(totalCard + totalOther), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, "", &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0,QPageLayout::Portrait);
    }
    th.setTextAlignment(Qt::AlignRight);
    ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("Being the equivalent of USD"), &th, f));
    th.setTextAlignment(Qt::AlignLeft);
    ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, float_str(totalDebet / def_usd), &th, f));
    ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_str(totalCredit / def_usd), &th, f));
    ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, float_str(lastBalance / def_usd), &th, f));
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0,QPageLayout::Portrait);
    }
    th.setTextAlignment(Qt::AlignRight);
    if (vatMode == VAT_INCLUDED) {
        ps->addTextRect(new PTextRect(250, top,  950, rowHeight, tr("VAT 20%"), &th, f));
        th.setTextAlignment(Qt::AlignLeft);
        ps->addTextRect(new PTextRect(1200, top, 300, rowHeight, "", &th, f));
        ps->addTextRect(new PTextRect(1500, top, 300, rowHeight, float_str(totalVat), &th, f));
        ps->addTextRect(new PTextRect(1800, top, 300, rowHeight, "", &th, f));
    }
    top += rowHeight;
    top += rowHeight;
    top += rowHeight;
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0,QPageLayout::Portrait);
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
        ps = pp->addScene(0,QPageLayout::Portrait);
    }
    f.setBold(false);
    th.setFont(f);
    r = ps->addTextRect(new PTextRect(20, top, 2000, rowHeight, tr("The sum of only ") + Utils::numberToWords(totalCredit),
                                      &th, f));
    top += r->textHeight();
    top += r->textHeight();
    top += r->textHeight();
    if (top > 2800) {
        top = 30;
        ps = pp->addScene(0,QPageLayout::Portrait);
    }
    f.setPointSize(f.pointSize() - 6);
    th.setFont(f);
    th.setWrapMode(QTextOption::WordWrap);
    ps->addTextRect(new PTextRect(20, top, 2000, rowHeight * 3, fPreferences.getDb(def_vouchers_invoice_footer).toString(),
                                  &th, f));
    TrackControl tc(0);
    tc.insert("Print invoice request", ui->leInvoice->text(), "");
    pp->exec();
    delete pp;
}

void DlgPrintVoucherAsInvoice::addRow(const DBMRegister &r, bool appendToInvoice)
{
    if (r.fFinance == 0) {
        message_error(tr("This is not valid finance voucher"));
        return;
    }
    if (appendToInvoice) {
        if (!fInvoice.addVoucher(r)) {
            message_error(tr("This voucher already in invoice"));
            return;
        }
    }
    int row = ui->tbl->addRow();
    ui->tbl->setItemWithValue(row, 0, r.fId);
    ui->tbl->setItemWithValue(row, 1, r.fWDate);
    ui->tbl->setItemWithValue(row, 2, r.fFinalName);
    switch (r.fSign) {
        case -1:
            ui->tbl->setItemWithValue(row, 3, r.fAmountAMD);
            ui->tbl->setItemWithValue(row, 4, 0);
            break;
        case 1:
            ui->tbl->setItemWithValue(row, 3, 0);
            ui->tbl->setItemWithValue(row, 4, r.fAmountAMD);
            break;
    }
    ui->tbl->setItemWithValue(row, 5, r.fPaymentModeName);
    ui->tbl->setItemWithValue(row, 6, r.fRemarks);
    ui->tbl->setItemWithValue(row, 7, r.fPaymentMode);
}

bool DlgPrintVoucherAsInvoice::save()
{
    if (ui->leInvoice->isEmpty()) {
        ui->leInvoice->setText(uuidx("IN"));
    }
    DoubleDatabase dd;
    if (!fInvoice.save(dd)) {
        message_error(fInvoice.fError);
        return false;
    }
    return true;
}

void DlgPrintVoucherAsInvoice::on_btnAddVoucher_clicked()
{
    DlgSeachFromDatabase *d = new DlgSeachFromDatabase(this);
    d->setTemplate(DlgSeachFromDatabase::stVoucher);
    d->fField = " where (m.f_id like '%%1%' or f_finalname like '%%1%' or f_amountamd like '%%1%') " +
                (ui->leCL->isEmpty() ? "" : " and cl.f_id=" + ui->leCL->text());
    if (d->exec() == QDialog::Accepted) {
        DoubleDatabase dd;
        dd[":f_id"] = d->fResult.at(0);
        dd.exec(DBMRegister::voucherQuery() + " where m.f_id=:f_id");
        if (dd.nextRow()) {
            DBMRegister r;
            r.fetchData(dd);
            addRow(r, true);
        }
    }
    delete d;
}

void DlgPrintVoucherAsInvoice::on_btnSave_clicked()
{
    save();
}
