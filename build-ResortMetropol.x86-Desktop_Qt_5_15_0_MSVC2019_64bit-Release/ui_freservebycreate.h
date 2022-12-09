/********************************************************************************
** Form generated from reading UI file 'freservebycreate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRESERVEBYCREATE_H
#define UI_FRESERVEBYCREATE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FReserveByCreate
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *toolButton;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FReserveByCreate)
    {
        if (FReserveByCreate->objectName().isEmpty())
            FReserveByCreate->setObjectName(QString::fromUtf8("FReserveByCreate"));
        FReserveByCreate->resize(944, 41);
        horizontalLayout = new QHBoxLayout(FReserveByCreate);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FReserveByCreate);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        toolButton = new QToolButton(FReserveByCreate);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout->addWidget(toolButton);

        deStart = new EDateEdit(FReserveByCreate);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FReserveByCreate);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FReserveByCreate);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        toolButton_2 = new QToolButton(FReserveByCreate);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);

        horizontalLayout->addWidget(toolButton_2);

        horizontalSpacer = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FReserveByCreate);

        QMetaObject::connectSlotsByName(FReserveByCreate);
    } // setupUi

    void retranslateUi(QWidget *FReserveByCreate)
    {
        FReserveByCreate->setWindowTitle(QCoreApplication::translate("FReserveByCreate", "Form", nullptr));
        label->setText(QCoreApplication::translate("FReserveByCreate", "Date from", nullptr));
        toolButton->setText(QCoreApplication::translate("FReserveByCreate", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FReserveByCreate", "Date to", nullptr));
        toolButton_2->setText(QCoreApplication::translate("FReserveByCreate", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FReserveByCreate: public Ui_FReserveByCreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRESERVEBYCREATE_H
