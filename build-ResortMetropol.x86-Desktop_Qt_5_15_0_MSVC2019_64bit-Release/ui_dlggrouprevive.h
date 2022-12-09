/********************************************************************************
** Form generated from reading UI file 'dlggrouprevive.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGGROUPREVIVE_H
#define UI_DLGGROUPREVIVE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgGroupRevive
{
public:
    QVBoxLayout *verticalLayout;
    EQTableWidget *tbl;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRevive;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgGroupRevive)
    {
        if (DlgGroupRevive->objectName().isEmpty())
            DlgGroupRevive->setObjectName(QString::fromUtf8("DlgGroupRevive"));
        DlgGroupRevive->resize(1023, 552);
        verticalLayout = new QVBoxLayout(DlgGroupRevive);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tbl = new EQTableWidget(DlgGroupRevive);
        if (tbl->columnCount() < 7)
            tbl->setColumnCount(7);
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
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tbl->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(tbl);

        widget = new QWidget(DlgGroupRevive);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(407, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnRevive = new QPushButton(widget);
        btnRevive->setObjectName(QString::fromUtf8("btnRevive"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/heart-pulses.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRevive->setIcon(icon);

        horizontalLayout->addWidget(btnRevive);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(406, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgGroupRevive);

        QMetaObject::connectSlotsByName(DlgGroupRevive);
    } // setupUi

    void retranslateUi(QDialog *DlgGroupRevive)
    {
        DlgGroupRevive->setWindowTitle(QCoreApplication::translate("DlgGroupRevive", "Revive reservations", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgGroupRevive", "Code", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgGroupRevive", "Room", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgGroupRevive", "Entry", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgGroupRevive", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tbl->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("DlgGroupRevive", "Guest", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tbl->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("DlgGroupRevive", "Info", nullptr));
        btnRevive->setText(QCoreApplication::translate("DlgGroupRevive", "Revive", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgGroupRevive", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgGroupRevive: public Ui_DlgGroupRevive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGGROUPREVIVE_H
