#ifndef WSTOREENTRY_H
#define WSTOREENTRY_H

#include "basewidget.h"
#include "cachedish.h"

namespace Ui {
class WStoreEntry;
}

class WStoreEntry : public BaseWidget
{
    Q_OBJECT

public:
    explicit WStoreEntry(QWidget *parent = nullptr);
    ~WStoreEntry();
    virtual void callback(int sel, const QString &code);
    virtual void setup();
    static void openDoc(int doc);
private:
    Ui::WStoreEntry *ui;
    void load(int doc);
    void newGoods(const QString &code);
    void countTotal();
private slots:
    void qtyChange(const QString &arg1);
    void priceChange(const QString &arg1);
    void totalChange(const QString &arg1);
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_btnSave_clicked();
    void on_btnRemove_clicked();
    void on_btnCalculate_clicked();
    void on_btnPrint_clicked();
};

#endif // WSTOREENTRY_H
