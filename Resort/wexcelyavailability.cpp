#include "wexcelyavailability.h"
#include "ui_wexcelyavailability.h"

#include "excely/pms/pmsconnectclient.h"
#include "excelyappconfig.h"
#include "excelyavailpusher.h"
#include "message.h"

#include <QApplication>
#include <QDateTime>
#include <QHeaderView>
#include <QMap>
#include <QSet>
#include <QTableWidgetItem>

#include <algorithm>

WExcelyAvailability::WExcelyAvailability(QWidget *parent)
    : BaseWidget(parent)
    , ui(new Ui::WExcelyAvailability)
{
    ui->setupUi(this);
    ui->deStart->setDate(QDate::currentDate());
    ui->deEnd->setDate(QDate::currentDate().addDays(30));
    ui->dePriceStart->setDate(QDate::currentDate());
    ui->dePriceEnd->setDate(QDate::currentDate().addDays(30));
    ui->spMinLOS->setValue(-1);
    ui->cbInvBlock->setEnabled(false);
    on_rbRatePlan_toggled(true);
    setupPricesTable();

    const ExcelyAppConfig cfg = ExcelyAppConfig::load();
    ui->leHotelCode->setText(cfg.pms.hotelCode);
}

WExcelyAvailability::~WExcelyAvailability()
{
    delete ui;
}

void WExcelyAvailability::setupTab()
{
    setupTabTextAndIcon(tr("Excely availability"), QStringLiteral(":/images/configure.png"));
}

void WExcelyAvailability::setupPricesTable()
{
    ui->cbPriceKind->clear();
    ui->cbPriceKind->addItem(tr("Base occupancy (adults)"), KindBase);
    ui->cbPriceKind->addItem(tr("Extra adult bed"), KindExtraAdult);
    ui->cbPriceKind->addItem(tr("Extra child bed"), KindExtraChild);
    ui->cbPriceKind->addItem(tr("Child without bed"), KindChildNoBed);
    ui->cbPriceKind->setCurrentIndex(0);

    ui->tblPrices->setColumnCount(ColCount);
    ui->tblPrices->setHorizontalHeaderLabels({
        tr("Room type"),
        tr("Rate plan"),
        tr("Start"),
        tr("End"),
        tr("Price"),
        tr("Currency"),
        tr("Type"),
        tr("Detail"),
    });
    ui->tblPrices->horizontalHeader()->setStretchLastSection(true);
    ui->tblPrices->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tblPrices->setEditTriggers(QAbstractItemView::NoEditTriggers);
    updatePriceKindUi();
}

QString WExcelyAvailability::priceKindLabel(int kind) const
{
    switch (kind) {
    case KindExtraAdult:
        return tr("Extra adult");
    case KindExtraChild:
        return tr("Extra child");
    case KindChildNoBed:
        return tr("Child no bed");
    case KindBase:
    default:
        return tr("Base");
    }
}

void WExcelyAvailability::updatePriceKindUi()
{
    const int kind = ui->cbPriceKind->currentData().toInt();
    const bool isBase = kind == KindBase;
    const bool isExtraAdult = kind == KindExtraAdult;
    const bool isChild = kind == KindExtraChild || kind == KindChildNoBed;

    ui->lbGuests->setText(isBase ? tr("Guests (adults)") : tr("Max extra guests"));
    ui->spGuests->setEnabled(isBase || isExtraAdult);
    if (isExtraAdult && ui->spGuests->value() < 1) {
        ui->spGuests->setValue(1);
    }
    ui->spAgeBucket->setEnabled(kind == KindExtraChild);
    ui->spMinAge->setEnabled(isChild);
    ui->spMaxAge->setEnabled(isChild);
    if (kind == KindChildNoBed && ui->spMinAge->value() < 0 && ui->spMaxAge->value() < 0) {
        ui->spMinAge->setValue(2);
        ui->spMaxAge->setValue(18);
    }
}

void WExcelyAvailability::on_cbPriceKind_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    updatePriceKindUi();
}

