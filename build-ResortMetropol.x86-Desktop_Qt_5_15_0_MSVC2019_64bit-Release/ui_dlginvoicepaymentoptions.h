/********************************************************************************
** Form generated from reading UI file 'dlginvoicepaymentoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGINVOICEPAYMENTOPTIONS_H
#define UI_DLGINVOICEPAYMENTOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgInvoicePaymentOptions
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *chCloseAfterSaveCheckout;
    QCheckBox *chDoNotPrintVoucher;
    QCheckBox *chAutoPrintInvoice;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *bntSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgInvoicePaymentOptions)
    {
        if (DlgInvoicePaymentOptions->objectName().isEmpty())
            DlgInvoicePaymentOptions->setObjectName(QString::fromUtf8("DlgInvoicePaymentOptions"));
        DlgInvoicePaymentOptions->resize(400, 128);
        verticalLayout = new QVBoxLayout(DlgInvoicePaymentOptions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        chCloseAfterSaveCheckout = new QCheckBox(DlgInvoicePaymentOptions);
        chCloseAfterSaveCheckout->setObjectName(QString::fromUtf8("chCloseAfterSaveCheckout"));

        verticalLayout->addWidget(chCloseAfterSaveCheckout);

        chDoNotPrintVoucher = new QCheckBox(DlgInvoicePaymentOptions);
        chDoNotPrintVoucher->setObjectName(QString::fromUtf8("chDoNotPrintVoucher"));

        verticalLayout->addWidget(chDoNotPrintVoucher);

        chAutoPrintInvoice = new QCheckBox(DlgInvoicePaymentOptions);
        chAutoPrintInvoice->setObjectName(QString::fromUtf8("chAutoPrintInvoice"));

        verticalLayout->addWidget(chAutoPrintInvoice);

        widget = new QWidget(DlgInvoicePaymentOptions);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bntSave = new QPushButton(widget);
        bntSave->setObjectName(QString::fromUtf8("bntSave"));

        horizontalLayout->addWidget(bntSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgInvoicePaymentOptions);

        QMetaObject::connectSlotsByName(DlgInvoicePaymentOptions);
    } // setupUi

    void retranslateUi(QDialog *DlgInvoicePaymentOptions)
    {
        DlgInvoicePaymentOptions->setWindowTitle(QCoreApplication::translate("DlgInvoicePaymentOptions", "Payment dialog options", nullptr));
        chCloseAfterSaveCheckout->setText(QCoreApplication::translate("DlgInvoicePaymentOptions", "Close after save if balance zero (checkout)", nullptr));
        chDoNotPrintVoucher->setText(QCoreApplication::translate("DlgInvoicePaymentOptions", "Do not print receipt voucher", nullptr));
        chAutoPrintInvoice->setText(QCoreApplication::translate("DlgInvoicePaymentOptions", "Print invoice immediately", nullptr));
        bntSave->setText(QCoreApplication::translate("DlgInvoicePaymentOptions", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgInvoicePaymentOptions", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgInvoicePaymentOptions: public Ui_DlgInvoicePaymentOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGINVOICEPAYMENTOPTIONS_H
