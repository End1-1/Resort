/********************************************************************************
** Form generated from reading UI file 'froomcatsale.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FROOMCATSALE_H
#define UI_FROOMCATSALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FRoomCatSale
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QLabel *label;
    EQLineEdit *leCat;
    EQLineEdit *leCatName;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FRoomCatSale)
    {
        if (FRoomCatSale->objectName().isEmpty())
            FRoomCatSale->setObjectName(QString::fromUtf8("FRoomCatSale"));
        FRoomCatSale->resize(790, 20);
        horizontalLayout = new QHBoxLayout(FRoomCatSale);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        wd = new WDate2(FRoomCatSale);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        label = new QLabel(FRoomCatSale);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leCat = new EQLineEdit(FRoomCatSale);
        leCat->setObjectName(QString::fromUtf8("leCat"));
        leCat->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(leCat);

        leCatName = new EQLineEdit(FRoomCatSale);
        leCatName->setObjectName(QString::fromUtf8("leCatName"));
        leCatName->setMaximumSize(QSize(250, 16777215));

        horizontalLayout->addWidget(leCatName);

        horizontalSpacer = new QSpacerItem(247, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FRoomCatSale);

        QMetaObject::connectSlotsByName(FRoomCatSale);
    } // setupUi

    void retranslateUi(QWidget *FRoomCatSale)
    {
        FRoomCatSale->setWindowTitle(QCoreApplication::translate("FRoomCatSale", "Form", nullptr));
        label->setText(QCoreApplication::translate("FRoomCatSale", "Category", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FRoomCatSale: public Ui_FRoomCatSale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FROOMCATSALE_H
