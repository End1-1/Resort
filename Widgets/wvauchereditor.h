#ifndef WVAUCHEREDITOR_H
#define WVAUCHEREDITOR_H

#include "basedialog.h"
#include "trackcontrol.h"
namespace Ui {
class WVaucherEditor;
}

class WVaucherEditor : public BaseDialog
{
    Q_OBJECT

public:
    explicit WVaucherEditor(QWidget *parent = nullptr);
    ~WVaucherEditor();
    virtual void callback(int sel, const QString &code);
    static void load(const QString &id);
    static void newVaucher(const QString &invoice);

private slots:
    void on_btnSave_clicked();
    void on_btnTrack_clicked();
    void on_btnPrint_clicked();
    void on_btnNewVaucher_clicked();
    void on_deWorking_textChanged(const QString &arg1);
    void on_leAmount_textChanged(const QString &arg1);

private:
    Ui::WVaucherEditor *ui;
    TrackControl *fTc;
    bool fFlagNew;
    void loadVaucher(const QString &id);
    bool errorCheck();
    void loadInvoice();
    void setNewFlag();
    void setRV();
    void setPS();
};

#endif // WVAUCHEREDITOR_H
