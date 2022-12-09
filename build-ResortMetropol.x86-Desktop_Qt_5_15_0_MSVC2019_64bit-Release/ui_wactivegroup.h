/********************************************************************************
** Form generated from reading UI file 'wactivegroup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WACTIVEGROUP_H
#define UI_WACTIVEGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WActiveGroup
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EQLineEdit *leGroup;
    EQLineEdit *leGroupName;

    void setupUi(QWidget *WActiveGroup)
    {
        if (WActiveGroup->objectName().isEmpty())
            WActiveGroup->setObjectName(QString::fromUtf8("WActiveGroup"));
        WActiveGroup->resize(391, 20);
        WActiveGroup->setMaximumSize(QSize(430, 16777215));
        horizontalLayout = new QHBoxLayout(WActiveGroup);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(WActiveGroup);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        leGroup = new EQLineEdit(WActiveGroup);
        leGroup->setObjectName(QString::fromUtf8("leGroup"));
        leGroup->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(leGroup);

        leGroupName = new EQLineEdit(WActiveGroup);
        leGroupName->setObjectName(QString::fromUtf8("leGroupName"));
        leGroupName->setMinimumSize(QSize(300, 0));
        leGroupName->setMaximumSize(QSize(300, 16777215));
        leGroupName->setReadOnly(true);

        horizontalLayout->addWidget(leGroupName);


        retranslateUi(WActiveGroup);

        QMetaObject::connectSlotsByName(WActiveGroup);
    } // setupUi

    void retranslateUi(QWidget *WActiveGroup)
    {
        WActiveGroup->setWindowTitle(QCoreApplication::translate("WActiveGroup", "Form", nullptr));
        label->setText(QCoreApplication::translate("WActiveGroup", "Group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WActiveGroup: public Ui_WActiveGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WACTIVEGROUP_H
