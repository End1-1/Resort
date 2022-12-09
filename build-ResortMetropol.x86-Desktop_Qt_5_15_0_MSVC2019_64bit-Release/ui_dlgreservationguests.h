/********************************************************************************
** Form generated from reading UI file 'dlgreservationguests.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRESERVATIONGUESTS_H
#define UI_DLGRESERVATIONGUESTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgReservationGuests
{
public:
    QHBoxLayout *horizontalLayout;
    EQTableWidget *tblData;

    void setupUi(QDialog *DlgReservationGuests)
    {
        if (DlgReservationGuests->objectName().isEmpty())
            DlgReservationGuests->setObjectName(QString::fromUtf8("DlgReservationGuests"));
        DlgReservationGuests->resize(855, 373);
        horizontalLayout = new QHBoxLayout(DlgReservationGuests);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tblData = new EQTableWidget(DlgReservationGuests);
        if (tblData->columnCount() < 5)
            tblData->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);

        horizontalLayout->addWidget(tblData);


        retranslateUi(DlgReservationGuests);

        QMetaObject::connectSlotsByName(DlgReservationGuests);
    } // setupUi

    void retranslateUi(QDialog *DlgReservationGuests)
    {
        DlgReservationGuests->setWindowTitle(QCoreApplication::translate("DlgReservationGuests", "Guests", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgReservationGuests", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgReservationGuests", "First name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgReservationGuests", "Last name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgReservationGuests", "Nation", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgReservationGuests", "Passport", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgReservationGuests: public Ui_DlgReservationGuests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRESERVATIONGUESTS_H
