/********************************************************************************
** Form generated from reading UI file 'froomstate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FROOMSTATE_H
#define UI_FROOMSTATE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FRoomState
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnDateLeft;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QPushButton *btnDateRight;
    QRadioButton *rbWorking;
    QRadioButton *rbReal;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chOnlyChecinCheckout;

    void setupUi(QWidget *FRoomState)
    {
        if (FRoomState->objectName().isEmpty())
            FRoomState->setObjectName(QString::fromUtf8("FRoomState"));
        FRoomState->resize(579, 43);
        horizontalLayout = new QHBoxLayout(FRoomState);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FRoomState);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnDateLeft = new QPushButton(FRoomState);
        btnDateLeft->setObjectName(QString::fromUtf8("btnDateLeft"));
        btnDateLeft->setMinimumSize(QSize(25, 25));
        btnDateLeft->setMaximumSize(QSize(25, 25));
        btnDateLeft->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDateLeft->setIcon(icon);

        horizontalLayout->addWidget(btnDateLeft);

        deStart = new EDateEdit(FRoomState);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FRoomState);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FRoomState);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        btnDateRight = new QPushButton(FRoomState);
        btnDateRight->setObjectName(QString::fromUtf8("btnDateRight"));
        btnDateRight->setMinimumSize(QSize(25, 25));
        btnDateRight->setMaximumSize(QSize(25, 25));
        btnDateRight->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDateRight->setIcon(icon1);

        horizontalLayout->addWidget(btnDateRight);

        rbWorking = new QRadioButton(FRoomState);
        rbWorking->setObjectName(QString::fromUtf8("rbWorking"));
        rbWorking->setChecked(true);

        horizontalLayout->addWidget(rbWorking);

        rbReal = new QRadioButton(FRoomState);
        rbReal->setObjectName(QString::fromUtf8("rbReal"));

        horizontalLayout->addWidget(rbReal);

        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chOnlyChecinCheckout = new QCheckBox(FRoomState);
        chOnlyChecinCheckout->setObjectName(QString::fromUtf8("chOnlyChecinCheckout"));
        chOnlyChecinCheckout->setFocusPolicy(Qt::NoFocus);
        chOnlyChecinCheckout->setChecked(true);

        horizontalLayout->addWidget(chOnlyChecinCheckout);


        retranslateUi(FRoomState);

        QMetaObject::connectSlotsByName(FRoomState);
    } // setupUi

    void retranslateUi(QWidget *FRoomState)
    {
        FRoomState->setWindowTitle(QCoreApplication::translate("FRoomState", "Form", nullptr));
        label->setText(QCoreApplication::translate("FRoomState", "Date from", nullptr));
        btnDateLeft->setText(QString());
        label_2->setText(QCoreApplication::translate("FRoomState", "Date to", nullptr));
        btnDateRight->setText(QString());
        rbWorking->setText(QCoreApplication::translate("FRoomState", "Use working date", nullptr));
        rbReal->setText(QCoreApplication::translate("FRoomState", "Use real date", nullptr));
        chOnlyChecinCheckout->setText(QCoreApplication::translate("FRoomState", "Checkin, checkout only", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FRoomState: public Ui_FRoomState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FROOMSTATE_H
