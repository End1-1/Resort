/********************************************************************************
** Form generated from reading UI file 'dlgtransferlog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGTRANSFERLOG_H
#define UI_DLGTRANSFERLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgTransferLog
{
public:
    QGridLayout *gridLayout;
    EDateEdit *deEnd;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *lbMsg;

    void setupUi(QDialog *DlgTransferLog)
    {
        if (DlgTransferLog->objectName().isEmpty())
            DlgTransferLog->setObjectName(QString::fromUtf8("DlgTransferLog"));
        DlgTransferLog->resize(344, 104);
        gridLayout = new QGridLayout(DlgTransferLog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        deEnd = new EDateEdit(DlgTransferLog);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 0, 2, 1, 1);

        widget = new QWidget(DlgTransferLog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnStart = new QPushButton(widget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        horizontalLayout->addWidget(btnStart);

        horizontalSpacer_2 = new QSpacerItem(107, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 3);

        label = new QLabel(DlgTransferLog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        deStart = new EDateEdit(DlgTransferLog);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 0, 1, 1, 1);

        lbMsg = new QLabel(DlgTransferLog);
        lbMsg->setObjectName(QString::fromUtf8("lbMsg"));

        gridLayout->addWidget(lbMsg, 1, 0, 1, 3);


        retranslateUi(DlgTransferLog);

        QMetaObject::connectSlotsByName(DlgTransferLog);
    } // setupUi

    void retranslateUi(QDialog *DlgTransferLog)
    {
        DlgTransferLog->setWindowTitle(QCoreApplication::translate("DlgTransferLog", "Transfer log", nullptr));
        btnStart->setText(QCoreApplication::translate("DlgTransferLog", "Start", nullptr));
        label->setText(QCoreApplication::translate("DlgTransferLog", "Date range", nullptr));
        lbMsg->setText(QCoreApplication::translate("DlgTransferLog", "Idle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgTransferLog: public Ui_DlgTransferLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGTRANSFERLOG_H
