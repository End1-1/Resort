/********************************************************************************
** Form generated from reading UI file 'dlgmovetocl.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGMOVETOCL_H
#define UI_DLGMOVETOCL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgMoveToCL
{
public:
    QGridLayout *gridLayout;
    EQLineEdit *leVoucher;
    EQLineEdit *leCurrPaymentName;
    EQLineEdit *leAmount;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_2;
    EQLineEdit *leDCL;
    EQLineEdit *leCurrPayment;
    EQTableWidget *tblPay;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnChange;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    EQLineEdit *leDCLName;
    EQLineEdit *leFinaleName;
    QLabel *label_7;
    EQLineEdit *leCurrCL;
    EQLineEdit *leCurrCLName;
    EQLineEdit *leInvoice;

    void setupUi(QDialog *DlgMoveToCL)
    {
        if (DlgMoveToCL->objectName().isEmpty())
            DlgMoveToCL->setObjectName(QString::fromUtf8("DlgMoveToCL"));
        DlgMoveToCL->resize(770, 400);
        gridLayout = new QGridLayout(DlgMoveToCL);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leVoucher = new EQLineEdit(DlgMoveToCL);
        leVoucher->setObjectName(QString::fromUtf8("leVoucher"));
        leVoucher->setMaximumSize(QSize(100, 16777215));
        leVoucher->setReadOnly(true);

        gridLayout->addWidget(leVoucher, 1, 1, 1, 1);

        leCurrPaymentName = new EQLineEdit(DlgMoveToCL);
        leCurrPaymentName->setObjectName(QString::fromUtf8("leCurrPaymentName"));
        leCurrPaymentName->setFocusPolicy(Qt::NoFocus);
        leCurrPaymentName->setReadOnly(true);

        gridLayout->addWidget(leCurrPaymentName, 4, 2, 1, 1);

        leAmount = new EQLineEdit(DlgMoveToCL);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(100, 16777215));
        leAmount->setReadOnly(true);

        gridLayout->addWidget(leAmount, 3, 1, 1, 1);

        label = new QLabel(DlgMoveToCL);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(DlgMoveToCL);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(DlgMoveToCL);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_6 = new QLabel(DlgMoveToCL);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_2 = new QLabel(DlgMoveToCL);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leDCL = new EQLineEdit(DlgMoveToCL);
        leDCL->setObjectName(QString::fromUtf8("leDCL"));
        leDCL->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leDCL, 0, 1, 1, 1);

        leCurrPayment = new EQLineEdit(DlgMoveToCL);
        leCurrPayment->setObjectName(QString::fromUtf8("leCurrPayment"));
        leCurrPayment->setMaximumSize(QSize(100, 16777215));
        leCurrPayment->setReadOnly(true);

        gridLayout->addWidget(leCurrPayment, 4, 1, 1, 1);

        tblPay = new EQTableWidget(DlgMoveToCL);
        if (tblPay->columnCount() < 4)
            tblPay->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblPay->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblPay->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblPay->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblPay->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblPay->setObjectName(QString::fromUtf8("tblPay"));
        tblPay->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblPay->setSelectionMode(QAbstractItemView::SingleSelection);
        tblPay->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(tblPay, 7, 0, 1, 3);

        label_4 = new QLabel(DlgMoveToCL);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        widget = new QWidget(DlgMoveToCL);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(280, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnChange = new QPushButton(widget);
        btnChange->setObjectName(QString::fromUtf8("btnChange"));

        horizontalLayout->addWidget(btnChange);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(280, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(widget, 8, 0, 1, 3);

        leDCLName = new EQLineEdit(DlgMoveToCL);
        leDCLName->setObjectName(QString::fromUtf8("leDCLName"));
        leDCLName->setFocusPolicy(Qt::NoFocus);
        leDCLName->setReadOnly(true);

        gridLayout->addWidget(leDCLName, 0, 2, 1, 1);

        leFinaleName = new EQLineEdit(DlgMoveToCL);
        leFinaleName->setObjectName(QString::fromUtf8("leFinaleName"));
        leFinaleName->setReadOnly(true);

        gridLayout->addWidget(leFinaleName, 2, 1, 1, 2);

        label_7 = new QLabel(DlgMoveToCL);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        leCurrCL = new EQLineEdit(DlgMoveToCL);
        leCurrCL->setObjectName(QString::fromUtf8("leCurrCL"));
        leCurrCL->setMaximumSize(QSize(100, 16777215));
        leCurrCL->setReadOnly(true);

        gridLayout->addWidget(leCurrCL, 5, 1, 1, 1);

        leCurrCLName = new EQLineEdit(DlgMoveToCL);
        leCurrCLName->setObjectName(QString::fromUtf8("leCurrCLName"));
        leCurrCLName->setFocusPolicy(Qt::NoFocus);
        leCurrCLName->setReadOnly(true);

        gridLayout->addWidget(leCurrCLName, 5, 2, 1, 1);

        leInvoice = new EQLineEdit(DlgMoveToCL);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(100, 16777215));
        leInvoice->setReadOnly(true);

        gridLayout->addWidget(leInvoice, 1, 2, 1, 1);

        QWidget::setTabOrder(leDCL, leVoucher);
        QWidget::setTabOrder(leVoucher, leFinaleName);
        QWidget::setTabOrder(leFinaleName, leAmount);
        QWidget::setTabOrder(leAmount, leCurrPayment);
        QWidget::setTabOrder(leCurrPayment, leCurrCL);
        QWidget::setTabOrder(leCurrCL, tblPay);
        QWidget::setTabOrder(tblPay, btnChange);
        QWidget::setTabOrder(btnChange, btnCancel);
        QWidget::setTabOrder(btnCancel, leCurrCLName);
        QWidget::setTabOrder(leCurrCLName, leDCLName);
        QWidget::setTabOrder(leDCLName, leCurrPaymentName);

        retranslateUi(DlgMoveToCL);

        QMetaObject::connectSlotsByName(DlgMoveToCL);
    } // setupUi

    void retranslateUi(QDialog *DlgMoveToCL)
    {
        DlgMoveToCL->setWindowTitle(QCoreApplication::translate("DlgMoveToCL", "Change CL", nullptr));
        label->setText(QCoreApplication::translate("DlgMoveToCL", "Destination CL", nullptr));
        label_3->setText(QCoreApplication::translate("DlgMoveToCL", "Voucher", nullptr));
        label_5->setText(QCoreApplication::translate("DlgMoveToCL", "Used payments", nullptr));
        label_6->setText(QCoreApplication::translate("DlgMoveToCL", "Amount", nullptr));
        label_2->setText(QCoreApplication::translate("DlgMoveToCL", "Item name", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblPay->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgMoveToCL", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblPay->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgMoveToCL", "Final name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblPay->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgMoveToCL", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblPay->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgMoveToCL", "CL", nullptr));
        label_4->setText(QCoreApplication::translate("DlgMoveToCL", "Current payment", nullptr));
        btnChange->setText(QCoreApplication::translate("DlgMoveToCL", "Change", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgMoveToCL", "Cancel", nullptr));
        label_7->setText(QCoreApplication::translate("DlgMoveToCL", "Current CL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgMoveToCL: public Ui_DlgMoveToCL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGMOVETOCL_H
