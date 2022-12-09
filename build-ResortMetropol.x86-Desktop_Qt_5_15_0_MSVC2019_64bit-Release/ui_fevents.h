/********************************************************************************
** Form generated from reading UI file 'fevents.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEVENTS_H
#define UI_FEVENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FEvents
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FEvents)
    {
        if (FEvents->objectName().isEmpty())
            FEvents->setObjectName(QString::fromUtf8("FEvents"));
        FEvents->resize(650, 38);
        horizontalLayout = new QHBoxLayout(FEvents);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FEvents);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(FEvents);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FEvents);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FEvents);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FEvents);

        QMetaObject::connectSlotsByName(FEvents);
    } // setupUi

    void retranslateUi(QWidget *FEvents)
    {
        FEvents->setWindowTitle(QCoreApplication::translate("FEvents", "Form", nullptr));
        label->setText(QCoreApplication::translate("FEvents", "From", nullptr));
        label_2->setText(QCoreApplication::translate("FEvents", "To", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FEvents: public Ui_FEvents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEVENTS_H
