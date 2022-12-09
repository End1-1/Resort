/********************************************************************************
** Form generated from reading UI file 'finvoices.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINVOICES_H
#define UI_FINVOICES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FInvoices
{
public:
    QGridLayout *gridLayout;
    QCheckBox *chContainsEmptyRooming;
    QLabel *label_2;
    EDateEdit *deEnd;
    QPushButton *btnNext;
    QPushButton *btnPrev;
    EDateEdit *deStart;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chNoVAT;

    void setupUi(QWidget *FInvoices)
    {
        if (FInvoices->objectName().isEmpty())
            FInvoices->setObjectName(QString::fromUtf8("FInvoices"));
        FInvoices->resize(787, 43);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FInvoices->sizePolicy().hasHeightForWidth());
        FInvoices->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(FInvoices);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chContainsEmptyRooming = new QCheckBox(FInvoices);
        chContainsEmptyRooming->setObjectName(QString::fromUtf8("chContainsEmptyRooming"));

        gridLayout->addWidget(chContainsEmptyRooming, 0, 8, 1, 1);

        label_2 = new QLabel(FInvoices);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        deEnd = new EDateEdit(FInvoices);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 0, 4, 1, 1);

        btnNext = new QPushButton(FInvoices);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setMinimumSize(QSize(25, 25));
        btnNext->setMaximumSize(QSize(25, 25));
        btnNext->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNext->setIcon(icon);

        gridLayout->addWidget(btnNext, 0, 5, 1, 1);

        btnPrev = new QPushButton(FInvoices);
        btnPrev->setObjectName(QString::fromUtf8("btnPrev"));
        btnPrev->setMinimumSize(QSize(25, 25));
        btnPrev->setMaximumSize(QSize(25, 25));
        btnPrev->setFocusPolicy(Qt::ClickFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrev->setIcon(icon1);

        gridLayout->addWidget(btnPrev, 0, 1, 1, 1);

        deStart = new EDateEdit(FInvoices);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 0, 2, 1, 1);

        label = new QLabel(FInvoices);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);

        chNoVAT = new QCheckBox(FInvoices);
        chNoVAT->setObjectName(QString::fromUtf8("chNoVAT"));

        gridLayout->addWidget(chNoVAT, 0, 7, 1, 1);

        QWidget::setTabOrder(deStart, deEnd);
        QWidget::setTabOrder(deEnd, btnPrev);
        QWidget::setTabOrder(btnPrev, btnNext);

        retranslateUi(FInvoices);

        QMetaObject::connectSlotsByName(FInvoices);
    } // setupUi

    void retranslateUi(QWidget *FInvoices)
    {
        FInvoices->setWindowTitle(QCoreApplication::translate("FInvoices", "Form", nullptr));
        chContainsEmptyRooming->setText(QCoreApplication::translate("FInvoices", "Contain free rooming", nullptr));
        label_2->setText(QCoreApplication::translate("FInvoices", "Ending", nullptr));
        btnNext->setText(QString());
        btnPrev->setText(QString());
        label->setText(QCoreApplication::translate("FInvoices", "Starting", nullptr));
        chNoVAT->setText(QCoreApplication::translate("FInvoices", "No VAT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FInvoices: public Ui_FInvoices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINVOICES_H
