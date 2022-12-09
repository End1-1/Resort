/********************************************************************************
** Form generated from reading UI file 'wquickcheckoutprocess.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WQUICKCHECKOUTPROCESS_H
#define UI_WQUICKCHECKOUTPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WQuickCheckoutProcess
{
public:
    QVBoxLayout *verticalLayout;
    EQTableWidget *tbl;

    void setupUi(QDialog *WQuickCheckoutProcess)
    {
        if (WQuickCheckoutProcess->objectName().isEmpty())
            WQuickCheckoutProcess->setObjectName(QString::fromUtf8("WQuickCheckoutProcess"));
        WQuickCheckoutProcess->resize(986, 547);
        verticalLayout = new QVBoxLayout(WQuickCheckoutProcess);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tbl = new EQTableWidget(WQuickCheckoutProcess);
        if (tbl->columnCount() < 7)
            tbl->setColumnCount(7);
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
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::SingleSelection);
        tbl->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbl->setWordWrap(false);

        verticalLayout->addWidget(tbl);


        retranslateUi(WQuickCheckoutProcess);

        QMetaObject::connectSlotsByName(WQuickCheckoutProcess);
    } // setupUi

    void retranslateUi(QDialog *WQuickCheckoutProcess)
    {
        WQuickCheckoutProcess->setWindowTitle(QCoreApplication::translate("WQuickCheckoutProcess", "Checkout", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WQuickCheckoutProcess", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WQuickCheckoutProcess", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WQuickCheckoutProcess", "Reservation", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WQuickCheckoutProcess", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WQuickCheckoutProcess", "Balance", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WQuickCheckoutProcess", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WQuickCheckoutProcess", "Departure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WQuickCheckoutProcess: public Ui_WQuickCheckoutProcess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WQUICKCHECKOUTPROCESS_H
