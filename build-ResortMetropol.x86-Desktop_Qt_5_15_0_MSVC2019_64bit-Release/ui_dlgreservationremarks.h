/********************************************************************************
** Form generated from reading UI file 'dlgreservationremarks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGRESERVATIONREMARKS_H
#define UI_DLGRESERVATIONREMARKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgReservationRemarks
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTextEdit *teText;
    QPushButton *btnRemoveSelected;
    QPushButton *btnSaveAs;
    QPushButton *btnSaveCurrent;
    EQTableWidget *tblData;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DlgReservationRemarks)
    {
        if (DlgReservationRemarks->objectName().isEmpty())
            DlgReservationRemarks->setObjectName(QString::fromUtf8("DlgReservationRemarks"));
        DlgReservationRemarks->resize(587, 477);
        gridLayout = new QGridLayout(DlgReservationRemarks);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgReservationRemarks);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        teText = new QTextEdit(DlgReservationRemarks);
        teText->setObjectName(QString::fromUtf8("teText"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(teText->sizePolicy().hasHeightForWidth());
        teText->setSizePolicy(sizePolicy);

        gridLayout->addWidget(teText, 1, 0, 1, 5);

        btnRemoveSelected = new QPushButton(DlgReservationRemarks);
        btnRemoveSelected->setObjectName(QString::fromUtf8("btnRemoveSelected"));

        gridLayout->addWidget(btnRemoveSelected, 2, 0, 1, 1);

        btnSaveAs = new QPushButton(DlgReservationRemarks);
        btnSaveAs->setObjectName(QString::fromUtf8("btnSaveAs"));

        gridLayout->addWidget(btnSaveAs, 2, 3, 1, 1);

        btnSaveCurrent = new QPushButton(DlgReservationRemarks);
        btnSaveCurrent->setObjectName(QString::fromUtf8("btnSaveCurrent"));

        gridLayout->addWidget(btnSaveCurrent, 2, 4, 1, 1);

        tblData = new EQTableWidget(DlgReservationRemarks);
        if (tblData->columnCount() < 2)
            tblData->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tblData->setObjectName(QString::fromUtf8("tblData"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(4);
        sizePolicy1.setHeightForWidth(tblData->sizePolicy().hasHeightForWidth());
        tblData->setSizePolicy(sizePolicy1);
        tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tblData->setSelectionMode(QAbstractItemView::NoSelection);
        tblData->horizontalHeader()->setVisible(false);
        tblData->verticalHeader()->setVisible(false);
        tblData->verticalHeader()->setDefaultSectionSize(50);

        gridLayout->addWidget(tblData, 3, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(162, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        btnOk = new QPushButton(DlgReservationRemarks);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        gridLayout->addWidget(btnOk, 4, 1, 1, 1);

        btnCancel = new QPushButton(DlgReservationRemarks);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 4, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 3, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 1, 1, 2);


        retranslateUi(DlgReservationRemarks);

        QMetaObject::connectSlotsByName(DlgReservationRemarks);
    } // setupUi

    void retranslateUi(QDialog *DlgReservationRemarks)
    {
        DlgReservationRemarks->setWindowTitle(QCoreApplication::translate("DlgReservationRemarks", "Remarks templates", nullptr));
        label->setText(QCoreApplication::translate("DlgReservationRemarks", "Current remark", nullptr));
        btnRemoveSelected->setText(QCoreApplication::translate("DlgReservationRemarks", "Remove selected", nullptr));
        btnSaveAs->setText(QCoreApplication::translate("DlgReservationRemarks", "Save as new", nullptr));
        btnSaveCurrent->setText(QCoreApplication::translate("DlgReservationRemarks", "Update current", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgReservationRemarks", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgReservationRemarks", "New Column", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgReservationRemarks", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgReservationRemarks", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgReservationRemarks: public Ui_DlgReservationRemarks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGRESERVATIONREMARKS_H
