/********************************************************************************
** Form generated from reading UI file 'fsalary.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FSALARY_H
#define UI_FSALARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FSalary
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QLabel *label_3;
    EQLineEdit *leEmploye;
    EQLineEdit *leEmployeName;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FSalary)
    {
        if (FSalary->objectName().isEmpty())
            FSalary->setObjectName(QString::fromUtf8("FSalary"));
        FSalary->resize(957, 41);
        horizontalLayout = new QHBoxLayout(FSalary);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FSalary);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(FSalary);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FSalary);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FSalary);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        label_3 = new QLabel(FSalary);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leEmploye = new EQLineEdit(FSalary);
        leEmploye->setObjectName(QString::fromUtf8("leEmploye"));
        leEmploye->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(leEmploye);

        leEmployeName = new EQLineEdit(FSalary);
        leEmployeName->setObjectName(QString::fromUtf8("leEmployeName"));
        leEmployeName->setEnabled(false);

        horizontalLayout->addWidget(leEmployeName);

        horizontalSpacer = new QSpacerItem(174, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FSalary);

        QMetaObject::connectSlotsByName(FSalary);
    } // setupUi

    void retranslateUi(QWidget *FSalary)
    {
        FSalary->setWindowTitle(QCoreApplication::translate("FSalary", "Form", nullptr));
        label->setText(QCoreApplication::translate("FSalary", "Date start", nullptr));
        label_2->setText(QCoreApplication::translate("FSalary", "Date end", nullptr));
        label_3->setText(QCoreApplication::translate("FSalary", "Employee", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FSalary: public Ui_FSalary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSALARY_H
