/********************************************************************************
** Form generated from reading UI file 'fonlinerest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FONLINEREST_H
#define UI_FONLINEREST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "eqtablewidget.h"

QT_BEGIN_NAMESPACE

class Ui_FOnlineRest
{
public:
    QVBoxLayout *verticalLayout;
    EQTableWidget *tblFilter;

    void setupUi(QWidget *FOnlineRest)
    {
        if (FOnlineRest->objectName().isEmpty())
            FOnlineRest->setObjectName(QString::fromUtf8("FOnlineRest"));
        FOnlineRest->resize(1024, 58);
        verticalLayout = new QVBoxLayout(FOnlineRest);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblFilter = new EQTableWidget(FOnlineRest);
        if (tblFilter->columnCount() < 6)
            tblFilter->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblFilter->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tblFilter->rowCount() < 1)
            tblFilter->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblFilter->setVerticalHeaderItem(0, __qtablewidgetitem6);
        tblFilter->setObjectName(QString::fromUtf8("tblFilter"));
        tblFilter->setMaximumSize(QSize(16777215, 40));
        tblFilter->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tblFilter->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblFilter->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblFilter->setSelectionMode(QAbstractItemView::SingleSelection);
        tblFilter->setSelectionBehavior(QAbstractItemView::SelectItems);
        tblFilter->horizontalHeader()->setVisible(false);
        tblFilter->horizontalHeader()->setDefaultSectionSize(200);
        tblFilter->horizontalHeader()->setHighlightSections(false);
        tblFilter->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tblFilter);


        retranslateUi(FOnlineRest);

        QMetaObject::connectSlotsByName(FOnlineRest);
    } // setupUi

    void retranslateUi(QWidget *FOnlineRest)
    {
        FOnlineRest->setWindowTitle(QCoreApplication::translate("FOnlineRest", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblFilter->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("FOnlineRest", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblFilter->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("FOnlineRest", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblFilter->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("FOnlineRest", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblFilter->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("FOnlineRest", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblFilter->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("FOnlineRest", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblFilter->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("FOnlineRest", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblFilter->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("FOnlineRest", "New Row", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FOnlineRest: public Ui_FOnlineRest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FONLINEREST_H
