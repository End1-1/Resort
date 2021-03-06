#ifndef EQTABLEWIDGET_H
#define EQTABLEWIDGET_H

#include "eqcheckbox.h"
#include "edateedit.h"
#include "eqlineedit.h"
#include "eqcombobox.h"
#include "epushbutton.h"
#include <QTableWidget>
#include <QFocusEvent>

#define for_row_count(x) for(int i = 0, rowCount = x->rowCount(); i < rowCount; i++)
#define for_col_count(x) for(int j = 0, colCount = x->columnCount(); j < colCount; j++);

class C5TableWidgetItem : public QTableWidgetItem {
public:
    explicit C5TableWidgetItem(int type = Type);

    explicit C5TableWidgetItem(const QString &text, int type = Type);

    virtual QVariant data(int role) const override;

    inline QString text() {return data(Qt::DisplayRole).toString(); }
};

class EQTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    EQTableWidget(QWidget *parent = nullptr);
    void fitToColumns();
    void setValue(int row, int column, const QVariant &data, int role = Qt::DisplayRole);
    inline QVariant itemValue(int row, int column, int role = Qt::DisplayRole) { return item(row, column)->data(role);}
    double sumOfColumn(int column);
    double sumOfColumn(int column, int columnCond, int cond);
    QString toString(int row, int column);
    QDate toDate(int row, int column);
    inline double toDouble(int row, int column) {return item(row, column)->data(Qt::EditRole).toDouble();}
    C5TableWidgetItem *item(int row, int column);
    void setItem(int row, int column, C5TableWidgetItem *i);
    //void setItem(int row, int column, const QVariant &v);
    inline int toInt(int row, int column) {return item(row, column)->data(Qt::EditRole).toInt();}
    void setItemWithValue(int row, int column, const QVariant &display, const QVariant &user = QVariant());
    QPushButton *addButton(int row, int column, const char *slot, QObject *receiver, const QIcon &icon);
    EPushButton *button(int row, int column);
    EQCheckBox *addCheckBox(int row, int column);
    EQCheckBox *checkBox(int row, int column);
    EQLineEdit *addLineEdit(int row, int column, bool valueToItem);
    EQLineEdit *lineEdit(int row, int column);
    EDateEdit *addDateEdit(int row, int column, bool valueToItem);
    EDateEdit *dateEdit(int row, int column);
    EQComboBox *addComboBox(int row, int column);
    EQComboBox *comboBox(int row, int column);
    int addRow();
    void setItemChecked(int row, int column, bool v);
    bool itemChecked(int row, int column);
    bool findWidgetCell(QWidget *find, int &row, int &col);
protected:
    virtual void focusOutEvent(QFocusEvent *event);
private slots:
    void lineEditTextChanged(const QString &text);
    void dateEditDateChanged(const QDate &date);
};

#endif // EQTABLEWIDGET_H
