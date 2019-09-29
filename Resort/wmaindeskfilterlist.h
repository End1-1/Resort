#ifndef WMAINDESKFILTERLIST_H
#define WMAINDESKFILTERLIST_H

#include "basedialog.h"

namespace Ui {
class WMainDeskFilterList;
}

class QListWidgetItem;

class WMainDeskFilterList : public BaseDialog
{
    Q_OBJECT

public:
    explicit WMainDeskFilterList(QWidget *parent = nullptr);
    ~WMainDeskFilterList();
    static bool filter(const QStringList &values, const QStringList &names, const QString &title, QString &out);

private slots:
    void on_lstValues_itemClicked(QListWidgetItem *item);

private:
    Ui::WMainDeskFilterList *ui;
};

#endif // WMAINDESKFILTERLIST_H
