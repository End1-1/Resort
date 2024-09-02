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
    DoubleDatabase dd;
    QString w2 = "-----";
    if (windowId.left(2).toLower() == "in") {
        dd[":f_invoice"] = windowId;
        dd.exec("select f_id from f_reservation where f_invoice=:f_invoice");
        if (dd.nextRow()) {
            w2 = dd.getString(0);
        }
    }
    if (windowId.left(2).toLower() == "rs") {
        dd[":f_id"] = windowId;
        dd.exec("select f_invoice from f_reservation where f_id=:f_id");
        if (dd.nextRow()) {
            w2 = dd.getString(0);
        }
    }
    QString query = QString("select f_comp, f_date, f_time, f_user, "
                            "f_action, f_value1, f_value2 "
                            "from airlog.log "
                            "where (f_rec='%1' or f_invoice='%1' or f_reservation='%1') "
                            "or (f_rec='%2' or f_invoice='%2' or f_reservation='%2') "
                            "order by f_date desc, f_time desc").arg(windowId).arg(w2);
    d->loadTrack(query, trackId, windowId);
    d->exec();
    delete d;
}

void DlgTracking::showTracking(const QString &windowId)
{
    if (windowId.isEmpty()) {
        return;
    }
    if (!r__(cr__tracking_chnages_individual)) {
        message_error(tr("Access denied"));
        return;
    }
    if (!fPreferences.getDb(def_show_logs).toBool()) {
        message_error(tr("Logs disabled"));
        return;
    }
    DlgTracking *d = new DlgTracking(fPreferences.getDefaultParentForMessage());
    d->fWindow = windowId;
    QString query = QString("select f_comp, f_date, f_time, f_user, "
                            "f_action, f_value1, f_value2 "
                            "from airlog.log "
                            "where (f_rec='%1' or f_invoice='%1' or f_reservation='%1') "
                            "order by f_date desc, f_time desc").arg(windowId);
    d->loadTrack(query, 0, windowId);
    d->exec();
    delete d;
}

void DlgTracking::loadTrack(const QString &query, int trackId, const QString &windowId)
{
    Q_UNUSED(trackId);
    DoubleDatabase db;
    QStringList sl = TrackControl::currentDb();
    db.setDatabase(sl.at(0), sl.at(1), sl.at(2), sl.at(3));
    db.open();
    if (!db.exec(query)) {
        message_error(db.fLastError);
        return;
    }
    Utils::fillTableWithData(ui->tblData, db.fDbRows);
    db.close();
}

void DlgTracking::on_chOld_clicked(bool checked)
{
    DoubleDatabase fDD;
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
        db.setDatabase("10.1.0.33", "testb", "root", "rootjan2018");
        db.open();
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
        QStringList sl = TrackControl::currentDb();
        db.setDatabase(sl.at(0), sl.at(1), sl.at(2), sl.at(3));
        db.open();
        db.exec(query);
        db.close();
        Utils::fillTableWithData(ui->tblData, db.fDbRows);
    }
}
