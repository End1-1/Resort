/********************************************************************************
** Form generated from reading UI file 'dlggroupreservationfuck.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGGROUPRESERVATIONFUCK_H
#define UI_DLGGROUPRESERVATIONFUCK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcombobox.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>
#include <eqtextedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgGroupReservationFuck
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wll;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_5;
    QGridLayout *gridLayout_3;
    EQLineEdit *lePreAmount;
    EQTableWidget *tblCat;
    QLabel *label_10;
    EQLineEdit *lePreQty;
    QWidget *wl;
    QGridLayout *gridLayout_2;
    EQComboBox *cbCat;
    QLabel *label_6;
    QPushButton *btnArrangeToAll;
    EDateEdit *deDeparture;
    QLabel *label_3;
    QPushButton *btnDateAll;
    EQComboBox *cbModeOfPayment;
    QLabel *label_11;
    EDateEdit *deArrival;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_9;
    EQLineEdit *leGroupCode;
    QLabel *label_2;
    EQLineEdit *leExtraname;
    EQComboBox *cbBed;
    QPushButton *btnPriceToAll;
    EQLineEdit *lePrice;
    QLabel *label_8;
    QLabel *label_4;
    EQLineEdit *leGroupName;
    QLabel *label;
    QPushButton *btnAllPayments;
    EQComboBox *cbArr;
    QPushButton *btnCopyLast;
    QWidget *wr;
    QGridLayout *gridLayout;
    EQLineEdit *leCardexCode;
    QLabel *label_5;
    QPushButton *btnArrangeToAll_2;
    QPushButton *btnRemarksToAll;
    EQLineEdit *leGuest;
    QLabel *label_7;
    QLabel *lbCard;
    QPushButton *btnAllCL;
    EQLineEdit *leCLCode;
    QLabel *lbCityLedger;
    QPushButton *btnAllCard;
    EQLineEdit *leCardCode;
    QPushButton *btnRemarksToAll_2;
    QSpacerItem *verticalSpacer;
    EQLineEdit *leCardexName;
    EQLineEdit *leCLName;
    EQLineEdit *leCardName;
    QPushButton *btnAddGuest;
    EQTextEdit *teCommonRemark;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnClear;
    QPushButton *btnClearFilter;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnPrint;
    QPushButton *btnSave;
    QPushButton *btnReviveReservations;
    QPushButton *btnCancelGroup;
    QPushButton *btnTrackChanges;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    EQTableWidget *tblRoom;
    EQTextEdit *teIndRemarks;

    void setupUi(QWidget *DlgGroupReservationFuck)
    {
        if (DlgGroupReservationFuck->objectName().isEmpty())
            DlgGroupReservationFuck->setObjectName(QString::fromUtf8("DlgGroupReservationFuck"));
        DlgGroupReservationFuck->resize(1306, 603);
        verticalLayout = new QVBoxLayout(DlgGroupReservationFuck);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wll = new QWidget(DlgGroupReservationFuck);
        wll->setObjectName(QString::fromUtf8("wll"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(wll->sizePolicy().hasHeightForWidth());
        wll->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(wll);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(wll);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(widget_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lePreAmount = new EQLineEdit(widget_5);
        lePreAmount->setObjectName(QString::fromUtf8("lePreAmount"));
        lePreAmount->setReadOnly(true);

        gridLayout_3->addWidget(lePreAmount, 2, 2, 1, 1);

        tblCat = new EQTableWidget(widget_5);
        if (tblCat->columnCount() < 7)
            tblCat->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblCat->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblCat->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblCat->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblCat->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblCat->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblCat->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblCat->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tblCat->setObjectName(QString::fromUtf8("tblCat"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tblCat->sizePolicy().hasHeightForWidth());
        tblCat->setSizePolicy(sizePolicy1);
        tblCat->setMinimumSize(QSize(0, 0));
        tblCat->setMaximumSize(QSize(480, 16777215));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        tblCat->setFont(font);
        tblCat->setFocusPolicy(Qt::ClickFocus);
        tblCat->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblCat->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblCat->verticalHeader()->setDefaultSectionSize(21);

        gridLayout_3->addWidget(tblCat, 0, 0, 1, 3);

        label_10 = new QLabel(widget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        lePreQty = new EQLineEdit(widget_5);
        lePreQty->setObjectName(QString::fromUtf8("lePreQty"));
        lePreQty->setMaximumSize(QSize(40, 3333));
        lePreQty->setReadOnly(true);

        gridLayout_3->addWidget(lePreQty, 2, 1, 1, 1);


        horizontalLayout->addWidget(widget_5);

        wl = new QWidget(wll);
        wl->setObjectName(QString::fromUtf8("wl"));
        gridLayout_2 = new QGridLayout(wl);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cbCat = new EQComboBox(wl);
        cbCat->setObjectName(QString::fromUtf8("cbCat"));
        cbCat->setProperty("Cache", QVariant(54));

        gridLayout_2->addWidget(cbCat, 6, 3, 1, 1);

        label_6 = new QLabel(wl);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        btnArrangeToAll = new QPushButton(wl);
        btnArrangeToAll->setObjectName(QString::fromUtf8("btnArrangeToAll"));
        btnArrangeToAll->setMinimumSize(QSize(25, 25));
        btnArrangeToAll->setMaximumSize(QSize(25, 25));
        btnArrangeToAll->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnArrangeToAll->setIcon(icon);

        gridLayout_2->addWidget(btnArrangeToAll, 5, 2, 1, 1);

        deDeparture = new EDateEdit(wl);
        deDeparture->setObjectName(QString::fromUtf8("deDeparture"));
        deDeparture->setMaximumSize(QSize(90, 16777215));

        gridLayout_2->addWidget(deDeparture, 4, 4, 1, 1);

        label_3 = new QLabel(wl);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        btnDateAll = new QPushButton(wl);
        btnDateAll->setObjectName(QString::fromUtf8("btnDateAll"));
        btnDateAll->setMinimumSize(QSize(25, 25));
        btnDateAll->setMaximumSize(QSize(25, 25));
        btnDateAll->setFocusPolicy(Qt::NoFocus);
        btnDateAll->setIcon(icon);

        gridLayout_2->addWidget(btnDateAll, 4, 5, 1, 1);

        cbModeOfPayment = new EQComboBox(wl);
        cbModeOfPayment->setObjectName(QString::fromUtf8("cbModeOfPayment"));
        cbModeOfPayment->setMaximumSize(QSize(90, 16777215));
        cbModeOfPayment->setProperty("Cache", QVariant(11));

        gridLayout_2->addWidget(cbModeOfPayment, 5, 4, 1, 1);

        label_11 = new QLabel(wl);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 3, 3, 1, 1);

        deArrival = new EDateEdit(wl);
        deArrival->setObjectName(QString::fromUtf8("deArrival"));
        deArrival->setMaximumSize(QSize(90, 16777215));

        gridLayout_2->addWidget(deArrival, 4, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 7, 0, 1, 1);

        label_9 = new QLabel(wl);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 5, 3, 1, 1);

        leGroupCode = new EQLineEdit(wl);
        leGroupCode->setObjectName(QString::fromUtf8("leGroupCode"));
        leGroupCode->setMaximumSize(QSize(90, 555));
        leGroupCode->setReadOnly(true);

        gridLayout_2->addWidget(leGroupCode, 2, 1, 1, 1);

        label_2 = new QLabel(wl);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 3, 1, 1);

        leExtraname = new EQLineEdit(wl);
        leExtraname->setObjectName(QString::fromUtf8("leExtraname"));
        leExtraname->setMaximumSize(QSize(90, 16777215));

        gridLayout_2->addWidget(leExtraname, 3, 4, 1, 1);

        cbBed = new EQComboBox(wl);
        cbBed->setObjectName(QString::fromUtf8("cbBed"));
        cbBed->setProperty("Cache", QVariant(47));

        gridLayout_2->addWidget(cbBed, 6, 4, 1, 1);

        btnPriceToAll = new QPushButton(wl);
        btnPriceToAll->setObjectName(QString::fromUtf8("btnPriceToAll"));
        btnPriceToAll->setMinimumSize(QSize(25, 25));
        btnPriceToAll->setMaximumSize(QSize(25, 25));
        btnPriceToAll->setFocusPolicy(Qt::NoFocus);
        btnPriceToAll->setIcon(icon);

        gridLayout_2->addWidget(btnPriceToAll, 6, 5, 1, 1);

        lePrice = new EQLineEdit(wl);
        lePrice->setObjectName(QString::fromUtf8("lePrice"));
        lePrice->setMaximumSize(QSize(90, 16777215));

        gridLayout_2->addWidget(lePrice, 6, 1, 1, 1);

        label_8 = new QLabel(wl);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 6, 0, 1, 1);

        label_4 = new QLabel(wl);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 4, 3, 1, 1);

        leGroupName = new EQLineEdit(wl);
        leGroupName->setObjectName(QString::fromUtf8("leGroupName"));
        leGroupName->setMaximumSize(QSize(90, 16777215));

        gridLayout_2->addWidget(leGroupName, 2, 4, 1, 1);

        label = new QLabel(wl);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        btnAllPayments = new QPushButton(wl);
        btnAllPayments->setObjectName(QString::fromUtf8("btnAllPayments"));
        btnAllPayments->setMinimumSize(QSize(25, 25));
        btnAllPayments->setMaximumSize(QSize(25, 25));
        btnAllPayments->setFocusPolicy(Qt::NoFocus);
        btnAllPayments->setIcon(icon);

        gridLayout_2->addWidget(btnAllPayments, 5, 5, 1, 1);

        cbArr = new EQComboBox(wl);
        cbArr->setObjectName(QString::fromUtf8("cbArr"));
        cbArr->setMaximumSize(QSize(90, 16777215));
        cbArr->setProperty("Cache", QVariant(37));

        gridLayout_2->addWidget(cbArr, 5, 1, 1, 1);

        btnCopyLast = new QPushButton(wl);
        btnCopyLast->setObjectName(QString::fromUtf8("btnCopyLast"));

        gridLayout_2->addWidget(btnCopyLast, 2, 5, 1, 1);


        horizontalLayout->addWidget(wl);

        wr = new QWidget(wll);
        wr->setObjectName(QString::fromUtf8("wr"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(wr->sizePolicy().hasHeightForWidth());
        wr->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(wr);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leCardexCode = new EQLineEdit(wr);
        leCardexCode->setObjectName(QString::fromUtf8("leCardexCode"));
        leCardexCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCardexCode, 2, 1, 1, 1);

        label_5 = new QLabel(wr);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        btnArrangeToAll_2 = new QPushButton(wr);
        btnArrangeToAll_2->setObjectName(QString::fromUtf8("btnArrangeToAll_2"));
        btnArrangeToAll_2->setMinimumSize(QSize(25, 25));
        btnArrangeToAll_2->setMaximumSize(QSize(25, 25));
        btnArrangeToAll_2->setFocusPolicy(Qt::NoFocus);
        btnArrangeToAll_2->setIcon(icon);

        gridLayout->addWidget(btnArrangeToAll_2, 2, 8, 1, 1);

        btnRemarksToAll = new QPushButton(wr);
        btnRemarksToAll->setObjectName(QString::fromUtf8("btnRemarksToAll"));
        btnRemarksToAll->setMinimumSize(QSize(25, 25));
        btnRemarksToAll->setMaximumSize(QSize(25, 25));
        btnRemarksToAll->setFocusPolicy(Qt::NoFocus);
        btnRemarksToAll->setIcon(icon);

        gridLayout->addWidget(btnRemarksToAll, 8, 8, 1, 1);

        leGuest = new EQLineEdit(wr);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setEnabled(false);

        gridLayout->addWidget(leGuest, 7, 1, 1, 5);

        label_7 = new QLabel(wr);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(false);

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        lbCard = new QLabel(wr);
        lbCard->setObjectName(QString::fromUtf8("lbCard"));

        gridLayout->addWidget(lbCard, 6, 0, 1, 1);

        btnAllCL = new QPushButton(wr);
        btnAllCL->setObjectName(QString::fromUtf8("btnAllCL"));
        btnAllCL->setMinimumSize(QSize(25, 25));
        btnAllCL->setMaximumSize(QSize(25, 25));
        btnAllCL->setFocusPolicy(Qt::NoFocus);
        btnAllCL->setIcon(icon);

        gridLayout->addWidget(btnAllCL, 5, 8, 1, 1);

        leCLCode = new EQLineEdit(wr);
        leCLCode->setObjectName(QString::fromUtf8("leCLCode"));
        leCLCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCLCode, 5, 1, 1, 1);

        lbCityLedger = new QLabel(wr);
        lbCityLedger->setObjectName(QString::fromUtf8("lbCityLedger"));

        gridLayout->addWidget(lbCityLedger, 5, 0, 1, 1);

        btnAllCard = new QPushButton(wr);
        btnAllCard->setObjectName(QString::fromUtf8("btnAllCard"));
        btnAllCard->setMinimumSize(QSize(25, 25));
        btnAllCard->setMaximumSize(QSize(25, 25));
        btnAllCard->setFocusPolicy(Qt::NoFocus);
        btnAllCard->setIcon(icon);

        gridLayout->addWidget(btnAllCard, 6, 8, 1, 1);

        leCardCode = new EQLineEdit(wr);
        leCardCode->setObjectName(QString::fromUtf8("leCardCode"));
        leCardCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCardCode, 6, 1, 1, 1);

        btnRemarksToAll_2 = new QPushButton(wr);
        btnRemarksToAll_2->setObjectName(QString::fromUtf8("btnRemarksToAll_2"));
        btnRemarksToAll_2->setEnabled(false);
        btnRemarksToAll_2->setMinimumSize(QSize(25, 25));
        btnRemarksToAll_2->setMaximumSize(QSize(25, 25));
        btnRemarksToAll_2->setFocusPolicy(Qt::NoFocus);
        btnRemarksToAll_2->setIcon(icon);

        gridLayout->addWidget(btnRemarksToAll_2, 7, 8, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        leCardexName = new EQLineEdit(wr);
        leCardexName->setObjectName(QString::fromUtf8("leCardexName"));

        gridLayout->addWidget(leCardexName, 2, 2, 1, 5);

        leCLName = new EQLineEdit(wr);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));
        leCLName->setFocusPolicy(Qt::NoFocus);
        leCLName->setReadOnly(true);

        gridLayout->addWidget(leCLName, 5, 2, 1, 5);

        leCardName = new EQLineEdit(wr);
        leCardName->setObjectName(QString::fromUtf8("leCardName"));
        leCardName->setFocusPolicy(Qt::NoFocus);
        leCardName->setReadOnly(true);

        gridLayout->addWidget(leCardName, 6, 2, 1, 5);

        btnAddGuest = new QPushButton(wr);
        btnAddGuest->setObjectName(QString::fromUtf8("btnAddGuest"));
        btnAddGuest->setEnabled(false);
        btnAddGuest->setMaximumSize(QSize(25, 25));
        btnAddGuest->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddGuest->setIcon(icon1);

        gridLayout->addWidget(btnAddGuest, 7, 6, 1, 1);

        teCommonRemark = new EQTextEdit(wr);
        teCommonRemark->setObjectName(QString::fromUtf8("teCommonRemark"));

        gridLayout->addWidget(teCommonRemark, 8, 1, 1, 6);


        horizontalLayout->addWidget(wr);


        verticalLayout->addWidget(wll);

        widget_4 = new QWidget(DlgGroupReservationFuck);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnClear = new QPushButton(widget_4);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        horizontalLayout_2->addWidget(btnClear);

        btnClearFilter = new QPushButton(widget_4);
        btnClearFilter->setObjectName(QString::fromUtf8("btnClearFilter"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/remove_filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearFilter->setIcon(icon2);

        horizontalLayout_2->addWidget(btnClearFilter);

        horizontalSpacer = new QSpacerItem(793, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnPrint = new QPushButton(widget_4);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(btnPrint);

        btnSave = new QPushButton(widget_4);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(btnSave);

        btnReviveReservations = new QPushButton(widget_4);
        btnReviveReservations->setObjectName(QString::fromUtf8("btnReviveReservations"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/heart-pulses.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReviveReservations->setIcon(icon3);

        horizontalLayout_2->addWidget(btnReviveReservations);

        btnCancelGroup = new QPushButton(widget_4);
        btnCancelGroup->setObjectName(QString::fromUtf8("btnCancelGroup"));
        btnCancelGroup->setEnabled(true);

        horizontalLayout_2->addWidget(btnCancelGroup);

        btnTrackChanges = new QPushButton(widget_4);
        btnTrackChanges->setObjectName(QString::fromUtf8("btnTrackChanges"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTrackChanges->setIcon(icon4);

        horizontalLayout_2->addWidget(btnTrackChanges);


        verticalLayout->addWidget(widget_4);

        widget_3 = new QWidget(DlgGroupReservationFuck);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(3);
        sizePolicy3.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy3);
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tblRoom = new EQTableWidget(widget_3);
        if (tblRoom->columnCount() < 22)
            tblRoom->setColumnCount(22);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(10, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(11, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(12, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(13, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(14, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(15, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(16, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(17, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(18, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(19, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(20, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tblRoom->setHorizontalHeaderItem(21, __qtablewidgetitem28);
        tblRoom->setObjectName(QString::fromUtf8("tblRoom"));
        tblRoom->setFocusPolicy(Qt::ClickFocus);
        tblRoom->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblRoom->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblRoom->setSelectionMode(QAbstractItemView::SingleSelection);
        tblRoom->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblRoom->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_2->addWidget(tblRoom);


        verticalLayout->addWidget(widget_3);

        teIndRemarks = new EQTextEdit(DlgGroupReservationFuck);
        teIndRemarks->setObjectName(QString::fromUtf8("teIndRemarks"));
        teIndRemarks->setMaximumSize(QSize(16777215, 50));
        teIndRemarks->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(teIndRemarks);

        QWidget::setTabOrder(leGroupCode, leGroupName);
        QWidget::setTabOrder(leGroupName, leExtraname);
        QWidget::setTabOrder(leExtraname, deArrival);
        QWidget::setTabOrder(deArrival, deDeparture);
        QWidget::setTabOrder(deDeparture, cbArr);
        QWidget::setTabOrder(cbArr, cbModeOfPayment);
        QWidget::setTabOrder(cbModeOfPayment, lePrice);
        QWidget::setTabOrder(lePrice, cbCat);
        QWidget::setTabOrder(cbCat, cbBed);
        QWidget::setTabOrder(cbBed, leCardexCode);
        QWidget::setTabOrder(leCardexCode, leCardexName);
        QWidget::setTabOrder(leCardexName, leCLCode);
        QWidget::setTabOrder(leCLCode, leCardCode);
        QWidget::setTabOrder(leCardCode, leGuest);
        QWidget::setTabOrder(leGuest, teCommonRemark);
        QWidget::setTabOrder(teCommonRemark, lePreQty);
        QWidget::setTabOrder(lePreQty, lePreAmount);
        QWidget::setTabOrder(lePreAmount, btnClear);
        QWidget::setTabOrder(btnClear, btnClearFilter);
        QWidget::setTabOrder(btnClearFilter, btnReviveReservations);
        QWidget::setTabOrder(btnReviveReservations, btnCancelGroup);

        retranslateUi(DlgGroupReservationFuck);

        QMetaObject::connectSlotsByName(DlgGroupReservationFuck);
    } // setupUi

    void retranslateUi(QWidget *DlgGroupReservationFuck)
    {
        DlgGroupReservationFuck->setWindowTitle(QCoreApplication::translate("DlgGroupReservationFuck", "Group Reservation", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblCat->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Cat", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblCat->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Bed", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblCat->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Tot.", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblCat->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Free", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblCat->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Tot", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblCat->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblCat->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgGroupReservationFuck", "M", nullptr));
        label_10->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Total (Qty/Amount)", nullptr));
        label_6->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Arrangement", nullptr));
        btnArrangeToAll->setText(QString());
        label_3->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Arrival", nullptr));
        btnDateAll->setText(QString());
        label_11->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Extra name", nullptr));
        label_9->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Mode of payment", nullptr));
        label_2->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Group name", nullptr));
        btnPriceToAll->setText(QString());
        label_8->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Price", nullptr));
        label_4->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Departure", nullptr));
        label->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Group id", nullptr));
        btnAllPayments->setText(QString());
        btnCopyLast->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Copy from last", nullptr));
        label_5->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Cardex", nullptr));
        btnArrangeToAll_2->setText(QString());
        btnRemarksToAll->setText(QString());
        label_7->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Guest", nullptr));
        lbCard->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Card", nullptr));
        btnAllCL->setText(QString());
        lbCityLedger->setText(QCoreApplication::translate("DlgGroupReservationFuck", "City Ledger", nullptr));
        btnAllCard->setText(QString());
        btnRemarksToAll_2->setText(QString());
        btnAddGuest->setText(QString());
        teCommonRemark->setPlaceholderText(QCoreApplication::translate("DlgGroupReservationFuck", "Remarks", nullptr));
        btnClear->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Clear unsaved", nullptr));
        btnClearFilter->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Show all", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Print", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Save", nullptr));
        btnReviveReservations->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Revive", nullptr));
        btnCancelGroup->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Cancel group", nullptr));
        btnTrackChanges->setText(QString());
        QTableWidgetItem *___qtablewidgetitem7 = tblRoom->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblRoom->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblRoom->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Cat", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblRoom->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Bed", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblRoom->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Arrival", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblRoom->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblRoom->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblRoom->horizontalHeaderItem(7);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Nights", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblRoom->horizontalHeaderItem(8);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblRoom->horizontalHeaderItem(9);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Arr.", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblRoom->horizontalHeaderItem(10);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblRoom->horizontalHeaderItem(11);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Remars", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblRoom->horizontalHeaderItem(12);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Male", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblRoom->horizontalHeaderItem(13);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Female", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tblRoom->horizontalHeaderItem(14);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Child", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tblRoom->horizontalHeaderItem(15);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("DlgGroupReservationFuck", "GuestCode", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tblRoom->horizontalHeaderItem(16);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("DlgGroupReservationFuck", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tblRoom->horizontalHeaderItem(17);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("DlgGroupReservationFuck", "OK", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tblRoom->horizontalHeaderItem(18);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Reserve", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tblRoom->horizontalHeaderItem(19);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("DlgGroupReservationFuck", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tblRoom->horizontalHeaderItem(20);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("DlgGroupReservationFuck", "State", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tblRoom->horizontalHeaderItem(21);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("DlgGroupReservationFuck", "State id", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgGroupReservationFuck: public Ui_DlgGroupReservationFuck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGGROUPRESERVATIONFUCK_H
