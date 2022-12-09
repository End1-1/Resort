/********************************************************************************
** Form generated from reading UI file 'fcashreportbyitem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCASHREPORTBYITEM_H
#define UI_FCASHREPORTBYITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FCashReportByItem
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    EQLineEdit *leOperator;
    EQLineEdit *leOperatorName;

    void setupUi(QWidget *FCashReportByItem)
    {
        if (FCashReportByItem->objectName().isEmpty())
            FCashReportByItem->setObjectName(QString::fromUtf8("FCashReportByItem"));
        FCashReportByItem->resize(657, 23);
        horizontalLayout = new QHBoxLayout(FCashReportByItem);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wd = new WDate2(FCashReportByItem);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(247, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(FCashReportByItem);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leOperator = new EQLineEdit(FCashReportByItem);
        leOperator->setObjectName(QString::fromUtf8("leOperator"));
        leOperator->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(leOperator);

        leOperatorName = new EQLineEdit(FCashReportByItem);
        leOperatorName->setObjectName(QString::fromUtf8("leOperatorName"));
        leOperatorName->setReadOnly(true);

        horizontalLayout->addWidget(leOperatorName);


        retranslateUi(FCashReportByItem);

        QMetaObject::connectSlotsByName(FCashReportByItem);
    } // setupUi

    void retranslateUi(QWidget *FCashReportByItem)
    {
        FCashReportByItem->setWindowTitle(QCoreApplication::translate("FCashReportByItem", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("FCashReportByItem", "Operator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCashReportByItem: public Ui_FCashReportByItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCASHREPORTBYITEM_H
