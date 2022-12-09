/********************************************************************************
** Form generated from reading UI file 'whotelstatus.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHOTELSTATUS_H
#define UI_WHOTELSTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WHotelStatus
{
public:
    QVBoxLayout *verticalLayout;
    EQTableWidget *tblMain;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    EQTableWidget *tblCategory;
    EQTableWidget *tableWidget_3;
    EQTableWidget *tblRoomStatus;
    EQTableWidget *tblNationality;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *lbAlreadyAriived;
    QLabel *lbArrivals;
    EQTableWidget *tblGuestInHouse;
    QLabel *lbAlreadyCheckout;
    EQTableWidget *tblAlreadyArrived;
    EQTableWidget *tblAlreadyCheckout;
    QLabel *lbGuestInHouse;
    EQTableWidget *tblArrivals;
    QLabel *lbDepartures;
    EQTableWidget *tblDepartures;

    void setupUi(QWidget *WHotelStatus)
    {
        if (WHotelStatus->objectName().isEmpty())
            WHotelStatus->setObjectName(QString::fromUtf8("WHotelStatus"));
        WHotelStatus->resize(1244, 609);
        verticalLayout = new QVBoxLayout(WHotelStatus);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblMain = new EQTableWidget(WHotelStatus);
        if (tblMain->columnCount() < 12)
            tblMain->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblMain->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        tblMain->setObjectName(QString::fromUtf8("tblMain"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(tblMain->sizePolicy().hasHeightForWidth());
        tblMain->setSizePolicy(sizePolicy);
        tblMain->setMinimumSize(QSize(0, 0));
        tblMain->setMaximumSize(QSize(16777215, 180));
        tblMain->setStyleSheet(QString::fromUtf8(""));
        tblMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblMain->setSelectionMode(QAbstractItemView::NoSelection);
        tblMain->setWordWrap(false);
        tblMain->horizontalHeader()->setVisible(false);
        tblMain->horizontalHeader()->setHighlightSections(false);
        tblMain->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tblMain->verticalHeader()->setVisible(false);
        tblMain->verticalHeader()->setDefaultSectionSize(21);

        verticalLayout->addWidget(tblMain);

        widget = new QWidget(WHotelStatus);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("x"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        tblCategory = new EQTableWidget(widget_2);
        if (tblCategory->columnCount() < 4)
            tblCategory->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblCategory->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        tblCategory->setObjectName(QString::fromUtf8("tblCategory"));
        tblCategory->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblCategory->setSelectionMode(QAbstractItemView::NoSelection);
        tblCategory->setWordWrap(false);
        tblCategory->horizontalHeader()->setVisible(false);
        tblCategory->verticalHeader()->setVisible(false);
        tblCategory->verticalHeader()->setDefaultSectionSize(21);

        gridLayout->addWidget(tblCategory, 1, 0, 1, 1);

        tableWidget_3 = new EQTableWidget(widget_2);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_3->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_3->setWordWrap(false);
        tableWidget_3->horizontalHeader()->setVisible(false);
        tableWidget_3->verticalHeader()->setVisible(false);
        tableWidget_3->verticalHeader()->setDefaultSectionSize(21);

        gridLayout->addWidget(tableWidget_3, 1, 1, 1, 1);

        tblRoomStatus = new EQTableWidget(widget_2);
        if (tblRoomStatus->columnCount() < 2)
            tblRoomStatus->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblRoomStatus->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblRoomStatus->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        tblRoomStatus->setObjectName(QString::fromUtf8("tblRoomStatus"));
        tblRoomStatus->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblRoomStatus->setSelectionMode(QAbstractItemView::NoSelection);
        tblRoomStatus->setWordWrap(false);
        tblRoomStatus->horizontalHeader()->setVisible(false);
        tblRoomStatus->verticalHeader()->setVisible(false);
        tblRoomStatus->verticalHeader()->setDefaultSectionSize(21);

        gridLayout->addWidget(tblRoomStatus, 1, 2, 1, 1);

        tblNationality = new EQTableWidget(widget_2);
        if (tblNationality->columnCount() < 4)
            tblNationality->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblNationality->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tblNationality->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tblNationality->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tblNationality->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        tblNationality->setObjectName(QString::fromUtf8("tblNationality"));
        tblNationality->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblNationality->setSelectionMode(QAbstractItemView::NoSelection);
        tblNationality->setWordWrap(false);
        tblNationality->horizontalHeader()->setVisible(false);
        tblNationality->verticalHeader()->setVisible(false);
        tblNationality->verticalHeader()->setDefaultSectionSize(21);

        gridLayout->addWidget(tblNationality, 1, 3, 1, 1);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lbAlreadyAriived = new QLabel(widget_3);
        lbAlreadyAriived->setObjectName(QString::fromUtf8("lbAlreadyAriived"));
        lbAlreadyAriived->setFont(font);
        lbAlreadyAriived->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lbAlreadyAriived, 0, 2, 1, 1);

        lbArrivals = new QLabel(widget_3);
        lbArrivals->setObjectName(QString::fromUtf8("lbArrivals"));
        lbArrivals->setFont(font);
        lbArrivals->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lbArrivals, 0, 0, 1, 1);

        tblGuestInHouse = new EQTableWidget(widget_3);
        tblGuestInHouse->setObjectName(QString::fromUtf8("tblGuestInHouse"));
        tblGuestInHouse->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblGuestInHouse->setSelectionMode(QAbstractItemView::NoSelection);
        tblGuestInHouse->setWordWrap(false);
        tblGuestInHouse->horizontalHeader()->setVisible(false);
        tblGuestInHouse->verticalHeader()->setVisible(false);
        tblGuestInHouse->verticalHeader()->setDefaultSectionSize(21);

        gridLayout_3->addWidget(tblGuestInHouse, 1, 1, 4, 1);

        lbAlreadyCheckout = new QLabel(widget_3);
        lbAlreadyCheckout->setObjectName(QString::fromUtf8("lbAlreadyCheckout"));
        lbAlreadyCheckout->setFont(font);
        lbAlreadyCheckout->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lbAlreadyCheckout, 2, 2, 1, 1);

        tblAlreadyArrived = new EQTableWidget(widget_3);
        tblAlreadyArrived->setObjectName(QString::fromUtf8("tblAlreadyArrived"));
        tblAlreadyArrived->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblAlreadyArrived->setSelectionMode(QAbstractItemView::NoSelection);
        tblAlreadyArrived->setWordWrap(false);
        tblAlreadyArrived->horizontalHeader()->setVisible(false);
        tblAlreadyArrived->verticalHeader()->setVisible(false);
        tblAlreadyArrived->verticalHeader()->setDefaultSectionSize(21);

        gridLayout_3->addWidget(tblAlreadyArrived, 1, 2, 1, 1);

        tblAlreadyCheckout = new EQTableWidget(widget_3);
        tblAlreadyCheckout->setObjectName(QString::fromUtf8("tblAlreadyCheckout"));
        tblAlreadyCheckout->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblAlreadyCheckout->setSelectionMode(QAbstractItemView::NoSelection);
        tblAlreadyCheckout->setWordWrap(false);
        tblAlreadyCheckout->horizontalHeader()->setVisible(false);
        tblAlreadyCheckout->verticalHeader()->setVisible(false);
        tblAlreadyCheckout->verticalHeader()->setDefaultSectionSize(21);

        gridLayout_3->addWidget(tblAlreadyCheckout, 3, 2, 2, 1);

        lbGuestInHouse = new QLabel(widget_3);
        lbGuestInHouse->setObjectName(QString::fromUtf8("lbGuestInHouse"));
        lbGuestInHouse->setFont(font);
        lbGuestInHouse->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lbGuestInHouse, 0, 1, 1, 1);

        tblArrivals = new EQTableWidget(widget_3);
        tblArrivals->setObjectName(QString::fromUtf8("tblArrivals"));
        tblArrivals->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblArrivals->setSelectionMode(QAbstractItemView::NoSelection);
        tblArrivals->setWordWrap(false);
        tblArrivals->horizontalHeader()->setVisible(false);
        tblArrivals->verticalHeader()->setVisible(false);
        tblArrivals->verticalHeader()->setDefaultSectionSize(21);

        gridLayout_3->addWidget(tblArrivals, 1, 0, 1, 1);

        lbDepartures = new QLabel(widget_3);
        lbDepartures->setObjectName(QString::fromUtf8("lbDepartures"));
        lbDepartures->setFont(font);
        lbDepartures->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(lbDepartures, 2, 0, 1, 1);

        tblDepartures = new EQTableWidget(widget_3);
        tblDepartures->setObjectName(QString::fromUtf8("tblDepartures"));
        tblDepartures->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblDepartures->setSelectionMode(QAbstractItemView::NoSelection);
        tblDepartures->setWordWrap(false);
        tblDepartures->horizontalHeader()->setVisible(false);
        tblDepartures->verticalHeader()->setVisible(false);
        tblDepartures->verticalHeader()->setDefaultSectionSize(21);

        gridLayout_3->addWidget(tblDepartures, 3, 0, 2, 1);


        verticalLayout_2->addWidget(widget_3);


        verticalLayout->addWidget(widget);


        retranslateUi(WHotelStatus);

        QMetaObject::connectSlotsByName(WHotelStatus);
    } // setupUi

    void retranslateUi(QWidget *WHotelStatus)
    {
        WHotelStatus->setWindowTitle(QCoreApplication::translate("WHotelStatus", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblMain->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblMain->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblMain->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblMain->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblMain->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblMain->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblMain->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblMain->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblMain->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblMain->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblMain->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblMain->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WHotelStatus", "New Column", nullptr));
        label->setText(QCoreApplication::translate("WHotelStatus", "Category", nullptr));
        label_2->setText(QCoreApplication::translate("WHotelStatus", "Market sigment", nullptr));
        label_3->setText(QCoreApplication::translate("WHotelStatus", "Room status", nullptr));
        label_4->setText(QCoreApplication::translate("WHotelStatus", "Nationality", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblCategory->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("WHotelStatus", "Cat", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblCategory->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("WHotelStatus", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblCategory->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("WHotelStatus", "Nbr", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblCategory->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("WHotelStatus", "Occ", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblRoomStatus->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("WHotelStatus", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblRoomStatus->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("WHotelStatus", "qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblNationality->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("WHotelStatus", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tblNationality->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("WHotelStatus", "Nationality", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tblNationality->horizontalHeaderItem(2);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("WHotelStatus", "Nbr", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tblNationality->horizontalHeaderItem(3);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("WHotelStatus", "Pax", nullptr));
        lbAlreadyAriived->setText(QCoreApplication::translate("WHotelStatus", "Already Arrived", nullptr));
        lbArrivals->setText(QCoreApplication::translate("WHotelStatus", " Arrivals Today", nullptr));
        lbAlreadyCheckout->setText(QCoreApplication::translate("WHotelStatus", "Already checkout", nullptr));
        lbGuestInHouse->setText(QCoreApplication::translate("WHotelStatus", "Guest in house", nullptr));
        lbDepartures->setText(QCoreApplication::translate("WHotelStatus", "Departures Today", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WHotelStatus: public Ui_WHotelStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHOTELSTATUS_H
