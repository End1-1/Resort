#ifndef WEXCELYAVAILABILITY_H
#define WEXCELYAVAILABILITY_H

#include "basewidget.h"
#include "excely/pms/models.h"
#include "excely/pms/pmsconfig.h"

namespace Ui {
class WExcelyAvailability;
}

class WExcelyAvailability : public BaseWidget
{
    Q_OBJECT

public:
    explicit WExcelyAvailability(QWidget *parent = nullptr);
    ~WExcelyAvailability() override;
    void setupTab() override;

private slots:
    void on_btnRefreshCatalog_clicked();
    void on_btnUpload_clicked();
    void on_btnResyncYear_clicked();
    void on_btnPushPmsDelta_clicked();
    void on_btnPushPmsYear_clicked();
    void on_btnPushPmsFull_clicked();
    void on_rbRatePlan_toggled(bool checked);
    void on_btnAddPriceRow_clicked();
    void on_btnRemovePriceRows_clicked();
    void on_btnClearPrices_clicked();
    void on_btnUploadPriceBatch_clicked();
    void on_cbPriceKind_currentIndexChanged(int index);

private:
    enum PriceKind {
        KindBase = 0,           // BaseByGuestAmt NumberOfGuests
        KindExtraAdult = 1,     // AdditionalGuestAmount (extra adult bed)
        KindExtraChild = 2,     // AdditionalGuestAmount AgeQualifyingCode=8
        KindChildNoBed = 3      // AdditionalGuestAmount BedRequired=false
    };

    enum PriceCol {
        ColRoomType = 0,
        ColRatePlan,
        ColStart,
        ColEnd,
        ColPrice,
        ColCurrency,
        ColKind,
        ColDetail,
        ColCount
    };

    Ui::WExcelyAvailability *ui;
    Excely::Pms::HotelCatalog m_catalog;

    bool ensureClient(Excely::Pms::Config *cfg, QString *errorText);
    bool buildAvailMessage(Excely::Pms::AvailStatusMessage *msg, QString *errorText) const;
    bool sendAvailMessages(const QVector<Excely::Pms::AvailStatusMessage> &messages);
    bool sendRateMessages(const QVector<Excely::Pms::RateAmountMessage> &messages);
    bool ratePlanAllowsPriceUpload(const QString &ratePlanCode) const;
    bool buildBatchRateMessages(QVector<Excely::Pms::RateAmountMessage> *out, QString *errorText) const;
    void fillCombosFromCatalog();
    void appendLog(const QString &line);
    void setupPricesTable();
    void updatePriceKindUi();
    QString priceKindLabel(int kind) const;
};

#endif // WEXCELYAVAILABILITY_H
