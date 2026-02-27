#include "dwmaindeskhint.h"
#include "ui_dwmaindeskhint.h"
#include "dlgfiltervalues.h"
#include "basewidget.h"
#include "wreservation.h"
#include "wreservation.h"
#include "winvoice.h"
#include "tablemodel.h"
#include <QPainter>

DWMainDeskHint::DWMainDeskHint(QWidget *parent) :
    QDockWidget(parent, Qt::WindowStaysOnBottomHint),
    Base(),
    ui(new Ui::DWMainDeskHint)
{
    ui->setupUi(this);
    fTableModel = new TableModel(ui->tbl, nullptr);
    fCheckInFilter = false;
    connect(ui->tbl->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(tblHeaderSectionClicked(int)));
    connect(this, SIGNAL(visibilityChanged(bool)), this, SLOT(thisVisibilityChanged(bool)));
    ui->btnCheckIn->setVisible(false);
    ui->tbl->setItemDelegate(new DeskHintItemDelegate());
    fTableModel->fBackgroundImages[0][RESERVE_CHECKIN] = QPixmap(":/images/ball-blue.png");
    fTableModel->fBackgroundImages[0][RESERVE_RESERVE] = QPixmap(":/images/ball-red.png");
    fTableModel->fBackgroundImages[0][RESERVE_OUTOFROOM] = QPixmap(":/images/ball-gray.png");
    fTableModel->fBackgroundImages[0][RESERVE_SERVICE] = QPixmap(":/images/ball-fiolet.png");
    fLoaded = false;
    for (int i = 0; i < 10; i++) {
        ui->tbl->fLinkColumns.append(i);
    }
}

DWMainDeskHint::~DWMainDeskHint()
{
    delete ui;
    delete fTableModel;
}

void DWMainDeskHint::commonFilter(const QString &filter, int col)
{
    if (!fLoaded) {
        load();
    }
    if (fCheckInFilter) {
        return;
    }
    if (col < 0) {
        fTableModel->searchInTable(filter);
    } else {
        fTableModel->searchInTable(filter, col);
    }
}

void DWMainDeskHint::filterEqual(const QStringList &values, int col)
{
    if (!fLoaded) {
        load();
    }
    if (fCheckInFilter) {
        return;
    }
    QString text = values.join("|");
    fTableModel->searchInTable(text, col);
}

void DWMainDeskHint::checkInFilter()
{
    if (!fLoaded) {
        load();
    }
    setWindowTitle(tr("Ready for checkin"));
    ui->btnCheckIn->setVisible(true);
    fCheckInFilter = true;
    fTableModel->searchInTableEqual("1", 0);
}

void DWMainDeskHint::checkOutFilter()
{
    if (!fLoaded) {
        load();
    }
    setWindowTitle(tr("Ready for checkout"));
    fCheckInFilter = true;
    fTableModel->searchInTable(WORKING_DATE.toString(def_date_format), 5);
}

void DWMainDeskHint::airFilter()
{
    if (!fLoaded) {
        load();
    }
    setWindowTitle(tr("Air reservations"));
    fCheckInFilter = true;
    fTableModel->searchInTableEqual("0", 2);
}

void DWMainDeskHint::hide()
{
    fCheckInFilter = false;
    QDockWidget::hide();
}

void DWMainDeskHint::show()
{
    //fTableModel->searchInTable("", -1);
    QWidget::show();
}

void DWMainDeskHint::reset()
{
    fLoaded = false;
}

void DWMainDeskHint::load()
{
    fTableModel->clearColumns();
    fTableModel->setColumn(ui->tbl->verticalHeader()->defaultSectionSize(), "", "")
            .setColumn(0, "", "Code")
            .setColumn(50, "", "Room")
            .setColumn(250, "", "Guest")
            .setColumn(100, "", "Arrival")
            .setColumn(100, "", "Depature")
            .setColumn(150, "", "Cardex")
            .setColumn(0, "", "Nat.")
            .setColumn(50, "", "")
            .setColumn(0, "", "Invoice")
            .setColumn(150, "", "Operator")
            .setColumn(0, "", "Booking");
    QString query = QString("select r.f_state, r.f_id, r.f_room, group_concat(g1.gname separator ', '), "
               "r.f_startDate, r.f_endDate, concat(r.f_cardex, '-', cdx.f_name), '', 'Open', r.f_invoice, "
               "concat(u.f_firstName, ' ', u.f_lastName), r.f_booking "
               "from f_reservation r "
               "left join (select f_reservation, concat(g.f_firstName, ' ' , g.f_lastName) as gname "
                    "from f_reservation_guests gr left join f_guests g on g.f_id=gr.f_guest) g1 on g1.f_reservation=r.f_id "
               "left join f_cardex cdx on cdx.f_cardex=r.f_cardex "
               "inner join users u on u.f_id=r.f_author "
               "where ((r.f_state=%1 or r.f_state=%2) or (r.f_state=%3 and r.f_enddate>='%4')) "
               " and r.f_startdate is not null "
               "group by r.f_id "
               "order by 1, 2 ")
            .arg(RESERVE_CHECKIN)
            .arg(RESERVE_RESERVE)
            .arg(RESERVE_SERVICE)
            .arg(WORKING_DATE.toString(def_mysql_datetime_format));
    fTableModel->setSqlQuery(query);
    fTableModel->apply(nullptr);
    fLoaded = true;
}

void DWMainDeskHint::tblHeaderSectionClicked(int logicalIndex)
{
    if (fCheckInFilter) {
        return;
    }
    QSet<QString> values;
    for (int i = 0, count = fTableModel->rowCount(); i < count; i++) {
        values << fTableModel->data(i, logicalIndex, Qt::DisplayRole).toString();
    }
    QStringList sortedValues = values.values();
    std::sort(sortedValues.begin(), sortedValues.end());
    switch (logicalIndex) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7: {
        DlgFilterValues *d = new DlgFilterValues(sortedValues, this);
        if (d->exec() == QDialog::Accepted) {
            filterEqual(sortedValues, logicalIndex);
        }
        delete d;
    }
    }
}

void DWMainDeskHint::thisVisibilityChanged(bool v)
{
    if (!v) {
        fCheckInFilter = false;
        ui->btnCheckIn->setVisible(false);
    } else {
        setFocus();
    }
}

void DWMainDeskHint::on_btnCheckIn_clicked()
{
    hide();
    QList<CacheRoom*> rooms;
    rooms.append(nullptr);
    WReservation *w = addTab<WReservation>();
    w->setInitialParams(WORKING_DATE, WORKING_DATE, rooms);
}

void DWMainDeskHint::on_tbl_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        int reserveState = fTableModel->data(index.row(), 0).toInt();
        switch (reserveState) {
        case RESERVE_RESERVE:
            WReservation::openReserveWindows(fTableModel->data(index.row(), 1, Qt::DisplayRole).toString());
            break;
        case RESERVE_CHECKIN:
            WInvoice::openInvoiceWindow(fTableModel->data(index.row(), 9, Qt::DisplayRole).toString());
            break;
        case -1:
            break;
        default:
            message_info(tr("This reservation is not editable"));
            break;
        }
    }
}


void DeskHintItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        return;
    }
    QColor fillColor;
    switch (index.column()) {
        case 0: {
        switch (index.data(Qt::DisplayRole).toInt()) {
        case RESERVE_CHECKIN:
            fillColor = QColor::fromRgb(__s.value("checkincolor", -16733441).toInt());
            break;
        case RESERVE_RESERVE:
            fillColor = QColor::fromRgb(__s.value("reservecolor", -42403).toInt());
            break;
        case RESERVE_SERVICE:
            fillColor = Qt::magenta;
            break;
        case RESERVE_OUTOFINVENTORY:
        case RESERVE_OUTOFROOM:
            fillColor = QColor::fromRgb(88, 88, 88);
            break;
        default:
            fillColor = Qt::yellow;
            break;
        }
        painter->setBrush(fillColor);
        QRectF rEllipse(option.rect);
        rEllipse.adjust(3, 3, -3, -3);
        painter->drawEllipse(rEllipse);
        return;
    }
    default:
        QItemDelegate::paint(painter, option, index);
        return;
    }
}
