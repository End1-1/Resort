/********************************************************************************
** Form generated from reading UI file 'fdiscounttotal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDISCOUNTTOTAL_H
#define UI_FDISCOUNTTOTAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FDiscountTotal
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QLabel *label_3;
    EQLineEdit *leMin;
    QLabel *label_4;
    EQLineEdit *leMinAmount;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FDiscountTotal)
    {
        if (FDiscountTotal->objectName().isEmpty())
            FDiscountTotal->setObjectName(QString::fromUtf8("FDiscountTotal"));
        FDiscountTotal->resize(765, 41);
        horizontalLayout = new QHBoxLayout(FDiscountTotal);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FDiscountTotal);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(FDiscountTotal);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FDiscountTotal);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FDiscountTotal);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        deEnd->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(deEnd);

        label_3 = new QLabel(FDiscountTotal);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leMin = new EQLineEdit(FDiscountTotal);
        leMin->setObjectName(QString::fromUtf8("leMin"));
        leMin->setMaximumSize(QSize(50, 16777215));
        leMin->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(leMin);

        label_4 = new QLabel(FDiscountTotal);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        leMinAmount = new EQLineEdit(FDiscountTotal);
        leMinAmount->setObjectName(QString::fromUtf8("leMinAmount"));
        leMinAmount->setMaximumSize(QSize(100, 16777215));
        leMinAmount->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(leMinAmount);

        horizontalSpacer = new QSpacerItem(464, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FDiscountTotal);

        QMetaObject::connectSlotsByName(FDiscountTotal);
    } // setupUi

    void retranslateUi(QWidget *FDiscountTotal)
    {
        FDiscountTotal->setWindowTitle(QCoreApplication::translate("FDiscountTotal", "Form", nullptr));
        label->setText(QCoreApplication::translate("FDiscountTotal", "Date  start", nullptr));
        label_2->setText(QCoreApplication::translate("FDiscountTotal", "Date end", nullptr));
        label_3->setText(QCoreApplication::translate("FDiscountTotal", "Minimum qty", nullptr));
        label_4->setText(QCoreApplication::translate("FDiscountTotal", "Minimum amount", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FDiscountTotal: public Ui_FDiscountTotal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDISCOUNTTOTAL_H
