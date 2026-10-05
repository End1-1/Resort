#ifndef EXCELYRESORTSINK_H
#define EXCELYRESORTSINK_H

#include "excely/channel/ibookingsink.h"

#include <QMap>
#include <QString>
#include <QStringList>

/**
 * Persists Channel::Booking / Resort::BookingDraft into f_reservation
 * with f_chmstatus=1 (lilac on chart until operator opens the reserve).
 */
class ExcelyResortSink : public Excely::Channel::IBookingSink,
                         public Excely::Channel::IResortBookingSink
{
public:
    enum class Outcome {
        Created,
        Updated,
        Canceled,
        Failed
    };

    explicit ExcelyResortSink(const QMap<QString, QString> &roomTypeMap);

    bool accept(const Excely::Channel::Booking &booking,
                QString *pmsReservationId,
                QString *errorText = nullptr) override;

    bool acceptDraft(const Excely::Resort::BookingDraft &draft,
                     QString *pmsReservationId,
                     QString *errorText = nullptr) override;

    Outcome lastOutcome() const { return m_lastOutcome; }
    QStringList takeWarnings();
    const QStringList &touchedReserveIds() const { return m_touchedReserveIds; }
    const QList<int> &touchedGuestIds() const { return m_touchedGuestIds; }

private:
    bool cancelByChm(const Excely::Resort::BookingDraft &draft,
                     QString *pmsReservationId,
                     QString *errorText);
    bool upsertRoom(const Excely::Resort::BookingDraft &draft,
                    const Excely::Resort::RoomDraft &room,
                    const QString &chmKey,
                    bool isUpdate,
                    const QString &existsRes,
                    const QString &existsIn,
                    int mainGuestId,
                    const QString &cardex,
                    int cityLedger,
                    int paymentType,
                    double dollarRate,
                    QString *outRsId,
                    QString *errorText);
    int ensureGuest(const Excely::Resort::GuestDraft &g);
    int findFreeRoom(const QString &roomTypeCode,
                     const QDate &start,
                     const QDate &end,
                     const QString &excludeReserveId,
                     QString *warn);
    QString resolveCardex(const Excely::Resort::BookingDraft &draft, int *cityLedger);

    QMap<QString, QString> m_roomTypeMap;
    Outcome m_lastOutcome = Outcome::Failed;
    QStringList m_warnings;
    QStringList m_touchedReserveIds;
    QList<int> m_touchedGuestIds;
};

#endif // EXCELYRESORTSINK_H
