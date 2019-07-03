#include "trackcontrol.h"
#include "base.h"
#include "defines.h"
#include "eqcheckbox.h"
#include "eqlineedit.h"
#include "eqdateedit.h"
#include "eqtextedit.h"
#include "eqtimeedit.h"
#include "eqspinbox.h"
#include "edateedit.h"
#include "eqdoubleedit.h"
#include "doubledatabase.h"
#include "eqcombobox.h"
#include <QHostInfo>
#include <QSqlError>
#include <QSqlQuery>
#include <QTimeEdit>
#include <QSpinBox>

QString TrackControl::fDbHost;
QString TrackControl::fDbDb;
QString TrackControl::fDbUser;
QString TrackControl::fDbPass;
QString TrackControl::fDbHostReserve;
QString TrackControl::fDbDbReserve;
QString TrackControl::fDbUserReserve;
QString TrackControl::fDbPassReserve;

static QString dbHost;
static QString dbDb;
static QString dbUser;
static QString dbPass;
static bool fail = false;

static const QColor COLOR_CHANGED = QColor::fromRgb(255, 255, 150);
static const QString QUERY  = "insert into airlog.log (f_comp, f_date, f_time, f_user, f_type, f_rec, f_invoice, f_reservation, f_action, f_value1, f_value2) "
                "values (:f_comp, :f_date, :f_time, :f_user, :f_type, :f_rec, :f_invoice, :f_reservation, :f_action, :f_value1, :f_value2)";

QStringList TrackControl::currentDb()
{
    QStringList sl;
    sl << dbHost
       << dbDb
       << dbUser
       << dbPass;
    return sl;
}

TrackControl::TrackControl(int table)
{
    fRecord = "-";
    fInvoice = "-";
    fReservation = "-";
    fTable = table;
}

bool TrackControl::contains(QWidget *w)
{
    for (TrackWidget *tw: fTrackWidgets) {
        if (w == tw->fWidget) {
            return true;
        }
    }
    return false;
}

TrackControl::~TrackControl()
{
    qDeleteAll(fTrackWidgets);
}

TrackControl &TrackControl::addWidget(QWidget *w, const QString &key)
{
    TrackWidget *t = new TrackWidget();
    t->fKey = key;
    t->fWidget = w;
    setOldValue(*t);
    fTrackWidgets << t;
    fTrackWidgetsMap.insert(key, t);
    if (isLineEdit(w)) {
        connect(static_cast<EQLineEdit*>(w), SIGNAL(textChanged(QString)), this, SLOT(lineEditTextChanged(QString)));
    } else if (isDateEdit(w)) {
        connect(static_cast<EQDateEdit*>(w), SIGNAL(dateChanged(QDate)), this, SLOT(dateEditChanged(QDate)));
    } else if (isTextEdit(w)) {
        connect(static_cast<EQTextEdit*>(w), SIGNAL(textChanged()), this, SLOT(textEditTextChanged()));
    } else if (isCheckBox(w)) {
        connect(static_cast<EQCheckBox*>(w), SIGNAL(clicked()), this, SLOT(checkBoxClicked()));
    } else if (isComboBox(w)) {
        connect(static_cast<QComboBox*>(w), SIGNAL(currentIndexChanged(int)), this, SLOT(comboIndexChanged(int)));
    } else if(isSpinBox(w)) {
        connect(static_cast<QSpinBox*>(w), SIGNAL(valueChanged(int)), this, SLOT(spinValueChanged(int)));
    } else if (isTimeEdit(w)) {
        connect(static_cast<QTimeEdit*>(w), SIGNAL(timeChanged(QTime)), this, SLOT(timeEditChanged(QTime)));
    } else if (isEDateEdit(w)) {
        connect(static_cast<EDateEdit*>(w), SIGNAL(textChanged(QString)), this, SLOT(edateTextChanged(QString)));
    } else if (isDoubleEdit(w)) {
        connect(static_cast<EQDoubleEdit*>(w), SIGNAL(textChanged(QString)), this, SLOT(lineEditTextChanged(QString)));
    }
    return *this;
}

QListIterator<TrackWidget *> TrackControl::widgetIterator()
{
    return QListIterator<TrackWidget*>(fTrackWidgets);
}

bool TrackControl::hasChanges()
{
    if (fTrackWidgets.count() == 0 && fMsgMsg.count() == 0) {
        return false;
    }
    foreach (TrackWidget *t, fTrackWidgets) {
        if (isTrackChanged(*t))
            return true;
    }
    if (fMsgMsg.count() > 0) {
        return true;
    }
    return false;
}

