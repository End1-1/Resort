#include "pexportinvoicetoexcel.h"
#include "xlsxall.h"
#include "message.h"
#include "cacheusers.h"
#include "paymentmode.h"
#include <QApplication>

PExportInvoiceToExcel::PExportInvoiceToExcel() :
    QObject(),
    Base()
{

}

void PExportInvoiceToExcel::exportInvoice(const QString &invoice, int side)
{
    PExportInvoiceToExcel p;
    p.run(invoice, side);
}

void PExportInvoiceToExcel::run(const QString &invoice, int fSide)
{
    XlsxDocument d;
    XlsxSheet *s = d.workbook()->addSheet(invoice);
    s->setColumnWidth(1, 2);
    s->setColumnWidth(2, 12);
    s->setColumnWidth(3, 40);
    s->setColumnWidth(4, 6);
    s->setColumnWidth(5, 10);
    s->setColumnWidth(6, 10);
    s->setColumnWidth(7, 10);
    int numNights = 0;
    DoubleDatabase drvoucher(true);
    drvoucher[":f_invoice"] = invoice;
    QString query;
    if (fSide > -1) {
        drvoucher[":f_side"] = fSide;
        query = "select ic.f_sign, ic.f_wdate, ic.f_paymentMode, ic.f_finalName, "
                "ic.f_amountAmd, ic.f_amountVat, ic.f_dc, ic.f_remarks "
                "from m_register ic "
                "where ic.f_inv=:f_invoice and ic.f_side=:f_side "
                "and ic.f_canceled=0 and ic.f_finance=1 "
                "order by ic.f_wdate, ic.f_id ";
    } else {
        query = "select ic.f_sign, ic.f_wdate, ic.f_paymentMode, ic.f_finalName, "
                "ic.f_amountAmd, ic.f_amountVat, ic.f_dc, ic.f_remarks "
                "from m_register ic "
                "where ic.f_inv=:f_invoice and ic.f_canceled=0 and ic.f_finance=1 "
                "order by ic.f_wdate, ic.f_id ";
    }
    drvoucher.exec(query);
    if (drvoucher.rowCount() == 0) {
        message_error(tr("Cannot print empty invoice. Contact with program developer."));
        return;
    }

    DoubleDatabase drheader(true);
    drheader[":f_invoice"] = invoice;
    drheader.exec("select concat(g.f_title, ' ', g.f_firstName, ' ', g.f_lastName) as guest, g.f_nation, "
               "cat.f_short, cat.f_description, r.f_room, r.f_startDate, "
               "r.f_checkInDate, r.f_checkinTime, r.f_endDate, r.f_man+r.f_woman+r.f_child as guest_qty, "
               "r.f_checkOutTime, r.f_author, ar.f_" + def_lang + " as f_arr, r.f_cardex, ca.f_name as cardexname, "
               "r.f_vatMode, vm.f_" + def_lang + " as vatmode, r.f_upgradeFrom, g.f_address, r.f_checkinUser,"
               "nights.ntotal, r.f_checkOutUser "
               "from f_reservation r "
               "inner join f_guests g on g.f_id=r.f_guest "
               "inner join f_room rm on rm.f_id=r.f_room "
               "inner join f_room_classes cat on cat.f_id=rm.f_class "
               "left join f_cardex ca on ca.f_cardex=r.f_cardex "
               "left join f_room_arrangement ar on ar.f_id=r.f_arrangement "
               "inner join f_vat_mode vm on vm.f_id=r.f_vatMode "
               "left join (select f_inv, count(f_id) as ntotal from m_register where f_canceled=0 and f_source='RM' and f_inv=:f_invoice) nights on nights.f_inv=r.f_invoice "
               "where r.f_invoice=:f_invoice ");
    drheader.nextRow();


    DoubleDatabase drh(true);
    drh[":f_invoice"] = invoice;
    drh.exec("select f_state from f_reservation where f_invoice=:f_invoice");
    drh.nextRow();
    numNights = drheader.getValue("ntotal").toInt();

    int row = 1;
    QFont fontHeader(qApp->font());
    fontHeader.setBold(true);
    d.style()->addHAlignment("header", xls_alignment_center);
    d.style()->addFont("header", fontHeader);
    XlsxCell *c = s->addCell(row++, 1, drh.getValue("f_state").toInt() == RESERVE_CHECKOUT ? tr("SETTLEMENT / TAX INVOICE") : tr ("PROFORMA INVOICE"), d.style()->styleNum("header"));
    s->setSpan("A1:E1");
    s->addCell(1, 6, fPreferences.getDb(def_vouchers_right_header).toString());
    QString inv = QString("%1 #%2")
            .arg(tr("ROOM"))
            .arg(QString("%1").arg(drheader.getValue("f_room").toString()));
    s->addCell(row++, 1, inv, d.style()->styleNum("header"));
    s->setSpan("A2:E2");
    c = s->addCell(row++, 1, drheader.getValue("guest").toString());
    s->setSpan("A3:E3");
    if (!drheader.getValue("f_address").toString().isEmpty()) {
        s->addCell(row++, 1, tr("Address: ") + drheader.getValue("f_address").toString());
        s->setSpan("A4:E4");
    }

    s->addCell(row, 1, tr("Nationality"));
    s->setSpan("A", "B", row);
    s->addCell(row, 3, drheader.getValue("f_nation").toString());
    s->setSpan("C", "D", row);
    row++;

    s->addCell(row, 4, tr("Arrival date"));
    s->addCell(row, 6, drheader.getValue("f_startDate").toString());
    row++;
    //row 2
    s->addCell(row, 1, tr("Room category"));
    s->setSpan("A", "B", row);
    s->addCell(row, 3, drheader.getValue("f_description").toString());
    s->addCell(row, 4, tr("Departure date"));
    s->setSpan("D", "E", row);
    s->addCell(row, 6, drheader.getValue("f_endDate").toString());
    row++;
    //row 3
    QString room = drheader.getValue("f_room").toString();
    if (drheader.getValue("f_upgradeFrom").toInt() > 0) {
        room += "           " + drheader.getValue("f_upgradeFrom").toString();
    }
    s->addCell(row, 1, tr("S/N "));
    s->setSpan("A", "B", row);
    s->addCell(row, 3, invoice);
    s->addCell(row, 4, tr("Number of nights"));
    s->setSpan("D", "E", row);
    s->addCell(row, 6, numNights);
    row++;
    //row 4
    s->addCell(row, 1, tr("CheckIn"));
    s->setSpan("A", "B", row);
    s->addCell(row, 3, drheader.getValue("f_checkInDate").toString());
    s->addCell(row, 4, tr("Number of guests"));
    s->setSpan("D", "E", row);
    s->addCell(row, 6, drheader.getValue("guest_qty").toInt());
    row++;
    //row 5
    s->addCell(row, 1, tr("CheckIn time"));
    s->setSpan("A", "B", row);
    s->addCell(row, 3, drheader.getValue("f_checkinTime").toString());
    s->addCell(row, 4, tr("CheckOut date"));
    s->setSpan("D", "E", row);
    s->addCell(row, 6, drheader.getValue("f_checkOutTime").toString());
    row++;
    //row 6
    s->addCell(row, 1, tr("Operator in"));
    s->setSpan("A", "B", row);
    s->addCell(row, 3, drheader.getValue("f_checkinUser").toString());
    s->addCell(row, 4, tr("CheckOut time"));
    s->setSpan("D", "E", row);
    s->addCell(row, 6, drheader.getValue("f_checkOutTime").toString());
    row++;
    //row 7
    s->addCell(row, 1, tr("Arrangement"));
    s->setSpan("A", "B", row);
    s->addCell(row, 3, drheader.getValue("f_arr").toString());
    s->addCell(row, 4, tr("CheckOut Op."));
    s->setSpan("D", "E", row);
    CacheUsers u;
    if (u.get(drheader.getValue("f_checkOutUser").toString())) {
        s->addCell(row, 6, u.fFull());
    } else {
        s->addCell(row, 6, "-");
    }
    row++;
    //row 8
    s->addCell(row, 1, tr("Cardex"));
    s->setSpan("A", "B", row);
    s->addCell(row, 3, drheader.getValue("f_cardex").toString() + "/" + drheader.getValue("cardexname").toString());
    row++;
    row++;


    //table header
    int r1 = row;
    s->addCell(row, 1, tr("*"));
    s->addCell(row, 2, tr("Date"));
    s->addCell(row, 3, tr("Description"));
    s->addCell(row, 4, tr("Cur"));
    s->addCell(row, 6, tr("Debit\n") + " " + drheader.getValue("vatmode").toString());
    s->addCell(row, 6, tr("Credit"));
    s->addCell(row, 7, tr("Balance"));
    row++;

    //table data

    int rowNum = 1;
    double lastBalance = 0;
    double totalVat = 0;
    double totalCredit = 0;
    double totalDebet = 0;
    double totalCash = 0;
    double totalCard = 0;
    double totalOther = 0;
    for (int i = 0; i < drvoucher.rowCount(); i++) {
        double debet, credit;
        if (drvoucher.getValue(i, "f_sign").toInt() == 1) {
            debet =  drvoucher.getValue(i, "f_amountAmd").toDouble();
            credit = 0;
        } else {
            debet = 0;
            credit = drvoucher.getValue(i, "f_amountAmd").toDouble();
        }

        s->addCell(row, 1, QString::number(rowNum++));
        s->addCell(row, 2, drvoucher.getValue(i, "f_wdate").toString());
        s->addCell(row, 3, drvoucher.getValue(i, "f_finalName").toString() + " " + drvoucher.getValue(i, "f_remarks").toString());
        s->addCell(row, 4, "AMD");

        int pMode = drvoucher.getValue(i, "f_paymentMode").toInt();
        if (drvoucher.getValue(i, "f_sign").toInt() <0 ) {
            switch (pMode) {
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
        }
        totalVat += drvoucher.getValue(i, "f_amountVat").toDouble();
        totalCredit += credit;
        totalDebet += debet;
        lastBalance -= -1 * ((debet) - credit);
        s->addCell(row, 5, debet);
        s->addCell(row, 6, credit);
        s->addCell(row, 7, lastBalance);
        row++;
    }
   // e.setBorder("A" + QString::number(r1), "G" + QString::number(row - 1), 1);
    row++;

    //Footer
    r1 = row;
    s->addCell(row, 3, tr("Total amount"));
    s->setSpan("C", "D", row);
   // e.setHorizontalAlignment("C" + QString::number(row), "D" + QString::number(row), Excel::hRight);
    s->addCell(row, 5, totalDebet);
    s->addCell(row, 6, totalCredit);
    s->addCell(row, 7, lastBalance);
    row++;
    s->addCell(row, 3, tr("Total cash"));
    s->setSpan("C", "D", row);
  //  e.setHorizontalAlignment("C" + QString::number(row), "D" + QString::number(row), Excel::hRight);
    s->addCell(row, 5, totalCash);
    row++;
    s->addCell(row, 3, tr("Total cashless"));
    s->setSpan("C", "D", row);
  //  e.setHorizontalAlignment("C" + QString::number(row), "D" + QString::number(row), Excel::hRight);
    s->addCell(row, 5, totalCard + totalOther);
    row++;
    s->addCell(row, 3, tr("Being the equivalent of USD"));
    s->setSpan("C", "D", row);
  //  e.setHorizontalAlignment("C" + QString::number(row), "D" + QString::number(row), Excel::hRight);
    s->addCell(row, 5, totalDebet / def_usd);
    s->addCell(row, 6, totalCredit / def_usd);
    s->addCell(row, 7, lastBalance / def_usd);
    row++;

    if (drheader.getValue("vatmode").toInt() == VAT_INCLUDED) {
        s->addCell(row, 3, tr("VAT 20%"));
        s->setSpan("C", "D", row);
   //     e.setHorizontalAlignment("C" + QString::number(row), "D" + QString::number(row), Excel::hRight);
        s->addCell(row, 5, totalVat);
        row++;;
    }
   // e.setBorder("C" + QString::number(r1), "G" + QString::number(row - 1), 1);
    row++;

    s->addCell(row, 1, tr("Guest signature"));
    row++;
    s->addCell(row, 1, tr("The sum of only ") + Utils::numberToWords(totalCredit));
  //  e.mergeCells("A" + QString::number(row), "G" + QString::number(row), true);
    row++;
    s->addCell(row, 1, fPreferences.getDb(def_vouchers_invoice_footer).toString());
  //  e.mergeCells("A" + QString::number(row), "G" + QString::number(row), true);

    QString err;
    d.save(err, true);
}
