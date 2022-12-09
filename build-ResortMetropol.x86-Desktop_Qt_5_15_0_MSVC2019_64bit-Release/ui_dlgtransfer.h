/********************************************************************************
** Form generated from reading UI file 'dlgtransfer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTRANSFER_H
#define UI_DLGTRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eqlineedit.h>
#include <eqtextedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgTransfer
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    EQLineEdit *leRoomCodeFrom;
    EQLineEdit *leRoomNameFrom;
    EQLineEdit *leInvoiceFrom;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    EQLineEdit *leReserveFrom;
    EQLineEdit *leGuestFrom;
    QTableWidget *tblData;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    EQLineEdit *leRoomNameTo;
    QLabel *label_4;
    QLabel *label_5;
    EQLineEdit *leRoomCodeTo;
    EQLineEdit *leInvoiceTo;
    EQLineEdit *leReserveTo;
    EQLineEdit *leGuestTo;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    EQTextEdit *teRemark;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    EQCheckBox *chGuest;
    EQCheckBox *chCompany;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgTransfer)
    {
        if (DlgTransfer->objectName().isEmpty())
            DlgTransfer->setObjectName(QString::fromUtf8("DlgTransfer"));
        DlgTransfer->resize(524, 567);
        verticalLayout = new QVBoxLayout(DlgTransfer);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DlgTransfer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        leRoomCodeFrom = new EQLineEdit(groupBox);
        leRoomCodeFrom->setObjectName(QString::fromUtf8("leRoomCodeFrom"));
        leRoomCodeFrom->setMaximumSize(QSize(70, 16777215));

        gridLayout_2->addWidget(leRoomCodeFrom, 0, 1, 1, 1);

        leRoomNameFrom = new EQLineEdit(groupBox);
        leRoomNameFrom->setObjectName(QString::fromUtf8("leRoomNameFrom"));
        leRoomNameFrom->setReadOnly(true);

        gridLayout_2->addWidget(leRoomNameFrom, 0, 3, 1, 1);

        leInvoiceFrom = new EQLineEdit(groupBox);
        leInvoiceFrom->setObjectName(QString::fromUtf8("leInvoiceFrom"));

        gridLayout_2->addWidget(leInvoiceFrom, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        leReserveFrom = new EQLineEdit(groupBox);
        leReserveFrom->setObjectName(QString::fromUtf8("leReserveFrom"));

        gridLayout_2->addWidget(leReserveFrom, 0, 4, 1, 1);

        leGuestFrom = new EQLineEdit(groupBox);
        leGuestFrom->setObjectName(QString::fromUtf8("leGuestFrom"));
        leGuestFrom->setReadOnly(true);

        gridLayout_2->addWidget(leGuestFrom, 1, 1, 1, 4);

        tblData = new QTableWidget(groupBox);
        if (tblData->columnCount() < 4)
            tblData->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        tblData->setMinimumSize(QSize(0, 200));
        tblData->setMaximumSize(QSize(16777215, 200));
        tblData->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);

        gridLayout_2->addWidget(tblData, 2, 1, 1, 4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(DlgTransfer);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leRoomNameTo = new EQLineEdit(groupBox_2);
        leRoomNameTo->setObjectName(QString::fromUtf8("leRoomNameTo"));
        leRoomNameTo->setReadOnly(true);

        gridLayout->addWidget(leRoomNameTo, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        leRoomCodeTo = new EQLineEdit(groupBox_2);
        leRoomCodeTo->setObjectName(QString::fromUtf8("leRoomCodeTo"));
        leRoomCodeTo->setMaximumSize(QSize(70, 16777215));
        leRoomCodeTo->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leRoomCodeTo, 0, 1, 1, 1);

        leInvoiceTo = new EQLineEdit(groupBox_2);
        leInvoiceTo->setObjectName(QString::fromUtf8("leInvoiceTo"));

        gridLayout->addWidget(leInvoiceTo, 0, 2, 1, 1);

        leReserveTo = new EQLineEdit(groupBox_2);
        leReserveTo->setObjectName(QString::fromUtf8("leReserveTo"));

        gridLayout->addWidget(leReserveTo, 0, 4, 1, 1);

        leGuestTo = new EQLineEdit(groupBox_2);
        leGuestTo->setObjectName(QString::fromUtf8("leGuestTo"));
        leGuestTo->setReadOnly(true);

        gridLayout->addWidget(leGuestTo, 1, 1, 1, 4);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(DlgTransfer);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        teRemark = new EQTextEdit(groupBox_3);
        teRemark->setObjectName(QString::fromUtf8("teRemark"));
        teRemark->setMinimumSize(QSize(0, 50));
        teRemark->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(teRemark);


        verticalLayout->addWidget(groupBox_3);

        widget_2 = new QWidget(DlgTransfer);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        chGuest = new EQCheckBox(widget_2);
        chGuest->setObjectName(QString::fromUtf8("chGuest"));
        chGuest->setChecked(true);

        horizontalLayout_3->addWidget(chGuest);

        chCompany = new EQCheckBox(widget_2);
        chCompany->setObjectName(QString::fromUtf8("chCompany"));

        horizontalLayout_3->addWidget(chCompany);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(DlgTransfer);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(66, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setEnabled(false);
        btnOk->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(66, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgTransfer);

        QMetaObject::connectSlotsByName(DlgTransfer);
    } // setupUi

    void retranslateUi(QDialog *DlgTransfer)
    {
        DlgTransfer->setWindowTitle(QCoreApplication::translate("DlgTransfer", "Transfer", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgTransfer", "From", nullptr));
        label_2->setText(QCoreApplication::translate("DlgTransfer", "Guest", nullptr));
        label->setText(QCoreApplication::translate("DlgTransfer", "Room", nullptr));
        label_3->setText(QCoreApplication::translate("DlgTransfer", "Entries", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgTransfer", "RecId", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgTransfer", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tblData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgTransfer", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tblData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgTransfer", "Amount", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DlgTransfer", "To", nullptr));
        label_4->setText(QCoreApplication::translate("DlgTransfer", "Room", nullptr));
        label_5->setText(QCoreApplication::translate("DlgTransfer", "Guest", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DlgTransfer", "Remarks", nullptr));
        chGuest->setText(QCoreApplication::translate("DlgTransfer", "Guest", nullptr));
        chCompany->setText(QCoreApplication::translate("DlgTransfer", "Company", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgTransfer", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgTransfer", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgTransfer: public Ui_DlgTransfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTRANSFER_H
