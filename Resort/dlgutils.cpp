#include "dlgutils.h"
#include <QFile>
#include "doubleutils.h"
#include "ui_dlgutils.h"

DlgUtils::DlgUtils(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgUtils)
{
    ui->setupUi(this);
}

DlgUtils::~DlgUtils()
{
    delete ui;
}

void DlgUtils::on_btnGenNumbers_clicked()
{
    QFile f("./uuid.txt");
    f.open(QIODevice::WriteOnly);
    f.reset();
    for (int i = 0; i < ui->leCount->text().toInt(); i++) {
        QString uid = uuidx(ui->lePrefix->text());
        f.write(uid.toLatin1());
        f.write("\r\n");
    }
    f.close();
    message_info(tr("Done."));
}

void DlgUtils::on_btnCorrectReservGrantTotal_clicked()
{
    DoubleDatabase dd;
    QMap<QString, double> invoices;
    if (!dd.exec("select r.f_invoice, r.f_grandtotal, sum(m.f_amountamd) as f_amountamd "
            "from f_reservation r "
            "inner join m_register m on m.f_inv=r.f_invoice "
            "where r.f_state=3 and m.f_sign=1 and m.f_finance=1 "
            "and m.f_canceled=0 "
            "group by 1, 2")) {
        message_error(dd.fLastError);
        return;
    }
    while (dd.nextRow()) {
        if (!equaldouble(dd.getDouble("f_grandtotal"), dd.getDouble("f_amountamd"))) {
            invoices[dd.getString("f_invoice")] = dd.getDouble("f_amountamd");
        }
    }
    int done = 0;
    for (auto v = invoices.begin(); v != invoices.end(); v++) {
        dd[":f_invoice"] = v.key();
        dd[":f_total"] = v.value();
        dd[":f_grandtotal"] = v.value();
        if (!dd.exec("update f_reservation set f_grandtotal=:f_grandtotal, f_total=:f_total where f_invoice=:f_invoice")) {
            message_error(dd.fLastError);
            return;
        }
        ui->lbInfo->setText(QString("%1 of %2").arg(++done).arg(invoices.count()));
        qApp->processEvents();
    }
    if (invoices.count() == 0) {
        ui->lbInfo->setText("All clear");
    }
    dd.exec("update f_reservation set f_total=f_roomfee+f_extrabedfee+f_mealprice where f_state=2");
    dd.exec("update f_reservation set f_grandtotal=datediff(f_enddate, f_startdate) * f_total where f_state=2");
    dd.exec("update f_reservation set f_total=f_grandtotal where f_state=2");
    message_info(tr("Done"));
}