void TrackControl::saveChanges()
{
    if (Base::fPreferences.getDb(def_no_tracking_changes).toBool()) {
        resetChanges();
        return;
    }
    if (!hasChanges()) {
        return;
    }
    foreach (TrackWidget *t, fTrackWidgets) {
        if (isTrackChanged(*t)) {
            this->insert(t->fKey, t->fOldValue, getNewValue(*t));
            t->fOldValue = "";
            setOldValue(*t);
        }
    }
    for (int i = 0; i < fMsgMsg.count(); i++) {
        this->insert(fMsgMsg[i], fMsgOld[i], fMsgNew[i]);
    }
    fMsgMsg.clear();
    fMsgOld.clear();
    fMsgNew.clear();
}

void TrackControl::resetChanges()
{
    foreach (TrackWidget *t, fTrackWidgets) {
        setOldValue(*t);
    }
}

bool TrackControl::isValueChanged(QWidget *w)
{
    foreach (TrackWidget *t, fTrackWidgets) {
        if (t->fWidget == w) {
            return isTrackChanged(*t);
        }
    }
    return false;
}

QString TrackControl::oldValue(QWidget *w)
{
    foreach (TrackWidget *t, fTrackWidgets) {
        if (t->fWidget == w) {
            return t->fOldValue;
        }
    }
    return "";
}

QString TrackControl::newValue(const QString &trackName)
{
    if (!fTrackWidgetsMap.contains(trackName)) {
        return "No widget for " + trackName;
    }
    return getNewValue(*fTrackWidgetsMap[trackName]);
}

void TrackControl::insertMessage(const QString &msg, const QString &v1, const QString &v2)
{
    fMsgMsg << msg;
    fMsgOld << v1;
    fMsgNew << v2;
}

void TrackControl::insert(const QString &action, const QVariant &value1, const QVariant &value2)
{
    if (fail) {
        return;
    }
    if (Base::fPreferences.getDb(def_no_tracking_changes).toBool()) {
        return;
    }
    DoubleDatabase db(dbHost, dbDb, dbUser, dbPass);
    if (!db.open(true, false)) {
        if (fail) {
            db.logEvent("Track control: " + db.fLastError);
            return;
        }
        dbHost = fDbHostReserve;
        dbDb = fDbDbReserve;
        dbUser = fDbUserReserve;
        dbPass = fDbPassReserve;
        db.setDatabase(dbHost, dbDb, dbUser, dbPass, 1);
        if (!db.open(true, false)) {
            fail = true;
            db.logEvent("Track control: " + db.fLastError);
            return;
        }
    }
    db[":f_comp"] = QHostInfo::localHostName().toUpper();
    db[":f_date"] = QDate::currentDate();
    db[":f_time"] = QTime::currentTime();
    db[":f_user"] = Base::fPreferences.getLocal(def_working_username).toString();
    db[":f_type"] = fTable;
    db[":f_rec"] = fRecord;
    db[":f_invoice"] = fInvoice;
    db[":f_reservation"] = fReservation;
    db[":f_action"] = action;
    db[":f_value1"] = value1;
    db[":f_value2"] = value2;
    if(!db.exec(QUERY)) {
        db.logEvent("TrackControl: " + db.fLastError);
        return;
    }
}

void TrackControl::del()
{
    if (Base::fPreferences.getDb(def_no_tracking_changes).toBool()) {
        return;
    }
    DoubleDatabase db(dbHost, dbDb, dbUser, dbPass);
    if (!db.open(true, false)) {
        QMessageBox::critical(nullptr, tr("TrackControl error"), db.fLastError);
        return;
    }
    db["f_invoice"] = fInvoice;
    db["f_reservation"] = fReservation;
    if (!db.exec("delete from airlog.log where f_invoice=:f_invoice or f_reservation=:f_reservation")) {
        QMessageBox::critical(nullptr, tr("TrackControl error"), db.fLastError);
        return;
    }
}

void TrackControl::setFirstConnection()
{
    dbHost = fDbHost;
    dbDb = fDbDb;
    dbUser = fDbUser;
    dbPass = fDbPass;
    fail = false;
}

void TrackControl::insert(int table, const QString &action, const QVariant &value1, const QVariant &value2, const QString &record, const QString &invoice, const QString &reservation)
{
    TrackControl tc(table);
    tc.fRecord = record;
    tc.fInvoice = invoice;
    tc.fReservation = reservation;
    tc.insert(action, value1, value2);
}

