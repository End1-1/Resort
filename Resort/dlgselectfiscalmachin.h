#ifndef DLGSELECTFISCALMACHIN_H
#define DLGSELECTFISCALMACHIN_H

#include <QDialog>

namespace Ui {
class DlgSelectFiscalMachin;
}

class QListWidgetItem;

class DlgSelectFiscalMachin : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSelectFiscalMachin(QSet<int> machines, QWidget *parent = nullptr);
    ~DlgSelectFiscalMachin();
    int fSelectedMachine;
private slots:
    void on_lst_itemClicked(QListWidgetItem *item);

private:
    Ui::DlgSelectFiscalMachin *ui;
};

#endif // DLGSELECTFISCALMACHIN_H
