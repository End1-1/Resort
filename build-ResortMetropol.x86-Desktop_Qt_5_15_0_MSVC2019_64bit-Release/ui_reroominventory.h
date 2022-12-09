/********************************************************************************
** Form generated from reading UI file 'reroominventory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REROOMINVENTORY_H
#define UI_REROOMINVENTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERoomInventory
{
public:
    QGridLayout *gridLayout;
    EQLineEdit *leName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    EQLineEdit *leCode;
    QLabel *label_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *lst;

    void setupUi(QDialog *RERoomInventory)
    {
        if (RERoomInventory->objectName().isEmpty())
            RERoomInventory->setObjectName(QString::fromUtf8("RERoomInventory"));
        RERoomInventory->resize(400, 472);
        gridLayout = new QGridLayout(RERoomInventory);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leName = new EQLineEdit(RERoomInventory);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        widget = new QWidget(RERoomInventory);
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


        gridLayout->addWidget(widget, 3, 0, 1, 2);

        label = new QLabel(RERoomInventory);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(RERoomInventory);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(RERoomInventory);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        widget_2 = new QWidget(RERoomInventory);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lst = new QListWidget(widget_2);
        lst->setObjectName(QString::fromUtf8("lst"));

        horizontalLayout_2->addWidget(lst);


        gridLayout->addWidget(widget_2, 2, 0, 1, 2);


        retranslateUi(RERoomInventory);

        QMetaObject::connectSlotsByName(RERoomInventory);
    } // setupUi

    void retranslateUi(QDialog *RERoomInventory)
    {
        RERoomInventory->setWindowTitle(QCoreApplication::translate("RERoomInventory", "Room inventory", nullptr));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RERoomInventory", "f_name", nullptr)));
        btnSave->setText(QCoreApplication::translate("RERoomInventory", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERoomInventory", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("RERoomInventory", "Code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERoomInventory", "f_id", nullptr)));
        label_2->setText(QCoreApplication::translate("RERoomInventory", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERoomInventory: public Ui_RERoomInventory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REROOMINVENTORY_H
