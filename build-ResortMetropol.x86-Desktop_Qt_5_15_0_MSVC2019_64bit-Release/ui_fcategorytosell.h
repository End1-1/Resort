/********************************************************************************
** Form generated from reading UI file 'fcategorytosell.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCATEGORYTOSELL_H
#define UI_FCATEGORYTOSELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcheckbox.h>

QT_BEGIN_NAMESPACE

class Ui_FCategoryToSell
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EDateEdit *deStart;
    EDateEdit *deEnd;
    EQCheckBox *chGroupByBed;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    EQCheckBox *chGroupByView;

    void setupUi(QWidget *FCategoryToSell)
    {
        if (FCategoryToSell->objectName().isEmpty())
            FCategoryToSell->setObjectName(QString::fromUtf8("FCategoryToSell"));
        FCategoryToSell->resize(400, 40);
        verticalLayout = new QVBoxLayout(FCategoryToSell);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        deStart = new EDateEdit(FCategoryToSell);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 0, 1, 1, 1);

        deEnd = new EDateEdit(FCategoryToSell);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 0, 3, 1, 1);

        chGroupByBed = new EQCheckBox(FCategoryToSell);
        chGroupByBed->setObjectName(QString::fromUtf8("chGroupByBed"));
        chGroupByBed->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(chGroupByBed, 0, 5, 1, 1);

        label_2 = new QLabel(FCategoryToSell);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(FCategoryToSell);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        chGroupByView = new EQCheckBox(FCategoryToSell);
        chGroupByView->setObjectName(QString::fromUtf8("chGroupByView"));
        chGroupByView->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(chGroupByView, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(FCategoryToSell);

        QMetaObject::connectSlotsByName(FCategoryToSell);
    } // setupUi

    void retranslateUi(QWidget *FCategoryToSell)
    {
        FCategoryToSell->setWindowTitle(QCoreApplication::translate("FCategoryToSell", "Form", nullptr));
        chGroupByBed->setText(QCoreApplication::translate("FCategoryToSell", "Bed", nullptr));
        label_2->setText(QCoreApplication::translate("FCategoryToSell", "Date start", nullptr));
        label->setText(QCoreApplication::translate("FCategoryToSell", "Date end", nullptr));
        chGroupByView->setText(QCoreApplication::translate("FCategoryToSell", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCategoryToSell: public Ui_FCategoryToSell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCATEGORYTOSELL_H
