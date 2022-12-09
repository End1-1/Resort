/********************************************************************************
** Form generated from reading UI file 'fcommonfilterbydate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCOMMONFILTERBYDATE_H
#define UI_FCOMMONFILTERBYDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FCommonFilterByDate
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deFrom;
    QLabel *label_2;
    EDateEdit *deTo;
    QWidget *wControls;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *lControls;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FCommonFilterByDate)
    {
        if (FCommonFilterByDate->objectName().isEmpty())
            FCommonFilterByDate->setObjectName(QString::fromUtf8("FCommonFilterByDate"));
        FCommonFilterByDate->resize(692, 41);
        horizontalLayout = new QHBoxLayout(FCommonFilterByDate);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FCommonFilterByDate);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deFrom = new EDateEdit(FCommonFilterByDate);
        deFrom->setObjectName(QString::fromUtf8("deFrom"));
        deFrom->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deFrom);

        label_2 = new QLabel(FCommonFilterByDate);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deTo = new EDateEdit(FCommonFilterByDate);
        deTo->setObjectName(QString::fromUtf8("deTo"));
        deTo->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deTo);

        wControls = new QWidget(FCommonFilterByDate);
        wControls->setObjectName(QString::fromUtf8("wControls"));
        horizontalLayout_3 = new QHBoxLayout(wControls);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lControls = new QHBoxLayout();
        lControls->setObjectName(QString::fromUtf8("lControls"));

        horizontalLayout_3->addLayout(lControls);


        horizontalLayout->addWidget(wControls);

        horizontalSpacer = new QSpacerItem(359, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FCommonFilterByDate);

        QMetaObject::connectSlotsByName(FCommonFilterByDate);
    } // setupUi

    void retranslateUi(QWidget *FCommonFilterByDate)
    {
        FCommonFilterByDate->setWindowTitle(QCoreApplication::translate("FCommonFilterByDate", "Form", nullptr));
        label->setText(QCoreApplication::translate("FCommonFilterByDate", "Date From", nullptr));
        label_2->setText(QCoreApplication::translate("FCommonFilterByDate", "Date To", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCommonFilterByDate: public Ui_FCommonFilterByDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCOMMONFILTERBYDATE_H
