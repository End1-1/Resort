#ifndef DLGSEACHFROMDATABASE_H
#define DLGSEACHFROMDATABASE_H

#include "basedialog.h"

namespace Ui {
class DlgSeachFromDatabase;
}

class DlgSeachFromDatabase : public BaseDialog
{
    Q_OBJECT

public:
    explicit DlgSeachFromDatabase(QWidget *parent = nullptr);
    ~DlgSeachFromDatabase();
    QString fQuery;
    QString fField;
    QList<QVariant> fResult;

private slots:
    void on_leSearch_returnPressed();
    void on_tbl_doubleClicked(const QModelIndex &index);

private:
    Ui::DlgSeachFromDatabase *ui;
};

#endif // DLGSEACHFROMDATABASE_H
