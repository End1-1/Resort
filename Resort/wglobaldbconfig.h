#ifndef WGLOBALDBCONFIG_H
#define WGLOBALDBCONFIG_H

#include "basewidget.h"
#include <QListWidgetItem>

namespace Ui
{
class WGlobalDbConfig;
}

class WGlobalDbConfig : public BaseWidget
{
    Q_OBJECT

public:
    explicit WGlobalDbConfig(QWidget *parent = nullptr);
    ~WGlobalDbConfig();
    virtual bool canClose();

protected:
    virtual void setupTab();

private slots:
    void on_btnSave_clicked();
    void on_lwHost_clicked(const QModelIndex &index);
    void on_btnSaveRestaurant_clicked();
    void on_btnRefresh_clicked();
    void on_btnSaveAccess_clicked();
    void on_btnSaveDatabases_clicked();
    void on_btnRemoveStation_clicked();
    void on_btnRefreshReset_clicked();
    void on_btnRemoveRest_clicked();
    void on_btnRefreshTax_clicked();
    void on_tblTax_cellDoubleClicked(int row, int column);
    void on_chShowLogs_clicked(bool checked);
    void on_btnRemoveDatabase_clicked();
    void on_btnInitExtRestData_clicked();
    void on_leExternalRestaurantDb_textChanged(const QString &arg1);
    void on_btnCorrectRoomChart_clicked();
    void on_btnAddrpGroup_clicked();
    void on_lwrpGroups_currentRowChanged(int currentRow);
    void on_lwrpReports_currentRowChanged(int currentRow);
    void on_chDebug_clicked(bool checked);
    void on_btnAddRoomType_clicked();
    void on_btnRemoveRoomType_clicked();
    void on_btnAddRatePlan_clicked();
    void on_btnRemoveRatePlan_clicked();

private:
    Ui::WGlobalDbConfig *ui;
    void getCompSettings();
    void getAccess();
    void getDatabases();
    void getMonthly();
    void getTax();
    void getApp();
    void getReportOptions();
};

#endif // WGLOBALDBCONFIG_H
