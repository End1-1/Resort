/********************************************************************************
** Form generated from reading UI file 'wreservationroomtab.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRESERVATIONROOMTAB_H
#define UI_WRESERVATIONROOMTAB_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcheckbox.h>
#include <eqcombobox.h>
#include <eqdateedit.h>
#include <eqlineedit.h>
#include <eqspinbox.h>
#include <eqtablewidget.h>
#include <eqtextedit.h>
#include <eqtimeedit.h>

QT_BEGIN_NAMESPACE

class Ui_WReservationRoomTab
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *grCommon;
    QGridLayout *gridLayout_2;
    QLabel *label_10;
    EQLineEdit *leInvoice;
    EQLineEdit *leStatusCode;
    EQLineEdit *leStatusName;
    QLabel *lbEndDateWarning;
    QLabel *label_9;
    QLabel *label_4;
    EQDateEdit *deCreated;
    EQLineEdit *leReserveCode;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *lbWolking;
    EQLineEdit *leReservId;
    QLabel *lbStatusCode;
    QLabel *lbDayUse;
    QLabel *lbEntryDate;
    EQSpinBox *sbNights;
    EDateEdit *deEntry;
    QLabel *lbDepartureDate;
    QLabel *lbStartDateWarning;
    EDateEdit *deDeparture;
    EQLineEdit *leReserveName;
    QGroupBox *grRoom;
    QGridLayout *gridLayout_8;
    QLabel *label_19;
    QLabel *label_36;
    QLabel *lbArrangement;
    QLabel *label_29;
    EQComboBox *cbArrangment;
    EQSpinBox *sbMan;
    EQLineEdit *leRoomCode;
    EQTableWidget *tblGuest;
    QPushButton *btnNewGuest;
    EQLineEdit *leRoomName;
    EQSpinBox *sbWoman;
    EQSpinBox *sbChild;
    QLabel *lbRoom_2;
    QLabel *label_21;
    QPushButton *btnAllNation;
    QLabel *label_28;
    EQLineEdit *leSearchGuest;
    QLabel *lbRoom;
    QLabel *label_30;
    EQCheckBox *chMealIncluded;
    EQSpinBox *sbBaby;
    QLabel *label_22;
    QLineEdit *leUpgradeFrom;
    QPushButton *btnReadFromDevice;
    QGroupBox *grAdd;
    QGridLayout *gridLayout_4;
    QLabel *label_34;
    QLabel *label_25;
    QLabel *label_24;
    QLabel *label_16;
    QLabel *label_26;
    QLabel *lbEarlyCheckinWarning;
    EQTimeEdit *teEarlyCheckIn;
    EQCheckBox *chEarlyCheckIn;
    QLabel *label_23;
    QLabel *label_35;
    EQCheckBox *chLateCheckout;
    EQCheckBox *chPickup;
    EQLineEdit *leEarlyCheckInFee;
    EQTimeEdit *teLateChecout;
    EQLineEdit *leLateCheckoutFee;
    EQTimeEdit *teArrivalTime;
    EQLineEdit *leArrivalFee;
    EQTimeEdit *teDepartureTime;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QGroupBox *grRemarks;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_6;
    QLabel *lbCardex;
    EQLineEdit *leCardexCode;
    EQLineEdit *leCardexname;
    QLabel *lbCardexError;
    QLabel *label_39;
    EQLineEdit *leCommission;
    QLineEdit *leBooking;
    QLabel *lbCityLedger;
    EQLineEdit *leCityLedgerCode;
    EQLineEdit *leCityLedgerName;
    QLabel *lbCLedgerError;
    EQTextEdit *teRoomRemarks;
    QPushButton *btnWakeup;
    QGroupBox *grPricing;
    QGridLayout *gridLayout_7;
    QLabel *lbRoomPrice;
    EQLineEdit *leRooming;
    EQCheckBox *chExtraBed;
    QLabel *label_15;
    QLabel *label_32;
    EQLineEdit *leExtraBedAmount;
    QLabel *label_12;
    EQLineEdit *lePricePerNight;
    EQLineEdit *leMealPrice;
    QLabel *lbVATMode;
    EQComboBox *cbVAT;
    QLabel *label_13;
    EQLineEdit *leNoVATReason;
    EQSpinBox *sbMealQty;
    QGroupBox *grPayment;
    QGridLayout *gridLayout_3;
    EQLineEdit *leAdvance;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *lbVAT;
    QLabel *label_6;
    QLabel *lbPaymentMode;
    QLabel *label_33;
    QPushButton *btnAppendAdvance;
    EQLineEdit *leTotal;
    EQLineEdit *leVAT;
    EQLineEdit *leGrandTotal;
    EQLineEdit *leTotalUSD;
    EQComboBox *cbPaymentType;

    void setupUi(QWidget *WReservationRoomTab)
    {
        if (WReservationRoomTab->objectName().isEmpty())
            WReservationRoomTab->setObjectName(QString::fromUtf8("WReservationRoomTab"));
        WReservationRoomTab->resize(996, 505);
        verticalLayout = new QVBoxLayout(WReservationRoomTab);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 0, 0, 0);
        widget_3 = new QWidget(WReservationRoomTab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        grCommon = new QGroupBox(widget_3);
        grCommon->setObjectName(QString::fromUtf8("grCommon"));
        grCommon->setMaximumSize(QSize(450, 16777215));
        gridLayout_2 = new QGridLayout(grCommon);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(6);
        label_10 = new QLabel(grCommon);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        leInvoice = new EQLineEdit(grCommon);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setFocusPolicy(Qt::NoFocus);
        leInvoice->setReadOnly(true);

        gridLayout_2->addWidget(leInvoice, 2, 1, 1, 4);

        leStatusCode = new EQLineEdit(grCommon);
        leStatusCode->setObjectName(QString::fromUtf8("leStatusCode"));
        leStatusCode->setMaximumSize(QSize(30, 16777215));
        leStatusCode->setProperty("ShowButton", QVariant(true));

        gridLayout_2->addWidget(leStatusCode, 4, 1, 1, 1);

        leStatusName = new EQLineEdit(grCommon);
        leStatusName->setObjectName(QString::fromUtf8("leStatusName"));
        leStatusName->setFocusPolicy(Qt::NoFocus);
        leStatusName->setReadOnly(true);

        gridLayout_2->addWidget(leStatusName, 4, 2, 1, 3);

        lbEndDateWarning = new QLabel(grCommon);
        lbEndDateWarning->setObjectName(QString::fromUtf8("lbEndDateWarning"));
        lbEndDateWarning->setMaximumSize(QSize(16, 16));
        lbEndDateWarning->setPixmap(QPixmap(QString::fromUtf8(":/images/warning.png")));
        lbEndDateWarning->setScaledContents(true);

        gridLayout_2->addWidget(lbEndDateWarning, 7, 5, 1, 1);

        label_9 = new QLabel(grCommon);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 1, 0, 1, 1);

        label_4 = new QLabel(grCommon);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        deCreated = new EQDateEdit(grCommon);
        deCreated->setObjectName(QString::fromUtf8("deCreated"));
        deCreated->setEnabled(true);
        deCreated->setFocusPolicy(Qt::NoFocus);
        deCreated->setReadOnly(true);

        gridLayout_2->addWidget(deCreated, 0, 1, 1, 4);

        leReserveCode = new EQLineEdit(grCommon);
        leReserveCode->setObjectName(QString::fromUtf8("leReserveCode"));
        leReserveCode->setMaximumSize(QSize(30, 16777215));
        leReserveCode->setFocusPolicy(Qt::NoFocus);
        leReserveCode->setReadOnly(true);
        leReserveCode->setProperty("ShowButton", QVariant(true));

        gridLayout_2->addWidget(leReserveCode, 3, 1, 1, 1);

        label_37 = new QLabel(grCommon);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_2->addWidget(label_37, 0, 0, 1, 1);

        label_38 = new QLabel(grCommon);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_2->addWidget(label_38, 2, 0, 1, 1);

        lbWolking = new QLabel(grCommon);
        lbWolking->setObjectName(QString::fromUtf8("lbWolking"));
        lbWolking->setEnabled(false);

        gridLayout_2->addWidget(lbWolking, 5, 4, 1, 1);

        leReservId = new EQLineEdit(grCommon);
        leReservId->setObjectName(QString::fromUtf8("leReservId"));
        leReservId->setMaximumSize(QSize(5555, 16777215));
        leReservId->setFocusPolicy(Qt::NoFocus);
        leReservId->setReadOnly(true);

        gridLayout_2->addWidget(leReservId, 1, 1, 1, 4);

        lbStatusCode = new QLabel(grCommon);
        lbStatusCode->setObjectName(QString::fromUtf8("lbStatusCode"));

        gridLayout_2->addWidget(lbStatusCode, 4, 0, 1, 1);

        lbDayUse = new QLabel(grCommon);
        lbDayUse->setObjectName(QString::fromUtf8("lbDayUse"));
        lbDayUse->setEnabled(false);

        gridLayout_2->addWidget(lbDayUse, 7, 4, 1, 1);

        lbEntryDate = new QLabel(grCommon);
        lbEntryDate->setObjectName(QString::fromUtf8("lbEntryDate"));

        gridLayout_2->addWidget(lbEntryDate, 5, 0, 1, 1);

        sbNights = new EQSpinBox(grCommon);
        sbNights->setObjectName(QString::fromUtf8("sbNights"));
        sbNights->setMaximumSize(QSize(6666, 16777215));
        sbNights->setMaximum(999);

        gridLayout_2->addWidget(sbNights, 6, 1, 1, 2);

        deEntry = new EDateEdit(grCommon);
        deEntry->setObjectName(QString::fromUtf8("deEntry"));

        gridLayout_2->addWidget(deEntry, 5, 1, 1, 3);

        lbDepartureDate = new QLabel(grCommon);
        lbDepartureDate->setObjectName(QString::fromUtf8("lbDepartureDate"));

        gridLayout_2->addWidget(lbDepartureDate, 7, 0, 1, 1);

        lbStartDateWarning = new QLabel(grCommon);
        lbStartDateWarning->setObjectName(QString::fromUtf8("lbStartDateWarning"));
        lbStartDateWarning->setMaximumSize(QSize(16, 16));
        lbStartDateWarning->setPixmap(QPixmap(QString::fromUtf8(":/images/warning.png")));
        lbStartDateWarning->setScaledContents(true);

        gridLayout_2->addWidget(lbStartDateWarning, 5, 5, 1, 1);

        deDeparture = new EDateEdit(grCommon);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));

        gridLayout_2->addWidget(deDeparture, 7, 1, 1, 3);

        leReserveName = new EQLineEdit(grCommon);
        leReserveName->setObjectName(QString::fromUtf8("leReserveName"));
        leReserveName->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(leReserveName, 3, 2, 1, 3);


        horizontalLayout->addWidget(grCommon);

        grRoom = new QGroupBox(widget_3);
        grRoom->setObjectName(QString::fromUtf8("grRoom"));
        gridLayout_8 = new QGridLayout(grRoom);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_19 = new QLabel(grRoom);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMaximumSize(QSize(24, 24));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/images/woman.png")));
        label_19->setScaledContents(true);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_19, 2, 3, 1, 1);

        label_36 = new QLabel(grRoom);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_8->addWidget(label_36, 0, 8, 1, 1);

        lbArrangement = new QLabel(grRoom);
        lbArrangement->setObjectName(QString::fromUtf8("lbArrangement"));

        gridLayout_8->addWidget(lbArrangement, 1, 0, 1, 1);

        label_29 = new QLabel(grRoom);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_8->addWidget(label_29, 2, 0, 1, 1);

        cbArrangment = new EQComboBox(grRoom);
        cbArrangment->setObjectName(QString::fromUtf8("cbArrangment"));
        cbArrangment->setProperty("Cache", QVariant(37));

        gridLayout_8->addWidget(cbArrangment, 1, 1, 1, 1);

        sbMan = new EQSpinBox(grRoom);
        sbMan->setObjectName(QString::fromUtf8("sbMan"));
        sbMan->setMinimum(0);
        sbMan->setValue(1);

        gridLayout_8->addWidget(sbMan, 2, 2, 1, 1);

        leRoomCode = new EQLineEdit(grRoom);
        leRoomCode->setObjectName(QString::fromUtf8("leRoomCode"));
        leRoomCode->setMinimumSize(QSize(0, 0));
        leRoomCode->setMaximumSize(QSize(70, 16777215));
        leRoomCode->setProperty("ShowButton", QVariant(true));

        gridLayout_8->addWidget(leRoomCode, 0, 1, 1, 1);

        tblGuest = new EQTableWidget(grRoom);
        if (tblGuest->columnCount() < 6)
            tblGuest->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tblGuest->setObjectName(QString::fromUtf8("tblGuest"));
        tblGuest->setMinimumSize(QSize(0, 0));
        tblGuest->setMaximumSize(QSize(2222, 22222));
        tblGuest->setFocusPolicy(Qt::NoFocus);
        tblGuest->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblGuest->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblGuest->setSelectionMode(QAbstractItemView::SingleSelection);
        tblGuest->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblGuest->setWordWrap(false);
        tblGuest->verticalHeader()->setVisible(false);
        tblGuest->verticalHeader()->setDefaultSectionSize(25);

        gridLayout_8->addWidget(tblGuest, 4, 0, 1, 12);

        btnNewGuest = new QPushButton(grRoom);
        btnNewGuest->setObjectName(QString::fromUtf8("btnNewGuest"));
        btnNewGuest->setMaximumSize(QSize(25, 25));
        btnNewGuest->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNewGuest->setIcon(icon);

        gridLayout_8->addWidget(btnNewGuest, 3, 9, 1, 1);

        leRoomName = new EQLineEdit(grRoom);
        leRoomName->setObjectName(QString::fromUtf8("leRoomName"));
        leRoomName->setFocusPolicy(Qt::NoFocus);
        leRoomName->setReadOnly(true);

        gridLayout_8->addWidget(leRoomName, 0, 2, 1, 5);

        sbWoman = new EQSpinBox(grRoom);
        sbWoman->setObjectName(QString::fromUtf8("sbWoman"));

        gridLayout_8->addWidget(sbWoman, 2, 4, 1, 1);

        sbChild = new EQSpinBox(grRoom);
        sbChild->setObjectName(QString::fromUtf8("sbChild"));

        gridLayout_8->addWidget(sbChild, 2, 6, 1, 1);

        lbRoom_2 = new QLabel(grRoom);
        lbRoom_2->setObjectName(QString::fromUtf8("lbRoom_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbRoom_2->sizePolicy().hasHeightForWidth());
        lbRoom_2->setSizePolicy(sizePolicy);

        gridLayout_8->addWidget(lbRoom_2, 0, 0, 1, 1);

        label_21 = new QLabel(grRoom);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setMaximumSize(QSize(24, 24));
        label_21->setLayoutDirection(Qt::RightToLeft);
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/images/boss.png")));
        label_21->setScaledContents(true);
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_21, 2, 1, 1, 1);

        btnAllNation = new QPushButton(grRoom);
        btnAllNation->setObjectName(QString::fromUtf8("btnAllNation"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnAllNation->sizePolicy().hasHeightForWidth());
        btnAllNation->setSizePolicy(sizePolicy1);
        btnAllNation->setMaximumSize(QSize(50, 16777215));

        gridLayout_8->addWidget(btnAllNation, 3, 11, 1, 1);

        label_28 = new QLabel(grRoom);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMaximumSize(QSize(24, 24));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/images/boy.png")));
        label_28->setScaledContents(true);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_28, 2, 5, 1, 1);

        leSearchGuest = new EQLineEdit(grRoom);
        leSearchGuest->setObjectName(QString::fromUtf8("leSearchGuest"));
        leSearchGuest->setProperty("AlwaysUpper", QVariant(true));

        gridLayout_8->addWidget(leSearchGuest, 3, 1, 1, 8);

        lbRoom = new QLabel(grRoom);
        lbRoom->setObjectName(QString::fromUtf8("lbRoom"));
        lbRoom->setMaximumSize(QSize(16, 16));
        lbRoom->setPixmap(QPixmap(QString::fromUtf8(":/images/question.png")));
        lbRoom->setScaledContents(true);

        gridLayout_8->addWidget(lbRoom, 0, 7, 1, 1);

        label_30 = new QLabel(grRoom);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_8->addWidget(label_30, 3, 0, 1, 1);

        chMealIncluded = new EQCheckBox(grRoom);
        chMealIncluded->setObjectName(QString::fromUtf8("chMealIncluded"));

        gridLayout_8->addWidget(chMealIncluded, 1, 2, 1, 4);

        sbBaby = new EQSpinBox(grRoom);
        sbBaby->setObjectName(QString::fromUtf8("sbBaby"));

        gridLayout_8->addWidget(sbBaby, 2, 8, 1, 1);

        label_22 = new QLabel(grRoom);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMaximumSize(QSize(24, 24));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/images/feeding-bottle.png")));
        label_22->setScaledContents(true);

        gridLayout_8->addWidget(label_22, 2, 7, 1, 1);

        leUpgradeFrom = new QLineEdit(grRoom);
        leUpgradeFrom->setObjectName(QString::fromUtf8("leUpgradeFrom"));
        leUpgradeFrom->setEnabled(false);
        leUpgradeFrom->setMinimumSize(QSize(70, 0));
        leUpgradeFrom->setMaximumSize(QSize(80, 16777215));
        leUpgradeFrom->setFocusPolicy(Qt::NoFocus);

        gridLayout_8->addWidget(leUpgradeFrom, 0, 9, 1, 3);

        btnReadFromDevice = new QPushButton(grRoom);
        btnReadFromDevice->setObjectName(QString::fromUtf8("btnReadFromDevice"));
        btnReadFromDevice->setMaximumSize(QSize(25, 25));
        btnReadFromDevice->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/card-reader.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReadFromDevice->setIcon(icon1);

        gridLayout_8->addWidget(btnReadFromDevice, 3, 10, 1, 1);


        horizontalLayout->addWidget(grRoom);

        grAdd = new QGroupBox(widget_3);
        grAdd->setObjectName(QString::fromUtf8("grAdd"));
        gridLayout_4 = new QGridLayout(grAdd);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_34 = new QLabel(grAdd);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_4->addWidget(label_34, 5, 0, 1, 1);

        label_25 = new QLabel(grAdd);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 9, 0, 1, 1);

        label_24 = new QLabel(grAdd);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_4->addWidget(label_24, 7, 0, 1, 1);

        label_16 = new QLabel(grAdd);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_4->addWidget(label_16, 1, 0, 1, 1);

        label_26 = new QLabel(grAdd);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_4->addWidget(label_26, 8, 0, 1, 1);

        lbEarlyCheckinWarning = new QLabel(grAdd);
        lbEarlyCheckinWarning->setObjectName(QString::fromUtf8("lbEarlyCheckinWarning"));
        lbEarlyCheckinWarning->setMaximumSize(QSize(16, 16));
        lbEarlyCheckinWarning->setPixmap(QPixmap(QString::fromUtf8(":/images/warning.png")));
        lbEarlyCheckinWarning->setScaledContents(true);

        gridLayout_4->addWidget(lbEarlyCheckinWarning, 1, 3, 1, 1);

        teEarlyCheckIn = new EQTimeEdit(grAdd);
        teEarlyCheckIn->setObjectName(QString::fromUtf8("teEarlyCheckIn"));
        teEarlyCheckIn->setCalendarPopup(false);

        gridLayout_4->addWidget(teEarlyCheckIn, 1, 2, 1, 1);

        chEarlyCheckIn = new EQCheckBox(grAdd);
        chEarlyCheckIn->setObjectName(QString::fromUtf8("chEarlyCheckIn"));

        gridLayout_4->addWidget(chEarlyCheckIn, 1, 1, 1, 1);

        label_23 = new QLabel(grAdd);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_4->addWidget(label_23, 4, 0, 1, 1);

        label_35 = new QLabel(grAdd);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_4->addWidget(label_35, 6, 0, 1, 1);

        chLateCheckout = new EQCheckBox(grAdd);
        chLateCheckout->setObjectName(QString::fromUtf8("chLateCheckout"));

        gridLayout_4->addWidget(chLateCheckout, 5, 1, 1, 1);

        chPickup = new EQCheckBox(grAdd);
        chPickup->setObjectName(QString::fromUtf8("chPickup"));

        gridLayout_4->addWidget(chPickup, 8, 1, 1, 1);

        leEarlyCheckInFee = new EQLineEdit(grAdd);
        leEarlyCheckInFee->setObjectName(QString::fromUtf8("leEarlyCheckInFee"));

        gridLayout_4->addWidget(leEarlyCheckInFee, 4, 2, 1, 2);

        teLateChecout = new EQTimeEdit(grAdd);
        teLateChecout->setObjectName(QString::fromUtf8("teLateChecout"));

        gridLayout_4->addWidget(teLateChecout, 5, 2, 1, 2);

        leLateCheckoutFee = new EQLineEdit(grAdd);
        leLateCheckoutFee->setObjectName(QString::fromUtf8("leLateCheckoutFee"));

        gridLayout_4->addWidget(leLateCheckoutFee, 6, 2, 1, 2);

        teArrivalTime = new EQTimeEdit(grAdd);
        teArrivalTime->setObjectName(QString::fromUtf8("teArrivalTime"));

        gridLayout_4->addWidget(teArrivalTime, 7, 2, 1, 2);

        leArrivalFee = new EQLineEdit(grAdd);
        leArrivalFee->setObjectName(QString::fromUtf8("leArrivalFee"));

        gridLayout_4->addWidget(leArrivalFee, 8, 2, 1, 2);

        teDepartureTime = new EQTimeEdit(grAdd);
        teDepartureTime->setObjectName(QString::fromUtf8("teDepartureTime"));

        gridLayout_4->addWidget(teDepartureTime, 9, 2, 1, 2);


        horizontalLayout->addWidget(grAdd);


        verticalLayout->addWidget(widget_3);

        widget = new QWidget(WReservationRoomTab);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(WReservationRoomTab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        grRemarks = new QGroupBox(widget_2);
        grRemarks->setObjectName(QString::fromUtf8("grRemarks"));
        verticalLayout_2 = new QVBoxLayout(grRemarks);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(grRemarks);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout = new QGridLayout(widget_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lbCardex = new QLabel(widget_4);
        lbCardex->setObjectName(QString::fromUtf8("lbCardex"));

        gridLayout_6->addWidget(lbCardex, 0, 0, 1, 1);

        leCardexCode = new EQLineEdit(widget_4);
        leCardexCode->setObjectName(QString::fromUtf8("leCardexCode"));
        leCardexCode->setMaximumSize(QSize(60, 16777215));
        leCardexCode->setProperty("ShowButton", QVariant(true));

        gridLayout_6->addWidget(leCardexCode, 0, 1, 1, 1);

        leCardexname = new EQLineEdit(widget_4);
        leCardexname->setObjectName(QString::fromUtf8("leCardexname"));
        leCardexname->setMinimumSize(QSize(0, 0));
        leCardexname->setFocusPolicy(Qt::NoFocus);
        leCardexname->setReadOnly(true);

        gridLayout_6->addWidget(leCardexname, 0, 2, 1, 1);

        lbCardexError = new QLabel(widget_4);
        lbCardexError->setObjectName(QString::fromUtf8("lbCardexError"));
        lbCardexError->setMaximumSize(QSize(16, 16));
        lbCardexError->setPixmap(QPixmap(QString::fromUtf8(":/images/question.png")));
        lbCardexError->setScaledContents(true);

        gridLayout_6->addWidget(lbCardexError, 0, 3, 1, 1);

        label_39 = new QLabel(widget_4);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_6->addWidget(label_39, 1, 0, 1, 1);

        leCommission = new EQLineEdit(widget_4);
        leCommission->setObjectName(QString::fromUtf8("leCommission"));
        leCommission->setMaximumSize(QSize(60, 16777215));
        leCommission->setReadOnly(false);

        gridLayout_6->addWidget(leCommission, 1, 1, 1, 1);

        leBooking = new QLineEdit(widget_4);
        leBooking->setObjectName(QString::fromUtf8("leBooking"));

        gridLayout_6->addWidget(leBooking, 1, 2, 1, 1);

        lbCityLedger = new QLabel(widget_4);
        lbCityLedger->setObjectName(QString::fromUtf8("lbCityLedger"));

        gridLayout_6->addWidget(lbCityLedger, 2, 0, 1, 1);

        leCityLedgerCode = new EQLineEdit(widget_4);
        leCityLedgerCode->setObjectName(QString::fromUtf8("leCityLedgerCode"));
        leCityLedgerCode->setMaximumSize(QSize(60, 16777215));
        leCityLedgerCode->setProperty("ShowButton", QVariant(true));

        gridLayout_6->addWidget(leCityLedgerCode, 2, 1, 1, 1);

        leCityLedgerName = new EQLineEdit(widget_4);
        leCityLedgerName->setObjectName(QString::fromUtf8("leCityLedgerName"));
        leCityLedgerName->setFocusPolicy(Qt::NoFocus);
        leCityLedgerName->setReadOnly(true);

        gridLayout_6->addWidget(leCityLedgerName, 2, 2, 1, 1);

        lbCLedgerError = new QLabel(widget_4);
        lbCLedgerError->setObjectName(QString::fromUtf8("lbCLedgerError"));
        lbCLedgerError->setMaximumSize(QSize(16, 16));
        lbCLedgerError->setPixmap(QPixmap(QString::fromUtf8(":/images/question.png")));
        lbCLedgerError->setScaledContents(true);

        gridLayout_6->addWidget(lbCLedgerError, 2, 3, 1, 1);


        gridLayout->addLayout(gridLayout_6, 0, 0, 1, 1);


        verticalLayout_2->addWidget(widget_4);

        teRoomRemarks = new EQTextEdit(grRemarks);
        teRoomRemarks->setObjectName(QString::fromUtf8("teRoomRemarks"));
        teRoomRemarks->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(teRoomRemarks);

        btnWakeup = new QPushButton(grRemarks);
        btnWakeup->setObjectName(QString::fromUtf8("btnWakeup"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/alarm.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWakeup->setIcon(icon2);

        verticalLayout_2->addWidget(btnWakeup);


        gridLayout_5->addWidget(grRemarks, 0, 2, 1, 1);

        grPricing = new QGroupBox(widget_2);
        grPricing->setObjectName(QString::fromUtf8("grPricing"));
        gridLayout_7 = new QGridLayout(grPricing);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lbRoomPrice = new QLabel(grPricing);
        lbRoomPrice->setObjectName(QString::fromUtf8("lbRoomPrice"));
        sizePolicy.setHeightForWidth(lbRoomPrice->sizePolicy().hasHeightForWidth());
        lbRoomPrice->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(lbRoomPrice, 0, 0, 1, 1);

        leRooming = new EQLineEdit(grPricing);
        leRooming->setObjectName(QString::fromUtf8("leRooming"));

        gridLayout_7->addWidget(leRooming, 0, 2, 1, 1);

        chExtraBed = new EQCheckBox(grPricing);
        chExtraBed->setObjectName(QString::fromUtf8("chExtraBed"));

        gridLayout_7->addWidget(chExtraBed, 1, 1, 1, 1);

        label_15 = new QLabel(grPricing);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_15, 1, 0, 1, 1);

        label_32 = new QLabel(grPricing);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        sizePolicy.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy);

        gridLayout_7->addWidget(label_32, 2, 0, 1, 1);

        leExtraBedAmount = new EQLineEdit(grPricing);
        leExtraBedAmount->setObjectName(QString::fromUtf8("leExtraBedAmount"));

        gridLayout_7->addWidget(leExtraBedAmount, 1, 2, 1, 1);

        label_12 = new QLabel(grPricing);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_7->addWidget(label_12, 3, 0, 1, 1);

        lePricePerNight = new EQLineEdit(grPricing);
        lePricePerNight->setObjectName(QString::fromUtf8("lePricePerNight"));
        lePricePerNight->setFocusPolicy(Qt::NoFocus);
        lePricePerNight->setReadOnly(true);

        gridLayout_7->addWidget(lePricePerNight, 3, 2, 1, 1);

        leMealPrice = new EQLineEdit(grPricing);
        leMealPrice->setObjectName(QString::fromUtf8("leMealPrice"));

        gridLayout_7->addWidget(leMealPrice, 2, 2, 1, 1);

        lbVATMode = new QLabel(grPricing);
        lbVATMode->setObjectName(QString::fromUtf8("lbVATMode"));

        gridLayout_7->addWidget(lbVATMode, 4, 0, 1, 1);

        cbVAT = new EQComboBox(grPricing);
        cbVAT->setObjectName(QString::fromUtf8("cbVAT"));
        cbVAT->setProperty("Cache", QVariant(22));

        gridLayout_7->addWidget(cbVAT, 4, 2, 1, 1);

        label_13 = new QLabel(grPricing);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_7->addWidget(label_13, 5, 0, 1, 1);

        leNoVATReason = new EQLineEdit(grPricing);
        leNoVATReason->setObjectName(QString::fromUtf8("leNoVATReason"));

        gridLayout_7->addWidget(leNoVATReason, 5, 1, 1, 2);

        sbMealQty = new EQSpinBox(grPricing);
        sbMealQty->setObjectName(QString::fromUtf8("sbMealQty"));

        gridLayout_7->addWidget(sbMealQty, 2, 1, 1, 1);


        gridLayout_5->addWidget(grPricing, 0, 0, 1, 1);

        grPayment = new QGroupBox(widget_2);
        grPayment->setObjectName(QString::fromUtf8("grPayment"));
        grPayment->setMaximumSize(QSize(300, 16777215));
        gridLayout_3 = new QGridLayout(grPayment);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        leAdvance = new EQLineEdit(grPayment);
        leAdvance->setObjectName(QString::fromUtf8("leAdvance"));
        leAdvance->setFocusPolicy(Qt::NoFocus);
        leAdvance->setReadOnly(true);

        gridLayout_3->addWidget(leAdvance, 7, 2, 1, 1);

        label_7 = new QLabel(grPayment);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 5, 0, 1, 2);

        label_8 = new QLabel(grPayment);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 2);

        lbVAT = new QLabel(grPayment);
        lbVAT->setObjectName(QString::fromUtf8("lbVAT"));

        gridLayout_3->addWidget(lbVAT, 3, 0, 1, 1);

        label_6 = new QLabel(grPayment);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(label_6, 4, 0, 1, 1);

        lbPaymentMode = new QLabel(grPayment);
        lbPaymentMode->setObjectName(QString::fromUtf8("lbPaymentMode"));

        gridLayout_3->addWidget(lbPaymentMode, 6, 0, 1, 1);

        label_33 = new QLabel(grPayment);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_3->addWidget(label_33, 7, 0, 1, 1);

        btnAppendAdvance = new QPushButton(grPayment);
        btnAppendAdvance->setObjectName(QString::fromUtf8("btnAppendAdvance"));
        btnAppendAdvance->setEnabled(false);
        btnAppendAdvance->setMinimumSize(QSize(25, 25));
        btnAppendAdvance->setMaximumSize(QSize(25, 25));
        btnAppendAdvance->setFocusPolicy(Qt::NoFocus);
        btnAppendAdvance->setIcon(icon);

        gridLayout_3->addWidget(btnAppendAdvance, 7, 3, 1, 1);

        leTotal = new EQLineEdit(grPayment);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));
        leTotal->setFocusPolicy(Qt::NoFocus);
        leTotal->setReadOnly(true);
        leTotal->setClearButtonEnabled(false);

        gridLayout_3->addWidget(leTotal, 1, 2, 1, 2);

        leVAT = new EQLineEdit(grPayment);
        leVAT->setObjectName(QString::fromUtf8("leVAT"));
        leVAT->setFocusPolicy(Qt::NoFocus);
        leVAT->setReadOnly(true);

        gridLayout_3->addWidget(leVAT, 3, 2, 1, 2);

        leGrandTotal = new EQLineEdit(grPayment);
        leGrandTotal->setObjectName(QString::fromUtf8("leGrandTotal"));
        leGrandTotal->setFocusPolicy(Qt::NoFocus);
        leGrandTotal->setReadOnly(true);

        gridLayout_3->addWidget(leGrandTotal, 4, 2, 1, 2);

        leTotalUSD = new EQLineEdit(grPayment);
        leTotalUSD->setObjectName(QString::fromUtf8("leTotalUSD"));
        leTotalUSD->setFocusPolicy(Qt::NoFocus);
        leTotalUSD->setReadOnly(true);

        gridLayout_3->addWidget(leTotalUSD, 5, 2, 1, 2);

        cbPaymentType = new EQComboBox(grPayment);
        cbPaymentType->setObjectName(QString::fromUtf8("cbPaymentType"));
        cbPaymentType->setProperty("Cache", QVariant(11));

        gridLayout_3->addWidget(cbPaymentType, 6, 2, 1, 2);


        gridLayout_5->addWidget(grPayment, 0, 1, 1, 1);


        verticalLayout->addWidget(widget_2);

        QWidget::setTabOrder(leStatusCode, deEntry);
        QWidget::setTabOrder(deEntry, sbNights);
        QWidget::setTabOrder(sbNights, deDeparture);
        QWidget::setTabOrder(deDeparture, leRoomCode);
        QWidget::setTabOrder(leRoomCode, cbArrangment);
        QWidget::setTabOrder(cbArrangment, chMealIncluded);
        QWidget::setTabOrder(chMealIncluded, sbMan);
        QWidget::setTabOrder(sbMan, sbWoman);
        QWidget::setTabOrder(sbWoman, sbChild);
        QWidget::setTabOrder(sbChild, sbBaby);
        QWidget::setTabOrder(sbBaby, leSearchGuest);
        QWidget::setTabOrder(leSearchGuest, leRooming);
        QWidget::setTabOrder(leRooming, chExtraBed);
        QWidget::setTabOrder(chExtraBed, leExtraBedAmount);
        QWidget::setTabOrder(leExtraBedAmount, sbMealQty);
        QWidget::setTabOrder(sbMealQty, leMealPrice);
        QWidget::setTabOrder(leMealPrice, cbVAT);
        QWidget::setTabOrder(cbVAT, leNoVATReason);
        QWidget::setTabOrder(leNoVATReason, cbPaymentType);
        QWidget::setTabOrder(cbPaymentType, teEarlyCheckIn);
        QWidget::setTabOrder(teEarlyCheckIn, chEarlyCheckIn);
        QWidget::setTabOrder(chEarlyCheckIn, leEarlyCheckInFee);
        QWidget::setTabOrder(leEarlyCheckInFee, teLateChecout);
        QWidget::setTabOrder(teLateChecout, chLateCheckout);
        QWidget::setTabOrder(chLateCheckout, leLateCheckoutFee);
        QWidget::setTabOrder(leLateCheckoutFee, teArrivalTime);
        QWidget::setTabOrder(teArrivalTime, leArrivalFee);
        QWidget::setTabOrder(leArrivalFee, teDepartureTime);
        QWidget::setTabOrder(teDepartureTime, teRoomRemarks);

        retranslateUi(WReservationRoomTab);

        QMetaObject::connectSlotsByName(WReservationRoomTab);
    } // setupUi

    void retranslateUi(QWidget *WReservationRoomTab)
    {
        WReservationRoomTab->setWindowTitle(QCoreApplication::translate("WReservationRoomTab", "Room tab", nullptr));
        grCommon->setTitle(QCoreApplication::translate("WReservationRoomTab", "Common", nullptr));
        label_10->setText(QCoreApplication::translate("WReservationRoomTab", "Reservation type", nullptr));
        leInvoice->setText(QString());
        lbEndDateWarning->setText(QString());
        label_9->setText(QCoreApplication::translate("WReservationRoomTab", "Reservation #", nullptr));
        label_4->setText(QCoreApplication::translate("WReservationRoomTab", "Nights", nullptr));
        label_37->setText(QCoreApplication::translate("WReservationRoomTab", "Created", nullptr));
        label_38->setText(QCoreApplication::translate("WReservationRoomTab", "Invoice #", nullptr));
        lbWolking->setText(QCoreApplication::translate("WReservationRoomTab", "(Walkin)", nullptr));
        leReservId->setText(QString());
        lbStatusCode->setText(QCoreApplication::translate("WReservationRoomTab", "Status", nullptr));
        lbDayUse->setText(QCoreApplication::translate("WReservationRoomTab", "(Day use)", nullptr));
        lbEntryDate->setText(QCoreApplication::translate("WReservationRoomTab", "Entry date", nullptr));
        lbDepartureDate->setText(QCoreApplication::translate("WReservationRoomTab", "Departure", nullptr));
        lbStartDateWarning->setText(QString());
        grRoom->setTitle(QCoreApplication::translate("WReservationRoomTab", "Room", nullptr));
        label_19->setText(QString());
        label_36->setText(QCoreApplication::translate("WReservationRoomTab", "Upgrade\n"
"from", nullptr));
        lbArrangement->setText(QCoreApplication::translate("WReservationRoomTab", "Arrangement", nullptr));
        label_29->setText(QCoreApplication::translate("WReservationRoomTab", "Guests", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblGuest->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WReservationRoomTab", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblGuest->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WReservationRoomTab", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblGuest->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WReservationRoomTab", "Name", nullptr));
        btnNewGuest->setText(QString());
        lbRoom_2->setText(QCoreApplication::translate("WReservationRoomTab", "Room", nullptr));
        label_21->setText(QString());
        btnAllNation->setText(QCoreApplication::translate("WReservationRoomTab", "Nation!", nullptr));
        label_28->setText(QString());
        lbRoom->setText(QString());
        label_30->setText(QCoreApplication::translate("WReservationRoomTab", "Search guest", nullptr));
        chMealIncluded->setText(QCoreApplication::translate("WReservationRoomTab", "Meal included", nullptr));
        label_22->setText(QString());
        leUpgradeFrom->setText(QString());
        btnReadFromDevice->setText(QString());
        grAdd->setTitle(QCoreApplication::translate("WReservationRoomTab", "Additional", nullptr));
        label_34->setText(QCoreApplication::translate("WReservationRoomTab", "Late checkout", nullptr));
        label_25->setText(QCoreApplication::translate("WReservationRoomTab", "Departure time", nullptr));
        label_24->setText(QCoreApplication::translate("WReservationRoomTab", "Arrival time", nullptr));
        label_16->setText(QCoreApplication::translate("WReservationRoomTab", "Early checkin", nullptr));
        label_26->setText(QCoreApplication::translate("WReservationRoomTab", "Airport pickup fee", nullptr));
        lbEarlyCheckinWarning->setText(QString());
        teEarlyCheckIn->setDisplayFormat(QCoreApplication::translate("WReservationRoomTab", "HH:mm", nullptr));
        chEarlyCheckIn->setText(QString());
        label_23->setText(QCoreApplication::translate("WReservationRoomTab", "Early checkin fee", nullptr));
        label_35->setText(QCoreApplication::translate("WReservationRoomTab", "Late checkout fee", nullptr));
        chLateCheckout->setText(QString());
        chPickup->setText(QString());
        teArrivalTime->setDisplayFormat(QCoreApplication::translate("WReservationRoomTab", "HH:mm", nullptr));
        teDepartureTime->setDisplayFormat(QCoreApplication::translate("WReservationRoomTab", "HH:mm", nullptr));
        grRemarks->setTitle(QCoreApplication::translate("WReservationRoomTab", "Other", nullptr));
        lbCardex->setText(QCoreApplication::translate("WReservationRoomTab", "Cardex", nullptr));
        lbCardexError->setText(QString());
        label_39->setText(QCoreApplication::translate("WReservationRoomTab", "Cardex commission", nullptr));
        leCommission->setText(QCoreApplication::translate("WReservationRoomTab", "0.00", nullptr));
        leBooking->setPlaceholderText(QCoreApplication::translate("WReservationRoomTab", "Booking number", nullptr));
        lbCityLedger->setText(QCoreApplication::translate("WReservationRoomTab", "City ledger", nullptr));
        lbCLedgerError->setText(QString());
        teRoomRemarks->setPlaceholderText(QCoreApplication::translate("WReservationRoomTab", "Remarks, double click to show templates", nullptr));
        btnWakeup->setText(QCoreApplication::translate("WReservationRoomTab", "Wakeup", nullptr));
        grPricing->setTitle(QCoreApplication::translate("WReservationRoomTab", "Pricing", nullptr));
        lbRoomPrice->setText(QCoreApplication::translate("WReservationRoomTab", "Room price", nullptr));
        chExtraBed->setText(QString());
        label_15->setText(QCoreApplication::translate("WReservationRoomTab", "Extra bed", nullptr));
        label_32->setText(QCoreApplication::translate("WReservationRoomTab", "Meal", nullptr));
        label_12->setText(QCoreApplication::translate("WReservationRoomTab", "Price per night", nullptr));
        lbVATMode->setText(QCoreApplication::translate("WReservationRoomTab", "VAT mode", nullptr));
        label_13->setText(QCoreApplication::translate("WReservationRoomTab", "No VAT reason", nullptr));
        sbMealQty->setProperty("Field", QVariant(QCoreApplication::translate("WReservationRoomTab", "f_mealQty", nullptr)));
        grPayment->setTitle(QCoreApplication::translate("WReservationRoomTab", "Payment", nullptr));
        label_7->setText(QCoreApplication::translate("WReservationRoomTab", "Total, USD", nullptr));
        label_8->setText(QCoreApplication::translate("WReservationRoomTab", "Total", nullptr));
        lbVAT->setText(QCoreApplication::translate("WReservationRoomTab", "VAT", nullptr));
        label_6->setText(QCoreApplication::translate("WReservationRoomTab", "Grand total", nullptr));
        lbPaymentMode->setText(QCoreApplication::translate("WReservationRoomTab", "Payment", nullptr));
        label_33->setText(QCoreApplication::translate("WReservationRoomTab", "Advance", nullptr));
        btnAppendAdvance->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WReservationRoomTab: public Ui_WReservationRoomTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRESERVATIONROOMTAB_H
