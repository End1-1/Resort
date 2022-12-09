/********************************************************************************
** Form generated from reading UI file 'dlgnotes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGNOTES_H
#define UI_DLGNOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqcombobox.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgNotes
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *leCode;
    EQLineEdit *leGuestCode;
    EQLineEdit *leNationality;
    QTextEdit *teText;
    QWidget *wdSchedule;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDissmiss;
    QPushButton *btnSchedule;
    QLabel *label;
    EQLineEdit *leRoomCode;
    QLabel *label_8;
    QLabel *label_5;
    EQLineEdit *leRoomName;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    EQComboBox *cbState;
    QDateTimeEdit *deInterval;
    QDateTimeEdit *deStart;
    QLabel *label_7;
    QLabel *label_10;
    EQLineEdit *leGroupCode;
    EQLineEdit *leGroupName;
    EQLineEdit *leGuestName;
    QLabel *label_11;
    QLineEdit *leAuthor;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgNotes)
    {
        if (DlgNotes->objectName().isEmpty())
            DlgNotes->setObjectName(QString::fromUtf8("DlgNotes"));
        DlgNotes->resize(400, 390);
        verticalLayout = new QVBoxLayout(DlgNotes);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leCode = new QLineEdit(DlgNotes);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setReadOnly(true);

        gridLayout->addWidget(leCode, 0, 1, 1, 2);

        leGuestCode = new EQLineEdit(DlgNotes);
        leGuestCode->setObjectName(QString::fromUtf8("leGuestCode"));
        leGuestCode->setMaximumSize(QSize(80, 16777215));
        leGuestCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leGuestCode, 5, 1, 1, 1);

        leNationality = new EQLineEdit(DlgNotes);
        leNationality->setObjectName(QString::fromUtf8("leNationality"));
        leNationality->setReadOnly(true);

        gridLayout->addWidget(leNationality, 6, 1, 1, 2);

        teText = new QTextEdit(DlgNotes);
        teText->setObjectName(QString::fromUtf8("teText"));
        teText->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(teText, 9, 1, 1, 2);

        wdSchedule = new QWidget(DlgNotes);
        wdSchedule->setObjectName(QString::fromUtf8("wdSchedule"));
        wdSchedule->setMinimumSize(QSize(0, 30));
        wdSchedule->setMaximumSize(QSize(16777215, 3333));
        horizontalLayout = new QHBoxLayout(wdSchedule);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        label_9 = new QLabel(wdSchedule);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        horizontalSpacer = new QSpacerItem(149, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnDissmiss = new QPushButton(wdSchedule);
        btnDissmiss->setObjectName(QString::fromUtf8("btnDissmiss"));

        horizontalLayout->addWidget(btnDissmiss);

        btnSchedule = new QPushButton(wdSchedule);
        btnSchedule->setObjectName(QString::fromUtf8("btnSchedule"));

        horizontalLayout->addWidget(btnSchedule);


        gridLayout->addWidget(wdSchedule, 10, 0, 1, 3);

        label = new QLabel(DlgNotes);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leRoomCode = new EQLineEdit(DlgNotes);
        leRoomCode->setObjectName(QString::fromUtf8("leRoomCode"));
        leRoomCode->setMaximumSize(QSize(80, 16777215));
        leRoomCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leRoomCode, 2, 1, 1, 1);

        label_8 = new QLabel(DlgNotes);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 9, 0, 1, 1);

        label_5 = new QLabel(DlgNotes);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        leRoomName = new EQLineEdit(DlgNotes);
        leRoomName->setObjectName(QString::fromUtf8("leRoomName"));
        leRoomName->setReadOnly(true);

        gridLayout->addWidget(leRoomName, 2, 2, 1, 1);

        label_3 = new QLabel(DlgNotes);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(DlgNotes);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(DlgNotes);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_6 = new QLabel(DlgNotes);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        cbState = new EQComboBox(DlgNotes);
        cbState->setObjectName(QString::fromUtf8("cbState"));

        gridLayout->addWidget(cbState, 1, 1, 1, 2);

        deInterval = new QDateTimeEdit(DlgNotes);
        deInterval->setObjectName(QString::fromUtf8("deInterval"));

        gridLayout->addWidget(deInterval, 4, 1, 1, 2);

        deStart = new QDateTimeEdit(DlgNotes);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setCalendarPopup(true);

        gridLayout->addWidget(deStart, 3, 1, 1, 2);

        label_7 = new QLabel(DlgNotes);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_10 = new QLabel(DlgNotes);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 7, 0, 1, 1);

        leGroupCode = new EQLineEdit(DlgNotes);
        leGroupCode->setObjectName(QString::fromUtf8("leGroupCode"));
        leGroupCode->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(leGroupCode, 7, 1, 1, 1);

        leGroupName = new EQLineEdit(DlgNotes);
        leGroupName->setObjectName(QString::fromUtf8("leGroupName"));
        leGroupName->setReadOnly(true);

        gridLayout->addWidget(leGroupName, 7, 2, 1, 1);

        leGuestName = new EQLineEdit(DlgNotes);
        leGuestName->setObjectName(QString::fromUtf8("leGuestName"));
        leGuestName->setReadOnly(true);

        gridLayout->addWidget(leGuestName, 5, 2, 1, 1);

        label_11 = new QLabel(DlgNotes);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 8, 0, 1, 1);

        leAuthor = new QLineEdit(DlgNotes);
        leAuthor->setObjectName(QString::fromUtf8("leAuthor"));
        leAuthor->setReadOnly(true);

        gridLayout->addWidget(leAuthor, 8, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(DlgNotes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DlgNotes);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgNotes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgNotes, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgNotes);
    } // setupUi

    void retranslateUi(QDialog *DlgNotes)
    {
        DlgNotes->setWindowTitle(QCoreApplication::translate("DlgNotes", "Note", nullptr));
        label_9->setText(QCoreApplication::translate("DlgNotes", "What the next", nullptr));
        btnDissmiss->setText(QCoreApplication::translate("DlgNotes", "Dissmis", nullptr));
        btnSchedule->setText(QCoreApplication::translate("DlgNotes", "Schedule", nullptr));
        label->setText(QCoreApplication::translate("DlgNotes", "Code", nullptr));
        label_8->setText(QCoreApplication::translate("DlgNotes", "Text", nullptr));
        label_5->setText(QCoreApplication::translate("DlgNotes", "Interval", nullptr));
        label_3->setText(QCoreApplication::translate("DlgNotes", "Room", nullptr));
        label_2->setText(QCoreApplication::translate("DlgNotes", "State", nullptr));
        label_4->setText(QCoreApplication::translate("DlgNotes", "Date start", nullptr));
        label_6->setText(QCoreApplication::translate("DlgNotes", "Guest", nullptr));
        cbState->setProperty("Cache", QVariant(QCoreApplication::translate("DlgNotes", "56", nullptr)));
        deInterval->setDisplayFormat(QCoreApplication::translate("DlgNotes", "HH:mm", nullptr));
        label_7->setText(QCoreApplication::translate("DlgNotes", "Naitonality", nullptr));
        label_10->setText(QCoreApplication::translate("DlgNotes", "Group", nullptr));
        label_11->setText(QCoreApplication::translate("DlgNotes", "Author", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgNotes: public Ui_DlgNotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGNOTES_H
