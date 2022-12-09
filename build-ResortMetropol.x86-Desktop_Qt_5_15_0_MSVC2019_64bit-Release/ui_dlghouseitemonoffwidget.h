/********************************************************************************
** Form generated from reading UI file 'dlghouseitemonoffwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGHOUSEITEMONOFFWIDGET_H
#define UI_DLGHOUSEITEMONOFFWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgHouseItemOnOffWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOk;
    QPushButton *btnReady;

    void setupUi(QWidget *DlgHouseItemOnOffWidget)
    {
        if (DlgHouseItemOnOffWidget->objectName().isEmpty())
            DlgHouseItemOnOffWidget->setObjectName(QString::fromUtf8("DlgHouseItemOnOffWidget"));
        DlgHouseItemOnOffWidget->resize(156, 40);
        horizontalLayout = new QHBoxLayout(DlgHouseItemOnOffWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnOk = new QPushButton(DlgHouseItemOnOffWidget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setMinimumSize(QSize(0, 40));
        btnOk->setCheckable(true);

        horizontalLayout->addWidget(btnOk);

        btnReady = new QPushButton(DlgHouseItemOnOffWidget);
        btnReady->setObjectName(QString::fromUtf8("btnReady"));
        btnReady->setMinimumSize(QSize(0, 40));
        btnReady->setCheckable(true);

        horizontalLayout->addWidget(btnReady);


        retranslateUi(DlgHouseItemOnOffWidget);

        QMetaObject::connectSlotsByName(DlgHouseItemOnOffWidget);
    } // setupUi

    void retranslateUi(QWidget *DlgHouseItemOnOffWidget)
    {
        DlgHouseItemOnOffWidget->setWindowTitle(QCoreApplication::translate("DlgHouseItemOnOffWidget", "Form", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgHouseItemOnOffWidget", "OK", nullptr));
        btnReady->setText(QCoreApplication::translate("DlgHouseItemOnOffWidget", "Not ready", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgHouseItemOnOffWidget: public Ui_DlgHouseItemOnOffWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGHOUSEITEMONOFFWIDGET_H
