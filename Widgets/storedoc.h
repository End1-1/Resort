#ifndef STOREDOC_H
#define STOREDOC_H

#include "basewidget.h"

namespace Ui {
class StoreDoc;
}

class StoreDoc : public BaseWidget
{
    Q_OBJECT

public:
    explicit StoreDoc(QWidget *parent = nullptr);
    ~StoreDoc();
    virtual void callback(int sel, const QString &code);
    void loadDoc(const QString &id);
    void copyDoc(const QString &id);
    virtual void setup();
    static void openStoreDocument(const QString &id);
private:
    Ui::StoreDoc *ui;
    QWidget *fFirstTab;
    QWidget *fGoodsTab;
    QWidget *fAccTab;
    void prepareDoc();
    void countTotal();
    void saveDoc(int docState);
private slots:
    void qtyChange(const QString &arg1);
    void priceChange(const QString &arg1);
    void totalChange(const QString &arg1);
    void on_btnSaveDoc_clicked();
    void on_btnNewMaterial_clicked();
    void newGoods(const QString &code);
    void on_btnAddMaterial_clicked();
    void on_btnDraftDoc_clicked();
    void on_btnRemoveDoc_clicked();
    void on_btnRemoveMaterial_clicked();
    void on_deDate_textChanged(const QString &arg1);
    void on_leTotal_textChanged(const QString &arg1);
    void on_leComments_textChanged(const QString &arg1);
    void on_btnPrintDoc_clicked();
};

#endif // STOREDOC_H
