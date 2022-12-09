/********************************************************************************
** Form generated from reading UI file 'dlggposorderinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGGPOSORDERINFO_H
#define UI_DLGGPOSORDERINFO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgGPOSOrderInfo
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *leOrder;
    EDateEdit *deDate;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *lbComment;
    QPushButton *btnTracking;
    QLabel *label_4;
    QLineEdit *lePaymentName;
    QLineEdit *lePaymentComment;
    EQLineEdit *lePayment;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *leStaff;
    QLineEdit *leComment;
    EQTableWidget *tblData;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    EQLineEdit *leCardAmount;
    QLabel *label;
    EQLineEdit *leTotal;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnPrint;
    QPushButton *btnPrintTax;
    QPushButton *btnOk;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgGPOSOrderInfo)
    {
        if (DlgGPOSOrderInfo->objectName().isEmpty())
            DlgGPOSOrderInfo->setObjectName(QString::fromUtf8("DlgGPOSOrderInfo"));
        DlgGPOSOrderInfo->resize(917, 511);
        verticalLayout = new QVBoxLayout(DlgGPOSOrderInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_3 = new QWidget(DlgGPOSOrderInfo);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        leOrder = new QLineEdit(widget_3);
        leOrder->setObjectName(QString::fromUtf8("leOrder"));
        leOrder->setMinimumSize(QSize(150, 0));
        leOrder->setMaximumSize(QSize(150, 16777215));
        leOrder->setReadOnly(true);

        gridLayout->addWidget(leOrder, 0, 2, 1, 1);

        deDate = new EDateEdit(widget_3);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMinimumSize(QSize(100, 0));
        deDate->setMaximumSize(QSize(100, 16777215));
        deDate->setReadOnly(true);

        gridLayout->addWidget(deDate, 0, 4, 1, 1);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 3, 1, 1);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        lbComment = new QLabel(widget_3);
        lbComment->setObjectName(QString::fromUtf8("lbComment"));

        gridLayout->addWidget(lbComment, 2, 3, 1, 1);

        btnTracking = new QPushButton(widget_3);
        btnTracking->setObjectName(QString::fromUtf8("btnTracking"));
        btnTracking->setMinimumSize(QSize(25, 25));
        btnTracking->setMaximumSize(QSize(25, 25));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tracking.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTracking->setIcon(icon);

        gridLayout->addWidget(btnTracking, 0, 8, 1, 1);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lePaymentName = new QLineEdit(widget_3);
        lePaymentName->setObjectName(QString::fromUtf8("lePaymentName"));
        lePaymentName->setEnabled(true);
        lePaymentName->setReadOnly(true);

        gridLayout->addWidget(lePaymentName, 1, 5, 1, 2);

        lePaymentComment = new QLineEdit(widget_3);
        lePaymentComment->setObjectName(QString::fromUtf8("lePaymentComment"));
        lePaymentComment->setEnabled(true);
        lePaymentComment->setReadOnly(true);

        gridLayout->addWidget(lePaymentComment, 2, 4, 1, 3);

        lePayment = new EQLineEdit(widget_3);
        lePayment->setObjectName(QString::fromUtf8("lePayment"));
        lePayment->setMinimumSize(QSize(30, 0));
        lePayment->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(lePayment, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(227, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 7, 1, 1);

        leStaff = new QLineEdit(widget_3);
        leStaff->setObjectName(QString::fromUtf8("leStaff"));
        leStaff->setReadOnly(true);

        gridLayout->addWidget(leStaff, 1, 2, 1, 1);

        leComment = new QLineEdit(widget_3);
        leComment->setObjectName(QString::fromUtf8("leComment"));
        leComment->setReadOnly(true);

        gridLayout->addWidget(leComment, 2, 2, 1, 1);


        verticalLayout->addWidget(widget_3);

        tblData = new EQTableWidget(DlgGPOSOrderInfo);
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

        verticalLayout->addWidget(tblData);

        widget_2 = new QWidget(DlgGPOSOrderInfo);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(537, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        leCardAmount = new EQLineEdit(widget_2);
        leCardAmount->setObjectName(QString::fromUtf8("leCardAmount"));
        leCardAmount->setMinimumSize(QSize(80, 0));
        leCardAmount->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(leCardAmount);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        leTotal = new EQLineEdit(widget_2);
        leTotal->setObjectName(QString::fromUtf8("leTotal"));
        leTotal->setMinimumSize(QSize(80, 0));
        leTotal->setMaximumSize(QSize(80, 16777215));
        leTotal->setReadOnly(true);

        horizontalLayout_2->addWidget(leTotal);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(DlgGPOSOrderInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(282, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnPrint = new QPushButton(widget);
        btnPrint->setObjectName(QString::fromUtf8("btnPrint"));

        horizontalLayout->addWidget(btnPrint);

        btnPrintTax = new QPushButton(widget);
        btnPrintTax->setObjectName(QString::fromUtf8("btnPrintTax"));

        horizontalLayout->addWidget(btnPrintTax);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        horizontalSpacer_2 = new QSpacerItem(281, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgGPOSOrderInfo);

        QMetaObject::connectSlotsByName(DlgGPOSOrderInfo);
    } // setupUi

    void retranslateUi(QDialog *DlgGPOSOrderInfo)
    {
        DlgGPOSOrderInfo->setWindowTitle(QCoreApplication::translate("DlgGPOSOrderInfo", "Order", nullptr));
        label_3->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Order S/N", nullptr));
        label_7->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Comment", nullptr));
        label_5->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Mode of payment", nullptr));
        label_2->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Date", nullptr));
        lbComment->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Payment comment", nullptr));
        btnTracking->setText(QString());
        label_4->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Staff", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Qty", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tblData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Adgt", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tblData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "DishId", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tblData->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tblData->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "History", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tblData->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Complex", nullptr));
        label_6->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Card amount for tax", nullptr));
        label->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Total", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Save", nullptr));
        btnPrint->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Print Receipt", nullptr));
        btnPrintTax->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Print Tax", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgGPOSOrderInfo", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgGPOSOrderInfo: public Ui_DlgGPOSOrderInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGGPOSORDERINFO_H
