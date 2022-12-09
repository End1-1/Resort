/********************************************************************************
** Form generated from reading UI file 'wquickreservations.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WQUICKRESERVATIONS_H
#define UI_WQUICKRESERVATIONS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqtablewidget.h>
#include <wactivegroup.h>
#include <wcardex.h>

QT_BEGIN_NAMESPACE

class Ui_WQuickReservations
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnDateLeft;
    EDateEdit *deDate;
    QPushButton *btnDateRight;
    WCardex *wCardex;
    WActiveGroup *wGroup;
    QPushButton *btnRefresh;
    QPushButton *btnCheckinSelected;
    QPushButton *btnClearSelectedRooms;
    QPushButton *btnTrackControl;
    QPushButton *btnOpenReservation;
    QPushButton *btnGuests;
    QPushButton *btnMassNation;
    QPushButton *btnRoomRate;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    EQTableWidget *tbl;
    EQTableWidget *tblTotal;

    void setupUi(QWidget *WQuickReservations)
    {
        if (WQuickReservations->objectName().isEmpty())
            WQuickReservations->setObjectName(QString::fromUtf8("WQuickReservations"));
        WQuickReservations->resize(1385, 706);
        verticalLayout = new QVBoxLayout(WQuickReservations);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(WQuickReservations);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnDateLeft = new QPushButton(widget);
        btnDateLeft->setObjectName(QString::fromUtf8("btnDateLeft"));
        btnDateLeft->setMinimumSize(QSize(25, 25));
        btnDateLeft->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDateLeft->setIcon(icon);

        horizontalLayout->addWidget(btnDateLeft);

        deDate = new EDateEdit(widget);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deDate);

        btnDateRight = new QPushButton(widget);
        btnDateRight->setObjectName(QString::fromUtf8("btnDateRight"));
        btnDateRight->setMinimumSize(QSize(25, 25));
        btnDateRight->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDateRight->setIcon(icon1);

        horizontalLayout->addWidget(btnDateRight);

        wCardex = new WCardex(widget);
        wCardex->setObjectName(QString::fromUtf8("wCardex"));

        horizontalLayout->addWidget(wCardex);

        wGroup = new WActiveGroup(widget);
        wGroup->setObjectName(QString::fromUtf8("wGroup"));

        horizontalLayout->addWidget(wGroup);

        btnRefresh = new QPushButton(widget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setMaximumSize(QSize(25, 25));
        btnRefresh->setFocusPolicy(Qt::ClickFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/goto.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon2);

        horizontalLayout->addWidget(btnRefresh);

        btnCheckinSelected = new QPushButton(widget);
        btnCheckinSelected->setObjectName(QString::fromUtf8("btnCheckinSelected"));
        btnCheckinSelected->setMaximumSize(QSize(25, 25));
        btnCheckinSelected->setFocusPolicy(Qt::ClickFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/checkin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckinSelected->setIcon(icon3);

        horizontalLayout->addWidget(btnCheckinSelected);

        btnClearSelectedRooms = new QPushButton(widget);
        btnClearSelectedRooms->setObjectName(QString::fromUtf8("btnClearSelectedRooms"));
        btnClearSelectedRooms->setMaximumSize(QSize(25, 25));
        btnClearSelectedRooms->setFocusPolicy(Qt::ClickFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClearSelectedRooms->setIcon(icon4);

        horizontalLayout->addWidget(btnClearSelectedRooms);

        btnTrackControl = new QPushButton(widget);
        btnTrackControl->setObjectName(QString::fromUtf8("btnTrackControl"));
        btnTrackControl->setMaximumSize(QSize(25, 25));
        btnTrackControl->setFocusPolicy(Qt::ClickFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTrackControl->setIcon(icon5);

        horizontalLayout->addWidget(btnTrackControl);

        btnOpenReservation = new QPushButton(widget);
        btnOpenReservation->setObjectName(QString::fromUtf8("btnOpenReservation"));
        btnOpenReservation->setMaximumSize(QSize(25, 25));
        btnOpenReservation->setFocusPolicy(Qt::ClickFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpenReservation->setIcon(icon6);

        horizontalLayout->addWidget(btnOpenReservation);

        btnGuests = new QPushButton(widget);
        btnGuests->setObjectName(QString::fromUtf8("btnGuests"));
        btnGuests->setMaximumSize(QSize(25, 25));
        btnGuests->setFocusPolicy(Qt::ClickFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/guests.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnGuests->setIcon(icon7);

        horizontalLayout->addWidget(btnGuests);

        btnMassNation = new QPushButton(widget);
        btnMassNation->setObjectName(QString::fromUtf8("btnMassNation"));
        btnMassNation->setMaximumSize(QSize(25, 25));
        btnMassNation->setFocusPolicy(Qt::ClickFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/nation.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMassNation->setIcon(icon8);

        horizontalLayout->addWidget(btnMassNation);

        btnRoomRate = new QPushButton(widget);
        btnRoomRate->setObjectName(QString::fromUtf8("btnRoomRate"));
        btnRoomRate->setMaximumSize(QSize(25, 25));
        btnRoomRate->setFocusPolicy(Qt::ClickFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/price-tag.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRoomRate->setIcon(icon9);

        horizontalLayout->addWidget(btnRoomRate);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(WQuickReservations);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tbl = new EQTableWidget(widget_2);
        if (tbl->columnCount() < 17)
            tbl->setColumnCount(17);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setFocusPolicy(Qt::ClickFocus);
        tbl->setContextMenuPolicy(Qt::CustomContextMenu);
        tbl->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tbl->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tbl->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tbl->setSelectionMode(QAbstractItemView::SingleSelection);
        tbl->setWordWrap(false);
        tbl->horizontalHeader()->setMinimumSectionSize(0);
        tbl->verticalHeader()->setMinimumSectionSize(0);

        verticalLayout_2->addWidget(tbl);

        tblTotal = new EQTableWidget(widget_2);
        if (tblTotal->rowCount() < 1)
            tblTotal->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblTotal->setVerticalHeaderItem(0, __qtablewidgetitem17);
        tblTotal->setObjectName(QString::fromUtf8("tblTotal"));
        tblTotal->setMaximumSize(QSize(16777215, 50));
        tblTotal->setFocusPolicy(Qt::ClickFocus);
        tblTotal->setStyleSheet(QString::fromUtf8("border-top: 0px;\n"
"border-left: 1px solid grey;\n"
"border-bottom: 1px solid grey;\n"
"border-right: 1px solid grey;"));
        tblTotal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblTotal->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblTotal->setSelectionMode(QAbstractItemView::NoSelection);
        tblTotal->horizontalHeader()->setVisible(false);
        tblTotal->horizontalHeader()->setMinimumSectionSize(0);
        tblTotal->verticalHeader()->setMinimumSectionSize(0);
        tblTotal->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout_2->addWidget(tblTotal);


        verticalLayout->addWidget(widget_2);


        retranslateUi(WQuickReservations);

        QMetaObject::connectSlotsByName(WQuickReservations);
    } // setupUi

    void retranslateUi(QWidget *WQuickReservations)
    {
        WQuickReservations->setWindowTitle(QCoreApplication::translate("WQuickReservations", "Form", nullptr));
        label->setText(QCoreApplication::translate("WQuickReservations", "Entry date", nullptr));
        btnDateLeft->setText(QString());
        deDate->setText(QCoreApplication::translate("WQuickReservations", "01/01/2019", nullptr));
        btnDateRight->setText(QString());
#if QT_CONFIG(tooltip)
        btnRefresh->setToolTip(QCoreApplication::translate("WQuickReservations", "Refresh", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRefresh->setText(QString());
#if QT_CONFIG(tooltip)
        btnCheckinSelected->setToolTip(QCoreApplication::translate("WQuickReservations", "Check in selected reservations", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCheckinSelected->setText(QString());
#if QT_CONFIG(tooltip)
        btnClearSelectedRooms->setToolTip(QCoreApplication::translate("WQuickReservations", "Check in selected reservations", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClearSelectedRooms->setText(QString());
#if QT_CONFIG(tooltip)
        btnTrackControl->setToolTip(QCoreApplication::translate("WQuickReservations", "View history", nullptr));
#endif // QT_CONFIG(tooltip)
        btnTrackControl->setText(QString());
#if QT_CONFIG(tooltip)
        btnOpenReservation->setToolTip(QCoreApplication::translate("WQuickReservations", "Open reservation", nullptr));
#endif // QT_CONFIG(tooltip)
        btnOpenReservation->setText(QString());
#if QT_CONFIG(tooltip)
        btnGuests->setToolTip(QCoreApplication::translate("WQuickReservations", "Edit guests", nullptr));
#endif // QT_CONFIG(tooltip)
        btnGuests->setText(QString());
#if QT_CONFIG(tooltip)
        btnMassNation->setToolTip(QCoreApplication::translate("WQuickReservations", "Edit nationality of selection", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMassNation->setText(QString());
#if QT_CONFIG(tooltip)
        btnRoomRate->setToolTip(QCoreApplication::translate("WQuickReservations", "Edit room rates of selection", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRoomRate->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WQuickReservations", "RS", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WQuickReservations", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WQuickReservations", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WQuickReservations", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WQuickReservations", "Entry", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WQuickReservations", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WQuickReservations", "Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WQuickReservations", "Pax", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tbl->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WQuickReservations", "First name", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tbl->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WQuickReservations", "Last name", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tbl->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WQuickReservations", "Passport", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tbl->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WQuickReservations", "Nat.", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tbl->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("WQuickReservations", "Cardex", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tbl->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("WQuickReservations", "Cityledger", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tbl->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("WQuickReservations", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tbl->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("WQuickReservations", "Guest code", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tbl->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("WQuickReservations", "Group", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblTotal->verticalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("WQuickReservations", "New Row", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WQuickReservations: public Ui_WQuickReservations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WQUICKRESERVATIONS_H
