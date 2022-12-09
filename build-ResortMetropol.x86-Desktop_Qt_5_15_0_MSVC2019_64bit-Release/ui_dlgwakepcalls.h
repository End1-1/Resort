/********************************************************************************
** Form generated from reading UI file 'dlgwakepcalls.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGWAKEPCALLS_H
#define UI_DLGWAKEPCALLS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_DlgWakepCalls
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *leInvoice;
    QLabel *label;
    QLineEdit *leRoom;
    QLabel *label_2;
    QLineEdit *leGuest;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    EDateEdit *deDate;
    QLabel *label_5;
    QTimeEdit *teTime;
    QCheckBox *chEveryDay;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnAddWakeup;
    EQTableWidget *tbl;

    void setupUi(QDialog *DlgWakepCalls)
    {
        if (DlgWakepCalls->objectName().isEmpty())
            DlgWakepCalls->setObjectName(QString::fromUtf8("DlgWakepCalls"));
        DlgWakepCalls->resize(746, 613);
        verticalLayout = new QVBoxLayout(DlgWakepCalls);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgWakepCalls);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leInvoice = new QLineEdit(widget);
        leInvoice->setObjectName(QString::fromUtf8("leInvoice"));
        leInvoice->setMaximumSize(QSize(150, 16777215));
        leInvoice->setReadOnly(true);

        horizontalLayout->addWidget(leInvoice);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leRoom = new QLineEdit(widget);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setMaximumSize(QSize(100, 16777215));
        leRoom->setReadOnly(true);

        horizontalLayout->addWidget(leRoom);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        leGuest = new QLineEdit(widget);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setMaximumSize(QSize(300, 16777215));
        leGuest->setReadOnly(true);

        horizontalLayout->addWidget(leGuest);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        groupBox = new QGroupBox(DlgWakepCalls);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        deDate = new EDateEdit(groupBox);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(deDate);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        teTime = new QTimeEdit(groupBox);
        teTime->setObjectName(QString::fromUtf8("teTime"));

        horizontalLayout_2->addWidget(teTime);

        chEveryDay = new QCheckBox(groupBox);
        chEveryDay->setObjectName(QString::fromUtf8("chEveryDay"));
        chEveryDay->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(chEveryDay);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnAddWakeup = new QPushButton(groupBox);
        btnAddWakeup->setObjectName(QString::fromUtf8("btnAddWakeup"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddWakeup->setIcon(icon);

        horizontalLayout_2->addWidget(btnAddWakeup);


        verticalLayout->addWidget(groupBox);

        tbl = new EQTableWidget(DlgWakepCalls);
        if (tbl->columnCount() < 4)
            tbl->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tbl->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tbl->setObjectName(QString::fromUtf8("tbl"));
        tbl->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout->addWidget(tbl);


        retranslateUi(DlgWakepCalls);

        QMetaObject::connectSlotsByName(DlgWakepCalls);
    } // setupUi

    void retranslateUi(QDialog *DlgWakepCalls)
    {
        DlgWakepCalls->setWindowTitle(QCoreApplication::translate("DlgWakepCalls", "Wakeup call", nullptr));
        label_3->setText(QCoreApplication::translate("DlgWakepCalls", "Invoice", nullptr));
        label->setText(QCoreApplication::translate("DlgWakepCalls", "Room", nullptr));
        label_2->setText(QCoreApplication::translate("DlgWakepCalls", "Guest", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DlgWakepCalls", "GroupBox", nullptr));
        label_4->setText(QCoreApplication::translate("DlgWakepCalls", "Date", nullptr));
        label_5->setText(QCoreApplication::translate("DlgWakepCalls", "Time", nullptr));
        chEveryDay->setText(QCoreApplication::translate("DlgWakepCalls", "Every day", nullptr));
        btnAddWakeup->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("DlgWakepCalls", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("DlgWakepCalls", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("DlgWakepCalls", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("DlgWakepCalls", "Every day", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgWakepCalls: public Ui_DlgWakepCalls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGWAKEPCALLS_H
