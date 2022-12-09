/********************************************************************************
** Form generated from reading UI file 'dlgtracking.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTRACKING_H
#define UI_DLGTRACKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgTracking
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *chOld;
    QTableWidget *tblData;

    void setupUi(QDialog *DlgTracking)
    {
        if (DlgTracking->objectName().isEmpty())
            DlgTracking->setObjectName(QString::fromUtf8("DlgTracking"));
        DlgTracking->resize(1135, 605);
        verticalLayout = new QVBoxLayout(DlgTracking);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chOld = new QCheckBox(DlgTracking);
        chOld->setObjectName(QString::fromUtf8("chOld"));

        verticalLayout->addWidget(chOld);

        tblData = new QTableWidget(DlgTracking);
        if (tblData->columnCount() < 7)
            tblData->setColumnCount(7);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);
        tblData->verticalHeader()->setDefaultSectionSize(25);

        verticalLayout->addWidget(tblData);


        retranslateUi(DlgTracking);

        QMetaObject::connectSlotsByName(DlgTracking);
    } // setupUi

    void retranslateUi(QDialog *DlgTracking)
    {
        DlgTracking->setWindowTitle(QCoreApplication::translate("DlgTracking", "Tracking for", nullptr));
        chOld->setText(QCoreApplication::translate("DlgTracking", "Old version", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgTracking", "Computer", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgTracking", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgTracking", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgTracking", "User", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgTracking", "Action", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgTracking", "Old value", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblData->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgTracking", "New value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgTracking: public Ui_DlgTracking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTRACKING_H
