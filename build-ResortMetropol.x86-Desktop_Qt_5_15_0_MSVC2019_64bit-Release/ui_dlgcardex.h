/********************************************************************************
** Form generated from reading UI file 'dlgcardex.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCARDEX_H
#define UI_DLGCARDEX_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eqdateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgCardex
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leContactPos;
    EQLineEdit *leEmail;
    EQLineEdit *leTel;
    EQLineEdit *leName;
    EQDateEdit *deValidTo;
    QLabel *Cardex;
    QLabel *label_13;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_7;
    EQLineEdit *leAddr1;
    EQLineEdit *leCardex;
    QLabel *label_4;
    QLabel *label_12;
    EQLineEdit *leFax;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    EQLineEdit *leVATModeCode;
    EQLineEdit *leVATModeName;
    QLabel *label_15;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRemove;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    EQLineEdit *leCode;
    EQLineEdit *leContact;
    EQLineEdit *leCardexGroupName;
    EQLineEdit *leAddr2;
    EQDateEdit *deValidFrom;
    EQLineEdit *leCommision;
    EQLineEdit *leCardexGroupCode;
    QLabel *label_2;
    EQLineEdit *leCLCode;
    QCheckBox *chCityLedger;
    EQCheckBox *chBookingRequire;
    EQLineEdit *leExtra2;
    EQLineEdit *leExtra1;
    QLabel *label_16;
    QLabel *label_17;

    void setupUi(QDialog *DlgCardex)
    {
        if (DlgCardex->objectName().isEmpty())
            DlgCardex->setObjectName(QString::fromUtf8("DlgCardex"));
        DlgCardex->resize(630, 448);
        verticalLayout = new QVBoxLayout(DlgCardex);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leContactPos = new EQLineEdit(DlgCardex);
        leContactPos->setObjectName(QString::fromUtf8("leContactPos"));

        gridLayout->addWidget(leContactPos, 6, 1, 1, 6);

        leEmail = new EQLineEdit(DlgCardex);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        gridLayout->addWidget(leEmail, 7, 1, 1, 6);

        leTel = new EQLineEdit(DlgCardex);
        leTel->setObjectName(QString::fromUtf8("leTel"));

        gridLayout->addWidget(leTel, 8, 1, 1, 6);

        leName = new EQLineEdit(DlgCardex);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 2, 1, 1, 6);

        deValidTo = new EQDateEdit(DlgCardex);
        deValidTo->setObjectName(QString::fromUtf8("deValidTo"));
        deValidTo->setMinimumSize(QSize(120, 0));
        deValidTo->setMaximumSize(QSize(120, 16777215));
        deValidTo->setCalendarPopup(true);

        gridLayout->addWidget(deValidTo, 12, 5, 1, 1);

        Cardex = new QLabel(DlgCardex);
        Cardex->setObjectName(QString::fromUtf8("Cardex"));

        gridLayout->addWidget(Cardex, 1, 0, 1, 1);

        label_13 = new QLabel(DlgCardex);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 13, 0, 1, 1);

        label_3 = new QLabel(DlgCardex);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_9 = new QLabel(DlgCardex);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        label_5 = new QLabel(DlgCardex);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_10 = new QLabel(DlgCardex);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        label_6 = new QLabel(DlgCardex);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_8 = new QLabel(DlgCardex);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label_11 = new QLabel(DlgCardex);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 12, 0, 1, 1);

        label_14 = new QLabel(DlgCardex);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 13, 3, 1, 1);

        label_7 = new QLabel(DlgCardex);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        leAddr1 = new EQLineEdit(DlgCardex);
        leAddr1->setObjectName(QString::fromUtf8("leAddr1"));

        gridLayout->addWidget(leAddr1, 3, 1, 1, 6);

        leCardex = new EQLineEdit(DlgCardex);
        leCardex->setObjectName(QString::fromUtf8("leCardex"));
        leCardex->setFocusPolicy(Qt::NoFocus);
        leCardex->setReadOnly(true);

        gridLayout->addWidget(leCardex, 1, 1, 1, 2);

        label_4 = new QLabel(DlgCardex);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_12 = new QLabel(DlgCardex);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 12, 3, 1, 1);

        leFax = new EQLineEdit(DlgCardex);
        leFax->setObjectName(QString::fromUtf8("leFax"));

        gridLayout->addWidget(leFax, 9, 1, 1, 6);

        widget_2 = new QWidget(DlgCardex);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        leVATModeCode = new EQLineEdit(widget_2);
        leVATModeCode->setObjectName(QString::fromUtf8("leVATModeCode"));
        leVATModeCode->setMaximumSize(QSize(50, 16777215));
        leVATModeCode->setProperty("ShowButton", QVariant(true));

        horizontalLayout_2->addWidget(leVATModeCode);

        leVATModeName = new EQLineEdit(widget_2);
        leVATModeName->setObjectName(QString::fromUtf8("leVATModeName"));
        leVATModeName->setMinimumSize(QSize(200, 0));
        leVATModeName->setReadOnly(true);

        horizontalLayout_2->addWidget(leVATModeName);


        gridLayout->addWidget(widget_2, 13, 5, 1, 2);

        label_15 = new QLabel(DlgCardex);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 0, 3, 1, 1);

        widget = new QWidget(DlgCardex);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnRemove = new QPushButton(widget);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        horizontalLayout->addWidget(btnRemove);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 15, 0, 1, 7);

        label = new QLabel(DlgCardex);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(DlgCardex);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leContact = new EQLineEdit(DlgCardex);
        leContact->setObjectName(QString::fromUtf8("leContact"));

        gridLayout->addWidget(leContact, 5, 1, 1, 6);

        leCardexGroupName = new EQLineEdit(DlgCardex);
        leCardexGroupName->setObjectName(QString::fromUtf8("leCardexGroupName"));
        leCardexGroupName->setFocusPolicy(Qt::NoFocus);
        leCardexGroupName->setReadOnly(true);

        gridLayout->addWidget(leCardexGroupName, 0, 5, 1, 1);

        leAddr2 = new EQLineEdit(DlgCardex);
        leAddr2->setObjectName(QString::fromUtf8("leAddr2"));

        gridLayout->addWidget(leAddr2, 4, 1, 1, 6);

        deValidFrom = new EQDateEdit(DlgCardex);
        deValidFrom->setObjectName(QString::fromUtf8("deValidFrom"));
        deValidFrom->setMinimumSize(QSize(120, 0));
        deValidFrom->setMaximumSize(QSize(120, 16777215));
        deValidFrom->setMinimumDate(QDate(2000, 1, 1));
        deValidFrom->setCalendarPopup(true);

        gridLayout->addWidget(deValidFrom, 12, 1, 1, 2);

        leCommision = new EQLineEdit(DlgCardex);
        leCommision->setObjectName(QString::fromUtf8("leCommision"));

        gridLayout->addWidget(leCommision, 13, 1, 1, 2);

        leCardexGroupCode = new EQLineEdit(DlgCardex);
        leCardexGroupCode->setObjectName(QString::fromUtf8("leCardexGroupCode"));

        gridLayout->addWidget(leCardexGroupCode, 0, 4, 1, 1);

        label_2 = new QLabel(DlgCardex);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 3, 1, 1);

        leCLCode = new EQLineEdit(DlgCardex);
        leCLCode->setObjectName(QString::fromUtf8("leCLCode"));

        gridLayout->addWidget(leCLCode, 1, 4, 1, 3);

        chCityLedger = new QCheckBox(DlgCardex);
        chCityLedger->setObjectName(QString::fromUtf8("chCityLedger"));
        chCityLedger->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(chCityLedger, 14, 5, 1, 1);

        chBookingRequire = new EQCheckBox(DlgCardex);
        chBookingRequire->setObjectName(QString::fromUtf8("chBookingRequire"));
        chBookingRequire->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(chBookingRequire, 14, 1, 1, 3);

        leExtra2 = new EQLineEdit(DlgCardex);
        leExtra2->setObjectName(QString::fromUtf8("leExtra2"));

        gridLayout->addWidget(leExtra2, 11, 1, 1, 4);

        leExtra1 = new EQLineEdit(DlgCardex);
        leExtra1->setObjectName(QString::fromUtf8("leExtra1"));

        gridLayout->addWidget(leExtra1, 10, 1, 1, 4);

        label_16 = new QLabel(DlgCardex);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 10, 0, 1, 1);

        label_17 = new QLabel(DlgCardex);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 11, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leCode, leCardexGroupCode);
        QWidget::setTabOrder(leCardexGroupCode, leCardexGroupName);
        QWidget::setTabOrder(leCardexGroupName, leCardex);
        QWidget::setTabOrder(leCardex, leCLCode);
        QWidget::setTabOrder(leCLCode, leName);
        QWidget::setTabOrder(leName, leAddr1);
        QWidget::setTabOrder(leAddr1, leAddr2);
        QWidget::setTabOrder(leAddr2, leContact);
        QWidget::setTabOrder(leContact, leContactPos);
        QWidget::setTabOrder(leContactPos, leEmail);
        QWidget::setTabOrder(leEmail, leTel);
        QWidget::setTabOrder(leTel, leFax);
        QWidget::setTabOrder(leFax, deValidFrom);
        QWidget::setTabOrder(deValidFrom, deValidTo);
        QWidget::setTabOrder(deValidTo, leCommision);
        QWidget::setTabOrder(leCommision, leVATModeCode);
        QWidget::setTabOrder(leVATModeCode, leVATModeName);
        QWidget::setTabOrder(leVATModeName, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(DlgCardex);

        QMetaObject::connectSlotsByName(DlgCardex);
    } // setupUi

    void retranslateUi(QDialog *DlgCardex)
    {
        DlgCardex->setWindowTitle(QCoreApplication::translate("DlgCardex", "Partner", nullptr));
        leContactPos->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_contactPos", nullptr)));
        leEmail->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_email", nullptr)));
        leTel->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_tel", nullptr)));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_name", nullptr)));
        deValidTo->setDisplayFormat(QCoreApplication::translate("DlgCardex", "dd/MM/yyyy", nullptr));
        deValidTo->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_dateTo", nullptr)));
        Cardex->setText(QCoreApplication::translate("DlgCardex", "Code", nullptr));
        label_13->setText(QCoreApplication::translate("DlgCardex", "Comission", nullptr));
        label_3->setText(QCoreApplication::translate("DlgCardex", "Name", nullptr));
        label_9->setText(QCoreApplication::translate("DlgCardex", "Tel.", nullptr));
        label_5->setText(QCoreApplication::translate("DlgCardex", "Address 2", nullptr));
        label_10->setText(QCoreApplication::translate("DlgCardex", "Fax", nullptr));
        label_6->setText(QCoreApplication::translate("DlgCardex", "Contact", nullptr));
        label_8->setText(QCoreApplication::translate("DlgCardex", "Email", nullptr));
        label_11->setText(QCoreApplication::translate("DlgCardex", "Valid from", nullptr));
        label_14->setText(QCoreApplication::translate("DlgCardex", "VAT Mode", nullptr));
        label_7->setText(QCoreApplication::translate("DlgCardex", "Contact position", nullptr));
        leAddr1->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_addr1", nullptr)));
        leCardex->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_cardex", nullptr)));
        label_4->setText(QCoreApplication::translate("DlgCardex", "Address 1", nullptr));
        label_12->setText(QCoreApplication::translate("DlgCardex", "Valid to", nullptr));
        leFax->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_fax", nullptr)));
        leVATModeCode->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_vatMode", nullptr)));
        label_15->setText(QCoreApplication::translate("DlgCardex", "Group", nullptr));
        btnRemove->setText(QCoreApplication::translate("DlgCardex", "Remove", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgCardex", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgCardex", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("DlgCardex", "Code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_id", nullptr)));
        leContact->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_contact", nullptr)));
        leCardexGroupName->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_group", nullptr)));
        leAddr2->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_addr2", nullptr)));
        deValidFrom->setDisplayFormat(QCoreApplication::translate("DlgCardex", "dd/MM/yyyy", nullptr));
        deValidFrom->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_dateFrom", nullptr)));
        leCommision->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_commission", nullptr)));
        label_2->setText(QCoreApplication::translate("DlgCardex", "City ledger code", nullptr));
        leCLCode->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_cityLedger", nullptr)));
        chCityLedger->setText(QCoreApplication::translate("DlgCardex", "Create city ledger", nullptr));
        chBookingRequire->setText(QCoreApplication::translate("DlgCardex", "Booking required", nullptr));
        chBookingRequire->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_bookingRequired", nullptr)));
        leExtra2->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_extra2", nullptr)));
        leExtra1->setProperty("Field", QVariant(QCoreApplication::translate("DlgCardex", "f_extra1", nullptr)));
        label_16->setText(QCoreApplication::translate("DlgCardex", "Extra1", nullptr));
        label_17->setText(QCoreApplication::translate("DlgCardex", "Extra2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgCardex: public Ui_DlgCardex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCARDEX_H
