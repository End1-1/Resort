/********************************************************************************
** Form generated from reading UI file 'wpaymentdetails.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WPAYMENTDETAILS_H
#define UI_WPAYMENTDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WPaymentDetails
{
public:
    QGridLayout *gridLayout;
    EQLineEdit *leCLName;
    QLabel *lbFiscalMachine;
    EQLineEdit *leCard;
    EQLineEdit *leCardName;
    EQLineEdit *leFiscalName;
    EQLineEdit *leVATName;
    QLabel *lbAmountVAT;
    EQLineEdit *leTaxReceipt;
    EQLineEdit *leVAT;
    EQLineEdit *lePaymentName;
    QLabel *label_5;
    EQLineEdit *leCL;
    QLabel *label;
    QLabel *lbVatMode;
    EQLineEdit *leFiscal;
    QLabel *lbCL;
    QLabel *label_6;
    EQLineEdit *leAmountUSD;
    EQLineEdit *lePayment;
    QLabel *label_4;
    EQLineEdit *leAmount;
    QPushButton *btnSuggestAmount;
    EQLineEdit *leVATAmount;
    QLabel *lbCard;

    void setupUi(QWidget *WPaymentDetails)
    {
        if (WPaymentDetails->objectName().isEmpty())
            WPaymentDetails->setObjectName(QString::fromUtf8("WPaymentDetails"));
        WPaymentDetails->resize(414, 260);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WPaymentDetails->sizePolicy().hasHeightForWidth());
        WPaymentDetails->setSizePolicy(sizePolicy);
        WPaymentDetails->setMinimumSize(QSize(0, 260));
        gridLayout = new QGridLayout(WPaymentDetails);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leCLName = new EQLineEdit(WPaymentDetails);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));
        leCLName->setMinimumSize(QSize(200, 0));
        leCLName->setMaximumSize(QSize(16777215, 16777215));
        leCLName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leCLName, 4, 2, 1, 2);

        lbFiscalMachine = new QLabel(WPaymentDetails);
        lbFiscalMachine->setObjectName(QString::fromUtf8("lbFiscalMachine"));

        gridLayout->addWidget(lbFiscalMachine, 0, 0, 1, 1);

        leCard = new EQLineEdit(WPaymentDetails);
        leCard->setObjectName(QString::fromUtf8("leCard"));
        leCard->setMinimumSize(QSize(100, 0));
        leCard->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leCard, 3, 1, 1, 1);

        leCardName = new EQLineEdit(WPaymentDetails);
        leCardName->setObjectName(QString::fromUtf8("leCardName"));
        leCardName->setMinimumSize(QSize(200, 0));
        leCardName->setMaximumSize(QSize(16777215, 16777215));
        leCardName->setFocusPolicy(Qt::NoFocus);
        leCardName->setReadOnly(true);

        gridLayout->addWidget(leCardName, 3, 2, 1, 2);

        leFiscalName = new EQLineEdit(WPaymentDetails);
        leFiscalName->setObjectName(QString::fromUtf8("leFiscalName"));
        leFiscalName->setMinimumSize(QSize(200, 0));
        leFiscalName->setMaximumSize(QSize(16777215, 16777215));
        leFiscalName->setFocusPolicy(Qt::NoFocus);
        leFiscalName->setReadOnly(true);

        gridLayout->addWidget(leFiscalName, 0, 2, 1, 2);

        leVATName = new EQLineEdit(WPaymentDetails);
        leVATName->setObjectName(QString::fromUtf8("leVATName"));
        leVATName->setMinimumSize(QSize(200, 0));
        leVATName->setMaximumSize(QSize(16777215, 16777215));
        leVATName->setFocusPolicy(Qt::NoFocus);
        leVATName->setReadOnly(true);

        gridLayout->addWidget(leVATName, 5, 2, 1, 2);

        lbAmountVAT = new QLabel(WPaymentDetails);
        lbAmountVAT->setObjectName(QString::fromUtf8("lbAmountVAT"));

        gridLayout->addWidget(lbAmountVAT, 7, 0, 1, 1);

        leTaxReceipt = new EQLineEdit(WPaymentDetails);
        leTaxReceipt->setObjectName(QString::fromUtf8("leTaxReceipt"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leTaxReceipt->sizePolicy().hasHeightForWidth());
        leTaxReceipt->setSizePolicy(sizePolicy1);
        leTaxReceipt->setMaximumSize(QSize(100, 16777215));
        leTaxReceipt->setFocusPolicy(Qt::NoFocus);
        leTaxReceipt->setReadOnly(true);

        gridLayout->addWidget(leTaxReceipt, 10, 1, 1, 1);

        leVAT = new EQLineEdit(WPaymentDetails);
        leVAT->setObjectName(QString::fromUtf8("leVAT"));
        leVAT->setMinimumSize(QSize(100, 0));
        leVAT->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leVAT, 5, 1, 1, 1);

        lePaymentName = new EQLineEdit(WPaymentDetails);
        lePaymentName->setObjectName(QString::fromUtf8("lePaymentName"));
        lePaymentName->setMinimumSize(QSize(200, 0));
        lePaymentName->setMaximumSize(QSize(16777215, 16777215));
        lePaymentName->setFocusPolicy(Qt::NoFocus);
        lePaymentName->setReadOnly(true);

        gridLayout->addWidget(lePaymentName, 1, 2, 1, 2);

        label_5 = new QLabel(WPaymentDetails);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 9, 0, 1, 1);

        leCL = new EQLineEdit(WPaymentDetails);
        leCL->setObjectName(QString::fromUtf8("leCL"));
        leCL->setMinimumSize(QSize(100, 0));
        leCL->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leCL, 4, 1, 1, 1);

        label = new QLabel(WPaymentDetails);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lbVatMode = new QLabel(WPaymentDetails);
        lbVatMode->setObjectName(QString::fromUtf8("lbVatMode"));

        gridLayout->addWidget(lbVatMode, 5, 0, 1, 1);

        leFiscal = new EQLineEdit(WPaymentDetails);
        leFiscal->setObjectName(QString::fromUtf8("leFiscal"));
        leFiscal->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leFiscal, 0, 1, 1, 1);

        lbCL = new QLabel(WPaymentDetails);
        lbCL->setObjectName(QString::fromUtf8("lbCL"));

        gridLayout->addWidget(lbCL, 4, 0, 1, 1);

        label_6 = new QLabel(WPaymentDetails);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 10, 0, 1, 1);

        leAmountUSD = new EQLineEdit(WPaymentDetails);
        leAmountUSD->setObjectName(QString::fromUtf8("leAmountUSD"));
        leAmountUSD->setMaximumSize(QSize(100, 16777215));
        leAmountUSD->setFocusPolicy(Qt::NoFocus);
        leAmountUSD->setReadOnly(true);

        gridLayout->addWidget(leAmountUSD, 9, 1, 1, 1);

        lePayment = new EQLineEdit(WPaymentDetails);
        lePayment->setObjectName(QString::fromUtf8("lePayment"));
        lePayment->setMinimumSize(QSize(100, 0));
        lePayment->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lePayment, 1, 1, 1, 1);

        label_4 = new QLabel(WPaymentDetails);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        leAmount = new EQLineEdit(WPaymentDetails);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMinimumSize(QSize(100, 0));
        leAmount->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(leAmount, 6, 1, 1, 1);

        btnSuggestAmount = new QPushButton(WPaymentDetails);
        btnSuggestAmount->setObjectName(QString::fromUtf8("btnSuggestAmount"));

        gridLayout->addWidget(btnSuggestAmount, 6, 2, 1, 2);

        leVATAmount = new EQLineEdit(WPaymentDetails);
        leVATAmount->setObjectName(QString::fromUtf8("leVATAmount"));
        leVATAmount->setMinimumSize(QSize(100, 0));
        leVATAmount->setMaximumSize(QSize(100, 16777215));
        leVATAmount->setFocusPolicy(Qt::NoFocus);
        leVATAmount->setReadOnly(true);

        gridLayout->addWidget(leVATAmount, 7, 1, 1, 1);

        lbCard = new QLabel(WPaymentDetails);
        lbCard->setObjectName(QString::fromUtf8("lbCard"));

        gridLayout->addWidget(lbCard, 3, 0, 1, 1);

        QWidget::setTabOrder(leFiscal, lePayment);
        QWidget::setTabOrder(lePayment, leCard);
        QWidget::setTabOrder(leCard, leCL);
        QWidget::setTabOrder(leCL, leVAT);
        QWidget::setTabOrder(leVAT, leAmount);
        QWidget::setTabOrder(leAmount, btnSuggestAmount);

        retranslateUi(WPaymentDetails);

        QMetaObject::connectSlotsByName(WPaymentDetails);
    } // setupUi

    void retranslateUi(QWidget *WPaymentDetails)
    {
        WPaymentDetails->setWindowTitle(QCoreApplication::translate("WPaymentDetails", "Form", nullptr));
        lbFiscalMachine->setText(QCoreApplication::translate("WPaymentDetails", "Fiscal", nullptr));
        lbAmountVAT->setText(QCoreApplication::translate("WPaymentDetails", "Amount VAT", nullptr));
        label_5->setText(QCoreApplication::translate("WPaymentDetails", "Amount USD", nullptr));
        label->setText(QCoreApplication::translate("WPaymentDetails", "Mode of payment", nullptr));
        lbVatMode->setText(QCoreApplication::translate("WPaymentDetails", "Mode of VAT", nullptr));
        lbCL->setText(QCoreApplication::translate("WPaymentDetails", "Cityledger", nullptr));
        label_6->setText(QCoreApplication::translate("WPaymentDetails", "Tax receipt", nullptr));
        label_4->setText(QCoreApplication::translate("WPaymentDetails", "Amount", nullptr));
        btnSuggestAmount->setText(QCoreApplication::translate("WPaymentDetails", "Suggest", nullptr));
        lbCard->setText(QCoreApplication::translate("WPaymentDetails", "Credit card", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WPaymentDetails: public Ui_WPaymentDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WPAYMENTDETAILS_H
