#ifndef WQUICKCHECKOUT_H
#define WQUICKCHECKOUT_H

#include "basewidget.h"
#include <QItemDelegate>
#include <QTreeWidget>

namespace Ui {
class WQuickCheckout;
}

class CheckoutItemDelegate : public QItemDelegate {
public:
    CheckoutItemDelegate(QTreeWidget *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QTreeWidget *fParent;
};

class WQuickCheckout : public BaseWidget
{
    Q_OBJECT

public:
    explicit WQuickCheckout(QWidget *parent = nullptr);
    ~WQuickCheckout();
    virtual void setup();

private:
    Ui::WQuickCheckout *ui;
    void buildTree();
};

#endif // WQUICKCHECKOUT_H
