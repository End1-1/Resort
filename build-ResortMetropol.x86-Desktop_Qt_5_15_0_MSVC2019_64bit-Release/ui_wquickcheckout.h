/********************************************************************************
** Form generated from reading UI file 'wquickcheckout.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WQUICKCHECKOUT_H
#define UI_WQUICKCHECKOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqtablewidget.h>
#include <wactivegroup.h>
#include <wcardex.h>

QT_BEGIN_NAMESPACE

class Ui_WQuickCheckout
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chAllInvoices;
    WCardex *wCardex;
    WActiveGroup *wGroup;
    QPushButton *btnRefresh;
    QPushButton *btnCheckout;
    QPushButton *btnCommonPostCharge;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    EQTableWidget *tbl;
    EQTableWidget *tblTotal;

    void setupUi(QWidget *WQuickCheckout)
    {
        if (WQuickCheckout->objectName().isEmpty())
            WQuickCheckout->setObjectName(QString::fromUtf8("WQuickCheckout"));
        WQuickCheckout->resize(1075, 645);
        verticalLayout = new QVBoxLayout(WQuickCheckout);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(WQuickCheckout);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chAllInvoices = new QCheckBox(widget);
        chAllInvoices->setObjectName(QString::fromUtf8("chAllInvoices"));

        horizontalLayout->addWidget(chAllInvoices);

        wCardex = new WCardex(widget);
        wCardex->setObjectName(QString::fromUtf8("wCardex"));

        horizontalLayout->addWidget(wCardex);

        wGroup = new WActiveGroup(widget);
        wGroup->setObjectName(QString::fromUtf8("wGroup"));

        horizontalLayout->addWidget(wGroup);

        btnRefresh = new QPushButton(widget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon);

        horizontalLayout->addWidget(btnRefresh);

        btnCheckout = new QPushButton(widget);
        btnCheckout->setObjectName(QString::fromUtf8("btnCheckout"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/departure.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCheckout->setIcon(icon1);

        horizontalLayout->addWidget(btnCheckout);

        btnCommonPostCharge = new QPushButton(widget);
        btnCommonPostCharge->setObjectName(QString::fromUtf8("btnCommonPostCharge"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/charge.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCommonPostCharge->setIcon(icon2);

        horizontalLayout->addWidget(btnCommonPostCharge);

        horizontalSpacer = new QSpacerItem(957, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(WQuickCheckout);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tbl = new EQTableWidget(widget_2);
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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(tbl->sizePolicy().hasHeightForWidth());
        tbl->setSizePolicy(sizePolicy1);
        tbl->setStyleSheet(QString::fromUtf8("\n"
"border-bottom: 0px solid gray;"));
        tbl->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::SingleSelection);
        tbl->setSelectionBehavior(QAbstractItemView::SelectRows);
        tbl->setWordWrap(false);

        verticalLayout_2->addWidget(tbl);

        tblTotal = new EQTableWidget(widget_2);
        if (tblTotal->columnCount() < 5)
            tblTotal->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tblTotal->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        if (tblTotal->rowCount() < 1)
            tblTotal->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tblTotal->setVerticalHeaderItem(0, __qtablewidgetitem15);
        tblTotal->setObjectName(QString::fromUtf8("tblTotal"));
        tblTotal->setMinimumSize(QSize(0, 30));
        tblTotal->setMaximumSize(QSize(16777215, 55));
        tblTotal->setStyleSheet(QString::fromUtf8("border-top: 0px solid gray;\n"
"border-left: 1px solid gray;\n"
"border-right: 1px solid gray;\n"
"border-bottom: 1px solid gray;"));
        tblTotal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblTotal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tblTotal->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblTotal->setSelectionMode(QAbstractItemView::NoSelection);
        tblTotal->setWordWrap(false);
        tblTotal->horizontalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tblTotal);


        verticalLayout->addWidget(widget_2);


        retranslateUi(WQuickCheckout);

        QMetaObject::connectSlotsByName(WQuickCheckout);
    } // setupUi

    void retranslateUi(QWidget *WQuickCheckout)
    {
        WQuickCheckout->setWindowTitle(QCoreApplication::translate("WQuickCheckout", "Form", nullptr));
        chAllInvoices->setText(QCoreApplication::translate("WQuickCheckout", "All invoices", nullptr));
#if QT_CONFIG(tooltip)
        btnRefresh->setToolTip(QCoreApplication::translate("WQuickCheckout", "Refresh", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRefresh->setText(QString());
#if QT_CONFIG(tooltip)
        btnCheckout->setToolTip(QCoreApplication::translate("WQuickCheckout", "Checkout selected invoices", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCheckout->setText(QString());
#if QT_CONFIG(tooltip)
        btnCommonPostCharge->setToolTip(QCoreApplication::translate("WQuickCheckout", "Checkout selected invoices", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCommonPostCharge->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WQuickCheckout", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WQuickCheckout", "Invoice", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WQuickCheckout", "Cardex", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WQuickCheckout", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WQuickCheckout", "Guest balance", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WQuickCheckout", "C/L balance", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WQuickCheckout", "Total Balance", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WQuickCheckout", "Pax", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tbl->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WQuickCheckout", "Cat", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tbl->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WQuickCheckout", "Group", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tblTotal->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WQuickCheckout", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tblTotal->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WQuickCheckout", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tblTotal->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("WQuickCheckout", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tblTotal->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("WQuickCheckout", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tblTotal->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("WQuickCheckout", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tblTotal->verticalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("WQuickCheckout", "New Row", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WQuickCheckout: public Ui_WQuickCheckout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WQUICKCHECKOUT_H
