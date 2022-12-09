/********************************************************************************
** Form generated from reading UI file 'fpartnersdebt.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FPARTNERSDEBT_H
#define UI_FPARTNERSDEBT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FPartnersDebt
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deFrom;
    QLabel *label_2;
    EDateEdit *deTo;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FPartnersDebt)
    {
        if (FPartnersDebt->objectName().isEmpty())
            FPartnersDebt->setObjectName(QString::fromUtf8("FPartnersDebt"));
        FPartnersDebt->resize(630, 41);
        horizontalLayout = new QHBoxLayout(FPartnersDebt);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FPartnersDebt);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deFrom = new EDateEdit(FPartnersDebt);
        deFrom->setObjectName(QString::fromUtf8("deFrom"));

        horizontalLayout->addWidget(deFrom);

        label_2 = new QLabel(FPartnersDebt);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deTo = new EDateEdit(FPartnersDebt);
        deTo->setObjectName(QString::fromUtf8("deTo"));

        horizontalLayout->addWidget(deTo);

        horizontalSpacer = new QSpacerItem(165, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FPartnersDebt);

        QMetaObject::connectSlotsByName(FPartnersDebt);
    } // setupUi

    void retranslateUi(QWidget *FPartnersDebt)
    {
        FPartnersDebt->setWindowTitle(QCoreApplication::translate("FPartnersDebt", "Form", nullptr));
        label->setText(QCoreApplication::translate("FPartnersDebt", "Date from", nullptr));
        label_2->setText(QCoreApplication::translate("FPartnersDebt", "Date to", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FPartnersDebt: public Ui_FPartnersDebt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FPARTNERSDEBT_H
