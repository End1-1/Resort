#include "dlgreservationguests.h"
#include "ui_dlgreservationguests.h"

DlgReservationGuests::DlgReservationGuests(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgReservationGuests)
{
    ui->setupUi(this);
}

DlgReservationGuests::~DlgReservationGuests()
{
    delete ui;
}

void DlgReservationGuests::viewGuests(const QString &id)
{
    DlgReservationGuests *rg = new DlgReservationGuests(fPreferences.getDefaultParentForMessage());
    rg->load(id);
    rg->exec();
    delete rg;
}

void DlgReservationGuests::load(const QString &id)
{
    DoubleDatabase fDD;
    fDD[":f_reservation"] = id;    
    fDD.exec("select g.f_title, g.f_firstName, g.f_lastName, n.f_name, g.f_passport "
                   "from f_reservation_guests r "
                   "left join f_guests g on g.f_id=r.f_guest "
                    "left join f_nationality n on n.f_short=g.f_nation "
                   "where r.f_reservation=:f_reservation "
                   "order by r.f_first desc");
    ui->tblData->clearContents();
    ui->tblData->setRowCount(fDD.rowCount());
    for (int i = 0; i < fDD.rowCount(); i++) {
        for (int j =0; j < fDD.columnCount(); j++) {
            ui->tblData->setItemWithValue(i, j, fDD.getValue(i, j));
        }
    }
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                80, 200, 200, 150, 200);
}
