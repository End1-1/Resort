#include "taxhelper.h"
#include "doubledatabase.h"
#include "defines.h"

TaxHelper *TaxHelper::fInstance = nullptr;

TaxHelper::TaxHelper(QObject *parent) : QObject(parent)
{
}

void TaxHelper::init()
{
    if (fInstance == nullptr) {
        fInstance = new TaxHelper();
    }
    fInstance->fTaxPoints.clear();
    fInstance->fTaxVAT.clear();
    fInstance->fTaxNoVAT.clear();
    DoubleDatabase dd;
    dd.exec("select * from s_tax_map");
    while (dd.nextRow()) {
        TaxPoint t;
        t.id = dd.getInt("f_id");
        t.ip = dd.getString("f_ip");
        t.port = dd.getInt("f_port");
        t.password = dd.getString("f_password");
        t.name = dd.getString("f_name");
        t.opcode = dd.getString("f_opcode");
        t.oppin = dd.getString("f_oppin");
        t.extPos = dd.getString("f_extpos");
        fInstance->fTaxPoints[t.id] = t;
    }
    dd.exec(QString("select f_item, f_vatdept, f_novatdept, f_tax "
                    "from f_invoice_item_tax t "
                    "left join f_invoice_item i on i.f_id=t.f_item "
                    "where f_comp='SmartHotel: %1'").arg(HOSTNAME));
    while (dd.nextRow()) {
        fInstance->fTaxVAT[dd.getInt("f_item")] = dd.getInt("f_vat");
        fInstance->fTaxNoVAT[dd.getInt("f_item")] = dd.getInt("f_novat");
    }
}