void TrackControl::removeHistory(const QString &inv, const QString &res)
{
    TrackControl tc(0);
    tc.fInvoice = inv;
    tc.fReservation = res;
    tc.del();
}

bool TrackControl::isTrackChanged(TrackWidget &t)
{
    return t.fOldValue.compare(getNewValue(t)) != 0;
}

void TrackControl::setOldValue(TrackWidget &t)
{
    if (isLineEdit(t.fWidget)) {
        t.fOldValue = static_cast<QLineEdit*>(t.fWidget)->text();
        static_cast<EQLineEdit*>(t.fWidget)->setBgColor(Qt::white);
    } else if (isTimeEdit(t.fWidget)) {
        t.fOldValue = static_cast<QTimeEdit*>(t.fWidget)->time().toString(def_time_format);
        static_cast<EQTimeEdit*>(t.fWidget)->setBgColor(Qt::white);
    } else if (isDateEdit(t.fWidget)) {
        t.fOldValue = static_cast<QDateEdit*>(t.fWidget)->date().toString(def_date_format);
        static_cast<EQDateEdit*>(t.fWidget)->setBgColor(Qt::white);
    } else if(isCheckBox(t.fWidget)) {
        t.fOldValue = static_cast<QCheckBox*>(t.fWidget)->isChecked() ? "1" : "0";
        static_cast<QCheckBox*>(t.fWidget)->setStyleSheet("");
    } else if (isTextEdit(t.fWidget)) {
        t.fOldValue = static_cast<QTextEdit*>(t.fWidget)->toPlainText();
        static_cast<EQTextEdit*>(t.fWidget)->setBgColor(Qt::white);
    } else if (isComboBox(t.fWidget)) {
        t.fOldValue = static_cast<QComboBox*>(t.fWidget)->currentText();
        static_cast<QComboBox*>(t.fWidget)->setStyleSheet("");
    } else if (isSpinBox(t.fWidget)) {
        t.fOldValue = QString::number(static_cast<QSpinBox*>(t.fWidget)->value());
        static_cast<EQSpinBox*>(t.fWidget)->setBgColor(Qt::white);
    } else if (isEDateEdit(t.fWidget)) {
        t.fOldValue = static_cast<EDateEdit*>(t.fWidget)->text();
        static_cast<EDateEdit*>(t.fWidget)->setStyleSheet("");
    } else if (isDoubleEdit(t.fWidget)) {
        t.fOldValue = static_cast<EQDoubleEdit*>(t.fWidget)->text();
        static_cast<EQDoubleEdit*>(t.fWidget)->setBgColor(Qt::white);
    }
}

QString TrackControl::getNewValue(TrackWidget &t)
{
    if (isLineEdit(t.fWidget)) {
        return static_cast<QLineEdit*>(t.fWidget)->text();
    } else if (isTimeEdit(t.fWidget)) {
        return static_cast<QTimeEdit*>(t.fWidget)->time().toString(def_time_format);
    } else if (isDateEdit(t.fWidget)) {
        return static_cast<QDateEdit*>(t.fWidget)->date().toString(def_date_format);
    } else if (isCheckBox(t.fWidget)) {
        return (static_cast<QCheckBox*>(t.fWidget)->isChecked() ? "1" : "0");
    } else if (isTextEdit(t.fWidget)) {
        return static_cast<QTextEdit*>(t.fWidget)->toPlainText();
    } else if (isComboBox(t.fWidget)) {
        return static_cast<QComboBox*>(t.fWidget)->currentText();
    } else if (isSpinBox(t.fWidget)) {
        return QString::number(static_cast<QSpinBox*>(t.fWidget)->value());
    } else if (isEDateEdit(t.fWidget)) {
        return static_cast<EDateEdit*>(t.fWidget)->text();
    } else  if (isDoubleEdit(t.fWidget)) {
        return static_cast<EQDoubleEdit*>(t.fWidget)->text();
    }
    return "";
}

void TrackControl::lineEditTextChanged(const QString &text)
{
    EQLineEdit *l = static_cast<EQLineEdit*>(sender());
    if (text != oldValue(l)) {
        l->setBgColor(COLOR_CHANGED);
    } else {
        l->setBgColor(Qt::white);
    }
}

