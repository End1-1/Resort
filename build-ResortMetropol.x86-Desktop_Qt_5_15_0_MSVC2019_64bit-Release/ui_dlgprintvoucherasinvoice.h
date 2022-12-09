/********************************************************************************
** Form generated from reading UI file 'dlgprintvoucherasinvoice.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRINTVOUCHERASINVOICE_H
#define UI_DLGPRINTVOUCHERASINVOICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgPrintVoucherAsInvoice
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddVoucher;
    QPushButton *btnSave;
    QPushButton *btnPrint;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    EQLineEdit *leInvoice;
    QLabel *label_2;
    EDateEdit *deDate;
    QLabel *label_3;
    EQLineEdit *leCL;
    EQLineEdit *leCLName;
    QSpacerItem *horizontalSpacer;
    EQTableWidget *tbl;
    EQTableWidget *tblTotal;

    void setupUi(QWidget *DlgPrintVoucherAsInvoice)
    {
        if (DlgPrintVoucherAsInvoice->objectName().isEmpty())
            DlgPrintVoucherAsInvoice->setObjectName(QString::fromUtf8("DlgPrintVoucherAsInvoice"));
        DlgPrintVoucherAsInvoice->resize(731, 393);
        DlgPrintVoucherAsInvoice->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(DlgPrintVoucherAsInvoice);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgPrintVoucherAsInvoice);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAddVoucher = new QPushButton(widget);
        btnAddVoucher->setObjectName(QString::fromUtf8("btnAddVoucher"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddVoucher->setIcon(icon);

        horizontalLayout->addWidget(btnAddVoucher);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon1);

        horizontalLayout->addWidget(btnSave);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint->setIcon(icon2);

        horizontalLayout->addWidget(btnPrint);

        horizontalSpacer_2 = new QSpacerItem(260, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(DlgPrintVoucherAsInvoice);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 30));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        leInvoice = new EQLineEdit(widget_2);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(100, 16777215));
        leInvoice->setReadOnly(true);

        horizontalLayout_2->addWidget(leInvoice);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        deDate = new EDateEdit(widget_2);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(deDate);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        leCL = new EQLineEdit(widget_2);
        leCL->setObjectName(QString::fromUtf8("leCL"));
        leCL->setMinimumSize(QSize(80, 0));
        leCL->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(leCL);

        leCLName = new EQLineEdit(widget_2);
        leCLName->setObjectName(QString::fromUtf8("leCLName"));
        leCLName->setMinimumSize(QSize(250, 0));
        leCLName->setMaximumSize(QSize(250, 16777215));
        leCLName->setReadOnly(true);

        horizontalLayout_2->addWidget(leCLName);

        horizontalSpacer = new QSpacerItem(410, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_2);

        tbl = new EQTableWidget(DlgPrintVoucherAsInvoice);
        if (tbl->columnCount() < 8)
            tbl->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setWordWrap(false);

        verticalLayout->addWidget(tbl);

        tblTotal = new EQTableWidget(DlgPrintVoucherAsInvoice);
        if (tblTotal->columnCount() < 6)
            tblTotal->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        tblTotal->setObjectName(QString::fromUtf8("tblTotal"));
        tblTotal->setMinimumSize(QSize(0, 30));
        tblTotal->setMaximumSize(QSize(16777215, 30));
        tblTotal->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblTotal->horizontalHeader()->setVisible(false);

        verticalLayout->addWidget(tblTotal);


        retranslateUi(DlgPrintVoucherAsInvoice);

        QMetaObject::connectSlotsByName(DlgPrintVoucherAsInvoice);
    } // setupUi

    void retranslateUi(QWidget *DlgPrintVoucherAsInvoice)
    {
        DlgPrintVoucherAsInvoice->setWindowTitle(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Print voucher as invoice", nullptr));
        btnAddVoucher->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Add voucher", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Save", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Print", nullptr));
        label->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Invoice", nullptr));
        label_2->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Date", nullptr));
        label_3->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "City ledger", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Debit", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Credit", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Payment", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Remarks", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "Paycode", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblTotal->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tblTotal->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblTotal->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblTotal->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblTotal->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblTotal->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("DlgPrintVoucherAsInvoice", "New Column", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgPrintVoucherAsInvoice: public Ui_DlgPrintVoucherAsInvoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRINTVOUCHERASINVOICE_H
