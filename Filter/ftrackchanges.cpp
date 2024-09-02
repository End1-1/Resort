#include "ftrackchanges.h"
#include "ui_ftrackchanges.h"
#include "wreportgrid.h"
#include "cachetrackingtables.h"
#include "cacheusers.h"
#include "dlgclearlog.h"

FTrackChanges::FTrackChanges(QWidget *parent) :
    WFilterBase(parent),
    ui(new Ui::FTrackChanges)
{
    ui->setupUi(this);
    fReportGrid->fModel->fDD.setDatabase(TrackControl::fDbHost, TrackControl::fDbDb, TrackControl::fDbUser,
                                         TrackControl::fDbPass);
    ui->deStart->setDate(QDate::currentDate().addDays(-30));
    ui->deEnd->setDate(QDate::currentDate());
    ui->leType->setSelector(this, cache(cid_tracking_tables), ui->leType);
    ui->leUser->setSelector(this, cache(cid_users), ui->leUser);
}

FTrackChanges::~FTrackChanges()
{
    delete ui;
}

void FTrackChanges::apply(WReportGrid *rg)
{
    if (!fPreferences.getDb(def_show_logs).toBool()) {
        message_error(tr("Logs disabled"));
        return;
    }
    QString where = "where (c.f_date between '"
                    + ui->deStart->date().toString(def_mysql_date_format) + "' and '"
                    + ui->deEnd->date().toString(def_mysql_date_format) + "') "
                    + "and (c.f_time between '"
                    + ui->teStart->time().toString("HH:mm") + "' and '"
                    + ui->teEnd->time().toString("HH:mm") + "') ";
    if (!ui->leUser->fHiddenText.isEmpty()) {
        where += " and c.f_user in (" + ui->leUser->fHiddenText + ") ";
    }
    if (!ui->leType->fHiddenText.isEmpty()) {
        where += " and c.f_table in (" + ui->leType->fHiddenText + ") ";
    }
    where += " order by c.f_id desc ";
    rg->fModel->fDD.setDatabase(TrackControl::fDbHost, TrackControl::fDbDb, TrackControl::fDbUser, TrackControl::fDbPass);
    buildQuery(rg, where);
}

QWidget *FTrackChanges::firstElement()
{
    return ui->deStart;
}

QWidget *FTrackChanges::lastElement()
{
    return ui->deEnd;
}

void FTrackChanges::on_btnClearLog_clicked()
{
    DlgClearLog *d = new DlgClearLog(this);
    d->exec();
    delete d;
    apply(fReportGrid);
}
