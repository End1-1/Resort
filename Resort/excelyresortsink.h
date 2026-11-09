#ifndef EXCELYRESORTSINK_H
#define EXCELYRESORTSINK_H

#include "excely/channel/ibookingsink.h"

class DoubleDatabase;

#include <QMap>
#include <QSet>
#include <QString>
#include <QStringList>
#include <QVector>

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
        Canceled,                 // processed Excely Cancel (or cancelByChm)
        AlreadyCanceledLocally,   // Create/Modify for f_chm already RESERVE_REMOVED — must RequestDenied, not Reserved
        Rejected,                 // permanent reject (unknown category / rate without amounts) → RequestDenied
        Failed
    };

    explicit ExcelyResortSink(const QMap<QString, QString> &roomTypeMap,
                              const QSet<QString> &knownRatePlans = {});

    bool accept(const Excely::Channel::Booking &booking,
                QString *pmsReservationId,
                QString *errorText = nullptr) override;

    bool acceptDraft(const Excely::Resort::BookingDraft &draft,
                     QString *pmsReservationId,
                     QString *errorText = nullptr) override;

    Outcome lastOutcome() const { return m_lastOutcome; }
    /** Reason for Outcome::Rejected (also for RequestDenied text). */
    QString rejectReason() const { return m_rejectReason; }
    QStringList takeWarnings();
    const QStringList &touchedReserveIds() const { return m_touchedReserveIds; }
    const QList<int> &touchedGuestIds() const { return m_touchedGuestIds; }
    /** Per-RoomStay PMS ids of the last accepted booking (for NotifReport). */
    const QVector<Excely::Channel::RoomConfirmation> &roomConfirmations() const { return m_roomConfirmations; }

private:
    bool cancelByChm(const Excely::Resort::BookingDraft &draft,
                     QString *pmsReservationId,
                     QString *errorText);
    void cancelReservationRow(const QString &rsId, const QString &reason);
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
    QString resolveNationShort(const QString &countryCode);
    // When a room is chosen, leaves lockDb inside a transaction that holds
    // SELECT ... FOR UPDATE on that f_room until the caller commits or rolls back.
    // *roomLocked is set only in that case. Room 0 means unassigned and no lock.
    int findFreeRoom(const QString &roomTypeCode,
                     const QDate &start,
                     const QDate &end,
                     const QString &excludeReserveId,
                     DoubleDatabase *lockDb,
                     bool *roomLocked,
                     QString *warn);
    /** Beds in assigned room, or typical capacity of mapped class (default 2). */
    int resolveBedQty(int roomId, const QString &roomTypeCode) const;
    /** Adults + children need beds; babies (0–2) do not. */
    static bool needsExtraBed(int men, int children, int bedQty, bool channelExtraBed);
    /**
     * Unknown room type (not in roomTypeMap) → reject.
     * Unknown rate plan → OK if room/booking has amounts; else reject.
     * Sets m_rejectReason on failure.
     */
    bool validateImportRooms(const Excely::Resort::BookingDraft &draft);
    /** Write one line to reservation TrackControl (airlog). */
    static void trackExcely(const QString &invoice,
                            const QString &rsId,
                            const QString &action,
                            const QString &oldValue,
                            const QString &newValue = QString());
    QString resolveCardex(const Excely::Resort::BookingDraft &draft, int *cityLedger);
    void linkReservationGuests(const QString &rsId,
                               int mainGuestId,
                               const Excely::Resort::BookingDraft &draft);
    /** Create/update AV vouchers from GuaranteePayment deposits on the primary invoice. */
    void syncAdvances(const Excely::Resort::BookingDraft &draft,
                      const QString &rsId,
                      const QString &invoiceId,
                      int roomId,
                      const QString &guestName,
                      int paymentType,
                      double dollarRate);

    QMap<QString, QString> m_roomTypeMap;
    QSet<QString> m_knownRatePlans; // Exely HotelAvail rate plan codes
    Outcome m_lastOutcome = Outcome::Failed;
    QString m_rejectReason;
    QStringList m_warnings;
    QStringList m_touchedReserveIds;
    QList<int> m_touchedGuestIds;
    QVector<Excely::Channel::RoomConfirmation> m_roomConfirmations;
};

#endif // EXCELYRESORTSINK_H
