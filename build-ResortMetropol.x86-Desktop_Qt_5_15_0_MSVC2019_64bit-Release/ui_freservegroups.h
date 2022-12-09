/********************************************************************************
** Form generated from reading UI file 'freservegroups.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRESERVEGROUPS_H
#define UI_FRESERVEGROUPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FReserveGroups
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QRadioButton *rbShowAll;
    QRadioButton *rbEntry;
    QRadioButton *rbDeparture;
    QCheckBox *chCanceled;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FReserveGroups)
    {
        if (FReserveGroups->objectName().isEmpty())
            FReserveGroups->setObjectName(QString::fromUtf8("FReserveGroups"));
        FReserveGroups->resize(757, 38);
        horizontalLayout = new QHBoxLayout(FReserveGroups);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FReserveGroups);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(FReserveGroups);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FReserveGroups);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FReserveGroups);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        rbShowAll = new QRadioButton(FReserveGroups);
        rbShowAll->setObjectName(QString::fromUtf8("rbShowAll"));
        rbShowAll->setChecked(true);

        horizontalLayout->addWidget(rbShowAll);

        rbEntry = new QRadioButton(FReserveGroups);
        rbEntry->setObjectName(QString::fromUtf8("rbEntry"));
        rbEntry->setChecked(false);

        horizontalLayout->addWidget(rbEntry);

        rbDeparture = new QRadioButton(FReserveGroups);
        rbDeparture->setObjectName(QString::fromUtf8("rbDeparture"));

        horizontalLayout->addWidget(rbDeparture);

        chCanceled = new QCheckBox(FReserveGroups);
        chCanceled->setObjectName(QString::fromUtf8("chCanceled"));

        horizontalLayout->addWidget(chCanceled);

        horizontalSpacer = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FReserveGroups);

        QMetaObject::connectSlotsByName(FReserveGroups);
    } // setupUi

    void retranslateUi(QWidget *FReserveGroups)
    {
        FReserveGroups->setWindowTitle(QCoreApplication::translate("FReserveGroups", "Form", nullptr));
        label->setText(QCoreApplication::translate("FReserveGroups", "Date from", nullptr));
        label_2->setText(QCoreApplication::translate("FReserveGroups", "Date to", nullptr));
        rbShowAll->setText(QCoreApplication::translate("FReserveGroups", "Show all", nullptr));
        rbEntry->setText(QCoreApplication::translate("FReserveGroups", "Search by entry date", nullptr));
        rbDeparture->setText(QCoreApplication::translate("FReserveGroups", "Search by departure date", nullptr));
        chCanceled->setText(QCoreApplication::translate("FReserveGroups", "Show only canceled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FReserveGroups: public Ui_FReserveGroups {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRESERVEGROUPS_H
