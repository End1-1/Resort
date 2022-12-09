/********************************************************************************
** Form generated from reading UI file 'dlgdishhistory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGDISHHISTORY_H
#define UI_DLGDISHHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgDishHistory
{
public:
    QVBoxLayout *verticalLayout;
    EQTableWidget *tblData;

    void setupUi(QDialog *DlgDishHistory)
    {
        if (DlgDishHistory->objectName().isEmpty())
            DlgDishHistory->setObjectName(QString::fromUtf8("DlgDishHistory"));
        DlgDishHistory->resize(704, 567);
        verticalLayout = new QVBoxLayout(DlgDishHistory);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblData = new EQTableWidget(DlgDishHistory);
        if (tblData->columnCount() < 3)
            tblData->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(tblData);


        retranslateUi(DlgDishHistory);

        QMetaObject::connectSlotsByName(DlgDishHistory);
    } // setupUi

    void retranslateUi(QDialog *DlgDishHistory)
    {
        DlgDishHistory->setWindowTitle(QCoreApplication::translate("DlgDishHistory", "Dish history", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgDishHistory", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgDishHistory", "Staff", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgDishHistory", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgDishHistory: public Ui_DlgDishHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGDISHHISTORY_H
