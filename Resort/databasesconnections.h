#ifndef DATABASESCONNECTIONS_H
#define DATABASESCONNECTIONS_H

#include "baseextendeddialog.h"

namespace Ui {
class DatabasesConnections;
}

class DatabasesConnections : public BaseExtendedDialog
{
    Q_OBJECT

public:
    explicit DatabasesConnections(QWidget *parent = nullptr);
    ~DatabasesConnections();

private slots:
    void on_btnAdd_clicked();
    void on_btnEdit_clicked();
    void on_btnRemove_clicked();
    void on_btnChangePassword_clicked();

    void on_chDirectConnection_clicked(bool checked);

    void on_leBroadcast_textChanged(const QString &arg1);

private:
    Ui::DatabasesConnections *ui;
    void loadDatabases();
};

#endif // DATABASESCONNECTIONS_H
