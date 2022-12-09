/********************************************************************************
** Form generated from reading UI file 'efilterlineedit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFILTERLINEEDIT_H
#define UI_EFILTERLINEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_EFilterLineEdit
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EQLineEdit *lineEdit;

    void setupUi(QWidget *EFilterLineEdit)
    {
        if (EFilterLineEdit->objectName().isEmpty())
            EFilterLineEdit->setObjectName(QString::fromUtf8("EFilterLineEdit"));
        EFilterLineEdit->resize(319, 38);
        horizontalLayout = new QHBoxLayout(EFilterLineEdit);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(EFilterLineEdit);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new EQLineEdit(EFilterLineEdit);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(EFilterLineEdit);

        QMetaObject::connectSlotsByName(EFilterLineEdit);
    } // setupUi

    void retranslateUi(QWidget *EFilterLineEdit)
    {
        EFilterLineEdit->setWindowTitle(QCoreApplication::translate("EFilterLineEdit", "Form", nullptr));
        label->setText(QCoreApplication::translate("EFilterLineEdit", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EFilterLineEdit: public Ui_EFilterLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFILTERLINEEDIT_H
