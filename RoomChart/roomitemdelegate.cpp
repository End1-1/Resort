#include "roomitemdelegate.h"
#include "cacheroom.h"
#include <QPainter>

RoomItemDelegate::RoomItemDelegate()
{
    fShowRoomDescription = __s.value("showroomdescription").toBool();
}

void RoomItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        QItemDelegate::paint(painter, option, index);
        return;
    }
    CacheRoom r;
    if (!r.get(index.data(Qt::UserRole).toString())) {
        return;
    }
    /*
    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, HSELECTION_COLOR);

    } else {
    */
    QLinearGradient bgFill(0, 0, 0, option.rect.height());
    int state = r.fState();
    QColor mainColor = ROOM_RECT_BACKGROUND[state][0];
    if (r.fDoNotDisturbe()) {
        mainColor = QColor::fromRgb(__s.value("donotdisturbecolor", -5570689).toInt());
    }
    QColor alpha = mainColor;
    alpha = alpha.lighter();
    bgFill.setColorAt(0, mainColor);
    bgFill.setColorAt(0.5, alpha);
    bgFill.setColorAt(1, mainColor);

    QBrush brush(bgFill);
    painter->fillRect(option.rect, brush);

    QTextOption o;
    o.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    o.setWrapMode(QTextOption::NoWrap);
    painter->setPen(LIGHT_GRAY);
    painter->drawRect(option.rect);

    painter->setPen(Qt::black);
    QRect rect = option.rect;
    rect.adjust(2, 1, -2, -1);
    painter->drawText(rect, fShowRoomDescription ? r.fName() + ", " + r.fRoomDescription() : r.fName(), o);
    painter->setPen(LIGHT_GRAY);

    rect.adjust(-1, -1, -1, -1);
   // painter->drawText(rect, r.fName(), o);
}
