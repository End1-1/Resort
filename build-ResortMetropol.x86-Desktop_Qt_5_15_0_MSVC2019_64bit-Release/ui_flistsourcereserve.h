/********************************************************************************
** Form generated from reading UI file 'flistsourcereserve.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLISTSOURCERESERVE_H
#define UI_FLISTSOURCERESERVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FListSourceReserve
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QLabel *label_3;
    EQLineEdit *leState;
    QLabel *label_4;
    EQLineEdit *leCardex;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FListSourceReserve)
    {
        if (FListSourceReserve->objectName().isEmpty())
            FListSourceReserve->setObjectName(QString::fromUtf8("FListSourceReserve"));
        FListSourceReserve->resize(945, 41);
        horizontalLayout = new QHBoxLayout(FListSourceReserve);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FListSourceReserve);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(FListSourceReserve);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FListSourceReserve);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FListSourceReserve);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        label_3 = new QLabel(FListSourceReserve);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leState = new EQLineEdit(FListSourceReserve);
        leState->setObjectName(QString::fromUtf8("leState"));
        leState->setFocusPolicy(Qt::ClickFocus);
        leState->setProperty("EnableHiddenText", QVariant(true));

        horizontalLayout->addWidget(leState);

        label_4 = new QLabel(FListSourceReserve);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        leCardex = new EQLineEdit(FListSourceReserve);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setFocusPolicy(Qt::ClickFocus);
        leCardex->setProperty("EnableHiddenText", QVariant(true));

        horizontalLayout->addWidget(leCardex);

        horizontalSpacer = new QSpacerItem(144, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FListSourceReserve);

        QMetaObject::connectSlotsByName(FListSourceReserve);
    } // setupUi

    void retranslateUi(QWidget *FListSourceReserve)
    {
        FListSourceReserve->setWindowTitle(QCoreApplication::translate("FListSourceReserve", "Form", nullptr));
        label->setText(QCoreApplication::translate("FListSourceReserve", "Date from", nullptr));
        label_2->setText(QCoreApplication::translate("FListSourceReserve", "Date to", nullptr));
        label_3->setText(QCoreApplication::translate("FListSourceReserve", "State", nullptr));
        label_4->setText(QCoreApplication::translate("FListSourceReserve", "Cardex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FListSourceReserve: public Ui_FListSourceReserve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLISTSOURCERESERVE_H
