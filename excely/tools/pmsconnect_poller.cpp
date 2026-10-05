#include "excely/channel/ibookingsink.h"
#include "excely/pms/exelybookingsource.h"
#include "excely/pms/pmsconfig.h"
#include "excely/resort/channeltoresort.h"

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDateTime>
#include <QJsonDocument>
#include <QTimer>
#include <cstdio>

using namespace Excely;

namespace {

class LoggingSink final : public Channel::IBookingSink, public Channel::IResortBookingSink
{
public:
    bool accept(const Channel::Booking &booking,
                QString *pmsReservationId,
                QString *errorText) override
    {
        Q_UNUSED(errorText);
        const Resort::BookingDraft draft = Resort::toResortDraft(booking);
        return acceptDraft(draft, pmsReservationId, errorText);
    }

    bool acceptDraft(const Resort::BookingDraft &draft,
                     QString *pmsReservationId,
                     QString *errorText) override
    {
        Q_UNUSED(errorText);
        const QByteArray json = QJsonDocument(draft.toImportJson())
                                    .toJson(QJsonDocument::Indented);
        fprintf(stdout, "--- Resort draft ---\n%s\n", json.constData());
        fflush(stdout);
        if (pmsReservationId) {
            *pmsReservationId = QStringLiteral("EXELY-%1").arg(draft.chmId);
        }
        return true;
    }
};

class Poller final : public QObject
{
    Q_OBJECT
public:
    Poller(Channel::IBookingSource *source, Channel::IBookingSink *sink,
           int intervalSec, bool dryRun, bool once, QObject *parent = nullptr)
        : QObject(parent)
        , m_source(source)
        , m_sink(sink)
        , m_intervalSec(intervalSec)
        , m_dryRun(dryRun)
        , m_once(once)
    {
        connect(&m_timer, &QTimer::timeout, this, &Poller::tick);
    }

    void start()
    {
        tick();
        if (!m_once) {
            m_timer.start(m_intervalSec * 1000);
        }
    }

private slots:
    void tick()
    {
        QVector<Channel::Booking> list;
        QVector<Channel::PmsError> errors;
        fprintf(stdout, "[%s] pullUndelivered...\n",
                qPrintable(QDateTime::currentDateTime().toString(Qt::ISODate)));
        fflush(stdout);

        if (!m_source->pullUndelivered(&list, &errors)) {
            for (const Channel::PmsError &e : errors) {
                fprintf(stderr, "ERROR code=%d type=%d: %s\n", e.code, e.type, qPrintable(e.text));
                if (e.isAuthError() || e.isLimitError()) {
                    QCoreApplication::exit(2);
                    return;
                }
            }
            if (errors.isEmpty()) {
                fprintf(stderr, "ERROR: pullUndelivered failed\n");
            }
            if (m_once) QCoreApplication::exit(1);
            return;
        }

        for (const Channel::PmsError &e : errors) {
            fprintf(stderr, "WARN code=%d: %s\n", e.code, qPrintable(e.text));
        }

        fprintf(stdout, "Got %d booking(s)\n", int(list.size()));
        for (const Channel::Booking &b : list) {
            const QByteArray universal = QJsonDocument(b.toJson()).toJson(QJsonDocument::Indented);
            fprintf(stdout, "--- Channel booking ---\n%s\n", universal.constData());

            QString pmsId;
            QString err;
            if (!m_sink->accept(b, &pmsId, &err)) {
                fprintf(stderr, "Sink rejected %s: %s\n", qPrintable(b.channelReservationId), qPrintable(err));
                if (!m_dryRun) {
                    QString e2;
                    m_source->rejectDelivery(b, err.isEmpty() ? QStringLiteral("Sink rejected") : err, &e2);
                }
                continue;
            }

            if (m_dryRun) {
                fprintf(stdout, "dry-run: skip NotifReport for %s (would confirm as %s)\n",
                        qPrintable(b.channelReservationId), qPrintable(pmsId));
                continue;
            }

            QString e2;
            if (!m_source->confirmDelivered(b, pmsId, &e2)) {
                fprintf(stderr, "confirmDelivered failed for %s: %s\n",
                        qPrintable(b.channelReservationId), qPrintable(e2));
            } else {
                fprintf(stdout, "Confirmed %s as %s\n",
                        qPrintable(b.channelReservationId), qPrintable(pmsId));
            }
        }

        if (m_once) {
            QCoreApplication::quit();
        }
    }

private:
    Channel::IBookingSource *m_source = nullptr;
    Channel::IBookingSink *m_sink = nullptr;
    int m_intervalSec = 300;
    bool m_dryRun = false;
    bool m_once = false;
    QTimer m_timer;
};

} // namespace

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(QStringLiteral("pmsconnect_poller"));
    QCoreApplication::setApplicationVersion(QStringLiteral("1.0"));

    QCommandLineParser parser;
    parser.setApplicationDescription(
        QStringLiteral("Exely PMSConnect undelivered-booking poller (standalone, not wired to Resort)"));
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption configOpt({QStringLiteral("c"), QStringLiteral("config")},
                                 QStringLiteral("INI config path"),
                                 QStringLiteral("file"));
    QCommandLineOption onceOpt(QStringLiteral("once"), QStringLiteral("Single pull then exit"));
    QCommandLineOption dryOpt(QStringLiteral("dry-run"), QStringLiteral("Do not send NotifReport"));
    QCommandLineOption pingOpt(QStringLiteral("ping"), QStringLiteral("Ping only and exit"));
    QCommandLineOption availOpt(QStringLiteral("hotel-avail"), QStringLiteral("Fetch hotel catalog and exit"));
    QCommandLineOption intervalOpt(QStringLiteral("interval"),
                                   QStringLiteral("Override poll interval seconds"),
                                   QStringLiteral("sec"));
    parser.addOption(configOpt);
    parser.addOption(onceOpt);
    parser.addOption(dryOpt);
    parser.addOption(pingOpt);
    parser.addOption(availOpt);
    parser.addOption(intervalOpt);
    parser.process(app);

    if (!parser.isSet(configOpt)) {
        fprintf(stderr, "Missing --config\n");
        return 1;
    }

    QString cfgErr;
    const Pms::Config cfg = Pms::Config::fromIniFile(parser.value(configOpt), &cfgErr);
    if (cfg.hotelCode.isEmpty()) {
        fprintf(stderr, "Config error: %s\n", qPrintable(cfgErr));
        return 1;
    }

    Pms::ExelyBookingSource source(cfg);
    LoggingSink sink;

    if (parser.isSet(pingOpt)) {
        QString err;
        if (!source.ping(&err)) {
            fprintf(stderr, "Ping failed: %s\n", qPrintable(err));
            return 2;
        }
        fprintf(stdout, "Ping OK\n");
        return 0;
    }

    if (parser.isSet(availOpt)) {
        Pms::HotelCatalog cat;
        QVector<Channel::PmsError> errs;
        if (!source.client().hotelAvail(&cat, &errs)) {
            for (const auto &e : errs) fprintf(stderr, "%s\n", qPrintable(e.text));
            return 2;
        }
        fprintf(stdout, "Room types: %d, rate plans: %d, companies: %d\n",
                int(cat.roomTypes.size()), int(cat.ratePlans.size()), int(cat.companies.size()));
        for (const auto &rt : cat.roomTypes) {
            fprintf(stdout, "  room %s %s\n", qPrintable(rt.roomTypeCode), qPrintable(rt.name));
        }
        for (const auto &rp : cat.ratePlans) {
            fprintf(stdout, "  rate %s %s\n", qPrintable(rp.ratePlanCode), qPrintable(rp.name));
        }
        return 0;
    }

    int interval = cfg.pollIntervalSec;
    if (parser.isSet(intervalOpt)) {
        interval = parser.value(intervalOpt).toInt();
        if (interval < 60) interval = 60;
    }

    auto *poller = new Poller(&source, &sink, interval,
                              parser.isSet(dryOpt),
                              parser.isSet(onceOpt),
                              &app);
    QTimer::singleShot(0, poller, &Poller::start);
    return app.exec();
}

#include "pmsconnect_poller.moc"
