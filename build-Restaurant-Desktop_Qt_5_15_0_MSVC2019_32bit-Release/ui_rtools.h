/********************************************************************************
** Form generated from reading UI file 'rtools.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTOOLS_H
#define UI_RTOOLS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RTools
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QGridLayout *gridLayout;
    QToolButton *btnMoveTable;
    QToolButton *btnOrderComment;
    QToolButton *btnRemoveOrder;
    QToolButton *btnChangePassword;
    QToolButton *btnComplex;
    QToolButton *btnShowHideRemovedItems;
    QToolButton *btnCompimentary;
    QToolButton *btnTax;
    QToolButton *btnRecover;
    QToolButton *btnPrintAnyReport;
    QToolButton *btnVoidBack;
    QToolButton *btnPrintVoid;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QToolButton *btnExit;
    QToolButton *btnShowTableOrders;
    QToolButton *btnTotalReport;
    QToolButton *btnTotalYesterday;
    QToolButton *btnShowNyTotal;
    QToolButton *btnTotalReportAnyDay;

    void setupUi(QDialog *RTools)
    {
        if (RTools->objectName().isEmpty())
            RTools->setObjectName(QString::fromUtf8("RTools"));
        RTools->resize(520, 458);
        verticalLayout = new QVBoxLayout(RTools);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(RTools);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnMoveTable = new QToolButton(frame);
        btnMoveTable->setObjectName(QString::fromUtf8("btnMoveTable"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/transfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMoveTable->setIcon(icon);
        btnMoveTable->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnMoveTable, 1, 0, 1, 1);

        btnOrderComment = new QToolButton(frame);
        btnOrderComment->setObjectName(QString::fromUtf8("btnOrderComment"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOrderComment->setIcon(icon1);
        btnOrderComment->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnOrderComment, 0, 1, 1, 1);

        btnRemoveOrder = new QToolButton(frame);
        btnRemoveOrder->setObjectName(QString::fromUtf8("btnRemoveOrder"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemoveOrder->setIcon(icon2);
        btnRemoveOrder->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnRemoveOrder, 1, 1, 1, 1);

        btnChangePassword = new QToolButton(frame);
        btnChangePassword->setObjectName(QString::fromUtf8("btnChangePassword"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChangePassword->setIcon(icon3);
        btnChangePassword->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnChangePassword, 2, 1, 1, 1);

        btnComplex = new QToolButton(frame);
        btnComplex->setObjectName(QString::fromUtf8("btnComplex"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/dinner.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnComplex->setIcon(icon4);
        btnComplex->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnComplex, 0, 2, 1, 1);

        btnShowHideRemovedItems = new QToolButton(frame);
        btnShowHideRemovedItems->setObjectName(QString::fromUtf8("btnShowHideRemovedItems"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/basket.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnShowHideRemovedItems->setIcon(icon5);
        btnShowHideRemovedItems->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnShowHideRemovedItems, 0, 0, 1, 1);

        btnCompimentary = new QToolButton(frame);
        btnCompimentary->setObjectName(QString::fromUtf8("btnCompimentary"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/gift.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCompimentary->setIcon(icon6);
        btnCompimentary->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnCompimentary, 1, 2, 1, 1);

        btnTax = new QToolButton(frame);
        btnTax->setObjectName(QString::fromUtf8("btnTax"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/tax.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTax->setIcon(icon7);
        btnTax->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnTax, 2, 0, 1, 1);

        btnRecover = new QToolButton(frame);
        btnRecover->setObjectName(QString::fromUtf8("btnRecover"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/heart-pulses.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRecover->setIcon(icon8);
        btnRecover->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnRecover, 2, 2, 1, 1);

        btnPrintAnyReport = new QToolButton(frame);
        btnPrintAnyReport->setObjectName(QString::fromUtf8("btnPrintAnyReport"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/invoice.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrintAnyReport->setIcon(icon9);
        btnPrintAnyReport->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnPrintAnyReport, 3, 0, 1, 1);

        btnVoidBack = new QToolButton(frame);
        btnVoidBack->setObjectName(QString::fromUtf8("btnVoidBack"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/recycle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVoidBack->setIcon(icon10);
        btnVoidBack->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnVoidBack, 3, 1, 1, 1);

        btnPrintVoid = new QToolButton(frame);
        btnPrintVoid->setObjectName(QString::fromUtf8("btnPrintVoid"));
        btnPrintVoid->setIcon(icon10);
        btnPrintVoid->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnPrintVoid, 3, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(RTools);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btnExit = new QToolButton(frame_2);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon11);
        btnExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(btnExit, 1, 2, 1, 1);

        btnShowTableOrders = new QToolButton(frame_2);
        btnShowTableOrders->setObjectName(QString::fromUtf8("btnShowTableOrders"));
        btnShowTableOrders->setIcon(icon9);
        btnShowTableOrders->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(btnShowTableOrders, 0, 2, 1, 1);

        btnTotalReport = new QToolButton(frame_2);
        btnTotalReport->setObjectName(QString::fromUtf8("btnTotalReport"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/money_calculator.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTotalReport->setIcon(icon12);
        btnTotalReport->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(btnTotalReport, 0, 0, 1, 1);

        btnTotalYesterday = new QToolButton(frame_2);
        btnTotalYesterday->setObjectName(QString::fromUtf8("btnTotalYesterday"));
        btnTotalYesterday->setIcon(icon12);
        btnTotalYesterday->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(btnTotalYesterday, 0, 1, 1, 1);

        btnShowNyTotal = new QToolButton(frame_2);
        btnShowNyTotal->setObjectName(QString::fromUtf8("btnShowNyTotal"));
        btnShowNyTotal->setIcon(icon12);
        btnShowNyTotal->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(btnShowNyTotal, 1, 1, 1, 1);

        btnTotalReportAnyDay = new QToolButton(frame_2);
        btnTotalReportAnyDay->setObjectName(QString::fromUtf8("btnTotalReportAnyDay"));
        btnTotalReportAnyDay->setIcon(icon12);
        btnTotalReportAnyDay->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout_2->addWidget(btnTotalReportAnyDay, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        verticalLayout->addWidget(frame_2);


        retranslateUi(RTools);

        QMetaObject::connectSlotsByName(RTools);
    } // setupUi

    void retranslateUi(QDialog *RTools)
    {
        RTools->setWindowTitle(QCoreApplication::translate("RTools", "Tools", nullptr));
        label_2->setText(QCoreApplication::translate("RTools", "Actions", nullptr));
        btnMoveTable->setText(QCoreApplication::translate("RTools", "Move\n"
"table", nullptr));
        btnOrderComment->setText(QCoreApplication::translate("RTools", "Order\n"
"comment", nullptr));
        btnRemoveOrder->setText(QCoreApplication::translate("RTools", "Remove\n"
"order", nullptr));
        btnChangePassword->setText(QCoreApplication::translate("RTools", "Change my\n"
"password", nullptr));
        btnComplex->setText(QCoreApplication::translate("RTools", "Add complex", nullptr));
        btnShowHideRemovedItems->setText(QCoreApplication::translate("RTools", "Show / hide\n"
"removed items", nullptr));
        btnCompimentary->setText(QCoreApplication::translate("RTools", "Complimentary", nullptr));
        btnTax->setText(QCoreApplication::translate("RTools", "Print tax", nullptr));
        btnRecover->setText(QCoreApplication::translate("RTools", "Recover", nullptr));
        btnPrintAnyReport->setText(QCoreApplication::translate("RTools", "Print receipt\n"
"by number", nullptr));
        btnVoidBack->setText(QCoreApplication::translate("RTools", "Void Back", nullptr));
        btnPrintVoid->setText(QCoreApplication::translate("RTools", "Print void\n"
"report", nullptr));
        label->setText(QCoreApplication::translate("RTools", "Reports", nullptr));
        btnExit->setText(QCoreApplication::translate("RTools", "Exit", nullptr));
        btnShowTableOrders->setText(QCoreApplication::translate("RTools", "Show table\n"
"orders", nullptr));
        btnTotalReport->setText(QCoreApplication::translate("RTools", "Total, Today", nullptr));
        btnTotalYesterday->setText(QCoreApplication::translate("RTools", "Total, Yesterday", nullptr));
        btnShowNyTotal->setText(QCoreApplication::translate("RTools", "Show my total", nullptr));
        btnTotalReportAnyDay->setText(QCoreApplication::translate("RTools", "Total, Any day", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RTools: public Ui_RTools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTOOLS_H
