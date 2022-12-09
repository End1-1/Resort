/********************************************************************************
** Form generated from reading UI file 'ftrackchanges.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTRACKCHANGES_H
#define UI_FTRACKCHANGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqdateedit.h>
#include <eqlineedit.h>
#include <eqtimeedit.h>

QT_BEGIN_NAMESPACE

class Ui_FTrackChanges
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leUser;
    QSpacerItem *horizontalSpacer;
    EQDateEdit *deEnd;
    QLabel *label_3;
    QLabel *label_4;
    EQTimeEdit *teStart;
    EQTimeEdit *teEnd;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    EQDateEdit *deStart;
    QLabel *label_6;
    EQLineEdit *leType;
    QLabel *label_7;
    EQLineEdit *leID;
    QPushButton *btnClearLog;

    void setupUi(QWidget *FTrackChanges)
    {
        if (FTrackChanges->objectName().isEmpty())
            FTrackChanges->setObjectName(QString::fromUtf8("FTrackChanges"));
        FTrackChanges->resize(907, 51);
        verticalLayout = new QVBoxLayout(FTrackChanges);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leUser = new EQLineEdit(FTrackChanges);
        leUser->setObjectName(QString::fromUtf8("leUser"));
        leUser->setMinimumSize(QSize(250, 0));
        leUser->setProperty("ShowButton", QVariant(true));
        leUser->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leUser, 0, 9, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 10, 1, 1);

        deEnd = new EQDateEdit(FTrackChanges);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 0, 3, 1, 1);

        label_3 = new QLabel(FTrackChanges);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        label_4 = new QLabel(FTrackChanges);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        teStart = new EQTimeEdit(FTrackChanges);
        teStart->setObjectName(QString::fromUtf8("teStart"));
        teStart->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 1)));

        gridLayout->addWidget(teStart, 0, 5, 1, 1);

        teEnd = new EQTimeEdit(FTrackChanges);
        teEnd->setObjectName(QString::fromUtf8("teEnd"));
        teEnd->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(23, 59, 59)));

        gridLayout->addWidget(teEnd, 0, 7, 1, 1);

        label_5 = new QLabel(FTrackChanges);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 8, 1, 1);

        label = new QLabel(FTrackChanges);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(FTrackChanges);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        deStart = new EQDateEdit(FTrackChanges);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 0, 1, 1, 1);

        label_6 = new QLabel(FTrackChanges);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        leType = new EQLineEdit(FTrackChanges);
        leType->setObjectName(QString::fromUtf8("leType"));
        leType->setProperty("ShowButton", QVariant(true));
        leType->setProperty("EnableHiddenText", QVariant(true));

        gridLayout->addWidget(leType, 1, 1, 1, 3);

        label_7 = new QLabel(FTrackChanges);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 1, 4, 1, 1);

        leID = new EQLineEdit(FTrackChanges);
        leID->setObjectName(QString::fromUtf8("leID"));

        gridLayout->addWidget(leID, 1, 5, 1, 1);

        btnClearLog = new QPushButton(FTrackChanges);
        btnClearLog->setObjectName(QString::fromUtf8("btnClearLog"));

        gridLayout->addWidget(btnClearLog, 1, 9, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(FTrackChanges);

        QMetaObject::connectSlotsByName(FTrackChanges);
    } // setupUi

    void retranslateUi(QWidget *FTrackChanges)
    {
        FTrackChanges->setWindowTitle(QCoreApplication::translate("FTrackChanges", "Form", nullptr));
        leUser->setProperty("HiddenTextValidator", QVariant(QCoreApplication::translate("FTrackChanges", "[0-9,]*", nullptr)));
        label_3->setText(QCoreApplication::translate("FTrackChanges", "Start time", nullptr));
        label_4->setText(QCoreApplication::translate("FTrackChanges", "End time", nullptr));
        label_5->setText(QCoreApplication::translate("FTrackChanges", "Users", nullptr));
        label->setText(QCoreApplication::translate("FTrackChanges", "Start date", nullptr));
        label_2->setText(QCoreApplication::translate("FTrackChanges", "End date", nullptr));
        label_6->setText(QCoreApplication::translate("FTrackChanges", "Type", nullptr));
        leType->setInputMask(QString());
        leType->setPlaceholderText(QString());
        leType->setProperty("HiddenTextValidator", QVariant(QCoreApplication::translate("FTrackChanges", "[0-9,]*", nullptr)));
        label_7->setText(QCoreApplication::translate("FTrackChanges", "ID", nullptr));
        btnClearLog->setText(QCoreApplication::translate("FTrackChanges", "Clear log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FTrackChanges: public Ui_FTrackChanges {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTRACKCHANGES_H
