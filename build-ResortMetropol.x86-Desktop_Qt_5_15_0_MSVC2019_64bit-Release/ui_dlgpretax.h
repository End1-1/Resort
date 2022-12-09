/********************************************************************************
** Form generated from reading UI file 'dlgpretax.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRETAX_H
#define UI_DLGPRETAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgPreTax
{
public:
    QVBoxLayout *verticalLayout;
    EQTableWidget *tblData;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    EQLineEdit *leTotal;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgPreTax)
    {
        if (DlgPreTax->objectName().isEmpty())
            DlgPreTax->setObjectName(QString::fromUtf8("DlgPreTax"));
        DlgPreTax->resize(513, 370);
        verticalLayout = new QVBoxLayout(DlgPreTax);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblData = new EQTableWidget(DlgPreTax);
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

        verticalLayout->addWidget(tblData);

        widget_2 = new QWidget(DlgPreTax);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        leTotal = new EQLineEdit(widget_2);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));
        leTotal->setReadOnly(true);

        horizontalLayout_2->addWidget(leTotal);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(DlgPreTax);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(152, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(151, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgPreTax);

        QMetaObject::connectSlotsByName(DlgPreTax);
    } // setupUi

    void retranslateUi(QDialog *DlgPreTax)
    {
        DlgPreTax->setWindowTitle(QCoreApplication::translate("DlgPreTax", "Tax Prepaid", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgPreTax", "Rec", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgPreTax", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgPreTax", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgPreTax", "Print", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgPreTax", "Mode", nullptr));
        label_2->setText(QCoreApplication::translate("DlgPreTax", "Mode", nullptr));
        label->setText(QCoreApplication::translate("DlgPreTax", "Total", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgPreTax", "Print", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgPreTax", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPreTax: public Ui_DlgPreTax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRETAX_H
