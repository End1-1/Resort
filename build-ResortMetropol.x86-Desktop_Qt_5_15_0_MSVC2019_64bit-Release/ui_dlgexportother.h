/********************************************************************************
** Form generated from reading UI file 'dlgexportother.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEXPORTOTHER_H
#define UI_DLGEXPORTOTHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgExportOther
{
public:
    QGridLayout *gridLayout;
    QCheckBox *chUsers;
    QCheckBox *chCardex;
    QCheckBox *chCityLedger;
    QPlainTextEdit *teLog;
    QCheckBox *chReports;
    QCheckBox *chMenu;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *chCorrectCLNames;
    QCheckBox *chUserRights;

    void setupUi(QDialog *DlgExportOther)
    {
        if (DlgExportOther->objectName().isEmpty())
            DlgExportOther->setObjectName(QString::fromUtf8("DlgExportOther"));
        DlgExportOther->resize(437, 417);
        gridLayout = new QGridLayout(DlgExportOther);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chUsers = new QCheckBox(DlgExportOther);
        chUsers->setObjectName(QString::fromUtf8("chUsers"));

        gridLayout->addWidget(chUsers, 0, 2, 1, 1);

        chCardex = new QCheckBox(DlgExportOther);
        chCardex->setObjectName(QString::fromUtf8("chCardex"));

        gridLayout->addWidget(chCardex, 0, 0, 1, 1);

        chCityLedger = new QCheckBox(DlgExportOther);
        chCityLedger->setObjectName(QString::fromUtf8("chCityLedger"));

        gridLayout->addWidget(chCityLedger, 0, 1, 1, 1);

        teLog = new QPlainTextEdit(DlgExportOther);
        teLog->setObjectName(QString::fromUtf8("teLog"));

        gridLayout->addWidget(teLog, 2, 0, 1, 6);

        chReports = new QCheckBox(DlgExportOther);
        chReports->setObjectName(QString::fromUtf8("chReports"));

        gridLayout->addWidget(chReports, 0, 3, 1, 1);

        chMenu = new QCheckBox(DlgExportOther);
        chMenu->setObjectName(QString::fromUtf8("chMenu"));

        gridLayout->addWidget(chMenu, 0, 4, 1, 1);

        widget = new QWidget(DlgExportOther);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnStart = new QPushButton(widget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        horizontalLayout->addWidget(btnStart);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(113, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 3, 0, 1, 6);

        chCorrectCLNames = new QCheckBox(DlgExportOther);
        chCorrectCLNames->setObjectName(QString::fromUtf8("chCorrectCLNames"));

        gridLayout->addWidget(chCorrectCLNames, 1, 1, 1, 1);

        chUserRights = new QCheckBox(DlgExportOther);
        chUserRights->setObjectName(QString::fromUtf8("chUserRights"));

        gridLayout->addWidget(chUserRights, 1, 2, 1, 1);


        retranslateUi(DlgExportOther);

        QMetaObject::connectSlotsByName(DlgExportOther);
    } // setupUi

    void retranslateUi(QDialog *DlgExportOther)
    {
        DlgExportOther->setWindowTitle(QCoreApplication::translate("DlgExportOther", "Export data", nullptr));
        chUsers->setText(QCoreApplication::translate("DlgExportOther", "Users", nullptr));
        chCardex->setText(QCoreApplication::translate("DlgExportOther", "Cardex", nullptr));
        chCityLedger->setText(QCoreApplication::translate("DlgExportOther", "City Ledger", nullptr));
        chReports->setText(QCoreApplication::translate("DlgExportOther", "Reports", nullptr));
        chMenu->setText(QCoreApplication::translate("DlgExportOther", "Menu", nullptr));
        btnStart->setText(QCoreApplication::translate("DlgExportOther", "Start", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgExportOther", "Cancel", nullptr));
        chCorrectCLNames->setText(QCoreApplication::translate("DlgExportOther", "C/L voiuchers correction", nullptr));
        chUserRights->setText(QCoreApplication::translate("DlgExportOther", "Users rights", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgExportOther: public Ui_DlgExportOther {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEXPORTOTHER_H