void WExcelyAvailability::appendLog(const QString &line)
{
    ui->teLog->appendPlainText(
        QStringLiteral("[%1] %2")
            .arg(QDateTime::currentDateTime().toString(QStringLiteral("HH:mm:ss")), line));
}

bool WExcelyAvailability::ensureClient(Excely::Pms::Config *cfg, QString *errorText)
{
    const ExcelyAppConfig app = ExcelyAppConfig::load();
    if (!app.hasCredentials(errorText)) {
        return false;
    }
    ui->leHotelCode->setText(app.pms.hotelCode);
    if (cfg) {
        *cfg = app.pms;
    }
    return true;
}

bool WExcelyAvailability::ratePlanAllowsPriceUpload(const QString &ratePlanCode) const
{
    for (const Excely::Pms::RatePlanInfo &rp : m_catalog.ratePlans) {
        if (rp.ratePlanCode == ratePlanCode) {
            return rp.priceUploadAllowed;
        }
    }
    return true;
}

void WExcelyAvailability::fillCombosFromCatalog()
{
    ui->cbRoomType->clear();
    ui->cbRatePlan->clear();
    ui->cbInvBlock->clear();
    ui->cbPriceRoomType->clear();
    ui->cbPriceRatePlan->clear();

    for (const Excely::Pms::RoomTypeInfo &rt : m_catalog.roomTypes) {
        const QString label = rt.name.isEmpty()
                ? rt.roomTypeCode
                : QStringLiteral("%1 — %2").arg(rt.roomTypeCode, rt.name);
        ui->cbRoomType->addItem(label, rt.roomTypeCode);
        ui->cbPriceRoomType->addItem(label, rt.roomTypeCode);
    }

    QSet<QString> blocks;
    for (const Excely::Pms::RatePlanInfo &rp : m_catalog.ratePlans) {
        if (!rp.ratePlanCode.isEmpty()) {
            QString label = rp.name.isEmpty()
                    ? rp.ratePlanCode
                    : QStringLiteral("%1 — %2").arg(rp.ratePlanCode, rp.name);
            if (!rp.priceUploadAllowed) {
                label += tr(" [prices locked]");
            }
            ui->cbRatePlan->addItem(label, rp.ratePlanCode);
            ui->cbPriceRatePlan->addItem(label, rp.ratePlanCode);
        }
        if (!rp.invBlockCode.isEmpty() && !blocks.contains(rp.invBlockCode)) {
            blocks.insert(rp.invBlockCode);
            ui->cbInvBlock->addItem(rp.invBlockCode, rp.invBlockCode);
        }
    }
}

void WExcelyAvailability::on_rbRatePlan_toggled(bool checked)
{
    ui->cbRatePlan->setEnabled(checked);
    ui->cbInvBlock->setEnabled(!checked);
}

void WExcelyAvailability::on_btnRefreshCatalog_clicked()
{
    QString err;
    Excely::Pms::Config cfg;
    if (!ensureClient(&cfg, &err)) {
        message_error(err);
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);
    Excely::Pms::PmsConnectClient client(cfg);
    Excely::Pms::HotelCatalog catalog;
    QVector<Excely::Channel::PmsError> errors;
    const bool ok = client.hotelAvail(&catalog, &errors);
    QApplication::restoreOverrideCursor();

    if (!ok) {
        QStringList lines;
        for (const Excely::Channel::PmsError &e : errors) {
            lines << QStringLiteral("%1: %2").arg(e.code).arg(e.text);
        }
        message_error(lines.isEmpty() ? tr("Failed to load Excely catalog") : lines.join(QLatin1Char('\n')));
        appendLog(tr("Catalog refresh failed"));
        return;
    }

    m_catalog = catalog;
    fillCombosFromCatalog();
    int uploadable = 0;
    for (const Excely::Pms::RatePlanInfo &rp : m_catalog.ratePlans) {
        if (rp.priceUploadAllowed) {
            ++uploadable;
        }
    }
    appendLog(tr("Catalog: %1 room types, %2 rate plans (%3 allow price upload)")
                  .arg(m_catalog.roomTypes.size())
                  .arg(m_catalog.ratePlans.size())
                  .arg(uploadable));
}

bool WExcelyAvailability::buildAvailMessage(Excely::Pms::AvailStatusMessage *msg, QString *errorText) const
{
    if (!msg) {
        return false;
    }
    msg->invTypeCode = ui->cbRoomType->currentData().toString();
    if (msg->invTypeCode.isEmpty()) {
        if (errorText) {
            *errorText = tr("Select a room type (refresh catalog first)");
        }
        return false;
    }

    if (ui->rbRatePlan->isChecked()) {
        msg->ratePlanCode = ui->cbRatePlan->currentData().toString();
        msg->invBlockCode.clear();
        if (msg->ratePlanCode.isEmpty()) {
            if (errorText) {
                *errorText = tr("Select a rate plan");
            }
            return false;
        }
    } else {
        const QString typed = ui->cbInvBlock->currentText().trimmed();
        const QString data = ui->cbInvBlock->currentData().toString().trimmed();
        msg->invBlockCode = !typed.isEmpty() ? typed : data;
        msg->ratePlanCode.clear();
        if (msg->invBlockCode.isEmpty()) {
            if (errorText) {
                *errorText = tr("Select or type an inventory block code");
            }
            return false;
        }
    }

    msg->start = ui->deStart->date();
    msg->end = ui->deEnd->date();
    if (!msg->start.isValid() || !msg->end.isValid() || msg->end < msg->start) {
        if (errorText) {
            *errorText = tr("Invalid date range");
        }
        return false;
    }

    msg->sendBookingLimit = true;
    msg->bookingLimit = ui->spBookingLimit->value();

    switch (ui->cbStatus->currentIndex()) {
    case 0:
        msg->restrictionStatus = QStringLiteral("Open");
        break;
    case 1:
        msg->restrictionStatus = QStringLiteral("Close");
        break;
    default:
        msg->restrictionStatus.clear();
        break;
    }

    msg->minLOS = ui->spMinLOS->value();
    return true;
}

bool WExcelyAvailability::sendAvailMessages(const QVector<Excely::Pms::AvailStatusMessage> &messages)
{
    QString err;
    Excely::Pms::Config cfg;
    if (!ensureClient(&cfg, &err)) {
        message_error(err);
        return false;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);
    Excely::Pms::PmsConnectClient client(cfg);
    QVector<Excely::Channel::PmsError> errors;
    const bool ok = client.hotelAvailNotif(messages, &errors);
    QApplication::restoreOverrideCursor();

    if (!ok) {
        QStringList lines;
        for (const Excely::Channel::PmsError &e : errors) {
            lines << QStringLiteral("%1: %2").arg(e.code).arg(e.text);
        }
        message_error(lines.isEmpty() ? tr("HotelAvailNotif failed") : lines.join(QLatin1Char('\n')));
        appendLog(tr("Availability upload failed"));
        return false;
    }

    for (const Excely::Channel::PmsError &e : errors) {
        appendLog(QStringLiteral("WARN %1: %2").arg(e.code).arg(e.text));
    }
    ExcelyAvailPusher::rememberUploaded(messages);
    return true;
}

bool WExcelyAvailability::sendRateMessages(const QVector<Excely::Pms::RateAmountMessage> &messages)
{
    QString err;
    Excely::Pms::Config cfg;
    if (!ensureClient(&cfg, &err)) {
        message_error(err);
        return false;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);
    Excely::Pms::PmsConnectClient client(cfg);
    QVector<Excely::Channel::PmsError> errors;
    const bool ok = client.hotelRateAmountNotif(messages, &errors);
    QApplication::restoreOverrideCursor();

    if (!ok) {
        QStringList lines;
        for (const Excely::Channel::PmsError &e : errors) {
            lines << QStringLiteral("%1: %2").arg(e.code).arg(e.text);
        }
        message_error(lines.isEmpty() ? tr("HotelRateAmountNotif failed") : lines.join(QLatin1Char('\n')));
        appendLog(tr("Price upload failed"));
        return false;
    }

    for (const Excely::Channel::PmsError &e : errors) {
        appendLog(QStringLiteral("WARN %1: %2").arg(e.code).arg(e.text));
    }
    return true;
}

