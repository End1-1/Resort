/********************************************************************************
** Form generated from reading UI file 'ftaxreport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTAXREPORT_H
#define UI_FTAXREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FTaxReport
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chCanceled;

    void setupUi(QWidget *FTaxReport)
    {
        if (FTaxReport->objectName().isEmpty())
            FTaxReport->setObjectName(QString::fromUtf8("FTaxReport"));
        FTaxReport->resize(358, 23);
        horizontalLayout = new QHBoxLayout(FTaxReport);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wd = new WDate2(FTaxReport);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        horizontalSpacer = new QSpacerItem(266, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chCanceled = new QCheckBox(FTaxReport);
        chCanceled->setObjectName(QString::fromUtf8("chCanceled"));

        horizontalLayout->addWidget(chCanceled);


        retranslateUi(FTaxReport);

        QMetaObject::connectSlotsByName(FTaxReport);
    } // setupUi

    void retranslateUi(QWidget *FTaxReport)
    {
        FTaxReport->setWindowTitle(QCoreApplication::translate("FTaxReport", "Form", nullptr));
        chCanceled->setText(QCoreApplication::translate("FTaxReport", "Canceled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTaxReport: public Ui_FTaxReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTAXREPORT_H
