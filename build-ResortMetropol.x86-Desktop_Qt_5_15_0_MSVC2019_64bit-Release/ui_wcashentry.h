/********************************************************************************
** Form generated from reading UI file 'wcashentry.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WCASHENTRY_H
#define UI_WCASHENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_WCashEntry
{
public:
    QGridLayout *gridLayout;
    QWidget *wOK;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    EQLineEdit *leCreditName;
    QSpacerItem *horizontalSpacer_3;
    EQLineEdit *leDebitName;
    QLabel *label_4;
    EQLineEdit *lePartnerCode;
    QLabel *label_7;
    EQLineEdit *leAmount;
    EQLineEdit *lePartnerName;
    QLabel *label_2;
    EQLineEdit *leDebit;
    QLabel *label_9;
    QLabel *lbCashIn;
    EQLineEdit *leDocTypeNum;
    EDateEdit *deDate;
    QLabel *label_3;
    QLabel *label_6;
    EQLineEdit *leCode;
    EQLineEdit *leCredit;
    EQLineEdit *leDocTypeName;
    EQLineEdit *leComment;
    QCheckBox *chEnable;
    QLabel *label;
    EQLineEdit *leDocNum;
    QLabel *label_8;
    QWidget *wOp;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbCashIn;
    QRadioButton *rbCashOut;
    QRadioButton *rbCashMove;
    QSpacerItem *verticalSpacer;
    QLabel *lbCachout;
    EQLineEdit *leCashout;
    EQLineEdit *leCashOutName;

    void setupUi(QWidget *WCashEntry)
    {
        if (WCashEntry->objectName().isEmpty())
            WCashEntry->setObjectName(QString::fromUtf8("WCashEntry"));
        WCashEntry->resize(400, 415);
        gridLayout = new QGridLayout(WCashEntry);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        wOK = new QWidget(WCashEntry);
        wOK->setObjectName(QString::fromUtf8("wOK"));
        horizontalLayout = new QHBoxLayout(wOK);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(wOK);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(wOK);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(wOK, 12, 0, 1, 3);

        leCreditName = new EQLineEdit(WCashEntry);
        leCreditName->setObjectName(QString::fromUtf8("leCreditName"));
        leCreditName->setEnabled(false);
        leCreditName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leCreditName, 9, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 3, 1, 1);

        leDebitName = new EQLineEdit(WCashEntry);
        leDebitName->setObjectName(QString::fromUtf8("leDebitName"));
        leDebitName->setEnabled(false);
        leDebitName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leDebitName, 7, 2, 1, 1);

        label_4 = new QLabel(WCashEntry);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        lePartnerCode = new EQLineEdit(WCashEntry);
        lePartnerCode->setObjectName(QString::fromUtf8("lePartnerCode"));
        lePartnerCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lePartnerCode, 10, 1, 1, 1);

        label_7 = new QLabel(WCashEntry);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 10, 0, 1, 1);

        leAmount = new EQLineEdit(WCashEntry);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leAmount, 6, 1, 1, 1);

        lePartnerName = new EQLineEdit(WCashEntry);
        lePartnerName->setObjectName(QString::fromUtf8("lePartnerName"));
        lePartnerName->setEnabled(false);
        lePartnerName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(lePartnerName, 10, 2, 1, 1);

        label_2 = new QLabel(WCashEntry);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        leDebit = new EQLineEdit(WCashEntry);
        leDebit->setObjectName(QString::fromUtf8("leDebit"));
        leDebit->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leDebit, 7, 1, 1, 1);

        label_9 = new QLabel(WCashEntry);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 6, 0, 1, 1);

        lbCashIn = new QLabel(WCashEntry);
        lbCashIn->setObjectName(QString::fromUtf8("lbCashIn"));

        gridLayout->addWidget(lbCashIn, 7, 0, 1, 1);

        leDocTypeNum = new EQLineEdit(WCashEntry);
        leDocTypeNum->setObjectName(QString::fromUtf8("leDocTypeNum"));
        leDocTypeNum->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leDocTypeNum, 3, 1, 1, 1);

        deDate = new EDateEdit(WCashEntry);
        deDate->setObjectName(QString::fromUtf8("deDate"));
        deDate->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(deDate, 5, 1, 1, 1);

        label_3 = new QLabel(WCashEntry);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_6 = new QLabel(WCashEntry);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 9, 0, 1, 1);

        leCode = new EQLineEdit(WCashEntry);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCode, 2, 1, 1, 1);

        leCredit = new EQLineEdit(WCashEntry);
        leCredit->setObjectName(QString::fromUtf8("leCredit"));
        leCredit->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCredit, 9, 1, 1, 1);

        leDocTypeName = new EQLineEdit(WCashEntry);
        leDocTypeName->setObjectName(QString::fromUtf8("leDocTypeName"));
        leDocTypeName->setEnabled(false);
        leDocTypeName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leDocTypeName, 3, 2, 1, 1);

        leComment = new EQLineEdit(WCashEntry);
        leComment->setObjectName(QString::fromUtf8("leComment"));

        gridLayout->addWidget(leComment, 11, 1, 1, 2);

        chEnable = new QCheckBox(WCashEntry);
        chEnable->setObjectName(QString::fromUtf8("chEnable"));

        gridLayout->addWidget(chEnable, 0, 1, 1, 1);

        label = new QLabel(WCashEntry);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        leDocNum = new EQLineEdit(WCashEntry);
        leDocNum->setObjectName(QString::fromUtf8("leDocNum"));
        leDocNum->setEnabled(false);
        leDocNum->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leDocNum, 4, 1, 1, 1);

        label_8 = new QLabel(WCashEntry);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 11, 0, 1, 1);

        wOp = new QWidget(WCashEntry);
        wOp->setObjectName(QString::fromUtf8("wOp"));
        wOp->setMinimumSize(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(wOp);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbCashIn = new QRadioButton(wOp);
        rbCashIn->setObjectName(QString::fromUtf8("rbCashIn"));

        horizontalLayout_2->addWidget(rbCashIn);

        rbCashOut = new QRadioButton(wOp);
        rbCashOut->setObjectName(QString::fromUtf8("rbCashOut"));

        horizontalLayout_2->addWidget(rbCashOut);

        rbCashMove = new QRadioButton(wOp);
        rbCashMove->setObjectName(QString::fromUtf8("rbCashMove"));

        horizontalLayout_2->addWidget(rbCashMove);


        gridLayout->addWidget(wOp, 1, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 13, 0, 1, 1);

        lbCachout = new QLabel(WCashEntry);
        lbCachout->setObjectName(QString::fromUtf8("lbCachout"));

        gridLayout->addWidget(lbCachout, 8, 0, 1, 1);

        leCashout = new EQLineEdit(WCashEntry);
        leCashout->setObjectName(QString::fromUtf8("leCashout"));
        leCashout->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leCashout, 8, 1, 1, 1);

        leCashOutName = new EQLineEdit(WCashEntry);
        leCashOutName->setObjectName(QString::fromUtf8("leCashOutName"));
        leCashOutName->setEnabled(false);
        leCashOutName->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(leCashOutName, 8, 2, 1, 1);

        QWidget::setTabOrder(chEnable, rbCashIn);
        QWidget::setTabOrder(rbCashIn, rbCashOut);
        QWidget::setTabOrder(rbCashOut, rbCashMove);
        QWidget::setTabOrder(rbCashMove, leCode);
        QWidget::setTabOrder(leCode, leDocTypeNum);
        QWidget::setTabOrder(leDocTypeNum, leDocNum);
        QWidget::setTabOrder(leDocNum, deDate);
        QWidget::setTabOrder(deDate, leAmount);
        QWidget::setTabOrder(leAmount, leDebit);
        QWidget::setTabOrder(leDebit, leCashout);
        QWidget::setTabOrder(leCashout, leCredit);
        QWidget::setTabOrder(leCredit, lePartnerCode);
        QWidget::setTabOrder(lePartnerCode, leComment);
        QWidget::setTabOrder(leComment, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);
        QWidget::setTabOrder(btnCancel, leCashOutName);

        retranslateUi(WCashEntry);

        QMetaObject::connectSlotsByName(WCashEntry);
    } // setupUi

    void retranslateUi(QWidget *WCashEntry)
    {
        WCashEntry->setWindowTitle(QCoreApplication::translate("WCashEntry", "Form", nullptr));
        btnSave->setText(QCoreApplication::translate("WCashEntry", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("WCashEntry", "Cancel", nullptr));
        label_4->setText(QCoreApplication::translate("WCashEntry", "Date", nullptr));
        label_7->setText(QCoreApplication::translate("WCashEntry", "Partner", nullptr));
        label_2->setText(QCoreApplication::translate("WCashEntry", "Document type", nullptr));
        label_9->setText(QCoreApplication::translate("WCashEntry", "Amount", nullptr));
        lbCashIn->setText(QCoreApplication::translate("WCashEntry", "Cash in", nullptr));
        label_3->setText(QCoreApplication::translate("WCashEntry", "Document number", nullptr));
        label_6->setText(QCoreApplication::translate("WCashEntry", "Purpose", nullptr));
        chEnable->setText(QString());
        label->setText(QCoreApplication::translate("WCashEntry", "Code", nullptr));
        label_8->setText(QCoreApplication::translate("WCashEntry", "Comment", nullptr));
        rbCashIn->setText(QCoreApplication::translate("WCashEntry", "Cash in", nullptr));
        rbCashOut->setText(QCoreApplication::translate("WCashEntry", "Cash out", nullptr));
        rbCashMove->setText(QCoreApplication::translate("WCashEntry", "Cash move", nullptr));
        lbCachout->setText(QCoreApplication::translate("WCashEntry", "Cash out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WCashEntry: public Ui_WCashEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WCASHENTRY_H
