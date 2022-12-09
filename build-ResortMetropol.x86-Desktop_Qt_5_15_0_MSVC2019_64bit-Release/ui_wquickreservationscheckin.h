/********************************************************************************
** Form generated from reading UI file 'wquickreservationscheckin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WQUICKRESERVATIONSCHECKIN_H
#define UI_WQUICKRESERVATIONSCHECKIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WQuickReservationsCheckin
{
public:
    QHBoxLayout *horizontalLayout;
    EQTableWidget *tbl;

    void setupUi(QDialog *WQuickReservationsCheckin)
    {
        if (WQuickReservationsCheckin->objectName().isEmpty())
            WQuickReservationsCheckin->setObjectName(QString::fromUtf8("WQuickReservationsCheckin"));
        WQuickReservationsCheckin->resize(884, 354);
        horizontalLayout = new QHBoxLayout(WQuickReservationsCheckin);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tbl = new EQTableWidget(WQuickReservationsCheckin);
        if (tbl->columnCount() < 8)
            tbl->setColumnCount(8);
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
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::NoSelection);

        horizontalLayout->addWidget(tbl);


        retranslateUi(WQuickReservationsCheckin);

        QMetaObject::connectSlotsByName(WQuickReservationsCheckin);
    } // setupUi

    void retranslateUi(QDialog *WQuickReservationsCheckin)
    {
        WQuickReservationsCheckin->setWindowTitle(QCoreApplication::translate("WQuickReservationsCheckin", "Check in progress", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WQuickReservationsCheckin", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WQuickReservationsCheckin", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WQuickReservationsCheckin", "Pax", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WQuickReservationsCheckin", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WQuickReservationsCheckin", "Entry", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WQuickReservationsCheckin", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WQuickReservationsCheckin", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WQuickReservationsCheckin", "Invoice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WQuickReservationsCheckin: public Ui_WQuickReservationsCheckin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WQUICKRESERVATIONSCHECKIN_H
