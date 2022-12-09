/********************************************************************************
** Form generated from reading UI file 'wguest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WGUEST_H
#define UI_WGUEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcombobox.h>
#include <eqlineedit.h>
#include <eqtextedit.h>

QT_BEGIN_NAMESPACE

class Ui_WGuest
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leNationality;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_14;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_15;
    EQLineEdit *leNationalityCode;
    EQLineEdit *leGuestCode;
    EQLineEdit *leTitle;
    EQLineEdit *leFirstname;
    EQLineEdit *leLastname;
    EQComboBox *cbSex;
    EQLineEdit *lePlaceBirth;
    EQLineEdit *lePassport;
    EQLineEdit *leAddress;
    EQLineEdit *leTel1;
    EQLineEdit *leTel2;
    EQLineEdit *leEmail;
    EQLineEdit *lePostBox;
    EQTextEdit *teRemarks;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRemove;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnReadFromDevice;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    EDateEdit *deBirth;

    void setupUi(QWidget *WGuest)
    {
        if (WGuest->objectName().isEmpty())
            WGuest->setObjectName(QString::fromUtf8("WGuest"));
        WGuest->resize(536, 502);
        verticalLayout = new QVBoxLayout(WGuest);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leNationality = new EQLineEdit(WGuest);
        leNationality->setObjectName(QString::fromUtf8("leNationality"));
        leNationality->setFocusPolicy(Qt::NoFocus);
        leNationality->setReadOnly(true);

        gridLayout->addWidget(leNationality, 7, 2, 1, 1);

        label_5 = new QLabel(WGuest);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(WGuest);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(WGuest);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(WGuest);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(WGuest);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label = new QLabel(WGuest);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_11 = new QLabel(WGuest);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 10, 0, 1, 1);

        label_9 = new QLabel(WGuest);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        label_14 = new QLabel(WGuest);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 13, 0, 1, 1);

        label_10 = new QLabel(WGuest);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        label_13 = new QLabel(WGuest);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 12, 0, 1, 1);

        label_12 = new QLabel(WGuest);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 11, 0, 1, 1);

        label_7 = new QLabel(WGuest);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_8 = new QLabel(WGuest);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label_15 = new QLabel(WGuest);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 14, 0, 1, 1);

        leNationalityCode = new EQLineEdit(WGuest);
        leNationalityCode->setObjectName(QString::fromUtf8("leNationalityCode"));
        leNationalityCode->setMaximumSize(QSize(70, 16777215));
        leNationalityCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leNationalityCode, 7, 1, 1, 1);

        leGuestCode = new EQLineEdit(WGuest);
        leGuestCode->setObjectName(QString::fromUtf8("leGuestCode"));
        leGuestCode->setFocusPolicy(Qt::NoFocus);
        leGuestCode->setReadOnly(true);
        leGuestCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leGuestCode, 0, 1, 1, 2);

        leTitle = new EQLineEdit(WGuest);
        leTitle->setObjectName(QString::fromUtf8("leTitle"));
        leTitle->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leTitle, 1, 1, 1, 2);

        leFirstname = new EQLineEdit(WGuest);
        leFirstname->setObjectName(QString::fromUtf8("leFirstname"));

        gridLayout->addWidget(leFirstname, 2, 1, 1, 2);

        leLastname = new EQLineEdit(WGuest);
        leLastname->setObjectName(QString::fromUtf8("leLastname"));

        gridLayout->addWidget(leLastname, 3, 1, 1, 2);

        cbSex = new EQComboBox(WGuest);
        cbSex->setObjectName(QString::fromUtf8("cbSex"));
        cbSex->setProperty("Cache", QVariant(52));

        gridLayout->addWidget(cbSex, 4, 1, 1, 2);

        lePlaceBirth = new EQLineEdit(WGuest);
        lePlaceBirth->setObjectName(QString::fromUtf8("lePlaceBirth"));

        gridLayout->addWidget(lePlaceBirth, 6, 1, 1, 2);

        lePassport = new EQLineEdit(WGuest);
        lePassport->setObjectName(QString::fromUtf8("lePassport"));

        gridLayout->addWidget(lePassport, 8, 1, 1, 2);

        leAddress = new EQLineEdit(WGuest);
        leAddress->setObjectName(QString::fromUtf8("leAddress"));

        gridLayout->addWidget(leAddress, 9, 1, 1, 2);

        leTel1 = new EQLineEdit(WGuest);
        leTel1->setObjectName(QString::fromUtf8("leTel1"));

        gridLayout->addWidget(leTel1, 10, 1, 1, 2);

        leTel2 = new EQLineEdit(WGuest);
        leTel2->setObjectName(QString::fromUtf8("leTel2"));

        gridLayout->addWidget(leTel2, 11, 1, 1, 2);

        leEmail = new EQLineEdit(WGuest);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        gridLayout->addWidget(leEmail, 12, 1, 1, 2);

        lePostBox = new EQLineEdit(WGuest);
        lePostBox->setObjectName(QString::fromUtf8("lePostBox"));

        gridLayout->addWidget(lePostBox, 13, 1, 1, 2);

        teRemarks = new EQTextEdit(WGuest);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));
        teRemarks->setMaximumSize(QSize(16777215, 75));

        gridLayout->addWidget(teRemarks, 14, 1, 1, 2);

        widget = new QWidget(WGuest);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnRemove = new QPushButton(widget);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        horizontalLayout->addWidget(btnRemove);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnReadFromDevice = new QPushButton(widget);
        btnReadFromDevice->setObjectName(QString::fromUtf8("btnReadFromDevice"));

        horizontalLayout->addWidget(btnReadFromDevice);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 15, 0, 1, 4);

        deBirth = new EDateEdit(WGuest);
        deBirth->setObjectName(QString::fromUtf8("deBirth"));
        deBirth->setProperty("DoNotCheckMinDate", QVariant(true));

        gridLayout->addWidget(deBirth, 5, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leTitle, leFirstname);
        QWidget::setTabOrder(leFirstname, leLastname);
        QWidget::setTabOrder(leLastname, cbSex);
        QWidget::setTabOrder(cbSex, deBirth);
        QWidget::setTabOrder(deBirth, lePlaceBirth);
        QWidget::setTabOrder(lePlaceBirth, leNationalityCode);
        QWidget::setTabOrder(leNationalityCode, lePassport);
        QWidget::setTabOrder(lePassport, leAddress);
        QWidget::setTabOrder(leAddress, leTel1);
        QWidget::setTabOrder(leTel1, leTel2);
        QWidget::setTabOrder(leTel2, leEmail);
        QWidget::setTabOrder(leEmail, lePostBox);
        QWidget::setTabOrder(lePostBox, teRemarks);
        QWidget::setTabOrder(teRemarks, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);
        QWidget::setTabOrder(btnCancel, leNationality);

        retranslateUi(WGuest);

        QMetaObject::connectSlotsByName(WGuest);
    } // setupUi

    void retranslateUi(QWidget *WGuest)
    {
        WGuest->setWindowTitle(QCoreApplication::translate("WGuest", "Guest info", nullptr));
        label_5->setText(QCoreApplication::translate("WGuest", "Code", nullptr));
        label_6->setText(QCoreApplication::translate("WGuest", "Date of birth", nullptr));
        label_2->setText(QCoreApplication::translate("WGuest", "First name", nullptr));
        label_3->setText(QCoreApplication::translate("WGuest", "Last name", nullptr));
        label_4->setText(QCoreApplication::translate("WGuest", "Sex", nullptr));
        label->setText(QCoreApplication::translate("WGuest", "Title", nullptr));
        label_11->setText(QCoreApplication::translate("WGuest", "Tel. 1", nullptr));
        label_9->setText(QCoreApplication::translate("WGuest", "Passport", nullptr));
        label_14->setText(QCoreApplication::translate("WGuest", "Post box", nullptr));
        label_10->setText(QCoreApplication::translate("WGuest", "Address", nullptr));
        label_13->setText(QCoreApplication::translate("WGuest", "Email", nullptr));
        label_12->setText(QCoreApplication::translate("WGuest", "Tel. 2", nullptr));
        label_7->setText(QCoreApplication::translate("WGuest", "Country of resident", nullptr));
        label_8->setText(QCoreApplication::translate("WGuest", "Nationality", nullptr));
        label_15->setText(QCoreApplication::translate("WGuest", "Remarks", nullptr));
        leNationalityCode->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_nation", nullptr)));
        leGuestCode->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_id", nullptr)));
        leTitle->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_title", nullptr)));
        leFirstname->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_firstName", nullptr)));
        leLastname->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_lastName", nullptr)));
        cbSex->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_sex", nullptr)));
        lePlaceBirth->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_placeBirth", nullptr)));
        lePassport->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_passport", nullptr)));
        leAddress->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_address", nullptr)));
        leTel1->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_tel1", nullptr)));
        leTel2->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_tel2", nullptr)));
        leEmail->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_email", nullptr)));
        lePostBox->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_postBox", nullptr)));
        teRemarks->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_remarks", nullptr)));
        btnRemove->setText(QCoreApplication::translate("WGuest", "Remove", nullptr));
        btnReadFromDevice->setText(QCoreApplication::translate("WGuest", "Read from device", nullptr));
        btnOk->setText(QCoreApplication::translate("WGuest", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("WGuest", "Cancel", nullptr));
        deBirth->setProperty("Field", QVariant(QCoreApplication::translate("WGuest", "f_dateBirth", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class WGuest: public Ui_WGuest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WGUEST_H