void WExcelyAvailability::on_btnUpload_clicked()
{
    Excely::Pms::AvailStatusMessage msg;
    QString err;
    if (!buildAvailMessage(&msg, &err)) {
        message_error(err);
        return;
    }
    if (sendAvailMessages({msg})) {
        const QString target = !msg.invBlockCode.isEmpty()
                ? QStringLiteral("invBlock=%1").arg(msg.invBlockCode)
                : QStringLiteral("ratePlan=%1").arg(msg.ratePlanCode);
        const QString status = msg.restrictionStatus.isEmpty()
                ? QStringLiteral("(no status)")
                : msg.restrictionStatus;
        const QString los = msg.minLOS > 0
                ? QStringLiteral("SetMinLOS=%1").arg(msg.minLOS)
                : (msg.minLOS == 0 ? QStringLiteral("RemoveMinLOS") : QStringLiteral("(no MinLOS)"));
        appendLog(tr("Avail uploaded %1 %2 / %3–%4 limit=%5 status=%6 %7")
                      .arg(msg.invTypeCode, target,
                           msg.start.toString(Qt::ISODate),
                           msg.end.toString(Qt::ISODate))
                      .arg(msg.bookingLimit)
                      .arg(status, los));
        message_info(tr("Availability uploaded"));
    }
}

void WExcelyAvailability::on_btnResyncYear_clicked()
{
    Excely::Pms::AvailStatusMessage msg;
    QString err;
    if (!buildAvailMessage(&msg, &err)) {
        message_error(err);
        return;
    }
    msg.end = msg.start.addDays(365);
    ui->deEnd->setDate(msg.end);
    if (sendAvailMessages({msg})) {
        const QString target = !msg.invBlockCode.isEmpty()
                ? QStringLiteral("invBlock=%1").arg(msg.invBlockCode)
                : QStringLiteral("ratePlan=%1").arg(msg.ratePlanCode);
        const QString status = msg.restrictionStatus.isEmpty()
                ? QStringLiteral("(no status)")
                : msg.restrictionStatus;
        const QString los = msg.minLOS > 0
                ? QStringLiteral("SetMinLOS=%1").arg(msg.minLOS)
                : (msg.minLOS == 0 ? QStringLiteral("RemoveMinLOS") : QStringLiteral("(no MinLOS)"));
        appendLog(tr("Avail resync year: %1 %2 / %3–%4 limit=%5 status=%6 %7")
                      .arg(msg.invTypeCode, target,
                           msg.start.toString(Qt::ISODate),
                           msg.end.toString(Qt::ISODate))
                      .arg(msg.bookingLimit)
                      .arg(status, los));
        message_info(tr("Availability year resync uploaded"));
    }
}

void WExcelyAvailability::on_btnPushPmsDelta_clicked()
{
    const QDate start = ui->deStart->date();
    const QDate end = ui->deEnd->date();
    if (!start.isValid() || !end.isValid() || end < start) {
        message_error(tr("Invalid date range"));
        return;
    }
    QApplication::setOverrideCursor(Qt::WaitCursor);
    const ExcelyAvailPusher::Result r = ExcelyAvailPusher::pushFromPms(start, end, false);
    QApplication::restoreOverrideCursor();
    appendLog(r.summary());
    if (r.ok) {
        message_info(r.summary());
    } else {
        message_error(r.summary());
    }
}

void WExcelyAvailability::on_btnPushPmsYear_clicked()
{
    const QDate start = ui->deStart->date().isValid() ? ui->deStart->date() : QDate::currentDate();
    const QDate end = start.addDays(365);
    ui->deStart->setDate(start);
    ui->deEnd->setDate(end);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    const ExcelyAvailPusher::Result r = ExcelyAvailPusher::pushFromPms(start, end, false);
    QApplication::restoreOverrideCursor();
    appendLog(r.summary());
    if (r.ok) {
        message_info(r.summary());
    } else {
        message_error(r.summary());
    }
}

