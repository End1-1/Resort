/********************************************************************************
** Form generated from reading UI file 'freportbypayment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREPORTBYPAYMENT_H
#define UI_FREPORTBYPAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FReportByPayment
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *leDateFrom;
    QLabel *label_2;
    EDateEdit *leDateTo;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FReportByPayment)
    {
        if (FReportByPayment->objectName().isEmpty())
            FReportByPayment->setObjectName(QString::fromUtf8("FReportByPayment"));
        FReportByPayment->resize(646, 41);
        horizontalLayout = new QHBoxLayout(FReportByPayment);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FReportByPayment);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leDateFrom = new EDateEdit(FReportByPayment);
        leDateFrom->setObjectName(QString::fromUtf8("leDateFrom"));

        horizontalLayout->addWidget(leDateFrom);

        label_2 = new QLabel(FReportByPayment);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        leDateTo = new EDateEdit(FReportByPayment);
        leDateTo->setObjectName(QString::fromUtf8("leDateTo"));

        horizontalLayout->addWidget(leDateTo);

        horizontalSpacer = new QSpacerItem(170, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FReportByPayment);

        QMetaObject::connectSlotsByName(FReportByPayment);
    } // setupUi

    void retranslateUi(QWidget *FReportByPayment)
    {
        FReportByPayment->setWindowTitle(QCoreApplication::translate("FReportByPayment", "Form", nullptr));
        label->setText(QCoreApplication::translate("FReportByPayment", "Date from", nullptr));
        label_2->setText(QCoreApplication::translate("FReportByPayment", "Date to", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FReportByPayment: public Ui_FReportByPayment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREPORTBYPAYMENT_H
