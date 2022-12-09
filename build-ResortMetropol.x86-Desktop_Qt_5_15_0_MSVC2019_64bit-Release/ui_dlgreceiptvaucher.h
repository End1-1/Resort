/********************************************************************************
** Form generated from reading UI file 'dlgreceiptvaucher.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRECEIPTVAUCHER_H
#define UI_DLGRECEIPTVAUCHER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <wcityledger.h>
#include <wguestinvoice.h>

QT_BEGIN_NAMESPACE

class Ui_DlgReceiptVaucher
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *grVoucher;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    EDateEdit *deDate;
    QLabel *label_11;
    EQLineEdit *leVaucher;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_10;
    EQLineEdit *leOpcode;
    EQLineEdit *leOpName;
    QTabWidget *tabWidget;
    QWidget *tabGuest;
    QHBoxLayout *horizontalLayout_2;
    WGuestInvoice *wRoom;
    QWidget *tabCL;
    QHBoxLayout *horizontalLayout_5;
    WCityLedger *wCL;
    QGroupBox *grPayment;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    EQLineEdit *leCardName;
    EQLineEdit *lePaymentName;
    QLabel *lbCL;
    EQLineEdit *leCardCode;
    QLabel *label_2;
    QLabel *label;
    EQLineEdit *leAmountUSD;
    QLabel *label_3;
    QLineEdit *leFiscalMachine;
    EQLineEdit *leFinalName;
    EQLineEdit *leCL;
    EQLineEdit *leAmountAMD;
    QLabel *lbCardType;
    EQLineEdit *lePaymentCode;
    QLabel *label_8;
    EQLineEdit *leCLName;
    QPushButton *btnSuggestAmount;
    QLabel *lbSuggestAmount;
    QPlainTextEdit *teRemarks;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnLog;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNew;
    QPushButton *btnSave;
    QPushButton *btnPrint;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgReceiptVaucher)
    {
        if (DlgReceiptVaucher->objectName().isEmpty())
            DlgReceiptVaucher->setObjectName(QString::fromUtf8("DlgReceiptVaucher"));
        DlgReceiptVaucher->resize(397, 476);
        DlgReceiptVaucher->setMaximumSize(QSize(397, 16777215));
        verticalLayout = new QVBoxLayout(DlgReceiptVaucher);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        grVoucher = new QGroupBox(DlgReceiptVaucher);
        grVoucher->setObjectName(QString::fromUtf8("grVoucher"));
        grVoucher->setMinimumSize(QSize(0, 0));
        gridLayout_3 = new QGridLayout(grVoucher);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(grVoucher);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 3, 1, 1);

        deDate = new EDateEdit(grVoucher);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(100, 16777215));
        deDate->setFocusPolicy(Qt::ClickFocus);
        deDate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        deDate->setReadOnly(true);

        gridLayout_3->addWidget(deDate, 0, 4, 1, 1);

        label_11 = new QLabel(grVoucher);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        leVaucher = new EQLineEdit(grVoucher);
        leVaucher->setObjectName(QString::fromUtf8("leVaucher"));
        leVaucher->setMaximumSize(QSize(80, 16777215));
        leVaucher->setReadOnly(true);

        gridLayout_3->addWidget(leVaucher, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        label_10 = new QLabel(grVoucher);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        leOpcode = new EQLineEdit(grVoucher);
        leOpcode->setObjectName(QString::fromUtf8("leOpcode"));
        leOpcode->setMaximumSize(QSize(100, 16777215));
        leOpcode->setCursor(QCursor(Qt::ArrowCursor));
        leOpcode->setReadOnly(true);

        gridLayout_3->addWidget(leOpcode, 1, 2, 1, 1);

        leOpName = new EQLineEdit(grVoucher);
        leOpName->setObjectName(QString::fromUtf8("leOpName"));
        leOpName->setCursor(QCursor(Qt::ArrowCursor));
        leOpName->setReadOnly(true);

        gridLayout_3->addWidget(leOpName, 1, 3, 1, 2);


        verticalLayout->addWidget(grVoucher);

        tabWidget = new QTabWidget(DlgReceiptVaucher);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabGuest = new QWidget();
        tabGuest->setObjectName(QString::fromUtf8("tabGuest"));
        horizontalLayout_2 = new QHBoxLayout(tabGuest);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        wRoom = new WGuestInvoice(tabGuest);
        wRoom->setObjectName(QString::fromUtf8("wRoom"));

        horizontalLayout_2->addWidget(wRoom);

        tabWidget->addTab(tabGuest, QString());
        tabCL = new QWidget();
        tabCL->setObjectName(QString::fromUtf8("tabCL"));
        horizontalLayout_5 = new QHBoxLayout(tabCL);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        wCL = new WCityLedger(tabCL);
        wCL->setObjectName(QString::fromUtf8("wCL"));

        horizontalLayout_5->addWidget(wCL);

        tabWidget->addTab(tabCL, QString());

        verticalLayout->addWidget(tabWidget);

        grPayment = new QGroupBox(DlgReceiptVaucher);
        grPayment->setObjectName(QString::fromUtf8("grPayment"));
        grPayment->setMinimumSize(QSize(0, 0));
        gridLayout_2 = new QGridLayout(grPayment);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(grPayment);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 6, 2, 1, 1);

        leCardName = new EQLineEdit(grPayment);
        leCardName->setObjectName(QString::fromUtf8("leCardName"));
        leCardName->setFocusPolicy(Qt::NoFocus);
        leCardName->setReadOnly(true);

        gridLayout_2->addWidget(leCardName, 3, 2, 1, 2);

        lePaymentName = new EQLineEdit(grPayment);
        lePaymentName->setObjectName(QString::fromUtf8("lePaymentName"));
        lePaymentName->setFocusPolicy(Qt::NoFocus);
        lePaymentName->setReadOnly(true);

        gridLayout_2->addWidget(lePaymentName, 1, 2, 1, 2);

        lbCL = new QLabel(grPayment);
        lbCL->setObjectName(QString::fromUtf8("lbCL"));

        gridLayout_2->addWidget(lbCL, 2, 0, 1, 1);

        leCardCode = new EQLineEdit(grPayment);
        leCardCode->setObjectName(QString::fromUtf8("leCardCode"));
        leCardCode->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(leCardCode, 3, 1, 1, 1);

        label_2 = new QLabel(grPayment);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(grPayment);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 1);

        leAmountUSD = new EQLineEdit(grPayment);
        leAmountUSD->setObjectName(QString::fromUtf8("leAmountUSD"));
        leAmountUSD->setMaximumSize(QSize(5252, 16777215));
        leAmountUSD->setFocusPolicy(Qt::NoFocus);
        leAmountUSD->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        leAmountUSD->setReadOnly(true);

        gridLayout_2->addWidget(leAmountUSD, 6, 3, 1, 1);

        label_3 = new QLabel(grPayment);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 6, 0, 1, 1);

        leFiscalMachine = new QLineEdit(grPayment);
        leFiscalMachine->setObjectName(QString::fromUtf8("leFiscalMachine"));
        leFiscalMachine->setReadOnly(true);

        gridLayout_2->addWidget(leFiscalMachine, 0, 1, 1, 3);

        leFinalName = new EQLineEdit(grPayment);
        leFinalName->setObjectName(QString::fromUtf8("leFinalName"));
        leFinalName->setFocusPolicy(Qt::NoFocus);
        leFinalName->setReadOnly(true);

        gridLayout_2->addWidget(leFinalName, 4, 1, 1, 3);

        leCL = new EQLineEdit(grPayment);
        leCL->setObjectName(QString::fromUtf8("leCL"));
        leCL->setMaximumSize(QSize(100, 16777215));
        leCL->setReadOnly(true);

        gridLayout_2->addWidget(leCL, 2, 1, 1, 1);

        leAmountAMD = new EQLineEdit(grPayment);
        leAmountAMD->setObjectName(QString::fromUtf8("leAmountAMD"));
        leAmountAMD->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(leAmountAMD, 6, 1, 1, 1);

        lbCardType = new QLabel(grPayment);
        lbCardType->setObjectName(QString::fromUtf8("lbCardType"));

        gridLayout_2->addWidget(lbCardType, 3, 0, 1, 1);

        lePaymentCode = new EQLineEdit(grPayment);
        lePaymentCode->setObjectName(QString::fromUtf8("lePaymentCode"));
        lePaymentCode->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(lePaymentCode, 1, 1, 1, 1);

        label_8 = new QLabel(grPayment);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        leCLName = new EQLineEdit(grPayment);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));
        leCLName->setMaximumSize(QSize(16777215, 16777215));
        leCLName->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(leCLName, 2, 2, 1, 2);

        btnSuggestAmount = new QPushButton(grPayment);
        btnSuggestAmount->setObjectName(QString::fromUtf8("btnSuggestAmount"));

        gridLayout_2->addWidget(btnSuggestAmount, 5, 1, 1, 3);

        lbSuggestAmount = new QLabel(grPayment);
        lbSuggestAmount->setObjectName(QString::fromUtf8("lbSuggestAmount"));

        gridLayout_2->addWidget(lbSuggestAmount, 5, 0, 1, 1);


        verticalLayout->addWidget(grPayment);

        teRemarks = new QPlainTextEdit(DlgReceiptVaucher);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));
        teRemarks->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(teRemarks);

        widget = new QWidget(DlgReceiptVaucher);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnLog = new QToolButton(widget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLog->setIcon(icon);

        horizontalLayout_3->addWidget(btnLog);

        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnNew = new QPushButton(widget);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        horizontalLayout_3->addWidget(btnNew);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout_3->addWidget(btnSave);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        btnPrint->setEnabled(false);

        horizontalLayout_3->addWidget(btnPrint);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_3->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(leVaucher, leOpcode);
        QWidget::setTabOrder(leOpcode, leOpName);
        QWidget::setTabOrder(leOpName, tabWidget);
        QWidget::setTabOrder(tabWidget, leFiscalMachine);
        QWidget::setTabOrder(leFiscalMachine, lePaymentCode);
        QWidget::setTabOrder(lePaymentCode, leCL);
        QWidget::setTabOrder(leCL, leCardCode);
        QWidget::setTabOrder(leCardCode, btnSuggestAmount);
        QWidget::setTabOrder(btnSuggestAmount, leAmountAMD);
        QWidget::setTabOrder(leAmountAMD, teRemarks);
        QWidget::setTabOrder(teRemarks, btnLog);
        QWidget::setTabOrder(btnLog, btnNew);
        QWidget::setTabOrder(btnNew, btnSave);
        QWidget::setTabOrder(btnSave, btnPrint);
        QWidget::setTabOrder(btnPrint, btnCancel);
        QWidget::setTabOrder(btnCancel, leCLName);
        QWidget::setTabOrder(leCLName, leCardName);

        retranslateUi(DlgReceiptVaucher);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgReceiptVaucher);
    } // setupUi

    void retranslateUi(QDialog *DlgReceiptVaucher)
    {
        DlgReceiptVaucher->setWindowTitle(QCoreApplication::translate("DlgReceiptVaucher", "Receipt voucher", nullptr));
        grVoucher->setTitle(QCoreApplication::translate("DlgReceiptVaucher", "Voucher", nullptr));
        label_5->setText(QCoreApplication::translate("DlgReceiptVaucher", "Date", nullptr));
        label_11->setText(QCoreApplication::translate("DlgReceiptVaucher", "Code", nullptr));
        label_10->setText(QCoreApplication::translate("DlgReceiptVaucher", "Operator", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGuest), QCoreApplication::translate("DlgReceiptVaucher", "Invoice", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCL), QCoreApplication::translate("DlgReceiptVaucher", "Cityledger", nullptr));
        grPayment->setTitle(QCoreApplication::translate("DlgReceiptVaucher", "Payment", nullptr));
        label_7->setText(QCoreApplication::translate("DlgReceiptVaucher", "Amount, USD", nullptr));
        lbCL->setText(QCoreApplication::translate("DlgReceiptVaucher", "City ledger", nullptr));
        label_2->setText(QCoreApplication::translate("DlgReceiptVaucher", "Fiscal", nullptr));
        label->setText(QCoreApplication::translate("DlgReceiptVaucher", "Final name", nullptr));
        label_3->setText(QCoreApplication::translate("DlgReceiptVaucher", "Amount, AMD", nullptr));
        lbCardType->setText(QCoreApplication::translate("DlgReceiptVaucher", "Card type", nullptr));
        label_8->setText(QCoreApplication::translate("DlgReceiptVaucher", "Payment mode", nullptr));
        btnSuggestAmount->setText(QCoreApplication::translate("DlgReceiptVaucher", "0", nullptr));
        lbSuggestAmount->setText(QCoreApplication::translate("DlgReceiptVaucher", "Suggest amount", nullptr));
        teRemarks->setPlaceholderText(QCoreApplication::translate("DlgReceiptVaucher", "Remarks", nullptr));
        btnLog->setText(QString());
        btnNew->setText(QCoreApplication::translate("DlgReceiptVaucher", "New", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgReceiptVaucher", "Save", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgReceiptVaucher", "Print", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgReceiptVaucher", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgReceiptVaucher: public Ui_DlgReceiptVaucher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRECEIPTVAUCHER_H
