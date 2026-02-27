#include "eqtablewidget.h"
#include "utils.h"
#include <QItemSelectionModel>
#include <QStyledItemDelegate>

class TableDelegate : public QStyledItemDelegate {
    QLocale loc;
public:
    QString displayText(const QVariant &value, const QLocale &locale) const {
        Q_UNUSED(locale)
        switch (value.type()) {
        case QVariant::Double: {
            QString v = loc.toString(value.toDouble(), 'f', 2);
            v.remove(QRegularExpression("\\.0+$")).remove(QRegularExpression("\\.$"));
            return v;
        }
        case QVariant::Date:
            return value.toDate().toString(def_date_format);
        case QVariant::DateTime:
            return value.toDateTime().toString(def_date_time_format);
        default:
            return value.toString();
        }
    }
};

EQTableWidget::EQTableWidget(QWidget *parent) :
    QTableWidget(parent)
{
    setItemDelegate(new TableDelegate());
    setWordWrap(false);
}

void EQTableWidget::fitToColumns()
{
    int w = 40;
    for (int i = 0; i < columnCount(); i++) {
        w += columnWidth(i);
    }
    setMinimumSize(w, 0);
}

void EQTableWidget::setValue(int row, int column, const QVariant &data, int role)
{
    C5TableWidgetItem *i = item(row, column);
    if (!i) {
        i = new C5TableWidgetItem();
        setItem(row, column, i);
    }
    i->setData(role, data);
}

double EQTableWidget::sumOfColumn(int column)
{
    double result = 0;
    for (int i = 0; i < rowCount(); i++) {
        result += toDouble(i, column);
    }
    return result;
}

double EQTableWidget::sumOfColumn(int column, int columnCond, int cond)
{
    double result = 0;
    for (int i = 0; i < rowCount(); i++) {
        if (toInt(i, columnCond) == cond) {
            result += toDouble(i, column);
        }
    }
    return result;
}

QString EQTableWidget::toString(int row, int column)
{
    QLocale loc;
    C5TableWidgetItem *i = item(row, column);
    if (!i) {
        return "";
    }
    QVariant v = i->data(Qt::EditRole);
    switch (v.type()) {
    case QVariant::Double:
        return float_str(v.toDouble(), 2);
    case QVariant::Date:
        return v.toDate().toString(def_date_format);
    case QVariant::DateTime:
        return v.toDateTime().toString(def_date_time_format);
    default:
        return v.toString();
    }
}

QDate EQTableWidget::toDate(int row, int column)
{
    C5TableWidgetItem *i = item(row, column);
    if (!i) {
        return QDate();
    }
    return i->data(Qt::EditRole).toDate();
}

C5TableWidgetItem *EQTableWidget::item(int row, int column)
{
    return static_cast<C5TableWidgetItem*>(QTableWidget::item(row, column));
}

void EQTableWidget::setItem(int row, int column, C5TableWidgetItem *i)
{
    i->setData(Qt::EditRole, i->data(Qt::EditRole));
    QTableWidget::setItem(row, column, i);
}

//void EQTableWidget::setItem(int row, int column, const QVariant &v)
//{
//    C5TableWidgetItem *i = item(row, column);
//    if (!i) {
//        i = new C5TableWidgetItem();
//    }
//    i->setData(Qt::EditRole, v);
//    setItem(row, column, i);
//}

void EQTableWidget::setItemWithValue(int row, int column, const QVariant &display, const QVariant &user)
{
    C5TableWidgetItem *i = new C5TableWidgetItem();
    i->setData(Qt::EditRole, display);
    i->setData(Qt::UserRole, user);
    setItem(row, column, i);
}

QPushButton *EQTableWidget::addButton(int row, int column, const char *slot, QObject *receiver, const QIcon &icon)
{
    EPushButton *b = new EPushButton();
    b->setTag(row);
    b->setIcon(icon);
    //b->setMaximumSize(25, 25);
    //b->setMinimumSize(25, 25);
    connect(b, SIGNAL(clickedWithTag(int)), receiver, slot);
    setCellWidget(row, column, b);
    return b;
}

EPushButton *EQTableWidget::button(int row, int column)
{
    return static_cast<EPushButton*>(cellWidget(row, column));
}

EQCheckBox *EQTableWidget::addCheckBox(int row, int column)
{
    EQCheckBox *check = new EQCheckBox();
    setCellWidget(row, column, check);
    return check;
}

EQCheckBox *EQTableWidget::checkBox(int row, int column)
{
    return static_cast<EQCheckBox*>(cellWidget(row, column));
}

EQLineEdit *EQTableWidget::addLineEdit(int row, int column, bool valueToItem)
{
    C5TableWidgetItem *i = item(row, column);
    if (!i) {
        i = new C5TableWidgetItem();
        setItem(row, column, i);
    }
    EQLineEdit *line = new EQLineEdit();
    line->fRow = row;
    line->fColumn = column;
    line->setText(i->text());
    line->setFrame(false);
    setCellWidget(row, column, line);
    if (valueToItem)  {
        connect(line, SIGNAL(textChanged(QString)), this, SLOT(lineEditTextChanged(QString)));
    }
    return line;
}

EQLineEdit *EQTableWidget::lineEdit(int row, int column)
{
    return dynamic_cast<EQLineEdit*>(cellWidget(row, column));
}

EDateEdit *EQTableWidget::addDateEdit(int row, int column, bool valueToItem)
{
    C5TableWidgetItem *i = item(row, column);
    if (!i) {
        i = new C5TableWidgetItem();
        setItem(row, column, i);
    }
    EDateEdit *d = new EDateEdit();
    d->fRow = row;
    d->fColumn = column;
    d->setFrame(false);
    setCellWidget(row, column, d);
    if (valueToItem) {
        connect(d, SIGNAL(dateChanged(QDate)), this, SLOT(dateEditDateChanged(QDate)));
    }
    return d;
}

EDateEdit *EQTableWidget::dateEdit(int row, int column)
{
    return dynamic_cast<EDateEdit*>(cellWidget(row, column));
}

EQComboBox *EQTableWidget::addComboBox(int row, int column)
{
    C5TableWidgetItem *i = item(row, column);
    if (!i) {
        i = new C5TableWidgetItem();
        setItem(row, column, i);
    }
    EQComboBox *c = new EQComboBox();
    c->fRow = row;
    c->setFrame(false);
    setCellWidget(row, column, c);
    return c;
}

EQComboBox *EQTableWidget::comboBox(int row, int column)
{
    EQComboBox *c = dynamic_cast<EQComboBox*>(cellWidget(row, column));
    return c;
}

int EQTableWidget::addRow()
{
    int row = rowCount();
    setRowCount(row + 1);
    return row;
}

void EQTableWidget::setItemChecked(int row, int column, bool v)
{
    C5TableWidgetItem *i = item (row, column);
    i->setCheckState(v ? Qt::Checked : Qt::Unchecked);
}

bool EQTableWidget::itemChecked(int row, int column)
{
    C5TableWidgetItem *i = item(row, column);
    return i->checkState() == Qt::Checked;
}

bool EQTableWidget::findWidgetCell(QWidget *find, int &row, int &col)
{
    for (int i = 0; i < columnCount(); i++) {
        for (int j = 0; j < rowCount(); j++) {
            QWidget *w = cellWidget(j, i);
            if (w == find) {
                row = j;
                col = i;
                return true;
            }
        }
    }
    return false;
}

void EQTableWidget::focusOutEvent(QFocusEvent *event)
{
    QTableWidget::focusOutEvent(event);
}

void EQTableWidget::lineEditTextChanged(const QString &text)
{
    EQLineEdit *line = static_cast<EQLineEdit*>(sender());
    item(line->fRow, line->fColumn)->setText(text);
}

void EQTableWidget::dateEditDateChanged(const QDate &date)
{
    EDateEdit *d = static_cast<EDateEdit*>(sender());
    item(d->fRow, d->fColumn)->setText(date.toString(def_date_format));
    item(d->fRow, d->fColumn)->setData(Qt::UserRole, date);
}


C5TableWidgetItem::C5TableWidgetItem(int type) :
    QTableWidgetItem (type)
{

}

C5TableWidgetItem::C5TableWidgetItem(const QString &text, int type) :
    QTableWidgetItem (text, type)
{

}

QVariant C5TableWidgetItem::data(int role) const
{
    QVariant v = QTableWidgetItem::data(role);
    if (role == Qt::DisplayRole) {
       switch (v.type()) {
       case QVariant::Int:
           return v.toString();
       case QVariant::Date:
           return v.toDate().toString(def_date_format);
       case QVariant::DateTime:
           return v.toDateTime().toString(def_date_time_format);
       case QVariant::Time:
           return v.toTime().toString(def_time_format);
       case QVariant::Double:
           return float_str(v.toDouble(), 2);
       default:
           return v.toString();
       }
    }
    return v;
}
