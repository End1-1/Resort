#include "dlgtracking.h"
#include "ui_dlgtracking.h"
#include "cacherights.h"

DlgTracking::DlgTracking(QWidget *parent) :
    BaseExtendedDialog(parent),
    ui(new Ui::DlgTracking)
{
    ui->setupUi(this);
    Utils::tableSetColumnWidths(ui->tblData, ui->tblData->columnCount(),
                                100, 90, 70, 200, 150, 200, 200);
}

DlgTracking::~DlgTracking()
{
    delete ui;
}

void DlgTracking::showTracking(int trackId, const QString &windowId)
{
    if (!r__(cr__tracking_chnages_individual)) {
        message_error(tr("Access denied"));
        return;
    }
    if (!fPreferences.getDb(def_show_logs).toBool()) {
        message_error(tr("Logs disabled"));
        return;
    }
    DlgTracking *d = new DlgTracking(fPreferences.getDefaultParentForMessage());
    d->fTrack = trackId;
    d->fWindow = windowId;
    QString query = "select f_comp, f_date, f_time, f_user, "
            "f_action, f_value1, f_value2 "
            "from airlog.log "
            "where f_type=:f_table and (f_rec=:f_rec or f_invoice=:f_invoice or f_reservation=:f_reservation) "
            "order by f_date, f_time";
    d->loadTrack(query, trackId, windowId);
    d->exec();
    delete d;
}

void DlgTracking::loadTrack(const QString &query, int trackId, const QString &windowId)
{
    DoubleDatabase db;
    db[":f_table"] = trackId;
    db[":f_rec"] = windowId;
    db[":f_reservation"] = windowId;
    db[":f_invoice"] = windowId;
    db.setDatabase(TrackControl::fDbHost, TrackControl::fDbDb, TrackControl::fDbUser, TrackControl::fDbPass, 1);
    db.open(true, false);
    db.exec(query);
    Utils::fillTableWithData(ui->tblData, db.fDbRows);
    db.close();
}

void DlgTracking::on_chOld_clicked(bool checked)
{
    DoubleDatabase fDD(true, doubleDatabase);
    if (checked) {
        fDD[":f_windowId"] = fWindow;
        QString query = "select f_comp, f_date, f_time, f_user, "
                "f_key, f_old, f_new "
                "from f_changes_tracking "
                "where f_windowId=:f_windowId "
                "order by f_date, f_time";
        fDD.exec(query);
        Utils::fillTableWithData(ui->tblData, fDD.fDbRows);
        DoubleDatabase db;
        db.setDatabase("10.1.0.44", "hna", "root", "rootjan2018", 1);
        db.open(true, false);
        db[":f_windowId"] = fWindow;
        db.exec(query);
        db.close();
        for (int i = 0; i < db.rowCount(); i++) {
            Utils::tableAppendRowData(ui->tblData, db.fDbRows.at(i), Qt::DisplayRole);
        }
    } else {
        QString query = "select f_comp, f_date, f_time, f_user, "
                "f_action, f_value1, f_value2 "
                "from airlog.log "
                "where f_type=:f_table and (f_rec=:f_rec or f_invoice=:f_invoice or f_reservation=:f_reservation) "
                "order by f_date, f_time";
        DoubleDatabase db;
        db[":f_table"] = fTrack;
        db[":f_rec"] = fWindow;
        db[":f_reservation"] = fWindow;
        db[":f_invoice"] = fWindow;
        db.setDatabase(TrackControl::fDbHost, TrackControl::fDbDb, TrackControl::fDbUser, TrackControl::fDbPass, 1);
        db.open(true, false);
        db.exec(query);
        db.close();
        Utils::fillTableWithData(ui->tblData, db.fDbRows);
    }


}