/********************************************************************************
** Form generated from reading UI file 'godaily.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GODAILY_H
#define UI_GODAILY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GODaily
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbSort;

    void setupUi(QWidget *GODaily)
    {
        if (GODaily->objectName().isEmpty())
            GODaily->setObjectName(QString::fromUtf8("GODaily"));
        GODaily->resize(402, 38);
        horizontalLayout = new QHBoxLayout(GODaily);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(GODaily);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbSort = new QComboBox(GODaily);
        cbSort->addItem(QString());
        cbSort->addItem(QString());
        cbSort->setObjectName(QString::fromUtf8("cbSort"));

        horizontalLayout->addWidget(cbSort);


        retranslateUi(GODaily);

        QMetaObject::connectSlotsByName(GODaily);
    } // setupUi

    void retranslateUi(QWidget *GODaily)
    {
        GODaily->setWindowTitle(QCoreApplication::translate("GODaily", "Form", nullptr));
        label->setText(QCoreApplication::translate("GODaily", "Sort by", nullptr));
        cbSort->setItemText(0, QCoreApplication::translate("GODaily", "Time, room", nullptr));
        cbSort->setItemText(1, QCoreApplication::translate("GODaily", "Room, time", nullptr));

    } // retranslateUi

};

namespace Ui {
    class GODaily: public Ui_GODaily {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GODAILY_H
