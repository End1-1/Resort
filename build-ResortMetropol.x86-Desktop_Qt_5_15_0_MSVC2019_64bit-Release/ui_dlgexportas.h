/********************************************************************************
** Form generated from reading UI file 'dlgexportas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEXPORTAS_H
#define UI_DLGEXPORTAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgExportAS
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leAsConnectionString;
    QPushButton *btnSaveAsSettings;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    EDateEdit *deEnd;
    QLabel *label;
    EDateEdit *deStart;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    EQLineEdit *leServiceExpenseAcc;
    EQLineEdit *leStore;
    EQLineEdit *lePartnerCode;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_7;
    EQLineEdit *leServiceIncomeAcc;
    QPushButton *btnUploadPostCharges;
    EQLineEdit *leVat;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_9;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_2;
    EQLineEdit *leServiceExpenseAccInvoice;
    EQLineEdit *leServiceIncomeAccInvoice;
    EQLineEdit *leVatInvoice;
    QLabel *label_11;
    QPushButton *btnUploadInvoices;
    QLabel *label_13;
    QLabel *lbProgress;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QLabel *label_14;
    QLabel *label_15;
    EQLineEdit *leExportPaymentRVDebet;
    QLabel *label_16;
    QPushButton *btnUploadPayments;
    EQLineEdit *leExportPaymentAVDebet;
    EQLineEdit *leExportPaymentAVCredit;
    EQLineEdit *leExportPaymentRVCredit;
    QWidget *tab_4;
    QFormLayout *formLayout;
    QLabel *label_8;
    QLineEdit *leRetailDocStartNumber;
    QLabel *label_17;
    QLabel *lbProgress2;
    QPushButton *btnUploadInvoicesRetail;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QPushButton *_5btnStart;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_18;
    QLabel *label_19;
    EQLineEdit *_5lePartnerCredit;
    EQLineEdit *_5lePartnerDebet;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *DlgExportAS)
    {
        if (DlgExportAS->objectName().isEmpty())
            DlgExportAS->setObjectName(QString::fromUtf8("DlgExportAS"));
        DlgExportAS->resize(737, 393);
        gridLayout_4 = new QGridLayout(DlgExportAS);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(DlgExportAS);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        leAsConnectionString = new QLineEdit(groupBox_2);
        leAsConnectionString->setObjectName(QString::fromUtf8("leAsConnectionString"));

        horizontalLayout->addWidget(leAsConnectionString);

        btnSaveAsSettings = new QPushButton(groupBox_2);
        btnSaveAsSettings->setObjectName(QString::fromUtf8("btnSaveAsSettings"));

        horizontalLayout->addWidget(btnSaveAsSettings);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(DlgExportAS);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 100));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        deEnd = new EDateEdit(groupBox);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout_3->addWidget(deEnd, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        deStart = new EDateEdit(groupBox);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout_3->addWidget(deStart, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(316, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 1, 0, 1, 1);

        tabWidget = new QTabWidget(DlgExportAS);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        leServiceExpenseAcc = new EQLineEdit(tab);
        leServiceExpenseAcc->setObjectName(QString::fromUtf8("leServiceExpenseAcc"));

        gridLayout_2->addWidget(leServiceExpenseAcc, 5, 1, 1, 1);

        leStore = new EQLineEdit(tab);
        leStore->setObjectName(QString::fromUtf8("leStore"));

        gridLayout_2->addWidget(leStore, 1, 1, 1, 1);

        lePartnerCode = new EQLineEdit(tab);
        lePartnerCode->setObjectName(QString::fromUtf8("lePartnerCode"));

        gridLayout_2->addWidget(lePartnerCode, 3, 1, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        leServiceIncomeAcc = new EQLineEdit(tab);
        leServiceIncomeAcc->setObjectName(QString::fromUtf8("leServiceIncomeAcc"));

        gridLayout_2->addWidget(leServiceIncomeAcc, 4, 1, 1, 1);

        btnUploadPostCharges = new QPushButton(tab);
        btnUploadPostCharges->setObjectName(QString::fromUtf8("btnUploadPostCharges"));

        gridLayout_2->addWidget(btnUploadPostCharges, 5, 2, 1, 1);

        leVat = new EQLineEdit(tab);
        leVat->setObjectName(QString::fromUtf8("leVat"));

        gridLayout_2->addWidget(leVat, 2, 1, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        leServiceExpenseAccInvoice = new EQLineEdit(tab_2);
        leServiceExpenseAccInvoice->setObjectName(QString::fromUtf8("leServiceExpenseAccInvoice"));

        gridLayout->addWidget(leServiceExpenseAccInvoice, 3, 1, 1, 1);

        leServiceIncomeAccInvoice = new EQLineEdit(tab_2);
        leServiceIncomeAccInvoice->setObjectName(QString::fromUtf8("leServiceIncomeAccInvoice"));

        gridLayout->addWidget(leServiceIncomeAccInvoice, 2, 1, 1, 1);

        leVatInvoice = new EQLineEdit(tab_2);
        leVatInvoice->setObjectName(QString::fromUtf8("leVatInvoice"));

        gridLayout->addWidget(leVatInvoice, 1, 1, 1, 1);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        btnUploadInvoices = new QPushButton(tab_2);
        btnUploadInvoices->setObjectName(QString::fromUtf8("btnUploadInvoices"));

        gridLayout->addWidget(btnUploadInvoices, 3, 2, 1, 1);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        lbProgress = new QLabel(tab_2);
        lbProgress->setObjectName(QString::fromUtf8("lbProgress"));

        gridLayout->addWidget(lbProgress, 4, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 3, 0, 1, 1);

        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_5->addWidget(label_15, 1, 0, 1, 1);

        leExportPaymentRVDebet = new EQLineEdit(tab_3);
        leExportPaymentRVDebet->setObjectName(QString::fromUtf8("leExportPaymentRVDebet"));

        gridLayout_5->addWidget(leExportPaymentRVDebet, 1, 1, 1, 1);

        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_5->addWidget(label_16, 0, 0, 1, 1);

        btnUploadPayments = new QPushButton(tab_3);
        btnUploadPayments->setObjectName(QString::fromUtf8("btnUploadPayments"));

        gridLayout_5->addWidget(btnUploadPayments, 2, 1, 1, 1);

        leExportPaymentAVDebet = new EQLineEdit(tab_3);
        leExportPaymentAVDebet->setObjectName(QString::fromUtf8("leExportPaymentAVDebet"));

        gridLayout_5->addWidget(leExportPaymentAVDebet, 0, 1, 1, 1);

        leExportPaymentAVCredit = new EQLineEdit(tab_3);
        leExportPaymentAVCredit->setObjectName(QString::fromUtf8("leExportPaymentAVCredit"));

        gridLayout_5->addWidget(leExportPaymentAVCredit, 0, 2, 1, 1);

        leExportPaymentRVCredit = new EQLineEdit(tab_3);
        leExportPaymentRVCredit->setObjectName(QString::fromUtf8("leExportPaymentRVCredit"));

        gridLayout_5->addWidget(leExportPaymentRVCredit, 1, 2, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        formLayout = new QFormLayout(tab_4);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_8);

        leRetailDocStartNumber = new QLineEdit(tab_4);
        leRetailDocStartNumber->setObjectName(QString::fromUtf8("leRetailDocStartNumber"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leRetailDocStartNumber);

        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_17);

        lbProgress2 = new QLabel(tab_4);
        lbProgress2->setObjectName(QString::fromUtf8("lbProgress2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lbProgress2);

        btnUploadInvoicesRetail = new QPushButton(tab_4);
        btnUploadInvoicesRetail->setObjectName(QString::fromUtf8("btnUploadInvoicesRetail"));

        formLayout->setWidget(2, QFormLayout::LabelRole, btnUploadInvoicesRetail);

        horizontalSpacer_4 = new QSpacerItem(611, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(2, QFormLayout::FieldRole, horizontalSpacer_4);

        verticalSpacer_3 = new QSpacerItem(20, 112, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer_3);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        _5btnStart = new QPushButton(tab_5);
        _5btnStart->setObjectName(QString::fromUtf8("_5btnStart"));

        gridLayout_6->addWidget(_5btnStart, 3, 1, 1, 1);

        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(247, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        label_18 = new QLabel(tab_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_6->addWidget(label_18, 1, 0, 1, 1);

        label_19 = new QLabel(tab_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_6->addWidget(label_19, 2, 0, 1, 1);

        _5lePartnerCredit = new EQLineEdit(tab_5);
        _5lePartnerCredit->setObjectName(QString::fromUtf8("_5lePartnerCredit"));

        gridLayout_6->addWidget(_5lePartnerCredit, 2, 1, 1, 1);

        _5lePartnerDebet = new EQLineEdit(tab_5);
        _5lePartnerDebet->setObjectName(QString::fromUtf8("_5lePartnerDebet"));

        gridLayout_6->addWidget(_5lePartnerDebet, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_4, 4, 1, 1, 1);

        tabWidget->addTab(tab_5, QString());

        gridLayout_4->addWidget(tabWidget, 2, 0, 1, 1);


        retranslateUi(DlgExportAS);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(DlgExportAS);
    } // setupUi

    void retranslateUi(QDialog *DlgExportAS)
    {
        DlgExportAS->setWindowTitle(QCoreApplication::translate("DlgExportAS", "Export to AS", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DlgExportAS", "AS connection string", nullptr));
        btnSaveAsSettings->setText(QCoreApplication::translate("DlgExportAS", "Save", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgExportAS", "Common options", nullptr));
        label->setText(QCoreApplication::translate("DlgExportAS", "Start date", nullptr));
        label_2->setText(QCoreApplication::translate("DlgExportAS", "End date", nullptr));
        label_6->setText(QCoreApplication::translate("DlgExportAS", "Service expense account", nullptr));
        label_3->setText(QCoreApplication::translate("DlgExportAS", "Partner code", nullptr));
        label_7->setText(QCoreApplication::translate("DlgExportAS", "Service income account", nullptr));
        btnUploadPostCharges->setText(QCoreApplication::translate("DlgExportAS", "Upload", nullptr));
        label_4->setText(QCoreApplication::translate("DlgExportAS", "VAT", nullptr));
        label_5->setText(QCoreApplication::translate("DlgExportAS", "Store code", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DlgExportAS", "Export post charges (Retail sale)", nullptr));
        label_9->setText(QCoreApplication::translate("DlgExportAS", "VAT", nullptr));
        label_12->setText(QCoreApplication::translate("DlgExportAS", "Service income account", nullptr));
        label_11->setText(QCoreApplication::translate("DlgExportAS", "Service expense account", nullptr));
        btnUploadInvoices->setText(QCoreApplication::translate("DlgExportAS", "Upload invoices", nullptr));
        label_13->setText(QCoreApplication::translate("DlgExportAS", "Progress", nullptr));
        lbProgress->setText(QCoreApplication::translate("DlgExportAS", "0/0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DlgExportAS", "Export invoices", nullptr));
        label_14->setText(QCoreApplication::translate("DlgExportAS", "Progress", nullptr));
        label_15->setText(QCoreApplication::translate("DlgExportAS", "Payment Debet/Credit", nullptr));
        label_16->setText(QCoreApplication::translate("DlgExportAS", "Advance Debet/Credit", nullptr));
        btnUploadPayments->setText(QCoreApplication::translate("DlgExportAS", "Upload payments", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("DlgExportAS", "Export payments", nullptr));
        label_8->setText(QCoreApplication::translate("DlgExportAS", "Document start number", nullptr));
        label_17->setText(QCoreApplication::translate("DlgExportAS", "Progress", nullptr));
        lbProgress2->setText(QCoreApplication::translate("DlgExportAS", "0/0", nullptr));
        btnUploadInvoicesRetail->setText(QCoreApplication::translate("DlgExportAS", "Upload", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("DlgExportAS", "Export invoices as Retail sale", nullptr));
        _5btnStart->setText(QCoreApplication::translate("DlgExportAS", "Start", nullptr));
        label_10->setText(QCoreApplication::translate("DlgExportAS", "Export advamces of checkout invoices", nullptr));
        label_18->setText(QCoreApplication::translate("DlgExportAS", "Partner debet", nullptr));
        label_19->setText(QCoreApplication::translate("DlgExportAS", "Partner credit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("DlgExportAS", "Export advances ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgExportAS: public Ui_DlgExportAS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEXPORTAS_H
