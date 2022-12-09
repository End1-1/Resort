/********************************************************************************
** Form generated from reading UI file 'dlgtaxback.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTAXBACK_H
#define UI_DLGTAXBACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgTaxBack
{
public:
    QVBoxLayout *verticalLayout;
    EQTableWidget *tblData;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgTaxBack)
    {
        if (DlgTaxBack->objectName().isEmpty())
            DlgTaxBack->setObjectName(QString::fromUtf8("DlgTaxBack"));
        DlgTaxBack->resize(629, 690);
        verticalLayout = new QVBoxLayout(DlgTaxBack);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblData = new EQTableWidget(DlgTaxBack);
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

        verticalLayout->addWidget(tblData);

        widget = new QWidget(DlgTaxBack);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(210, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(209, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgTaxBack);

        QMetaObject::connectSlotsByName(DlgTaxBack);
    } // setupUi

    void retranslateUi(QDialog *DlgTaxBack)
    {
        DlgTaxBack->setWindowTitle(QCoreApplication::translate("DlgTaxBack", "Tax back", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgTaxBack", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgTaxBack", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgTaxBack", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgTaxBack", "Source", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgTaxBack", "Sel", nullptr));
        btnOK->setText(QCoreApplication::translate("DlgTaxBack", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgTaxBack", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgTaxBack: public Ui_DlgTaxBack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTAXBACK_H
