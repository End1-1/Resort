#ifndef WQUICKCHECKOUT_H
#define WQUICKCHECKOUT_H

#include "basewidget.h"
#include <QItemDelegate>
#include <QTreeWidget>

namespace Ui {
class WQuickCheckout;
}

class WQuickCheckout;

class WQuickCheckoutItemDelegate : public QItemDelegate {
public:
    WQuickCheckoutItemDelegate(WQuickCheckout *w);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    WQuickCheckout *fParent;
};

class WQuickCheckout : public BaseWidget
{
    Q_OBJECT

public:
    explicit WQuickCheckout(QWidget *parent = nullptr);
    ~WQuickCheckout();
    bool selected(int row);
    virtual void setup();
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_chAllInvoices_clicked(bool checked);
    void on_btnRefresh_clicked();
    void on_tbl_doubleClicked(const QModelIndex &index);
    void on_btnCheckout_clicked();
    void on_btnCommonPostCharge_clicked();

private:
    Ui::WQuickCheckout *ui;
    void refresh();
    void setRowSelected(int flag);
    void updateRow(int row);
};

#endif // WQUICKCHECKOUT_H
