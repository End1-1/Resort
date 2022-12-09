/********************************************************************************
** Form generated from reading UI file 'fbreakfast.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FBREAKFAST_H
#define UI_FBREAKFAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FBreakfast
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FBreakfast)
    {
        if (FBreakfast->objectName().isEmpty())
            FBreakfast->setObjectName(QString::fromUtf8("FBreakfast"));
        FBreakfast->resize(800, 41);
        horizontalLayout = new QHBoxLayout(FBreakfast);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FBreakfast);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(FBreakfast);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FBreakfast);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FBreakfast);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        horizontalSpacer = new QSpacerItem(219, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FBreakfast);

        QMetaObject::connectSlotsByName(FBreakfast);
    } // setupUi

    void retranslateUi(QWidget *FBreakfast)
    {
        FBreakfast->setWindowTitle(QCoreApplication::translate("FBreakfast", "Form", nullptr));
        label->setText(QCoreApplication::translate("FBreakfast", "Date start", nullptr));
        label_2->setText(QCoreApplication::translate("FBreakfast", "Date end", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FBreakfast: public Ui_FBreakfast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FBREAKFAST_H
