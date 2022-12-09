/********************************************************************************
** Form generated from reading UI file 'dlgpostcharge.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPOSTCHARGE_H
#define UI_DLGPOSTCHARGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <wcityledger.h>
#include <wguestinvoice.h>

QT_BEGIN_NAMESPACE

class Ui_DlgPostCharge
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_9;
    EQLineEdit *leVoucher;
    QLabel *label_2;
    EDateEdit *deDate;
    QPlainTextEdit *teRemarks;
    QTabWidget *tabWidget;
    QWidget *tabInvoice;
    QVBoxLayout *verticalLayout;
    WGuestInvoice *wRoom;
    QWidget *tabDirect;
    QWidget *tabCity;
    QGridLayout *gridLayout_3;
    WCityLedger *wCL;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNew;
    QPushButton *btnSave;
    QPushButton *btnPrint;
    QPushButton *btnPrintTax;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *grSale;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    EQLineEdit *leVATName;
    EQLineEdit *lePayment;
    EQLineEdit *leFinalName;
    EQLineEdit *leItemName;
    EQLineEdit *leItem;
    EQLineEdit *leCard;
    EQLineEdit *leAmount;
    EQLineEdit *leCardName;
    QLabel *label_6;
    QLabel *lbCard;
    EQLineEdit *leVAT;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_5;
    EQLineEdit *lePaymentName;
    EQLineEdit *leAmountUSD;
    EQLineEdit *leFiscal;
    QLabel *lbPayment;
    QRadioButton *rbGuest;
    QRadioButton *rbCompany;

    void setupUi(QDialog *DlgPostCharge)
    {
        if (DlgPostCharge->objectName().isEmpty())
            DlgPostCharge->setObjectName(QString::fromUtf8("DlgPostCharge"));
        DlgPostCharge->resize(447, 481);
        gridLayout_4 = new QGridLayout(DlgPostCharge);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(DlgPostCharge);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setFocusPolicy(Qt::ClickFocus);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 0, 2, 1, 1);

        leVoucher = new EQLineEdit(groupBox);
        leVoucher->setObjectName(QString::fromUtf8("leVoucher"));
        leVoucher->setMaximumSize(QSize(80, 16777215));
        leVoucher->setFocusPolicy(Qt::ClickFocus);
        leVoucher->setReadOnly(true);

        gridLayout_2->addWidget(leVoucher, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFocusPolicy(Qt::ClickFocus);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        deDate = new EDateEdit(groupBox);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setReadOnly(true);

        gridLayout_2->addWidget(deDate, 0, 3, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        teRemarks = new QPlainTextEdit(DlgPostCharge);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));
        teRemarks->setMaximumSize(QSize(16777215, 70));
        teRemarks->setFocusPolicy(Qt::ClickFocus);

        gridLayout_4->addWidget(teRemarks, 5, 0, 1, 1);

        tabWidget = new QTabWidget(DlgPostCharge);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setFocusPolicy(Qt::ClickFocus);
        tabInvoice = new QWidget();
        tabInvoice->setObjectName(QString::fromUtf8("tabInvoice"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabInvoice->sizePolicy().hasHeightForWidth());
        tabInvoice->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(tabInvoice);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wRoom = new WGuestInvoice(tabInvoice);
        wRoom->setObjectName(QString::fromUtf8("wRoom"));
        sizePolicy.setHeightForWidth(wRoom->sizePolicy().hasHeightForWidth());
        wRoom->setSizePolicy(sizePolicy);
        wRoom->setFocusPolicy(Qt::StrongFocus);

        verticalLayout->addWidget(wRoom);

        tabWidget->addTab(tabInvoice, QString());
        tabDirect = new QWidget();
        tabDirect->setObjectName(QString::fromUtf8("tabDirect"));
        tabWidget->addTab(tabDirect, QString());
        tabCity = new QWidget();
        tabCity->setObjectName(QString::fromUtf8("tabCity"));
        gridLayout_3 = new QGridLayout(tabCity);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        wCL = new WCityLedger(tabCity);
        wCL->setObjectName(QString::fromUtf8("wCL"));

        gridLayout_3->addWidget(wCL, 0, 0, 1, 1);

        tabWidget->addTab(tabCity, QString());

        gridLayout_4->addWidget(tabWidget, 1, 0, 1, 1);

        widget = new QWidget(DlgPostCharge);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setFocusPolicy(Qt::ClickFocus);
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnNew = new QPushButton(widget);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        btnNew->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(btnNew);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(btnSave);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setEnabled(false);
        btnPrint->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(btnPrint);

        btnPrintTax = new QPushButton(widget);
        btnPrintTax->setObjectName(QString::fromUtf8("btnPrintTax"));
        btnPrintTax->setEnabled(false);
        btnPrintTax->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(btnPrintTax);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout_3->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(22, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout_4->addWidget(widget, 6, 0, 1, 1);

        grSale = new QGroupBox(DlgPostCharge);
        grSale->setObjectName(QString::fromUtf8("grSale"));
        grSale->setFocusPolicy(Qt::ClickFocus);
        gridLayout = new QGridLayout(grSale);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(grSale);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        label = new QLabel(grSale);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leVATName = new EQLineEdit(grSale);
        leVATName->setObjectName(QString::fromUtf8("leVATName"));
        leVATName->setFocusPolicy(Qt::ClickFocus);
        leVATName->setReadOnly(true);

        gridLayout->addWidget(leVATName, 4, 2, 1, 2);

        lePayment = new EQLineEdit(grSale);
        lePayment->setObjectName(QString::fromUtf8("lePayment"));
        lePayment->setMaximumSize(QSize(80, 16777215));
        lePayment->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(lePayment, 2, 1, 1, 1);

        leFinalName = new EQLineEdit(grSale);
        leFinalName->setObjectName(QString::fromUtf8("leFinalName"));
        leFinalName->setReadOnly(true);

        gridLayout->addWidget(leFinalName, 1, 1, 1, 3);

        leItemName = new EQLineEdit(grSale);
        leItemName->setObjectName(QString::fromUtf8("leItemName"));
        leItemName->setFocusPolicy(Qt::ClickFocus);
        leItemName->setReadOnly(true);

        gridLayout->addWidget(leItemName, 0, 2, 1, 2);

        leItem = new EQLineEdit(grSale);
        leItem->setObjectName(QString::fromUtf8("leItem"));
        leItem->setMaximumSize(QSize(80, 16777215));
        leItem->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(leItem, 0, 1, 1, 1);

        leCard = new EQLineEdit(grSale);
        leCard->setObjectName(QString::fromUtf8("leCard"));
        leCard->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCard, 3, 1, 1, 1);

        leAmount = new EQLineEdit(grSale);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(80, 16777215));
        leAmount->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(leAmount, 5, 1, 1, 1);

        leCardName = new EQLineEdit(grSale);
        leCardName->setObjectName(QString::fromUtf8("leCardName"));
        leCardName->setFocusPolicy(Qt::NoFocus);
        leCardName->setReadOnly(true);

        gridLayout->addWidget(leCardName, 3, 2, 1, 2);

        label_6 = new QLabel(grSale);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        lbCard = new QLabel(grSale);
        lbCard->setObjectName(QString::fromUtf8("lbCard"));

        gridLayout->addWidget(lbCard, 3, 0, 1, 1);

        leVAT = new EQLineEdit(grSale);
        leVAT->setObjectName(QString::fromUtf8("leVAT"));
        leVAT->setMaximumSize(QSize(80, 16777215));
        leVAT->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(leVAT, 4, 1, 1, 1);

        label_4 = new QLabel(grSale);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        label_8 = new QLabel(grSale);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        label_5 = new QLabel(grSale);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(label_5, 5, 2, 1, 1);

        lePaymentName = new EQLineEdit(grSale);
        lePaymentName->setObjectName(QString::fromUtf8("lePaymentName"));
        lePaymentName->setFocusPolicy(Qt::ClickFocus);
        lePaymentName->setReadOnly(true);

        gridLayout->addWidget(lePaymentName, 2, 2, 1, 2);

        leAmountUSD = new EQLineEdit(grSale);
        leAmountUSD->setObjectName(QString::fromUtf8("leAmountUSD"));
        leAmountUSD->setMaximumSize(QSize(80, 16777215));
        leAmountUSD->setFocusPolicy(Qt::ClickFocus);
        leAmountUSD->setReadOnly(true);

        gridLayout->addWidget(leAmountUSD, 5, 3, 1, 1);

        leFiscal = new EQLineEdit(grSale);
        leFiscal->setObjectName(QString::fromUtf8("leFiscal"));
        leFiscal->setMaximumSize(QSize(80, 16777215));
        leFiscal->setFocusPolicy(Qt::StrongFocus);
        leFiscal->setReadOnly(true);

        gridLayout->addWidget(leFiscal, 6, 1, 1, 1);

        lbPayment = new QLabel(grSale);
        lbPayment->setObjectName(QString::fromUtf8("lbPayment"));
        lbPayment->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(lbPayment, 2, 0, 1, 1);

        rbGuest = new QRadioButton(grSale);
        rbGuest->setObjectName(QString::fromUtf8("rbGuest"));
        rbGuest->setChecked(true);

        gridLayout->addWidget(rbGuest, 7, 1, 1, 1);

        rbCompany = new QRadioButton(grSale);
        rbCompany->setObjectName(QString::fromUtf8("rbCompany"));

        gridLayout->addWidget(rbCompany, 7, 3, 1, 1);


        gridLayout_4->addWidget(grSale, 2, 0, 1, 1);

        QWidget::setTabOrder(wRoom, leItem);
        QWidget::setTabOrder(leItem, lePayment);
        QWidget::setTabOrder(lePayment, leCard);
        QWidget::setTabOrder(leCard, leVAT);
        QWidget::setTabOrder(leVAT, leAmount);

        retranslateUi(DlgPostCharge);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgPostCharge);
    } // setupUi

    void retranslateUi(QDialog *DlgPostCharge)
    {
        DlgPostCharge->setWindowTitle(QCoreApplication::translate("DlgPostCharge", "Posting charge", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgPostCharge", "Voucher", nullptr));
        label_9->setText(QCoreApplication::translate("DlgPostCharge", "Voucher date", nullptr));
        label_2->setText(QCoreApplication::translate("DlgPostCharge", "Voucher number", nullptr));
        teRemarks->setPlaceholderText(QCoreApplication::translate("DlgPostCharge", "Remarks", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabInvoice), QCoreApplication::translate("DlgPostCharge", "Guest invoice", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDirect), QCoreApplication::translate("DlgPostCharge", "Direct", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCity), QCoreApplication::translate("DlgPostCharge", "City ledger", nullptr));
        btnNew->setText(QCoreApplication::translate("DlgPostCharge", "New", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgPostCharge", "Save", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgPostCharge", "Print", nullptr));
        btnPrintTax->setText(QCoreApplication::translate("DlgPostCharge", "Print tax", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgPostCharge", "Cancel", nullptr));
        grSale->setTitle(QCoreApplication::translate("DlgPostCharge", "Type of sale", nullptr));
        label_3->setText(QCoreApplication::translate("DlgPostCharge", "Tax number", nullptr));
        label->setText(QCoreApplication::translate("DlgPostCharge", "Item", nullptr));
        label_6->setText(QCoreApplication::translate("DlgPostCharge", "Mode of VAT", nullptr));
        lbCard->setText(QCoreApplication::translate("DlgPostCharge", "Credit card", nullptr));
        label_4->setText(QCoreApplication::translate("DlgPostCharge", "Amount", nullptr));
        label_8->setText(QCoreApplication::translate("DlgPostCharge", "Final name", nullptr));
        label_5->setText(QCoreApplication::translate("DlgPostCharge", "Amount, USD", nullptr));
        lbPayment->setText(QCoreApplication::translate("DlgPostCharge", "Mode of payment", nullptr));
        rbGuest->setText(QCoreApplication::translate("DlgPostCharge", "Guest side", nullptr));
        rbCompany->setText(QCoreApplication::translate("DlgPostCharge", "Company side", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPostCharge: public Ui_DlgPostCharge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPOSTCHARGE_H
