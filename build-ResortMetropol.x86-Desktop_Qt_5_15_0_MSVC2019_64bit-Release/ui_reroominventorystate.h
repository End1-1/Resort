/********************************************************************************
** Form generated from reading UI file 'reroominventorystate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REROOMINVENTORYSTATE_H
#define UI_REROOMINVENTORYSTATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERoomInventoryState
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leCode;
    QLabel *label_2;
    EQLineEdit *leName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RERoomInventoryState)
    {
        if (RERoomInventoryState->objectName().isEmpty())
            RERoomInventoryState->setObjectName(QString::fromUtf8("RERoomInventoryState"));
        RERoomInventoryState->resize(388, 111);
        gridLayout = new QGridLayout(RERoomInventoryState);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RERoomInventoryState);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(RERoomInventoryState);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(RERoomInventoryState);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leName = new EQLineEdit(RERoomInventoryState);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        widget = new QWidget(RERoomInventoryState);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);


        retranslateUi(RERoomInventoryState);

        QMetaObject::connectSlotsByName(RERoomInventoryState);
    } // setupUi

    void retranslateUi(QDialog *RERoomInventoryState)
    {
        RERoomInventoryState->setWindowTitle(QCoreApplication::translate("RERoomInventoryState", "Room inventory state", nullptr));
        label->setText(QCoreApplication::translate("RERoomInventoryState", "Code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERoomInventoryState", "f_id", nullptr)));
        label_2->setText(QCoreApplication::translate("RERoomInventoryState", "Name", nullptr));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RERoomInventoryState", "f_name", nullptr)));
        btnSave->setText(QCoreApplication::translate("RERoomInventoryState", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERoomInventoryState", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERoomInventoryState: public Ui_RERoomInventoryState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REROOMINVENTORYSTATE_H
