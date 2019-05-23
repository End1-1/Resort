#include "wquickcheckout.h"
#include "ui_wquickcheckout.h"
#include <QPainter>

static const int r_invoice = 1;
static const int r_sign = 2;

WQuickCheckout::WQuickCheckout(QWidget *parent) :
    BaseWidget(parent),
    ui(new Ui::WQuickCheckout)
{
    ui->setupUi(this);
    ui->tw->setItemDelegate(new CheckoutItemDelegate(ui->tw));
    buildTree();
}

WQuickCheckout::~WQuickCheckout()
{
    delete ui;
}

void WQuickCheckout::setup()
{
    setupTabTextAndIcon(tr("Checkout"), ":/images/departure.png");
}

void WQuickCheckout::buildTree()
{
    QMap<int, QTreeWidgetItem*> roomItemMap;
    DoubleDatabase dd(true, false);
    dd[":f_state"] = RESERVE_CHECKIN;
    dd.exec("select r.f_room, g.guest as f_guest, r.f_invoice, r.f_enddate "
            "from f_reservation r "
            "left join guests g on g.f_id=r.f_guest "
            "where r.f_state=:f_state "
            "order by r.f_enddate ");
    while (dd.nextRow()) {
        auto *item = new QTreeWidgetItem();
        roomItemMap[dd.getInt("f_room")] = item;
        item->setData(0, Qt::EditRole, dd.getInt("f_room"));
        item->setData(1, Qt::EditRole, dd.getString("f_guest"));
        item->setFirstColumnSpanned(true);
        ui->tw->addTopLevelItem(item);
    }
    dd[":f_state"] = RESERVE_CHECKIN;
    dd.exec("select m.f_room, m.f_wdate, m.f_finalname, m.f_amountamd, m.f_sign, m.f_fiscal "
            "from m_register m "
            "inner join f_reservation r on r.f_invoice=m.f_inv "
            "where r.f_state=:f_state and m.f_finance=1 and m.f_canceled=0 "
            "order by m.f_wdate, m.f_time ");
    while (dd.nextRow()) {
        if (!roomItemMap.contains(dd.getInt("f_room"))) {
            continue;
        }
        auto *item = roomItemMap[dd.getInt("f_room")];
        auto *ci = new QTreeWidgetItem();
        ci->setData(0, Qt::UserRole + r_invoice, dd.getString("f_invoice"));
        ci->setData(0, Qt::UserRole + r_sign, dd.getInt("f_sign"));
        ci->setData(0, Qt::EditRole, dd.getDate("f_wdate"));
        ci->setData(1, Qt::EditRole, dd.getString("f_finalname"));
        ci->setData(2, Qt::EditRole, dd.getDouble("f_amountamd"));
        ci->setData(3, Qt::EditRole, dd.getInt("f_fiscal"));
        ci->setFirstColumnSpanned(true);
        item->addChild(ci);
    }
}


CheckoutItemDelegate::CheckoutItemDelegate(QTreeWidget *parent)
{
    fParent = parent;
}

void CheckoutItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        return;
    }
    painter->save();
    painter->fillRect(option.rect, Qt::white);
    QFont f(painter->font());
    if (index.data(Qt::UserRole + r_sign).toInt() == -1) {
        f.setBold(true);
    }
    painter->setFont(f);
    QRect rText = option.rect;
    //rText.adjust(2, 2, -2, -2);
    QVariant v = index.data(Qt::EditRole);
    switch (v.type()) {
    case QVariant::Double:
        v = float_str(v.toDouble(), 2);
        break;
    case QVariant::Date:
        v = v.toDate().toString(def_date_format);
        break;
    default:
        break;
    }
    painter->drawText(rText, v.toString());
    painter->restore();
}
