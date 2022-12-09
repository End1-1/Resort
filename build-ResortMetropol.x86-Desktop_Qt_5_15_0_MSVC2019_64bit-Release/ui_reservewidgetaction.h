/********************************************************************************
** Form generated from reading UI file 'reservewidgetaction.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVEWIDGETACTION_H
#define UI_RESERVEWIDGETACTION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_ReserveWidgetAction
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QTextEdit *teRemarks;
    QLabel *label_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnLock;
    QPushButton *btnEdit;
    QPushButton *btnUnlock;
    QPushButton *btnCancel;
    QPushButton *btnOk;
    QPushButton *btnRemove;
    EDateEdit *deStart;
    EDateEdit *deEnd;
    QLineEdit *leAuthor;

    void setupUi(QDialog *ReserveWidgetAction)
    {
        if (ReserveWidgetAction->objectName().isEmpty())
            ReserveWidgetAction->setObjectName(QString::fromUtf8("ReserveWidgetAction"));
        ReserveWidgetAction->resize(291, 274);
        gridLayout_2 = new QGridLayout(ReserveWidgetAction);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(ReserveWidgetAction);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        teRemarks = new QTextEdit(ReserveWidgetAction);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));

        gridLayout_2->addWidget(teRemarks, 2, 0, 1, 3);

        label_2 = new QLabel(ReserveWidgetAction);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(ReserveWidgetAction);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnLock = new QPushButton(groupBox);
        btnLock->setObjectName(QString::fromUtf8("btnLock"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLock->setIcon(icon);

        gridLayout->addWidget(btnLock, 1, 0, 1, 1);

        btnEdit = new QPushButton(groupBox);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEdit->setIcon(icon1);

        gridLayout->addWidget(btnEdit, 0, 0, 1, 1);

        btnUnlock = new QPushButton(groupBox);
        btnUnlock->setObjectName(QString::fromUtf8("btnUnlock"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/unlock.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUnlock->setIcon(icon2);

        gridLayout->addWidget(btnUnlock, 1, 1, 1, 1);

        btnCancel = new QPushButton(groupBox);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 2, 1, 1, 1);

        btnOk = new QPushButton(groupBox);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        gridLayout->addWidget(btnOk, 2, 0, 1, 1);

        btnRemove = new QPushButton(groupBox);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/garbage.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon3);

        gridLayout->addWidget(btnRemove, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 3, 0, 1, 3);

        deStart = new EDateEdit(ReserveWidgetAction);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setReadOnly(true);

        gridLayout_2->addWidget(deStart, 1, 1, 1, 1);

        deEnd = new EDateEdit(ReserveWidgetAction);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        deEnd->setReadOnly(true);

        gridLayout_2->addWidget(deEnd, 1, 2, 1, 1);

        leAuthor = new QLineEdit(ReserveWidgetAction);
        leAuthor->setObjectName(QString::fromUtf8("leAuthor"));
        leAuthor->setReadOnly(true);

        gridLayout_2->addWidget(leAuthor, 0, 1, 1, 2);


        retranslateUi(ReserveWidgetAction);

        QMetaObject::connectSlotsByName(ReserveWidgetAction);
    } // setupUi

    void retranslateUi(QDialog *ReserveWidgetAction)
    {
        ReserveWidgetAction->setWindowTitle(QCoreApplication::translate("ReserveWidgetAction", "Reserve action", nullptr));
        label->setText(QCoreApplication::translate("ReserveWidgetAction", "Created by", nullptr));
        teRemarks->setPlaceholderText(QCoreApplication::translate("ReserveWidgetAction", "Remarks", nullptr));
        label_2->setText(QCoreApplication::translate("ReserveWidgetAction", "Range", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ReserveWidgetAction", "Action", nullptr));
        btnLock->setText(QCoreApplication::translate("ReserveWidgetAction", "Lock", nullptr));
        btnEdit->setText(QCoreApplication::translate("ReserveWidgetAction", "Create", nullptr));
        btnUnlock->setText(QCoreApplication::translate("ReserveWidgetAction", "Unlock", nullptr));
        btnCancel->setText(QCoreApplication::translate("ReserveWidgetAction", "Cancel", nullptr));
        btnOk->setText(QCoreApplication::translate("ReserveWidgetAction", "OK", nullptr));
        btnRemove->setText(QCoreApplication::translate("ReserveWidgetAction", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReserveWidgetAction: public Ui_ReserveWidgetAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVEWIDGETACTION_H
