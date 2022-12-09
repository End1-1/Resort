/********************************************************************************
** Form generated from reading UI file 'fexportreservation.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEXPORTRESERVATION_H
#define UI_FEXPORTRESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>
#include <wdate2.h>

QT_BEGIN_NAMESPACE

class Ui_FExportReservation
{
public:
    QHBoxLayout *horizontalLayout;
    WDate2 *wd;
    QRadioButton *rbEntry;
    QRadioButton *rbDeparture;
    QRadioButton *rbCreated;
    QRadioButton *rbCanceled;
    QLabel *label;
    EQLineEdit *leStateCode;
    EQLineEdit *leStateName;
    QCheckBox *chSelectAll;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chOverride;
    QPushButton *btnStartExport;

    void setupUi(QWidget *FExportReservation)
    {
        if (FExportReservation->objectName().isEmpty())
            FExportReservation->setObjectName(QString::fromUtf8("FExportReservation"));
        FExportReservation->resize(971, 41);
        horizontalLayout = new QHBoxLayout(FExportReservation);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wd = new WDate2(FExportReservation);
        wd->setObjectName(QString::fromUtf8("wd"));

        horizontalLayout->addWidget(wd);

        rbEntry = new QRadioButton(FExportReservation);
        rbEntry->setObjectName(QString::fromUtf8("rbEntry"));
        rbEntry->setFocusPolicy(Qt::ClickFocus);
        rbEntry->setChecked(true);

        horizontalLayout->addWidget(rbEntry);

        rbDeparture = new QRadioButton(FExportReservation);
        rbDeparture->setObjectName(QString::fromUtf8("rbDeparture"));
        rbDeparture->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbDeparture);

        rbCreated = new QRadioButton(FExportReservation);
        rbCreated->setObjectName(QString::fromUtf8("rbCreated"));
        rbCreated->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbCreated);

        rbCanceled = new QRadioButton(FExportReservation);
        rbCanceled->setObjectName(QString::fromUtf8("rbCanceled"));
        rbCanceled->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(rbCanceled);

        label = new QLabel(FExportReservation);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leStateCode = new EQLineEdit(FExportReservation);
        leStateCode->setObjectName(QString::fromUtf8("leStateCode"));
        leStateCode->setMaximumSize(QSize(50, 16777215));
        leStateCode->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(leStateCode);

        leStateName = new EQLineEdit(FExportReservation);
        leStateName->setObjectName(QString::fromUtf8("leStateName"));
        leStateName->setEnabled(false);
        leStateName->setMaximumSize(QSize(200, 16777215));
        leStateName->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(leStateName);

        chSelectAll = new QCheckBox(FExportReservation);
        chSelectAll->setObjectName(QString::fromUtf8("chSelectAll"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        chSelectAll->setFont(font);

        horizontalLayout->addWidget(chSelectAll);

        horizontalSpacer = new QSpacerItem(254, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chOverride = new QCheckBox(FExportReservation);
        chOverride->setObjectName(QString::fromUtf8("chOverride"));
        chOverride->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chOverride);

        btnStartExport = new QPushButton(FExportReservation);
        btnStartExport->setObjectName(QString::fromUtf8("btnStartExport"));
        btnStartExport->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(btnStartExport);


        retranslateUi(FExportReservation);

        QMetaObject::connectSlotsByName(FExportReservation);
    } // setupUi

    void retranslateUi(QWidget *FExportReservation)
    {
        FExportReservation->setWindowTitle(QCoreApplication::translate("FExportReservation", "Form", nullptr));
        rbEntry->setText(QCoreApplication::translate("FExportReservation", "Entry", nullptr));
        rbDeparture->setText(QCoreApplication::translate("FExportReservation", "Departure", nullptr));
        rbCreated->setText(QCoreApplication::translate("FExportReservation", "Created", nullptr));
        rbCanceled->setText(QCoreApplication::translate("FExportReservation", "Canceled", nullptr));
        label->setText(QCoreApplication::translate("FExportReservation", "State", nullptr));
        chSelectAll->setText(QCoreApplication::translate("FExportReservation", "Select all", nullptr));
        chOverride->setText(QCoreApplication::translate("FExportReservation", "Override", nullptr));
        btnStartExport->setText(QCoreApplication::translate("FExportReservation", "Export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FExportReservation: public Ui_FExportReservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEXPORTRESERVATION_H
