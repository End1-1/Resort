/********************************************************************************
** Form generated from reading UI file 'wmaindeskfilterlist.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WMAINDESKFILTERLIST_H
#define UI_WMAINDESKFILTERLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WMainDeskFilterList
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *lstValues;

    void setupUi(QDialog *WMainDeskFilterList)
    {
        if (WMainDeskFilterList->objectName().isEmpty())
            WMainDeskFilterList->setObjectName(QString::fromUtf8("WMainDeskFilterList"));
        WMainDeskFilterList->resize(275, 417);
        verticalLayout = new QVBoxLayout(WMainDeskFilterList);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lstValues = new QListWidget(WMainDeskFilterList);
        lstValues->setObjectName(QString::fromUtf8("lstValues"));
        lstValues->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lstValues->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(lstValues);


        retranslateUi(WMainDeskFilterList);

        QMetaObject::connectSlotsByName(WMainDeskFilterList);
    } // setupUi

    void retranslateUi(QDialog *WMainDeskFilterList)
    {
        WMainDeskFilterList->setWindowTitle(QCoreApplication::translate("WMainDeskFilterList", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WMainDeskFilterList: public Ui_WMainDeskFilterList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WMAINDESKFILTERLIST_H