void TrackControl::edateTextChanged(const QString &text)
{
    EDateEdit *e = static_cast<EDateEdit*>(sender());
    if (!e->valid()) {
        e->setStyleSheet("background:red");
        return;
    }
    if (text != oldValue(e)) {
        e->setStyleSheet("background:yellow");
    } else {
        e->setStyleSheet("");
    }
}

void TrackControl::dateEditChanged(const QDate &date)
{
    EQDateEdit *d = static_cast<EQDateEdit*>(sender());
    if (!d->date().isValid()) {
        d->setBgColor(Qt::red);
    }
    if (date.toString(def_date_format) == oldValue(d)) {
        d->setBgColor(Qt::white);
    } else {
        d->setBgColor(COLOR_CHANGED);
    }
}

void TrackControl::textEditTextChanged()
{
    EQTextEdit *t = static_cast<EQTextEdit*>(sender());
    if (t->toPlainText() == oldValue(t)) {
        t->setBgColor(Qt::white);
    } else {
        t->setBgColor(COLOR_CHANGED);
    }
}

void TrackControl::checkBoxClicked()
{
    QString styleUnchanged("");
    QString styleChanged("QCheckBox::indicator:checked {image: url(:/images/ch_checked_changed.png)} \
                        QCheckBox::indicator:unchecked {image: url(:/images/ch_unchecked_changed.png)}");
    EQCheckBox *c = static_cast<EQCheckBox*>(sender());
    if (QString::number(c->isChecked()) == oldValue(c)) {
        c->setStyle(styleUnchanged);
    } else {
        c->setStyle(styleChanged);
    }
}

void TrackControl::comboIndexChanged(int index)
{
    Q_UNUSED(index)
    QComboBox *c = static_cast<QComboBox*>(sender());
    if (c->currentText() != oldValue(c)) {
        c->setStyleSheet("QComboBox {background-color:rgb(255,255,150)}");
    } else {
        c->setStyleSheet("");
    }
}

void TrackControl::spinValueChanged(int value)
{
    EQSpinBox *s = static_cast<EQSpinBox*>(sender());
    if (QString::number(value) == oldValue(s)) {
        s->setBgColor(Qt::white);
    } else {
        s->setBgColor(COLOR_CHANGED);
    }
}

void TrackControl::timeEditChanged(const QTime &time)
{
    EQTimeEdit *t = static_cast<EQTimeEdit*>(sender());
    if (time.toString(def_time_format) == oldValue(t)) {
        t->setBgColor(Qt::white);
    } else {
        t->setBgColor(COLOR_CHANGED);
    }
}

TrackWidget::TrackWidget()
{
    fWidget = nullptr;
}

bool cmpWidgetName(QWidget *w, const QString &with)
{
    return QString(w->metaObject()->className()).compare(with, Qt::CaseInsensitive) == 0;
}

bool isLineEdit(QWidget *w)
{
    bool cmpOK = cmpWidgetName(w, "QLineEdit")
            || cmpWidgetName(w, "EQLineEdit");
    return cmpOK;
}

bool isTimeEdit(QWidget *w)
{
    return cmpWidgetName(w, "QTimeEdit") || cmpWidgetName(w, "EQTimeEdit");
}

bool isDateEdit(QWidget *w)
{
    return cmpWidgetName(w, "QDateEdit") || cmpWidgetName(w, "EQDateEdit");
}

bool isCheckBox(QWidget *w)
{
    return cmpWidgetName(w, "QCheckBox") || cmpWidgetName(w, "EQCheckBox");
}

bool isTextEdit(QWidget *w)
{
    return cmpWidgetName(w, "QTextEdit") || cmpWidgetName(w, "EQTextEdit") || cmpWidgetName(w, "QPlainTextEdit");
}

bool isComboBox(QWidget *w)
{
    return cmpWidgetName(w, "QComboBox") || cmpWidgetName(w, "EQComboBox");
}

bool isSpinBox(QWidget *w)
{
    return cmpWidgetName(w, "QSpinBox") || cmpWidgetName(w, "EQSpinBox");
}

bool isColorLineEdit(QWidget *w)
{
    return cmpWidgetName(w, "EColorLineEdit");
}

bool isEDateEdit(QWidget *w)
{
    return cmpWidgetName(w, "EDateEdit");
}

bool isComboCompleter(QWidget *w)
{
    return cmpWidgetName(w, "EComboBoxCompleter");
}

bool isComboMonth(QWidget *w)
{
    return cmpWidgetName(w, "EComboMonth");
}

bool isDoubleEdit(QWidget *w)
{
    return cmpWidgetName(w, "EQDoubleEdit");
}
