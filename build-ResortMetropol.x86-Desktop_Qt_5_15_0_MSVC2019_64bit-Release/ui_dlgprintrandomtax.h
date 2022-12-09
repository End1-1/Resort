/********************************************************************************
** Form generated from reading UI file 'dlgprintrandomtax.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGPRINTRANDOMTAX_H
#define UI_DLGPRINTRANDOMTAX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgPrintRandomTax
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    EQLineEdit *leItemAmount;
    EQLineEdit *leItemName;
    QLabel *label_2;
    EQLineEdit *leItemCode;
    QLabel *label_4;
    QPushButton *btnAdd;
    EQLineEdit *leItemQty;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLabel *label_5;
    EQLineEdit *leRoom;
    QLabel *label_6;
    EQLineEdit *leInvoice;
    QLabel *label_7;
    EQLineEdit *leGuest;
    QLabel *label_12;
    EQLineEdit *leVAT;
    EQTableWidget *tblData;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    EQLineEdit *leCash;
    QLabel *label_9;
    EQLineEdit *leCard;
    QLabel *label_10;
    EQLineEdit *lePrepaiment;
    QLabel *label_11;
    EQLineEdit *leTotal;
    QPushButton *btnPrint;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DlgPrintRandomTax)
    {
        if (DlgPrintRandomTax->objectName().isEmpty())
            DlgPrintRandomTax->setObjectName(QString::fromUtf8("DlgPrintRandomTax"));
        DlgPrintRandomTax->resize(918, 431);
        verticalLayout = new QVBoxLayout(DlgPrintRandomTax);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgPrintRandomTax);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leItemAmount = new EQLineEdit(widget);
        leItemAmount->setObjectName(QString::fromUtf8("leItemAmount"));

        gridLayout->addWidget(leItemAmount, 1, 7, 1, 1);

        leItemName = new EQLineEdit(widget);
        leItemName->setObjectName(QString::fromUtf8("leItemName"));
        leItemName->setFocusPolicy(Qt::NoFocus);
        leItemName->setReadOnly(true);

        gridLayout->addWidget(leItemName, 1, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        leItemCode = new EQLineEdit(widget);
        leItemCode->setObjectName(QString::fromUtf8("leItemCode"));

        gridLayout->addWidget(leItemCode, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 6, 1, 1);

        btnAdd = new QPushButton(widget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon);

        gridLayout->addWidget(btnAdd, 1, 8, 1, 1);

        leItemQty = new EQLineEdit(widget);
        leItemQty->setObjectName(QString::fromUtf8("leItemQty"));
        leItemQty->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(leItemQty, 1, 5, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 9, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        leRoom = new EQLineEdit(widget);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setFocusPolicy(Qt::NoFocus);
        leRoom->setReadOnly(true);

        gridLayout->addWidget(leRoom, 0, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        leInvoice = new EQLineEdit(widget);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setFocusPolicy(Qt::NoFocus);
        leInvoice->setReadOnly(true);

        gridLayout->addWidget(leInvoice, 0, 3, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 4, 1, 1);

        leGuest = new EQLineEdit(widget);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setFocusPolicy(Qt::NoFocus);
        leGuest->setReadOnly(true);

        gridLayout->addWidget(leGuest, 0, 5, 1, 3);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 0, 8, 1, 1);

        leVAT = new EQLineEdit(widget);
        leVAT->setObjectName(QString::fromUtf8("leVAT"));

        gridLayout->addWidget(leVAT, 0, 9, 1, 1);


        verticalLayout->addWidget(widget);

        tblData = new EQTableWidget(DlgPrintRandomTax);
        if (tblData->columnCount() < 9)
            tblData->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setFocusPolicy(Qt::NoFocus);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tblData);

        widget_3 = new QWidget(DlgPrintRandomTax);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        leCash = new EQLineEdit(widget_3);
        leCash->setObjectName(QString::fromUtf8("leCash"));

        horizontalLayout_3->addWidget(leCash);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);

        leCard = new EQLineEdit(widget_3);
        leCard->setObjectName(QString::fromUtf8("leCard"));

        horizontalLayout_3->addWidget(leCard);

        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        lePrepaiment = new EQLineEdit(widget_3);
        lePrepaiment->setObjectName(QString::fromUtf8("lePrepaiment"));

        horizontalLayout_3->addWidget(lePrepaiment);

        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        leTotal = new EQLineEdit(widget_3);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        leTotal->setFont(font);
        leTotal->setFocusPolicy(Qt::NoFocus);
        leTotal->setReadOnly(true);

        horizontalLayout_3->addWidget(leTotal);

        btnPrint = new QPushButton(widget_3);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint->setIcon(icon1);

        horizontalLayout_3->addWidget(btnPrint);

        horizontalSpacer_3 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_3);

        QWidget::setTabOrder(leItemCode, leItemQty);
        QWidget::setTabOrder(leItemQty, leItemAmount);
        QWidget::setTabOrder(leItemAmount, btnAdd);
        QWidget::setTabOrder(btnAdd, leCash);
        QWidget::setTabOrder(leCash, leCard);
        QWidget::setTabOrder(leCard, lePrepaiment);
        QWidget::setTabOrder(lePrepaiment, btnPrint);

        retranslateUi(DlgPrintRandomTax);

        QMetaObject::connectSlotsByName(DlgPrintRandomTax);
    } // setupUi

    void retranslateUi(QDialog *DlgPrintRandomTax)
    {
        DlgPrintRandomTax->setWindowTitle(QCoreApplication::translate("DlgPrintRandomTax", "Manual Tax", nullptr));
        label_2->setText(QCoreApplication::translate("DlgPrintRandomTax", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("DlgPrintRandomTax", "Amount", nullptr));
        btnAdd->setText(QString());
        leItemQty->setText(QCoreApplication::translate("DlgPrintRandomTax", "1", nullptr));
        label_3->setText(QCoreApplication::translate("DlgPrintRandomTax", "Qty", nullptr));
        label->setText(QCoreApplication::translate("DlgPrintRandomTax", "Code", nullptr));
        label_5->setText(QCoreApplication::translate("DlgPrintRandomTax", "Room", nullptr));
        label_6->setText(QCoreApplication::translate("DlgPrintRandomTax", "Invoice", nullptr));
        label_7->setText(QCoreApplication::translate("DlgPrintRandomTax", "Guest", nullptr));
        label_12->setText(QCoreApplication::translate("DlgPrintRandomTax", "VAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgPrintRandomTax", "Item Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgPrintRandomTax", "Item name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgPrintRandomTax", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgPrintRandomTax", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgPrintRandomTax", "Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgPrintRandomTax", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblData->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgPrintRandomTax", "Adgt", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblData->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgPrintRandomTax", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblData->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgPrintRandomTax", "Source", nullptr));
        label_8->setText(QCoreApplication::translate("DlgPrintRandomTax", "Cash", nullptr));
        label_9->setText(QCoreApplication::translate("DlgPrintRandomTax", "Card", nullptr));
        label_10->setText(QCoreApplication::translate("DlgPrintRandomTax", "Prepayment", nullptr));
        label_11->setText(QCoreApplication::translate("DlgPrintRandomTax", "Total", nullptr));
#if QT_CONFIG(tooltip)
        btnPrint->setToolTip(QCoreApplication::translate("DlgPrintRandomTax", "Print", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPrint->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DlgPrintRandomTax: public Ui_DlgPrintRandomTax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGPRINTRANDOMTAX_H
