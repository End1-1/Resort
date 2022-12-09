/********************************************************************************
** Form generated from reading UI file 'dlggroupreserveoption.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGGROUPRESERVEOPTION_H
#define UI_DLGGROUPRESERVEOPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgGroupReserveOption
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *bgtnRemoveFromGroup;
    EQLineEdit *leGroupName;
    QSpacerItem *horizontalSpacer;
    EQLineEdit *leGroupCode;
    QPushButton *btnAddToGroup;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *leReservation;
    QLineEdit *leGuest;
    QLabel *label_4;
    QLineEdit *leRoom;

    void setupUi(QDialog *DlgGroupReserveOption)
    {
        if (DlgGroupReserveOption->objectName().isEmpty())
            DlgGroupReserveOption->setObjectName(QString::fromUtf8("DlgGroupReserveOption"));
        DlgGroupReserveOption->resize(490, 111);
        verticalLayout = new QVBoxLayout(DlgGroupReserveOption);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(DlgGroupReserveOption);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        bgtnRemoveFromGroup = new QPushButton(widget);
        bgtnRemoveFromGroup->setObjectName(QString::fromUtf8("bgtnRemoveFromGroup"));

        gridLayout->addWidget(bgtnRemoveFromGroup, 2, 4, 1, 1);

        leGroupName = new EQLineEdit(widget);
        leGroupName->setObjectName(QString::fromUtf8("leGroupName"));
        leGroupName->setEnabled(false);

        gridLayout->addWidget(leGroupName, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(36, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 5, 1, 1);

        leGroupCode = new EQLineEdit(widget);
        leGroupCode->setObjectName(QString::fromUtf8("leGroupCode"));
        leGroupCode->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(leGroupCode, 2, 1, 1, 1);

        btnAddToGroup = new QPushButton(widget);
        btnAddToGroup->setObjectName(QString::fromUtf8("btnAddToGroup"));

        gridLayout->addWidget(btnAddToGroup, 2, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        leReservation = new QLineEdit(widget);
        leReservation->setObjectName(QString::fromUtf8("leReservation"));
        leReservation->setEnabled(false);

        gridLayout->addWidget(leReservation, 0, 1, 1, 2);

        leGuest = new QLineEdit(widget);
        leGuest->setObjectName(QString::fromUtf8("leGuest"));
        leGuest->setEnabled(false);

        gridLayout->addWidget(leGuest, 1, 1, 1, 4);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        leRoom = new QLineEdit(widget);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setEnabled(false);

        gridLayout->addWidget(leRoom, 0, 4, 1, 1);


        verticalLayout->addWidget(widget);


        retranslateUi(DlgGroupReserveOption);

        QMetaObject::connectSlotsByName(DlgGroupReserveOption);
    } // setupUi

    void retranslateUi(QDialog *DlgGroupReserveOption)
    {
        DlgGroupReserveOption->setWindowTitle(QCoreApplication::translate("DlgGroupReserveOption", "Group options", nullptr));
        label->setText(QCoreApplication::translate("DlgGroupReserveOption", "Group", nullptr));
        bgtnRemoveFromGroup->setText(QCoreApplication::translate("DlgGroupReserveOption", "Remove from group", nullptr));
        btnAddToGroup->setText(QCoreApplication::translate("DlgGroupReserveOption", "Add to group", nullptr));
        label_2->setText(QCoreApplication::translate("DlgGroupReserveOption", "Reservation", nullptr));
        label_3->setText(QCoreApplication::translate("DlgGroupReserveOption", "Guest", nullptr));
        label_4->setText(QCoreApplication::translate("DlgGroupReserveOption", "Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgGroupReserveOption: public Ui_DlgGroupReserveOption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGGROUPRESERVEOPTION_H
