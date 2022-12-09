/********************************************************************************
** Form generated from reading UI file 'fallguestindaterange.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FALLGUESTINDATERANGE_H
#define UI_FALLGUESTINDATERANGE_H

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
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FAllGuestInDateRange
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *btnBack;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QToolButton *btnForward;
    QLabel *label_3;
    EQLineEdit *leNatCode;
    EQLineEdit *leNatName;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chCheckinOnly;

    void setupUi(QWidget *FAllGuestInDateRange)
    {
        if (FAllGuestInDateRange->objectName().isEmpty())
            FAllGuestInDateRange->setObjectName(QString::fromUtf8("FAllGuestInDateRange"));
        FAllGuestInDateRange->resize(905, 41);
        horizontalLayout = new QHBoxLayout(FAllGuestInDateRange);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FAllGuestInDateRange);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnBack = new QToolButton(FAllGuestInDateRange);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBack->setIcon(icon);

        horizontalLayout->addWidget(btnBack);

        deStart = new EDateEdit(FAllGuestInDateRange);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FAllGuestInDateRange);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FAllGuestInDateRange);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        btnForward = new QToolButton(FAllGuestInDateRange);
        btnForward->setObjectName(QString::fromUtf8("btnForward"));
        btnForward->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnForward->setIcon(icon1);

        horizontalLayout->addWidget(btnForward);

        label_3 = new QLabel(FAllGuestInDateRange);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leNatCode = new EQLineEdit(FAllGuestInDateRange);
        leNatCode->setObjectName(QString::fromUtf8("leNatCode"));
        leNatCode->setMaximumSize(QSize(50, 16777215));
        leNatCode->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(leNatCode);

        leNatName = new EQLineEdit(FAllGuestInDateRange);
        leNatName->setObjectName(QString::fromUtf8("leNatName"));
        leNatName->setEnabled(false);
        leNatName->setMaximumSize(QSize(200, 16777215));
        leNatName->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(leNatName);

        horizontalSpacer = new QSpacerItem(107, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chCheckinOnly = new QCheckBox(FAllGuestInDateRange);
        chCheckinOnly->setObjectName(QString::fromUtf8("chCheckinOnly"));
        chCheckinOnly->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chCheckinOnly);


        retranslateUi(FAllGuestInDateRange);

        QMetaObject::connectSlotsByName(FAllGuestInDateRange);
    } // setupUi

    void retranslateUi(QWidget *FAllGuestInDateRange)
    {
        FAllGuestInDateRange->setWindowTitle(QCoreApplication::translate("FAllGuestInDateRange", "Form", nullptr));
        label->setText(QCoreApplication::translate("FAllGuestInDateRange", "Date start", nullptr));
        btnBack->setText(QCoreApplication::translate("FAllGuestInDateRange", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FAllGuestInDateRange", "Date end", nullptr));
        btnForward->setText(QCoreApplication::translate("FAllGuestInDateRange", "...", nullptr));
        label_3->setText(QCoreApplication::translate("FAllGuestInDateRange", "Nationality", nullptr));
        chCheckinOnly->setText(QCoreApplication::translate("FAllGuestInDateRange", "Checkin only", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FAllGuestInDateRange: public Ui_FAllGuestInDateRange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FALLGUESTINDATERANGE_H
