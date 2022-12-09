/********************************************************************************
** Form generated from reading UI file 'goexpextedarrivals.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOEXPEXTEDARRIVALS_H
#define UI_GOEXPEXTEDARRIVALS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GOExpextedArrivals
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbSort;

    void setupUi(QWidget *GOExpextedArrivals)
    {
        if (GOExpextedArrivals->objectName().isEmpty())
            GOExpextedArrivals->setObjectName(QString::fromUtf8("GOExpextedArrivals"));
        GOExpextedArrivals->resize(318, 20);
        horizontalLayout = new QHBoxLayout(GOExpextedArrivals);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(GOExpextedArrivals);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbSort = new QComboBox(GOExpextedArrivals);
        cbSort->addItem(QString());
        cbSort->addItem(QString());
        cbSort->setObjectName(QString::fromUtf8("cbSort"));

        horizontalLayout->addWidget(cbSort);


        retranslateUi(GOExpextedArrivals);

        QMetaObject::connectSlotsByName(GOExpextedArrivals);
    } // setupUi

    void retranslateUi(QWidget *GOExpextedArrivals)
    {
        GOExpextedArrivals->setWindowTitle(QCoreApplication::translate("GOExpextedArrivals", "Form", nullptr));
        label->setText(QCoreApplication::translate("GOExpextedArrivals", "Sort by", nullptr));
        cbSort->setItemText(0, QCoreApplication::translate("GOExpextedArrivals", "Arrival date, room, cardex", nullptr));
        cbSort->setItemText(1, QCoreApplication::translate("GOExpextedArrivals", "Arrival date, cardex, room", nullptr));

    } // retranslateUi

};

namespace Ui {
    class GOExpextedArrivals: public Ui_GOExpextedArrivals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOEXPEXTEDARRIVALS_H
