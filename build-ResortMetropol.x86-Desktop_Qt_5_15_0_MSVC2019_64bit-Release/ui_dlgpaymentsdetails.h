/********************************************************************************
** Form generated from reading UI file 'dlgpaymentsdetails.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPAYMENTSDETAILS_H
#define UI_DLGPAYMENTSDETAILS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgPaymentsDetails
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    EQLineEdit *leRoomName;
    QLabel *label_2;
    EQLineEdit *leCityLedgerName;
    QLabel *label_18;
    EQLineEdit *leGuest;
    QLineEdit *leReservation;
    QLabel *label_19;
    EQLineEdit *leCityLedgerCode;
    EQLineEdit *leInvoice;
    QPushButton *btnSave;
    EQLineEdit *leRoomCode;
    QPushButton *btnOptions;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCash;
    QPushButton *btnCard;
    QPushButton *btnCityLedger;
    QPushButton *btnBank;
    QPushButton *btnBankPayX;
    QPushButton *btnBankPayX_2;
    QSpacerItem *horizontalSpacer_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    EQTableWidget *tblGuest;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_7;
    EQLineEdit *leTotalUSDGuest;
    QLabel *label_4;
    EQLineEdit *lePaidUSDGuest;
    EQLineEdit *leBalanceAMDGuest;
    EQLineEdit *leTotalAmdGuest;
    QLabel *label_3;
    EQLineEdit *leBalanceUSDGuest;
    QLabel *label_6;
    QLabel *label_5;
    EQLineEdit *lePaidAMDGuest;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    EQTableWidget *tblCompany;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    EQLineEdit *leTotalCompUSD;
    QLabel *label_9;
    EQLineEdit *lePaidCompUSD;
    EQLineEdit *leBalanceCompAMD;
    EQLineEdit *leTotalCompAMD;
    QLabel *label_10;
    EQLineEdit *leBalanceCompUSD;
    QLabel *label_11;
    QLabel *label_12;
    EQLineEdit *lePaidCompAMD;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    EQTableWidget *tblRefund;
    QWidget *widget_4;
    QGridLayout *gridLayout_5;
    QLabel *label_23;
    EQLineEdit *leRefund;
    QLabel *label_20;
    EQLineEdit *leRefundUSD;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_22;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_15;
    EQLineEdit *leTotalAMD;
    EQLineEdit *leTotalUSD;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_14;
    EQLineEdit *lePaidAMD;
    EQLineEdit *lePaidUSD;
    QLabel *label_13;
    EQLineEdit *leBalanceAMD;
    EQLineEdit *leBalanceUSD;

    void setupUi(QDialog *DlgPaymentsDetails)
    {
        if (DlgPaymentsDetails->objectName().isEmpty())
            DlgPaymentsDetails->setObjectName(QString::fromUtf8("DlgPaymentsDetails"));
        DlgPaymentsDetails->resize(1005, 548);
        DlgPaymentsDetails->setMinimumSize(QSize(800, 0));
        verticalLayout_2 = new QVBoxLayout(DlgPaymentsDetails);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(DlgPaymentsDetails);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 8, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        leRoomName = new EQLineEdit(widget);
        leRoomName->setObjectName(QString::fromUtf8("leRoomName"));
        leRoomName->setMaximumSize(QSize(100, 16777215));
        leRoomName->setFocusPolicy(Qt::NoFocus);
        leRoomName->setReadOnly(true);

        gridLayout_4->addWidget(leRoomName, 0, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 6, 1, 1);

        leCityLedgerName = new EQLineEdit(widget);
        leCityLedgerName->setObjectName(QString::fromUtf8("leCityLedgerName"));
        leCityLedgerName->setFocusPolicy(Qt::NoFocus);
        leCityLedgerName->setReadOnly(true);

        gridLayout_4->addWidget(leCityLedgerName, 2, 3, 1, 5);

        label_18 = new QLabel(widget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_4->addWidget(label_18, 0, 3, 1, 1);

        leGuest = new EQLineEdit(widget);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setMinimumSize(QSize(200, 0));
        leGuest->setFocusPolicy(Qt::NoFocus);
        leGuest->setReadOnly(true);

        gridLayout_4->addWidget(leGuest, 0, 7, 1, 1);

        leReservation = new QLineEdit(widget);
        leReservation->setObjectName(QString::fromUtf8("leReservation"));
        leReservation->setEnabled(false);
        leReservation->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(leReservation, 0, 5, 1, 1);

        label_19 = new QLabel(widget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_4->addWidget(label_19, 2, 0, 1, 1);

        leCityLedgerCode = new EQLineEdit(widget);
        leCityLedgerCode->setObjectName(QString::fromUtf8("leCityLedgerCode"));
        leCityLedgerCode->setFocusPolicy(Qt::NoFocus);
        leCityLedgerCode->setReadOnly(true);

        gridLayout_4->addWidget(leCityLedgerCode, 2, 1, 1, 2);

        leInvoice = new EQLineEdit(widget);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(70, 16777215));
        leInvoice->setFocusPolicy(Qt::NoFocus);
        leInvoice->setReadOnly(true);

        gridLayout_4->addWidget(leInvoice, 0, 4, 1, 1);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon);
        btnSave->setIconSize(QSize(20, 20));

        gridLayout_4->addWidget(btnSave, 0, 9, 1, 1);

        leRoomCode = new EQLineEdit(widget);
        leRoomCode->setObjectName(QString::fromUtf8("leRoomCode"));
        leRoomCode->setMaximumSize(QSize(40, 16777215));
        leRoomCode->setFocusPolicy(Qt::ClickFocus);
        leRoomCode->setReadOnly(false);

        gridLayout_4->addWidget(leRoomCode, 0, 1, 1, 1);

        btnOptions = new QPushButton(widget);
        btnOptions->setObjectName(QString::fromUtf8("btnOptions"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOptions->setIcon(icon1);
        btnOptions->setIconSize(QSize(20, 20));

        gridLayout_4->addWidget(btnOptions, 2, 9, 1, 1);


        verticalLayout_2->addWidget(widget);

        frame_2 = new QFrame(DlgPaymentsDetails);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnCash = new QPushButton(frame_2);
        btnCash->setObjectName(QString::fromUtf8("btnCash"));
        btnCash->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(btnCash);

        btnCard = new QPushButton(frame_2);
        btnCard->setObjectName(QString::fromUtf8("btnCard"));
        btnCard->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(btnCard);

        btnCityLedger = new QPushButton(frame_2);
        btnCityLedger->setObjectName(QString::fromUtf8("btnCityLedger"));
        btnCityLedger->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(btnCityLedger);

        btnBank = new QPushButton(frame_2);
        btnBank->setObjectName(QString::fromUtf8("btnBank"));
        btnBank->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(btnBank);

        btnBankPayX = new QPushButton(frame_2);
        btnBankPayX->setObjectName(QString::fromUtf8("btnBankPayX"));
        btnBankPayX->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(btnBankPayX);

        btnBankPayX_2 = new QPushButton(frame_2);
        btnBankPayX_2->setObjectName(QString::fromUtf8("btnBankPayX_2"));
        btnBankPayX_2->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(btnBankPayX_2);

        horizontalSpacer_5 = new QSpacerItem(453, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(frame_2);

        tabWidget = new QTabWidget(DlgPaymentsDetails);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tblGuest = new EQTableWidget(tab);
        if (tblGuest->columnCount() < 11)
            tblGuest->setColumnCount(11);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblGuest->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        tblGuest->setObjectName(QString::fromUtf8("tblGuest"));
        tblGuest->setMinimumSize(QSize(0, 150));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        tblGuest->setFont(font);
        tblGuest->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout->addWidget(tblGuest);

        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        leTotalUSDGuest = new EQLineEdit(widget_2);
        leTotalUSDGuest->setObjectName(QString::fromUtf8("leTotalUSDGuest"));
        leTotalUSDGuest->setMinimumSize(QSize(120, 0));
        leTotalUSDGuest->setMaximumSize(QSize(120, 16777215));
        leTotalUSDGuest->setFocusPolicy(Qt::NoFocus);
        leTotalUSDGuest->setStyleSheet(QString::fromUtf8("background:#9dff8a;"));
        leTotalUSDGuest->setReadOnly(true);

        gridLayout->addWidget(leTotalUSDGuest, 1, 3, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        lePaidUSDGuest = new EQLineEdit(widget_2);
        lePaidUSDGuest->setObjectName(QString::fromUtf8("lePaidUSDGuest"));
        lePaidUSDGuest->setMinimumSize(QSize(120, 0));
        lePaidUSDGuest->setMaximumSize(QSize(120, 16777215));
        lePaidUSDGuest->setFocusPolicy(Qt::NoFocus);
        lePaidUSDGuest->setStyleSheet(QString::fromUtf8("background:#9dff8a;"));
        lePaidUSDGuest->setReadOnly(true);

        gridLayout->addWidget(lePaidUSDGuest, 2, 3, 1, 1);

        leBalanceAMDGuest = new EQLineEdit(widget_2);
        leBalanceAMDGuest->setObjectName(QString::fromUtf8("leBalanceAMDGuest"));
        leBalanceAMDGuest->setMinimumSize(QSize(120, 0));
        leBalanceAMDGuest->setMaximumSize(QSize(120, 16777215));
        leBalanceAMDGuest->setFocusPolicy(Qt::NoFocus);
        leBalanceAMDGuest->setStyleSheet(QString::fromUtf8("background:#9dff8a;"));
        leBalanceAMDGuest->setReadOnly(true);

        gridLayout->addWidget(leBalanceAMDGuest, 3, 2, 1, 1);

        leTotalAmdGuest = new EQLineEdit(widget_2);
        leTotalAmdGuest->setObjectName(QString::fromUtf8("leTotalAmdGuest"));
        leTotalAmdGuest->setMinimumSize(QSize(120, 0));
        leTotalAmdGuest->setMaximumSize(QSize(120, 16777215));
        leTotalAmdGuest->setFocusPolicy(Qt::NoFocus);
        leTotalAmdGuest->setStyleSheet(QString::fromUtf8("background:#9dff8a;"));
        leTotalAmdGuest->setReadOnly(true);

        gridLayout->addWidget(leTotalAmdGuest, 1, 2, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        leBalanceUSDGuest = new EQLineEdit(widget_2);
        leBalanceUSDGuest->setObjectName(QString::fromUtf8("leBalanceUSDGuest"));
        leBalanceUSDGuest->setMinimumSize(QSize(120, 0));
        leBalanceUSDGuest->setMaximumSize(QSize(120, 16777215));
        leBalanceUSDGuest->setFocusPolicy(Qt::NoFocus);
        leBalanceUSDGuest->setStyleSheet(QString::fromUtf8("background:#9dff8a;"));
        leBalanceUSDGuest->setReadOnly(true);

        gridLayout->addWidget(leBalanceUSDGuest, 3, 3, 1, 1);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 1, 1, 1);

        lePaidAMDGuest = new EQLineEdit(widget_2);
        lePaidAMDGuest->setObjectName(QString::fromUtf8("lePaidAMDGuest"));
        lePaidAMDGuest->setMinimumSize(QSize(120, 0));
        lePaidAMDGuest->setMaximumSize(QSize(120, 16777215));
        lePaidAMDGuest->setFocusPolicy(Qt::NoFocus);
        lePaidAMDGuest->setStyleSheet(QString::fromUtf8("background:#9dff8a;"));
        lePaidAMDGuest->setReadOnly(true);

        gridLayout->addWidget(lePaidAMDGuest, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tblCompany = new EQTableWidget(tab_2);
        if (tblCompany->columnCount() < 11)
            tblCompany->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(7, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(8, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(9, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblCompany->setHorizontalHeaderItem(10, __qtablewidgetitem21);
        tblCompany->setObjectName(QString::fromUtf8("tblCompany"));
        tblCompany->setFont(font);
        tblCompany->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_3->addWidget(tblCompany);

        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 3, 1, 1);

        leTotalCompUSD = new EQLineEdit(widget_3);
        leTotalCompUSD->setObjectName(QString::fromUtf8("leTotalCompUSD"));
        leTotalCompUSD->setMinimumSize(QSize(120, 0));
        leTotalCompUSD->setMaximumSize(QSize(120, 16777215));
        leTotalCompUSD->setFocusPolicy(Qt::NoFocus);
        leTotalCompUSD->setStyleSheet(QString::fromUtf8("background:#ffb68a;"));
        leTotalCompUSD->setReadOnly(true);

        gridLayout_2->addWidget(leTotalCompUSD, 1, 3, 1, 1);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 2, 1, 1, 1);

        lePaidCompUSD = new EQLineEdit(widget_3);
        lePaidCompUSD->setObjectName(QString::fromUtf8("lePaidCompUSD"));
        lePaidCompUSD->setMinimumSize(QSize(120, 0));
        lePaidCompUSD->setMaximumSize(QSize(120, 16777215));
        lePaidCompUSD->setFocusPolicy(Qt::NoFocus);
        lePaidCompUSD->setStyleSheet(QString::fromUtf8("background:#ffb68a;"));
        lePaidCompUSD->setReadOnly(true);

        gridLayout_2->addWidget(lePaidCompUSD, 2, 3, 1, 1);

        leBalanceCompAMD = new EQLineEdit(widget_3);
        leBalanceCompAMD->setObjectName(QString::fromUtf8("leBalanceCompAMD"));
        leBalanceCompAMD->setMinimumSize(QSize(120, 0));
        leBalanceCompAMD->setMaximumSize(QSize(120, 16777215));
        leBalanceCompAMD->setFocusPolicy(Qt::NoFocus);
        leBalanceCompAMD->setStyleSheet(QString::fromUtf8("background:#ffb68a;"));
        leBalanceCompAMD->setReadOnly(true);

        gridLayout_2->addWidget(leBalanceCompAMD, 3, 2, 1, 1);

        leTotalCompAMD = new EQLineEdit(widget_3);
        leTotalCompAMD->setObjectName(QString::fromUtf8("leTotalCompAMD"));
        leTotalCompAMD->setMinimumSize(QSize(120, 0));
        leTotalCompAMD->setMaximumSize(QSize(120, 16777215));
        leTotalCompAMD->setFocusPolicy(Qt::NoFocus);
        leTotalCompAMD->setStyleSheet(QString::fromUtf8("background:#ffb68a;"));
        leTotalCompAMD->setReadOnly(true);

        gridLayout_2->addWidget(leTotalCompAMD, 1, 2, 1, 1);

        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 1, 1, 1, 1);

        leBalanceCompUSD = new EQLineEdit(widget_3);
        leBalanceCompUSD->setObjectName(QString::fromUtf8("leBalanceCompUSD"));
        leBalanceCompUSD->setMinimumSize(QSize(120, 0));
        leBalanceCompUSD->setMaximumSize(QSize(120, 16777215));
        leBalanceCompUSD->setFocusPolicy(Qt::NoFocus);
        leBalanceCompUSD->setStyleSheet(QString::fromUtf8("background:#ffb68a;"));
        leBalanceCompUSD->setReadOnly(true);

        gridLayout_2->addWidget(leBalanceCompUSD, 3, 3, 1, 1);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 0, 2, 1, 1);

        label_12 = new QLabel(widget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 3, 1, 1, 1);

        lePaidCompAMD = new EQLineEdit(widget_3);
        lePaidCompAMD->setObjectName(QString::fromUtf8("lePaidCompAMD"));
        lePaidCompAMD->setMinimumSize(QSize(120, 0));
        lePaidCompAMD->setMaximumSize(QSize(120, 16777215));
        lePaidCompAMD->setFocusPolicy(Qt::NoFocus);
        lePaidCompAMD->setStyleSheet(QString::fromUtf8("background:#ffb68a;"));
        lePaidCompAMD->setReadOnly(true);

        gridLayout_2->addWidget(lePaidCompAMD, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 0, 1, 1);


        verticalLayout_3->addWidget(widget_3);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tblRefund = new EQTableWidget(tab_3);
        if (tblRefund->columnCount() < 9)
            tblRefund->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(6, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(7, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tblRefund->setHorizontalHeaderItem(8, __qtablewidgetitem30);
        tblRefund->setObjectName(QString::fromUtf8("tblRefund"));
        tblRefund->setMinimumSize(QSize(0, 150));
        tblRefund->setFont(font);
        tblRefund->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblRefund->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblRefund->setSelectionMode(QAbstractItemView::NoSelection);
        tblRefund->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_4->addWidget(tblRefund);

        widget_4 = new QWidget(tab_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_5 = new QGridLayout(widget_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(widget_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_23, 0, 4, 1, 1);

        leRefund = new EQLineEdit(widget_4);
        leRefund->setObjectName(QString::fromUtf8("leRefund"));
        leRefund->setMinimumSize(QSize(120, 0));
        leRefund->setMaximumSize(QSize(120, 16777215));
        leRefund->setFocusPolicy(Qt::NoFocus);
        leRefund->setReadOnly(true);

        gridLayout_5->addWidget(leRefund, 1, 4, 1, 1);

        label_20 = new QLabel(widget_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_20, 0, 5, 1, 1);

        leRefundUSD = new EQLineEdit(widget_4);
        leRefundUSD->setObjectName(QString::fromUtf8("leRefundUSD"));
        leRefundUSD->setMinimumSize(QSize(120, 0));
        leRefundUSD->setMaximumSize(QSize(120, 16777215));
        leRefundUSD->setFocusPolicy(Qt::NoFocus);
        leRefundUSD->setReadOnly(true);

        gridLayout_5->addWidget(leRefundUSD, 1, 5, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        label_22 = new QLabel(widget_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_5->addWidget(label_22, 1, 3, 1, 1);


        verticalLayout_4->addWidget(widget_4);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);

        frame = new QFrame(DlgPaymentsDetails);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(frame);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_17, 0, 2, 1, 1);

        label_16 = new QLabel(frame);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_16, 0, 3, 1, 1);

        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);

        gridLayout_3->addWidget(label_15, 1, 1, 1, 1);

        leTotalAMD = new EQLineEdit(frame);
        leTotalAMD->setObjectName(QString::fromUtf8("leTotalAMD"));
        leTotalAMD->setMinimumSize(QSize(120, 0));
        leTotalAMD->setMaximumSize(QSize(120, 16777215));
        leTotalAMD->setFont(font1);
        leTotalAMD->setFocusPolicy(Qt::NoFocus);
        leTotalAMD->setReadOnly(true);

        gridLayout_3->addWidget(leTotalAMD, 1, 2, 1, 1);

        leTotalUSD = new EQLineEdit(frame);
        leTotalUSD->setObjectName(QString::fromUtf8("leTotalUSD"));
        leTotalUSD->setMinimumSize(QSize(120, 0));
        leTotalUSD->setMaximumSize(QSize(120, 16777215));
        leTotalUSD->setFont(font1);
        leTotalUSD->setFocusPolicy(Qt::NoFocus);
        leTotalUSD->setReadOnly(true);

        gridLayout_3->addWidget(leTotalUSD, 1, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(560, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        gridLayout_3->addWidget(label_14, 2, 1, 1, 1);

        lePaidAMD = new EQLineEdit(frame);
        lePaidAMD->setObjectName(QString::fromUtf8("lePaidAMD"));
        lePaidAMD->setMinimumSize(QSize(120, 0));
        lePaidAMD->setMaximumSize(QSize(120, 16777215));
        lePaidAMD->setFont(font1);
        lePaidAMD->setFocusPolicy(Qt::NoFocus);
        lePaidAMD->setReadOnly(true);

        gridLayout_3->addWidget(lePaidAMD, 2, 2, 1, 1);

        lePaidUSD = new EQLineEdit(frame);
        lePaidUSD->setObjectName(QString::fromUtf8("lePaidUSD"));
        lePaidUSD->setMinimumSize(QSize(120, 0));
        lePaidUSD->setMaximumSize(QSize(120, 16777215));
        lePaidUSD->setFont(font1);
        lePaidUSD->setFocusPolicy(Qt::NoFocus);
        lePaidUSD->setReadOnly(true);

        gridLayout_3->addWidget(lePaidUSD, 2, 3, 1, 1);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        gridLayout_3->addWidget(label_13, 3, 1, 1, 1);

        leBalanceAMD = new EQLineEdit(frame);
        leBalanceAMD->setObjectName(QString::fromUtf8("leBalanceAMD"));
        leBalanceAMD->setMinimumSize(QSize(120, 0));
        leBalanceAMD->setMaximumSize(QSize(120, 16777215));
        leBalanceAMD->setFont(font1);
        leBalanceAMD->setFocusPolicy(Qt::NoFocus);
        leBalanceAMD->setReadOnly(true);

        gridLayout_3->addWidget(leBalanceAMD, 3, 2, 1, 1);

        leBalanceUSD = new EQLineEdit(frame);
        leBalanceUSD->setObjectName(QString::fromUtf8("leBalanceUSD"));
        leBalanceUSD->setMinimumSize(QSize(120, 0));
        leBalanceUSD->setMaximumSize(QSize(120, 16777215));
        leBalanceUSD->setFont(font1);
        leBalanceUSD->setFocusPolicy(Qt::NoFocus);
        leBalanceUSD->setReadOnly(true);

        gridLayout_3->addWidget(leBalanceUSD, 3, 3, 1, 1);


        verticalLayout_2->addWidget(frame);

        QWidget::setTabOrder(leRoomCode, leRoomName);
        QWidget::setTabOrder(leRoomName, leInvoice);
        QWidget::setTabOrder(leInvoice, leGuest);
        QWidget::setTabOrder(leGuest, leCityLedgerCode);
        QWidget::setTabOrder(leCityLedgerCode, leCityLedgerName);
        QWidget::setTabOrder(leCityLedgerName, btnCash);
        QWidget::setTabOrder(btnCash, btnCard);
        QWidget::setTabOrder(btnCard, btnCityLedger);
        QWidget::setTabOrder(btnCityLedger, btnBank);
        QWidget::setTabOrder(btnBank, tabWidget);
        QWidget::setTabOrder(tabWidget, tblGuest);
        QWidget::setTabOrder(tblGuest, leTotalAMD);
        QWidget::setTabOrder(leTotalAMD, leTotalUSD);
        QWidget::setTabOrder(leTotalUSD, lePaidAMD);
        QWidget::setTabOrder(lePaidAMD, lePaidUSD);
        QWidget::setTabOrder(lePaidUSD, leBalanceAMD);
        QWidget::setTabOrder(leBalanceAMD, leBalanceUSD);
        QWidget::setTabOrder(leBalanceUSD, btnSave);
        QWidget::setTabOrder(btnSave, leTotalUSDGuest);
        QWidget::setTabOrder(leTotalUSDGuest, lePaidUSDGuest);
        QWidget::setTabOrder(lePaidUSDGuest, leBalanceAMDGuest);
        QWidget::setTabOrder(leBalanceAMDGuest, leTotalAmdGuest);
        QWidget::setTabOrder(leTotalAmdGuest, leBalanceUSDGuest);
        QWidget::setTabOrder(leBalanceUSDGuest, lePaidAMDGuest);
        QWidget::setTabOrder(lePaidAMDGuest, tblCompany);
        QWidget::setTabOrder(tblCompany, leTotalCompUSD);
        QWidget::setTabOrder(leTotalCompUSD, lePaidCompUSD);
        QWidget::setTabOrder(lePaidCompUSD, leBalanceCompAMD);
        QWidget::setTabOrder(leBalanceCompAMD, leTotalCompAMD);
        QWidget::setTabOrder(leTotalCompAMD, leBalanceCompUSD);
        QWidget::setTabOrder(leBalanceCompUSD, lePaidCompAMD);

        retranslateUi(DlgPaymentsDetails);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgPaymentsDetails);
    } // setupUi

    void retranslateUi(QDialog *DlgPaymentsDetails)
    {
        DlgPaymentsDetails->setWindowTitle(QCoreApplication::translate("DlgPaymentsDetails", "Payments details", nullptr));
        label->setText(QCoreApplication::translate("DlgPaymentsDetails", "Room", nullptr));
        label_2->setText(QCoreApplication::translate("DlgPaymentsDetails", "Guest", nullptr));
        label_18->setText(QCoreApplication::translate("DlgPaymentsDetails", "Invoice N:", nullptr));
        label_19->setText(QCoreApplication::translate("DlgPaymentsDetails", "City ledger", nullptr));
        btnSave->setText(QString());
        btnOptions->setText(QString());
        btnCash->setText(QCoreApplication::translate("DlgPaymentsDetails", "Cash", nullptr));
        btnCard->setText(QCoreApplication::translate("DlgPaymentsDetails", "Card", nullptr));
        btnCityLedger->setText(QCoreApplication::translate("DlgPaymentsDetails", "City ledger", nullptr));
        btnBank->setText(QCoreApplication::translate("DlgPaymentsDetails", "Bank", nullptr));
        btnBankPayX->setText(QCoreApplication::translate("DlgPaymentsDetails", "PayX", nullptr));
        btnBankPayX_2->setText(QCoreApplication::translate("DlgPaymentsDetails", "Terminal", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblGuest->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgPaymentsDetails", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblGuest->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgPaymentsDetails", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblGuest->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgPaymentsDetails", "ModeId", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblGuest->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgPaymentsDetails", "Mode", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblGuest->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgPaymentsDetails", "Account", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblGuest->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgPaymentsDetails", "Amount, AMD", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblGuest->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgPaymentsDetails", "Amount, USD", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblGuest->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgPaymentsDetails", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblGuest->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgPaymentsDetails", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblGuest->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DlgPaymentsDetails", "Tax", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblGuest->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("DlgPaymentsDetails", "RV", nullptr));
        label_7->setText(QCoreApplication::translate("DlgPaymentsDetails", "USD", nullptr));
        label_4->setText(QCoreApplication::translate("DlgPaymentsDetails", "Paid", nullptr));
        label_3->setText(QCoreApplication::translate("DlgPaymentsDetails", "Total", nullptr));
        label_6->setText(QCoreApplication::translate("DlgPaymentsDetails", "AMD", nullptr));
        label_5->setText(QCoreApplication::translate("DlgPaymentsDetails", "Balance", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DlgPaymentsDetails", "Paid by guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblCompany->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("DlgPaymentsDetails", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblCompany->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("DlgPaymentsDetails", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblCompany->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("DlgPaymentsDetails", "ModeId", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblCompany->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("DlgPaymentsDetails", "Mode", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblCompany->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("DlgPaymentsDetails", "Account", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblCompany->horizontalHeaderItem(5);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("DlgPaymentsDetails", "Amount, AMD", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblCompany->horizontalHeaderItem(6);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("DlgPaymentsDetails", "Amount, USD", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblCompany->horizontalHeaderItem(7);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("DlgPaymentsDetails", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblCompany->horizontalHeaderItem(8);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("DlgPaymentsDetails", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblCompany->horizontalHeaderItem(9);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("DlgPaymentsDetails", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tblCompany->horizontalHeaderItem(10);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("DlgPaymentsDetails", "RV", nullptr));
        label_8->setText(QCoreApplication::translate("DlgPaymentsDetails", "USD", nullptr));
        label_9->setText(QCoreApplication::translate("DlgPaymentsDetails", "Paid", nullptr));
        label_10->setText(QCoreApplication::translate("DlgPaymentsDetails", "Total", nullptr));
        label_11->setText(QCoreApplication::translate("DlgPaymentsDetails", "AMD", nullptr));
        label_12->setText(QCoreApplication::translate("DlgPaymentsDetails", "Balance", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DlgPaymentsDetails", "Paid by company", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tblRefund->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("DlgPaymentsDetails", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tblRefund->horizontalHeaderItem(1);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("DlgPaymentsDetails", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tblRefund->horizontalHeaderItem(2);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("DlgPaymentsDetails", "Amount, AMD", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tblRefund->horizontalHeaderItem(3);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("DlgPaymentsDetails", "Amount, USD", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tblRefund->horizontalHeaderItem(4);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("DlgPaymentsDetails", "City Ledger", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tblRefund->horizontalHeaderItem(5);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("DlgPaymentsDetails", "City Ledger", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tblRefund->horizontalHeaderItem(6);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("DlgPaymentsDetails", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tblRefund->horizontalHeaderItem(7);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("DlgPaymentsDetails", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tblRefund->horizontalHeaderItem(8);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("DlgPaymentsDetails", "Side", nullptr));
        label_23->setText(QCoreApplication::translate("DlgPaymentsDetails", "AMD", nullptr));
        label_20->setText(QCoreApplication::translate("DlgPaymentsDetails", "USD", nullptr));
        label_22->setText(QCoreApplication::translate("DlgPaymentsDetails", "Total", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("DlgPaymentsDetails", "Refund", nullptr));
        label_17->setText(QCoreApplication::translate("DlgPaymentsDetails", "AMD", nullptr));
        label_16->setText(QCoreApplication::translate("DlgPaymentsDetails", "USD", nullptr));
        label_15->setText(QCoreApplication::translate("DlgPaymentsDetails", "Total", nullptr));
        label_14->setText(QCoreApplication::translate("DlgPaymentsDetails", "Paid", nullptr));
        label_13->setText(QCoreApplication::translate("DlgPaymentsDetails", "Balance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPaymentsDetails: public Ui_DlgPaymentsDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPAYMENTSDETAILS_H
