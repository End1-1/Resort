/********************************************************************************
** Form generated from reading UI file 'reresttable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTTABLE_H
#define UI_RERESTTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERestTable
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    EQLineEdit *leHallCode;
    QLabel *label_3;
    QLabel *label_4;
    EQLineEdit *leHallName;
    EQLineEdit *leCode;
    EQLineEdit *leName;
    EQLineEdit *leQueue;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RERestTable)
    {
        if (RERestTable->objectName().isEmpty())
            RERestTable->setObjectName(QString::fromUtf8("RERestTable"));
        RERestTable->resize(346, 165);
        verticalLayout = new QVBoxLayout(RERestTable);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RERestTable);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(RERestTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leHallCode = new EQLineEdit(RERestTable);
        leHallCode->setObjectName(QString::fromUtf8("leHallCode"));
        leHallCode->setMaximumSize(QSize(80, 16777215));
        leHallCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leHallCode, 2, 1, 1, 1);

        label_3 = new QLabel(RERestTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(RERestTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leHallName = new EQLineEdit(RERestTable);
        leHallName->setObjectName(QString::fromUtf8("leHallName"));
        leHallName->setReadOnly(true);

        gridLayout->addWidget(leHallName, 2, 2, 1, 1);

        leCode = new EQLineEdit(RERestTable);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 2);

        leName = new EQLineEdit(RERestTable);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 2);

        leQueue = new EQLineEdit(RERestTable);
        leQueue->setObjectName(QString::fromUtf8("leQueue"));

        gridLayout->addWidget(leQueue, 3, 1, 1, 2);

        widget = new QWidget(RERestTable);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(146, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(RERestTable);

        QMetaObject::connectSlotsByName(RERestTable);
    } // setupUi

    void retranslateUi(QDialog *RERestTable)
    {
        RERestTable->setWindowTitle(QCoreApplication::translate("RERestTable", "Table", nullptr));
        label->setText(QCoreApplication::translate("RERestTable", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("RERestTable", "Name", nullptr));
        leHallCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestTable", "f_hall", nullptr)));
        label_3->setText(QCoreApplication::translate("RERestTable", "Hall", nullptr));
        label_4->setText(QCoreApplication::translate("RERestTable", "Queue", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestTable", "f_id", nullptr)));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RERestTable", "f_name", nullptr)));
        leQueue->setProperty("Field", QVariant(QCoreApplication::translate("RERestTable", "f_queue", nullptr)));
        btnOk->setText(QCoreApplication::translate("RERestTable", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestTable", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERestTable: public Ui_RERestTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTTABLE_H