void WExcelyAvailability::on_btnPushPmsFull_clicked()
{
    const QDate start = QDate::currentDate();
    const QDate end = start.addDays(365);
    if (message_confirm(tr("Send PMS availability for every date %1–%2?\n"
                           "This overwrites quotas in Exely with PMS free rooms and resets the delta baseline.")
                            .arg(start.toString(Qt::ISODate), end.toString(Qt::ISODate)))
            != QDialog::Accepted) {
        return;
    }
    ui->deStart->setDate(start);
    ui->deEnd->setDate(end);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    const ExcelyAvailPusher::Result r = ExcelyAvailPusher::pushFromPms(start, end, true);
    QApplication::restoreOverrideCursor();
    appendLog(r.summary());
    if (r.ok) {
        message_info(r.summary());
    } else {
        message_error(r.summary());
    }
}

void WExcelyAvailability::on_btnAddPriceRow_clicked()
{
    const QString roomCode = ui->cbPriceRoomType->currentData().toString();
    const QString roomLabel = ui->cbPriceRoomType->currentText();
    const QString rateCode = ui->cbPriceRatePlan->currentData().toString();
    const QString rateLabel = ui->cbPriceRatePlan->currentText();
    if (roomCode.isEmpty() || rateCode.isEmpty()) {
        message_error(tr("Select room type and rate plan (refresh catalog first)"));
        return;
    }
    if (!ratePlanAllowsPriceUpload(rateCode)) {
        message_error(tr("Selected rate plan does not allow price upload (prices locked)"));
        return;
    }
    const QDate start = ui->dePriceStart->date();
    const QDate end = ui->dePriceEnd->date();
    if (!start.isValid() || !end.isValid() || end < start) {
        message_error(tr("Invalid date range"));
        return;
    }
    const int kind = ui->cbPriceKind->currentData().toInt();
    // Base occupancy needs price > 0; additional can be 0 (e.g. free child without bed)
    if (kind == KindBase && ui->dsPrice->value() <= 0.0) {
        message_error(tr("Enter price per night greater than zero"));
        return;
    }
    if (ui->dsPrice->value() < 0.0) {
        message_error(tr("Price cannot be negative"));
        return;
    }
    const QString currency = ui->leCurrency->text().trimmed().toUpper();
    if (currency.isEmpty()) {
        message_error(tr("Currency is required (e.g. AMD, EUR, USD)"));
        return;
    }
    if (kind == KindExtraChild
            && ui->spAgeBucket->value() < 0
            && (ui->spMinAge->value() < 0 || ui->spMaxAge->value() < 0)) {
        message_error(tr("Extra child: set Age bucket and/or Min–Max age"));
        return;
    }
    if (kind == KindChildNoBed
            && (ui->spMinAge->value() < 0 || ui->spMaxAge->value() < 0)) {
        message_error(tr("Child without bed: set Min and Max age (e.g. 2–18)"));
        return;
    }

    QString detail;
    switch (kind) {
    case KindExtraAdult:
        detail = tr("maxExtra=%1").arg(ui->spGuests->value());
        break;
    case KindExtraChild: {
        QStringList parts;
        if (ui->spAgeBucket->value() >= 0) {
            parts << tr("bucket=%1").arg(ui->spAgeBucket->value());
        }
        if (ui->spMinAge->value() >= 0 && ui->spMaxAge->value() >= 0) {
            parts << tr("age=%1-%2").arg(ui->spMinAge->value()).arg(ui->spMaxAge->value());
        }
        detail = parts.join(QLatin1Char(' '));
        break;
    }
    case KindChildNoBed:
        detail = tr("age=%1-%2 no bed")
                     .arg(ui->spMinAge->value())
                     .arg(ui->spMaxAge->value());
        break;
    case KindBase:
    default:
        detail = tr("guests=%1").arg(ui->spGuests->value());
        break;
    }

    const int row = ui->tblPrices->rowCount();
    ui->tblPrices->insertRow(row);

    auto *roomItem = new QTableWidgetItem(roomLabel);
    roomItem->setData(Qt::UserRole, roomCode);
    ui->tblPrices->setItem(row, ColRoomType, roomItem);

    auto *rateItem = new QTableWidgetItem(rateLabel);
    rateItem->setData(Qt::UserRole, rateCode);
    ui->tblPrices->setItem(row, ColRatePlan, rateItem);

    ui->tblPrices->setItem(row, ColStart, new QTableWidgetItem(start.toString(Qt::ISODate)));
    ui->tblPrices->setItem(row, ColEnd, new QTableWidgetItem(end.toString(Qt::ISODate)));
    ui->tblPrices->setItem(row, ColPrice,
                            new QTableWidgetItem(QString::number(ui->dsPrice->value(), 'f', 2)));
    ui->tblPrices->setItem(row, ColCurrency, new QTableWidgetItem(currency));

    auto *kindItem = new QTableWidgetItem(priceKindLabel(kind));
    kindItem->setData(Qt::UserRole, kind);
    kindItem->setData(Qt::UserRole + 1, ui->spGuests->value());
    kindItem->setData(Qt::UserRole + 2, ui->spAgeBucket->value());
    kindItem->setData(Qt::UserRole + 3, ui->spMinAge->value());
    kindItem->setData(Qt::UserRole + 4, ui->spMaxAge->value());
    ui->tblPrices->setItem(row, ColKind, kindItem);
    ui->tblPrices->setItem(row, ColDetail, new QTableWidgetItem(detail));

    appendLog(tr("Price row added: %1 / %2 %3–%4 = %5 %6 [%7 %8]")
                  .arg(roomCode, rateCode,
                       start.toString(Qt::ISODate),
                       end.toString(Qt::ISODate))
                  .arg(ui->dsPrice->value(), 0, 'f', 2)
                  .arg(currency, priceKindLabel(kind), detail));
}

void WExcelyAvailability::on_btnRemovePriceRows_clicked()
{
    const QList<QTableWidgetItem *> selected = ui->tblPrices->selectedItems();
    QSet<int> rows;
    for (QTableWidgetItem *it : selected) {
        rows.insert(it->row());
    }
    QList<int> sorted = rows.values();
    std::sort(sorted.begin(), sorted.end(), std::greater<int>());
    for (int r : sorted) {
        ui->tblPrices->removeRow(r);
    }
}

void WExcelyAvailability::on_btnClearPrices_clicked()
{
    ui->tblPrices->setRowCount(0);
    appendLog(tr("Price table cleared"));
}

bool WExcelyAvailability::buildBatchRateMessages(QVector<Excely::Pms::RateAmountMessage> *out,
                                                 QString *errorText) const
{
    if (!out) {
        return false;
    }
    out->clear();
    if (ui->tblPrices->rowCount() <= 0) {
        if (errorText) {
            *errorText = tr("Price table is empty — add rows with + first");
        }
        return false;
    }

    // Group rows with same room/rate/dates/currency into one RateAmountMessage
    // (BaseByGuestAmts + AdditionalGuestAmounts together).
    QMap<QString, Excely::Pms::RateAmountMessage> grouped;
    QStringList order;

    for (int row = 0; row < ui->tblPrices->rowCount(); ++row) {
        const QTableWidgetItem *roomItem = ui->tblPrices->item(row, ColRoomType);
        const QTableWidgetItem *rateItem = ui->tblPrices->item(row, ColRatePlan);
        const QTableWidgetItem *startItem = ui->tblPrices->item(row, ColStart);
        const QTableWidgetItem *endItem = ui->tblPrices->item(row, ColEnd);
        const QTableWidgetItem *priceItem = ui->tblPrices->item(row, ColPrice);
        const QTableWidgetItem *curItem = ui->tblPrices->item(row, ColCurrency);
        const QTableWidgetItem *kindItem = ui->tblPrices->item(row, ColKind);
        if (!roomItem || !rateItem || !startItem || !endItem || !priceItem || !curItem || !kindItem) {
            if (errorText) {
                *errorText = tr("Incomplete price row %1").arg(row + 1);
            }
            return false;
        }

        const QString inv = roomItem->data(Qt::UserRole).toString();
        const QString rate = rateItem->data(Qt::UserRole).toString();
        const QDate start = QDate::fromString(startItem->text(), Qt::ISODate);
        const QDate end = QDate::fromString(endItem->text(), Qt::ISODate);
        const double amount = priceItem->text().toDouble();
        const QString currency = curItem->text().trimmed().toUpper();
        const int kind = kindItem->data(Qt::UserRole).toInt();
        const int guests = kindItem->data(Qt::UserRole + 1).toInt();
        const int ageBucket = kindItem->data(Qt::UserRole + 2).toInt();
        const int minAge = kindItem->data(Qt::UserRole + 3).toInt();
        const int maxAge = kindItem->data(Qt::UserRole + 4).toInt();

        if (inv.isEmpty() || rate.isEmpty() || !start.isValid() || !end.isValid() || end < start
                || currency.isEmpty() || amount < 0.0) {
            if (errorText) {
                *errorText = tr("Invalid price row %1").arg(row + 1);
            }
            return false;
        }
        if (kind == KindBase && (amount <= 0.0 || guests < 1)) {
            if (errorText) {
                *errorText = tr("Invalid base price row %1").arg(row + 1);
            }
            return false;
        }
        if (!ratePlanAllowsPriceUpload(rate)) {
            if (errorText) {
                *errorText = tr("Row %1: rate plan %2 has prices locked")
                                 .arg(row + 1)
                                 .arg(rate);
            }
            return false;
        }

        const QString key = QStringLiteral("%1|%2|%3|%4|%5")
                                .arg(inv, rate,
                                     start.toString(Qt::ISODate),
                                     end.toString(Qt::ISODate),
                                     currency);
        if (!grouped.contains(key)) {
            Excely::Pms::RateAmountMessage msg;
            msg.invTypeCode = inv;
            msg.ratePlanCode = rate;
            msg.start = start;
            msg.end = end;
            msg.currencyCode = currency;
            grouped.insert(key, msg);
            order.append(key);
        }
        Excely::Pms::RateAmountMessage &msg = grouped[key];

        if (kind == KindBase) {
            msg.baseByGuestAmts.append(qMakePair(guests, amount));
        } else {
            Excely::Pms::AdditionalGuestAmount add;
            add.amountAfterTax = amount;
            add.currencyCode = currency;
            if (kind == KindExtraAdult) {
                add.maxAdditionalGuests = qMax(1, guests);
            } else if (kind == KindExtraChild) {
                add.ageQualifyingCode = 8;
                if (ageBucket >= 0) {
                    add.ageBucket = ageBucket;
                }
                if (minAge >= 0) {
                    add.minAge = minAge;
                }
                if (maxAge >= 0) {
                    add.maxAge = maxAge;
                }
            } else if (kind == KindChildNoBed) {
                add.sendBedRequired = true;
                add.bedRequired = false;
                add.minAge = minAge;
                add.maxAge = maxAge;
            }
            msg.additionalGuests.append(add);
        }
    }

    for (const QString &key : order) {
        out->append(grouped.value(key));
    }
    return true;
}

void WExcelyAvailability::on_btnUploadPriceBatch_clicked()
{
    QVector<Excely::Pms::RateAmountMessage> messages;
    QString err;
    if (!buildBatchRateMessages(&messages, &err)) {
        message_error(err);
        return;
    }
    if (sendRateMessages(messages)) {
        appendLog(tr("Prices batch uploaded: %1 RateAmountMessage(s) in 1 request")
                      .arg(messages.size()));
        message_info(tr("Uploaded %1 price lines in one request").arg(messages.size()));
    }
}
