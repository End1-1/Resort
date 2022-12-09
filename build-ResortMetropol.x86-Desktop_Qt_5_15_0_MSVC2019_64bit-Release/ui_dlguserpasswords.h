/********************************************************************************
** Form generated from reading UI file 'dlguserpasswords.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGUSERPASSWORDS_H
#define UI_DLGUSERPASSWORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgUserPasswords
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lePos;
    QLineEdit *leOldPass;
    QLineEdit *leNewPass;
    QCheckBox *chWaiter;
    QCheckBox *chManager;
    QLabel *lbUsername;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgUserPasswords)
    {
        if (DlgUserPasswords->objectName().isEmpty())
            DlgUserPasswords->setObjectName(QString::fromUtf8("DlgUserPasswords"));
        DlgUserPasswords->resize(400, 204);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgUserPasswords->sizePolicy().hasHeightForWidth());
        DlgUserPasswords->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DlgUserPasswords);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lePos = new QLineEdit(DlgUserPasswords);
        lePos->setObjectName(QString::fromUtf8("lePos"));
        lePos->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePos, 5, 0, 1, 1);

        leOldPass = new QLineEdit(DlgUserPasswords);
        leOldPass->setObjectName(QString::fromUtf8("leOldPass"));
        leOldPass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leOldPass, 2, 0, 1, 1);

        leNewPass = new QLineEdit(DlgUserPasswords);
        leNewPass->setObjectName(QString::fromUtf8("leNewPass"));
        leNewPass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(leNewPass, 3, 0, 1, 1);

        chWaiter = new QCheckBox(DlgUserPasswords);
        chWaiter->setObjectName(QString::fromUtf8("chWaiter"));

        gridLayout->addWidget(chWaiter, 4, 0, 1, 1);

        chManager = new QCheckBox(DlgUserPasswords);
        chManager->setObjectName(QString::fromUtf8("chManager"));

        gridLayout->addWidget(chManager, 1, 0, 1, 1);

        lbUsername = new QLabel(DlgUserPasswords);
        lbUsername->setObjectName(QString::fromUtf8("lbUsername"));
        lbUsername->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbUsername, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget = new QWidget(DlgUserPasswords);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(chManager, leOldPass);
        QWidget::setTabOrder(leOldPass, leNewPass);
        QWidget::setTabOrder(leNewPass, chWaiter);
        QWidget::setTabOrder(chWaiter, lePos);
        QWidget::setTabOrder(lePos, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(DlgUserPasswords);

        QMetaObject::connectSlotsByName(DlgUserPasswords);
    } // setupUi

    void retranslateUi(QDialog *DlgUserPasswords)
    {
        DlgUserPasswords->setWindowTitle(QCoreApplication::translate("DlgUserPasswords", "Change password", nullptr));
        lePos->setPlaceholderText(QCoreApplication::translate("DlgUserPasswords", "New POS password", nullptr));
        leOldPass->setPlaceholderText(QCoreApplication::translate("DlgUserPasswords", "Current password", nullptr));
        leNewPass->setPlaceholderText(QCoreApplication::translate("DlgUserPasswords", "New password", nullptr));
        chWaiter->setText(QCoreApplication::translate("DlgUserPasswords", "POS", nullptr));
        chManager->setText(QCoreApplication::translate("DlgUserPasswords", "Manager", nullptr));
        lbUsername->setText(QCoreApplication::translate("DlgUserPasswords", "Username", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgUserPasswords", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgUserPasswords", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgUserPasswords: public Ui_DlgUserPasswords {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGUSERPASSWORDS_H
