/********************************************************************************
** Form generated from reading UI file 'dlgchangeclofvaucher.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCHANGECLOFVAUCHER_H
#define UI_DLGCHANGECLOFVAUCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgChangeCLOfVaucher
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    EQLineEdit *leOldCLCode;
    EQLineEdit *leOldCLName;
    EQLineEdit *leAmount;
    QLabel *label_4;
    EQLineEdit *leName;
    QLabel *label_3;
    EQLineEdit *leNewCLCode;
    EQLineEdit *leNewCLName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    EQLineEdit *leVaucher;
    QLabel *label_6;
    EQLineEdit *leRoom;

    void setupUi(QDialog *DlgChangeCLOfVaucher)
    {
        if (DlgChangeCLOfVaucher->objectName().isEmpty())
            DlgChangeCLOfVaucher->setObjectName(QString::fromUtf8("DlgChangeCLOfVaucher"));
        DlgChangeCLOfVaucher->resize(400, 215);
        gridLayout = new QGridLayout(DlgChangeCLOfVaucher);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgChangeCLOfVaucher);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(DlgChangeCLOfVaucher);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        leOldCLCode = new EQLineEdit(DlgChangeCLOfVaucher);
        leOldCLCode->setObjectName(QString::fromUtf8("leOldCLCode"));
        leOldCLCode->setEnabled(false);
        leOldCLCode->setMinimumSize(QSize(80, 0));
        leOldCLCode->setFocusPolicy(Qt::NoFocus);
        leOldCLCode->setReadOnly(false);

        gridLayout->addWidget(leOldCLCode, 2, 1, 1, 1);

        leOldCLName = new EQLineEdit(DlgChangeCLOfVaucher);
        leOldCLName->setObjectName(QString::fromUtf8("leOldCLName"));
        leOldCLName->setEnabled(false);
        leOldCLName->setMinimumSize(QSize(200, 0));
        leOldCLName->setFocusPolicy(Qt::NoFocus);
        leOldCLName->setReadOnly(false);

        gridLayout->addWidget(leOldCLName, 2, 2, 1, 1);

        leAmount = new EQLineEdit(DlgChangeCLOfVaucher);
        leAmount->setObjectName(QString::fromUtf8("leAmount"));
        leAmount->setEnabled(false);
        leAmount->setMinimumSize(QSize(80, 0));
        leAmount->setFocusPolicy(Qt::NoFocus);
        leAmount->setReadOnly(false);

        gridLayout->addWidget(leAmount, 4, 1, 1, 1);

        label_4 = new QLabel(DlgChangeCLOfVaucher);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        leName = new EQLineEdit(DlgChangeCLOfVaucher);
        leName->setObjectName(QString::fromUtf8("leName"));
        leName->setEnabled(false);
        leName->setFocusPolicy(Qt::NoFocus);
        leName->setReadOnly(false);

        gridLayout->addWidget(leName, 3, 1, 1, 2);

        label_3 = new QLabel(DlgChangeCLOfVaucher);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        leNewCLCode = new EQLineEdit(DlgChangeCLOfVaucher);
        leNewCLCode->setObjectName(QString::fromUtf8("leNewCLCode"));
        leNewCLCode->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(leNewCLCode, 5, 1, 1, 1);

        leNewCLName = new EQLineEdit(DlgChangeCLOfVaucher);
        leNewCLName->setObjectName(QString::fromUtf8("leNewCLName"));
        leNewCLName->setMinimumSize(QSize(200, 0));
        leNewCLName->setFocusPolicy(Qt::NoFocus);
        leNewCLName->setReadOnly(true);

        gridLayout->addWidget(leNewCLName, 5, 2, 1, 1);

        widget = new QWidget(DlgChangeCLOfVaucher);
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


        gridLayout->addWidget(widget, 6, 0, 1, 3);

        label_5 = new QLabel(DlgChangeCLOfVaucher);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        leVaucher = new EQLineEdit(DlgChangeCLOfVaucher);
        leVaucher->setObjectName(QString::fromUtf8("leVaucher"));
        leVaucher->setEnabled(false);

        gridLayout->addWidget(leVaucher, 0, 1, 1, 2);

        label_6 = new QLabel(DlgChangeCLOfVaucher);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        leRoom = new EQLineEdit(DlgChangeCLOfVaucher);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setEnabled(false);

        gridLayout->addWidget(leRoom, 1, 1, 1, 1);


        retranslateUi(DlgChangeCLOfVaucher);

        QMetaObject::connectSlotsByName(DlgChangeCLOfVaucher);
    } // setupUi

    void retranslateUi(QDialog *DlgChangeCLOfVaucher)
    {
        DlgChangeCLOfVaucher->setWindowTitle(QCoreApplication::translate("DlgChangeCLOfVaucher", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DlgChangeCLOfVaucher", "Current city ledger", nullptr));
        label_2->setText(QCoreApplication::translate("DlgChangeCLOfVaucher", "Name", nullptr));
        label_4->setText(QCoreApplication::translate("DlgChangeCLOfVaucher", "New city ledger", nullptr));
        label_3->setText(QCoreApplication::translate("DlgChangeCLOfVaucher", "Amount", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgChangeCLOfVaucher", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgChangeCLOfVaucher", "Cancel", nullptr));
        label_5->setText(QCoreApplication::translate("DlgChangeCLOfVaucher", "Voucher", nullptr));
        label_6->setText(QCoreApplication::translate("DlgChangeCLOfVaucher", "Room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgChangeCLOfVaucher: public Ui_DlgChangeCLOfVaucher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCHANGECLOFVAUCHER_H
