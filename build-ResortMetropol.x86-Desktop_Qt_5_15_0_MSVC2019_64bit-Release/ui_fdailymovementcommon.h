/********************************************************************************
** Form generated from reading UI file 'fdailymovementcommon.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDAILYMOVEMENTCOMMON_H
#define UI_FDAILYMOVEMENTCOMMON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FDailyMovementCommon
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deDate;
    QLabel *label_2;
    EDateEdit *leEnd;
    QCheckBox *chExpandDate;
    QLabel *label_3;
    EQLineEdit *leTypeOfSale;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FDailyMovementCommon)
    {
        if (FDailyMovementCommon->objectName().isEmpty())
            FDailyMovementCommon->setObjectName(QString::fromUtf8("FDailyMovementCommon"));
        FDailyMovementCommon->resize(688, 41);
        horizontalLayout = new QHBoxLayout(FDailyMovementCommon);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FDailyMovementCommon);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deDate = new EDateEdit(FDailyMovementCommon);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deDate);

        label_2 = new QLabel(FDailyMovementCommon);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        leEnd = new EDateEdit(FDailyMovementCommon);
        leEnd->setObjectName(QString::fromUtf8("leEnd"));

        horizontalLayout->addWidget(leEnd);

        chExpandDate = new QCheckBox(FDailyMovementCommon);
        chExpandDate->setObjectName(QString::fromUtf8("chExpandDate"));
        chExpandDate->setFocusPolicy(Qt::ClickFocus);
        chExpandDate->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(chExpandDate);

        label_3 = new QLabel(FDailyMovementCommon);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(label_3);

        leTypeOfSale = new EQLineEdit(FDailyMovementCommon);
        leTypeOfSale->setObjectName(QString::fromUtf8("leTypeOfSale"));
        leTypeOfSale->setMinimumSize(QSize(200, 0));
        leTypeOfSale->setFocusPolicy(Qt::ClickFocus);
        leTypeOfSale->setProperty("EnableHiddenText", QVariant(true));

        horizontalLayout->addWidget(leTypeOfSale);

        horizontalSpacer = new QSpacerItem(532, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FDailyMovementCommon);

        QMetaObject::connectSlotsByName(FDailyMovementCommon);
    } // setupUi

    void retranslateUi(QWidget *FDailyMovementCommon)
    {
        FDailyMovementCommon->setWindowTitle(QCoreApplication::translate("FDailyMovementCommon", "Form", nullptr));
        label->setText(QCoreApplication::translate("FDailyMovementCommon", "Date from", nullptr));
        label_2->setText(QCoreApplication::translate("FDailyMovementCommon", "Date to", nullptr));
        chExpandDate->setText(QCoreApplication::translate("FDailyMovementCommon", "Show by date", nullptr));
        label_3->setText(QCoreApplication::translate("FDailyMovementCommon", "Type of sale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FDailyMovementCommon: public Ui_FDailyMovementCommon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDAILYMOVEMENTCOMMON_H
