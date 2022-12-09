/********************************************************************************
** Form generated from reading UI file 'wtaxattack.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WTAXATTACK_H
#define UI_WTAXATTACK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_WTaxAttack
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btnPrintTax;
    QLabel *label_2;
    EQLineEdit *leCardexName;
    EQLineEdit *leCardex;
    EDateEdit *deStart;
    QSpacerItem *horizontalSpacer;
    QToolButton *btnRefresh;
    EDateEdit *deEnd;
    QLabel *label;
    QLabel *label_3;
    EQLineEdit *leSearch;
    QLabel *label_4;
    EQLineEdit *leInvoice;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    EQTableWidget *tbl;
    EQTableWidget *tblt;

    void setupUi(QWidget *WTaxAttack)
    {
        if (WTaxAttack->objectName().isEmpty())
            WTaxAttack->setObjectName(QString::fromUtf8("WTaxAttack"));
        WTaxAttack->resize(1085, 734);
        verticalLayout = new QVBoxLayout(WTaxAttack);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(WTaxAttack);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnPrintTax = new QPushButton(widget);
        btnPrintTax->setObjectName(QString::fromUtf8("btnPrintTax"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrintTax->setIcon(icon);

        gridLayout->addWidget(btnPrintTax, 0, 8, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        leCardexName = new EQLineEdit(widget);
        leCardexName->setObjectName(QString::fromUtf8("leCardexName"));
        leCardexName->setMaximumSize(QSize(250, 16777215));
        leCardexName->setReadOnly(true);

        gridLayout->addWidget(leCardexName, 0, 5, 1, 1);

        leCardex = new EQLineEdit(widget);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCardex, 0, 4, 1, 1);

        deStart = new EDateEdit(widget);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deStart, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(283, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        btnRefresh = new QToolButton(widget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon1);

        gridLayout->addWidget(btnRefresh, 0, 6, 1, 1);

        deEnd = new EDateEdit(widget);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        deEnd->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(deEnd, 0, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        leSearch = new EQLineEdit(widget);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));

        gridLayout->addWidget(leSearch, 1, 1, 1, 2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        leInvoice = new EQLineEdit(widget);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(leInvoice, 1, 4, 1, 2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(WTaxAttack);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(widget_2);

        tbl = new EQTableWidget(WTaxAttack);
        if (tbl->columnCount() < 10)
            tbl->setColumnCount(10);
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setContextMenuPolicy(Qt::CustomContextMenu);
        tbl->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tbl->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tbl);

        tblt = new EQTableWidget(WTaxAttack);
        if (tblt->columnCount() < 8)
            tblt->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblt->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblt->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblt->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblt->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblt->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblt->setHorizontalHeaderItem(5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tblt->setHorizontalHeaderItem(6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tblt->setHorizontalHeaderItem(7, __qtablewidgetitem17);
        if (tblt->rowCount() < 1)
            tblt->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tblt->setVerticalHeaderItem(0, __qtablewidgetitem18);
        tblt->setObjectName(QString::fromUtf8("tblt"));
        tblt->setMinimumSize(QSize(0, 50));
        tblt->setMaximumSize(QSize(16777215, 50));
        tblt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblt->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblt->horizontalHeader()->setVisible(false);

        verticalLayout->addWidget(tblt);


        retranslateUi(WTaxAttack);

        QMetaObject::connectSlotsByName(WTaxAttack);
    } // setupUi

    void retranslateUi(QWidget *WTaxAttack)
    {
        WTaxAttack->setWindowTitle(QCoreApplication::translate("WTaxAttack", "Form", nullptr));
        btnPrintTax->setText(QCoreApplication::translate("WTaxAttack", "Start!", nullptr));
        label_2->setText(QCoreApplication::translate("WTaxAttack", "Cardex", nullptr));
        btnRefresh->setText(QString());
        label->setText(QCoreApplication::translate("WTaxAttack", "Checkout date", nullptr));
        label_3->setText(QCoreApplication::translate("WTaxAttack", "Common search", nullptr));
        label_4->setText(QCoreApplication::translate("WTaxAttack", "Invoices", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WTaxAttack", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WTaxAttack", "Checkout ", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WTaxAttack", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WTaxAttack", "Cardex", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WTaxAttack", "Voucher", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WTaxAttack", "Purpose", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WTaxAttack", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WTaxAttack", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tbl->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WTaxAttack", "ItemCode", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tbl->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WTaxAttack", "Mode of VAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblt->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WTaxAttack", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblt->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WTaxAttack", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblt->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("WTaxAttack", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblt->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("WTaxAttack", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblt->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("WTaxAttack", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblt->horizontalHeaderItem(5);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("WTaxAttack", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tblt->horizontalHeaderItem(6);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("WTaxAttack", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tblt->horizontalHeaderItem(7);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("WTaxAttack", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tblt->verticalHeaderItem(0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("WTaxAttack", "New Row", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WTaxAttack: public Ui_WTaxAttack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WTAXATTACK_H
