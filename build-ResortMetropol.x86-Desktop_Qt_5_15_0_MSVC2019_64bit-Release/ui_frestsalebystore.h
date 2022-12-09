/********************************************************************************
** Form generated from reading UI file 'frestsalebystore.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRESTSALEBYSTORE_H
#define UI_FRESTSALEBYSTORE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FRestSaleByStore
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *btnBack;
    EDateEdit *leDateStart;
    QLabel *label_2;
    EDateEdit *leDateEnd;
    QToolButton *btnNext;
    QCheckBox *chShowItems;
    QCheckBox *chShowDates;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FRestSaleByStore)
    {
        if (FRestSaleByStore->objectName().isEmpty())
            FRestSaleByStore->setObjectName(QString::fromUtf8("FRestSaleByStore"));
        FRestSaleByStore->resize(735, 41);
        horizontalLayout = new QHBoxLayout(FRestSaleByStore);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FRestSaleByStore);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnBack = new QToolButton(FRestSaleByStore);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon);

        horizontalLayout->addWidget(btnBack);

        leDateStart = new EDateEdit(FRestSaleByStore);
        leDateStart->setObjectName(QString::fromUtf8("leDateStart"));

        horizontalLayout->addWidget(leDateStart);

        label_2 = new QLabel(FRestSaleByStore);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        leDateEnd = new EDateEdit(FRestSaleByStore);
        leDateEnd->setObjectName(QString::fromUtf8("leDateEnd"));

        horizontalLayout->addWidget(leDateEnd);

        btnNext = new QToolButton(FRestSaleByStore);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon1);

        horizontalLayout->addWidget(btnNext);

        chShowItems = new QCheckBox(FRestSaleByStore);
        chShowItems->setObjectName(QString::fromUtf8("chShowItems"));
        chShowItems->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(chShowItems);

        chShowDates = new QCheckBox(FRestSaleByStore);
        chShowDates->setObjectName(QString::fromUtf8("chShowDates"));
        chShowDates->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(chShowDates);

        horizontalSpacer = new QSpacerItem(139, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FRestSaleByStore);

        QMetaObject::connectSlotsByName(FRestSaleByStore);
    } // setupUi

    void retranslateUi(QWidget *FRestSaleByStore)
    {
        FRestSaleByStore->setWindowTitle(QCoreApplication::translate("FRestSaleByStore", "Form", nullptr));
        label->setText(QCoreApplication::translate("FRestSaleByStore", "Date start", nullptr));
        btnBack->setText(QCoreApplication::translate("FRestSaleByStore", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FRestSaleByStore", "Date end", nullptr));
        btnNext->setText(QCoreApplication::translate("FRestSaleByStore", "...", nullptr));
        chShowItems->setText(QCoreApplication::translate("FRestSaleByStore", "Show orders items", nullptr));
        chShowDates->setText(QCoreApplication::translate("FRestSaleByStore", "Show dates", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FRestSaleByStore: public Ui_FRestSaleByStore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRESTSALEBYSTORE_H
