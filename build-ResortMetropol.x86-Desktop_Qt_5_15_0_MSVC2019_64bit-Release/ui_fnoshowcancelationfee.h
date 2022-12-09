/********************************************************************************
** Form generated from reading UI file 'fnoshowcancelationfee.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FNOSHOWCANCELATIONFEE_H
#define UI_FNOSHOWCANCELATIONFEE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FNoShowCancelationFee
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnBack;
    EDateEdit *deStart;
    EDateEdit *deEnd;
    QPushButton *btnForward;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FNoShowCancelationFee)
    {
        if (FNoShowCancelationFee->objectName().isEmpty())
            FNoShowCancelationFee->setObjectName(QString::fromUtf8("FNoShowCancelationFee"));
        FNoShowCancelationFee->resize(957, 41);
        horizontalLayout = new QHBoxLayout(FNoShowCancelationFee);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnBack = new QPushButton(FNoShowCancelationFee);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setMaximumSize(QSize(25, 25));
        btnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon);

        horizontalLayout->addWidget(btnBack);

        deStart = new EDateEdit(FNoShowCancelationFee);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setMaximumSize(QSize(120, 16777215));
        deStart->setFocusPolicy(Qt::WheelFocus);

        horizontalLayout->addWidget(deStart);

        deEnd = new EDateEdit(FNoShowCancelationFee);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        deEnd->setMaximumSize(QSize(120, 16777215));
        deEnd->setFocusPolicy(Qt::WheelFocus);

        horizontalLayout->addWidget(deEnd);

        btnForward = new QPushButton(FNoShowCancelationFee);
        btnForward->setObjectName(QString::fromUtf8("btnForward"));
        btnForward->setMaximumSize(QSize(25, 25));
        btnForward->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnForward->setIcon(icon1);

        horizontalLayout->addWidget(btnForward);

        horizontalSpacer = new QSpacerItem(622, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FNoShowCancelationFee);

        QMetaObject::connectSlotsByName(FNoShowCancelationFee);
    } // setupUi

    void retranslateUi(QWidget *FNoShowCancelationFee)
    {
        FNoShowCancelationFee->setWindowTitle(QCoreApplication::translate("FNoShowCancelationFee", "Form", nullptr));
        btnBack->setText(QString());
        btnForward->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FNoShowCancelationFee: public Ui_FNoShowCancelationFee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FNOSHOWCANCELATIONFEE_H
