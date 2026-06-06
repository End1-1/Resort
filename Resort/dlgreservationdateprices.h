#ifndef DLGRESERVATIONDATEPRICES_H
#define DLGRESERVATIONDATEPRICES_H

#include <QDate>
#include <QDialog>
#include <QList>

namespace Ui {
class DlgReservationDatePrices;
}

class DlgReservationDatePrices : public QDialog
{
    Q_OBJECT

public:
    explicit DlgReservationDatePrices(const QString &reservationId,
                                      const QDate &entry,
                                      const QDate &departure,
                                      double defaultPrice,
                                      QWidget *parent = nullptr);
    ~DlgReservationDatePrices();

    static QList<QDate> stayDates(const QDate &entry, const QDate &departure);
    static bool edit(const QString &reservationId,
                     const QDate &entry,
                     const QDate &departure,
                     double defaultPrice,
                     double &roomTotal,
                     QWidget *parent = nullptr);

    double roomTotal() const;

private slots:
    void on_btnFillDefault_clicked();
    void on_btnOk_clicked();
    void on_btnCancel_clicked();
    void updateTotal();

private:
    void buildTable();
    bool save();

    Ui::DlgReservationDatePrices *ui;
    QString fReservationId;
    QDate fEntry;
    QDate fDeparture;
    double fDefaultPrice;
    QList<QDate> fDates;
};

#endif // DLGRESERVATIONDATEPRICES_H
