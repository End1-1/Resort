/********************************************************************************
** Form generated from reading UI file 'dlgadvanceentry.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGADVANCEENTRY_H
#define UI_DLGADVANCEENTRY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <wguestinvoice.h>
#include <wpaymentdetails.h>

QT_BEGIN_NAMESPACE

class Ui_DlgAdvanceEntry
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    WPaymentDetails *wPayment;
    EQLineEdit *leUser;
    QLabel *label_2;
    EQLineEdit *leVoucher;
    EDateEdit *deDate;
    EQLineEdit *leUsername;
    QPlainTextEdit *teRemarks;
    QLabel *label_3;
    QLabel *lbOperator;
    QLabel *label;
    WGuestInvoice *wInvoice;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnLog;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNew;
    QPushButton *btnSave;
    QPushButton *btnPrint;
    QPushButton *btnPrintTax;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    EQLineEdit *leFinalName;

    void setupUi(QDialog *DlgAdvanceEntry)
    {
        if (DlgAdvanceEntry->objectName().isEmpty())
            DlgAdvanceEntry->setObjectName(QString::fromUtf8("DlgAdvanceEntry"));
        DlgAdvanceEntry->resize(564, 505);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgAdvanceEntry->sizePolicy().hasHeightForWidth());
        DlgAdvanceEntry->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DlgAdvanceEntry);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        tabWidget = new QTabWidget(DlgAdvanceEntry);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        wPayment = new WPaymentDetails(tab);
        wPayment->setObjectName(QString::fromUtf8("wPayment"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(wPayment->sizePolicy().hasHeightForWidth());
        wPayment->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(wPayment, 3, 0, 1, 4);

        leUser = new EQLineEdit(tab);
        leUser->setObjectName(QString::fromUtf8("leUser"));
        leUser->setMaximumSize(QSize(100, 16777215));
        leUser->setReadOnly(true);

        gridLayout_2->addWidget(leUser, 1, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        leVoucher = new EQLineEdit(tab);
        leVoucher->setObjectName(QString::fromUtf8("leVoucher"));
        leVoucher->setMaximumSize(QSize(100, 16777215));
        leVoucher->setReadOnly(true);

        gridLayout_2->addWidget(leVoucher, 0, 1, 1, 1);

        deDate = new EDateEdit(tab);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(100, 16777215));
        deDate->setReadOnly(true);

        gridLayout_2->addWidget(deDate, 0, 3, 1, 1);

        leUsername = new EQLineEdit(tab);
        leUsername->setObjectName(QString::fromUtf8("leUsername"));
        leUsername->setReadOnly(true);

        gridLayout_2->addWidget(leUsername, 1, 2, 1, 2);

        teRemarks = new QPlainTextEdit(tab);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));
        teRemarks->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(teRemarks, 6, 0, 1, 4);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        lbOperator = new QLabel(tab);
        lbOperator->setObjectName(QString::fromUtf8("lbOperator"));

        gridLayout_2->addWidget(lbOperator, 1, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 1);

        wInvoice = new WGuestInvoice(tab);
        wInvoice->setObjectName(QString::fromUtf8("wInvoice"));
        sizePolicy1.setHeightForWidth(wInvoice->sizePolicy().hasHeightForWidth());
        wInvoice->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(wInvoice, 2, 0, 1, 4);

        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnLog = new QToolButton(widget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLog->setIcon(icon);

        horizontalLayout->addWidget(btnLog);

        horizontalSpacer = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnNew = new QPushButton(widget);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        horizontalLayout->addWidget(btnNew);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnPrintTax = new QPushButton(widget);
        btnPrintTax->setObjectName(QString::fromUtf8("btnPrintTax"));

        horizontalLayout->addWidget(btnPrintTax);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(widget, 7, 0, 1, 4);

        leFinalName = new EQLineEdit(tab);
        leFinalName->setObjectName(QString::fromUtf8("leFinalName"));
        leFinalName->setReadOnly(true);

        gridLayout_2->addWidget(leFinalName, 4, 1, 1, 3);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(DlgAdvanceEntry);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgAdvanceEntry);
    } // setupUi

    void retranslateUi(QDialog *DlgAdvanceEntry)
    {
        DlgAdvanceEntry->setWindowTitle(QCoreApplication::translate("DlgAdvanceEntry", "Advance entry", nullptr));
        leUser->setProperty("Field", QVariant(QCoreApplication::translate("DlgAdvanceEntry", "f_user", nullptr)));
        label_2->setText(QCoreApplication::translate("DlgAdvanceEntry", "Voucher", nullptr));
        teRemarks->setPlaceholderText(QCoreApplication::translate("DlgAdvanceEntry", "Remarks", nullptr));
        label_3->setText(QCoreApplication::translate("DlgAdvanceEntry", "Date", nullptr));
        lbOperator->setText(QCoreApplication::translate("DlgAdvanceEntry", "Operator", nullptr));
        label->setText(QCoreApplication::translate("DlgAdvanceEntry", "Final name", nullptr));
        btnLog->setText(QString());
        btnNew->setText(QCoreApplication::translate("DlgAdvanceEntry", "New", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgAdvanceEntry", "Save", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgAdvanceEntry", "Print", nullptr));
        btnPrintTax->setText(QCoreApplication::translate("DlgAdvanceEntry", "Print tax", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgAdvanceEntry", "Close", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DlgAdvanceEntry", "Voucher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgAdvanceEntry: public Ui_DlgAdvanceEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGADVANCEENTRY_H
