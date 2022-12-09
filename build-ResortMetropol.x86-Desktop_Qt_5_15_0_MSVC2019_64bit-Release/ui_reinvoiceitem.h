/********************************************************************************
** Form generated from reading UI file 'reinvoiceitem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REINVOICEITEM_H
#define UI_REINVOICEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqcheckbox.h>
#include <eqlineedit.h>
#include <eqtablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_REInvoiceItem
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *ArmSoft;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    EQLineEdit *leTaxName;
    QLabel *label_3;
    EQLineEdit *leASCode;
    EQLineEdit *lePrice;
    EQLineEdit *leVaucher;
    QLabel *label_6;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    EQLineEdit *leCode;
    QLabel *label_15;
    QLabel *label_5;
    EQCheckBox *chAuto;
    QLabel *label_11;
    EQLineEdit *leADGT;
    QLabel *label_10;
    EQLineEdit *leNameRu;
    QLabel *label_4;
    EQLineEdit *leGroupName;
    EQLineEdit *leNameEn;
    EQLineEdit *leASType;
    EQLineEdit *leGroupCode;
    QLabel *label_9;
    QLabel *label_8;
    EQCheckBox *chRest;
    EQLineEdit *leNameAm;
    EQLineEdit *leReceptionTax;
    QLabel *label;
    EQLineEdit *leVATDept;
    EQLineEdit *leNoVATDept;
    QLabel *label_7;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    EQTableWidget *tblTaxPrint;
    QWidget *tab_3;
    QFormLayout *formLayout;
    QLabel *label_16;
    EQLineEdit *leAccIncome;
    QLabel *label_17;
    EQLineEdit *leAccIncomeNoVat;
    QLabel *label_18;
    EQLineEdit *leAccVAT;
    QLabel *label_19;
    EQLineEdit *leAccNOVAT;
    EQLineEdit *leByerAcc;
    QSpacerItem *verticalSpacer;
    QLabel *label_20;
    QLabel *label_21;
    EQLineEdit *leAccExpense;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *tnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *REInvoiceItem)
    {
        if (REInvoiceItem->objectName().isEmpty())
            REInvoiceItem->setObjectName(QString::fromUtf8("REInvoiceItem"));
        REInvoiceItem->resize(436, 493);
        verticalLayout = new QVBoxLayout(REInvoiceItem);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ArmSoft = new QTabWidget(REInvoiceItem);
        ArmSoft->setObjectName(QString::fromUtf8("ArmSoft"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        leTaxName = new EQLineEdit(tab);
        leTaxName->setObjectName(QString::fromUtf8("leTaxName"));

        gridLayout->addWidget(leTaxName, 9, 1, 1, 2);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        leASCode = new EQLineEdit(tab);
        leASCode->setObjectName(QString::fromUtf8("leASCode"));

        gridLayout->addWidget(leASCode, 7, 1, 1, 1);

        lePrice = new EQLineEdit(tab);
        lePrice->setObjectName(QString::fromUtf8("lePrice"));

        gridLayout->addWidget(lePrice, 6, 1, 1, 2);

        leVaucher = new EQLineEdit(tab);
        leVaucher->setObjectName(QString::fromUtf8("leVaucher"));

        gridLayout->addWidget(leVaucher, 1, 1, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 1, 0, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 12, 0, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 7, 0, 1, 1);

        leCode = new EQLineEdit(tab);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 2);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 8, 0, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        chAuto = new EQCheckBox(tab);
        chAuto->setObjectName(QString::fromUtf8("chAuto"));

        gridLayout->addWidget(chAuto, 14, 1, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 9, 0, 1, 1);

        leADGT = new EQLineEdit(tab);
        leADGT->setObjectName(QString::fromUtf8("leADGT"));

        gridLayout->addWidget(leADGT, 10, 1, 1, 2);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 14, 0, 1, 1);

        leNameRu = new EQLineEdit(tab);
        leNameRu->setObjectName(QString::fromUtf8("leNameRu"));

        gridLayout->addWidget(leNameRu, 5, 1, 1, 2);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        leGroupName = new EQLineEdit(tab);
        leGroupName->setObjectName(QString::fromUtf8("leGroupName"));
        leGroupName->setFocusPolicy(Qt::NoFocus);
        leGroupName->setReadOnly(true);

        gridLayout->addWidget(leGroupName, 2, 2, 1, 1);

        leNameEn = new EQLineEdit(tab);
        leNameEn->setObjectName(QString::fromUtf8("leNameEn"));

        gridLayout->addWidget(leNameEn, 4, 1, 1, 2);

        leASType = new EQLineEdit(tab);
        leASType->setObjectName(QString::fromUtf8("leASType"));
        leASType->setProperty("Type", QVariant(1));

        gridLayout->addWidget(leASType, 8, 1, 1, 1);

        leGroupCode = new EQLineEdit(tab);
        leGroupCode->setObjectName(QString::fromUtf8("leGroupCode"));
        leGroupCode->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(leGroupCode, 2, 1, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 13, 0, 1, 1);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 11, 0, 1, 1);

        chRest = new EQCheckBox(tab);
        chRest->setObjectName(QString::fromUtf8("chRest"));
        chRest->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(chRest, 14, 2, 1, 1);

        leNameAm = new EQLineEdit(tab);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 3, 1, 1, 2);

        leReceptionTax = new EQLineEdit(tab);
        leReceptionTax->setObjectName(QString::fromUtf8("leReceptionTax"));

        gridLayout->addWidget(leReceptionTax, 12, 1, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leVATDept = new EQLineEdit(tab);
        leVATDept->setObjectName(QString::fromUtf8("leVATDept"));

        gridLayout->addWidget(leVATDept, 11, 1, 1, 2);

        leNoVATDept = new EQLineEdit(tab);
        leNoVATDept->setObjectName(QString::fromUtf8("leNoVATDept"));

        gridLayout->addWidget(leNoVATDept, 13, 1, 1, 2);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 10, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        ArmSoft->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tblTaxPrint = new EQTableWidget(tab_2);
        if (tblTaxPrint->columnCount() < 2)
            tblTaxPrint->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblTaxPrint->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblTaxPrint->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tblTaxPrint->setObjectName(QString::fromUtf8("tblTaxPrint"));

        horizontalLayout_3->addWidget(tblTaxPrint);

        ArmSoft->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        formLayout = new QFormLayout(tab_3);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_16);

        leAccIncome = new EQLineEdit(tab_3);
        leAccIncome->setObjectName(QString::fromUtf8("leAccIncome"));

        formLayout->setWidget(0, QFormLayout::FieldRole, leAccIncome);

        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_17);

        leAccIncomeNoVat = new EQLineEdit(tab_3);
        leAccIncomeNoVat->setObjectName(QString::fromUtf8("leAccIncomeNoVat"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leAccIncomeNoVat);

        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_18);

        leAccVAT = new EQLineEdit(tab_3);
        leAccVAT->setObjectName(QString::fromUtf8("leAccVAT"));

        formLayout->setWidget(3, QFormLayout::FieldRole, leAccVAT);

        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_19);

        leAccNOVAT = new EQLineEdit(tab_3);
        leAccNOVAT->setObjectName(QString::fromUtf8("leAccNOVAT"));

        formLayout->setWidget(4, QFormLayout::FieldRole, leAccNOVAT);

        leByerAcc = new EQLineEdit(tab_3);
        leByerAcc->setObjectName(QString::fromUtf8("leByerAcc"));

        formLayout->setWidget(5, QFormLayout::FieldRole, leByerAcc);

        verticalSpacer = new QSpacerItem(295, 251, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(6, QFormLayout::FieldRole, verticalSpacer);

        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_20);

        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_21);

        leAccExpense = new EQLineEdit(tab_3);
        leAccExpense->setObjectName(QString::fromUtf8("leAccExpense"));

        formLayout->setWidget(2, QFormLayout::FieldRole, leAccExpense);

        ArmSoft->addTab(tab_3, QString());

        verticalLayout->addWidget(ArmSoft);

        widget = new QWidget(REInvoiceItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        tnCancel = new QPushButton(widget);
        tnCancel->setObjectName(QString::fromUtf8("tnCancel"));

        horizontalLayout->addWidget(tnCancel);

        horizontalSpacer_2 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(leVaucher, leGroupCode);
        QWidget::setTabOrder(leGroupCode, leNameAm);
        QWidget::setTabOrder(leNameAm, leNameEn);
        QWidget::setTabOrder(leNameEn, leNameRu);
        QWidget::setTabOrder(leNameRu, lePrice);
        QWidget::setTabOrder(lePrice, leASCode);
        QWidget::setTabOrder(leASCode, leASType);
        QWidget::setTabOrder(leASType, leTaxName);
        QWidget::setTabOrder(leTaxName, leADGT);
        QWidget::setTabOrder(leADGT, leVATDept);
        QWidget::setTabOrder(leVATDept, leReceptionTax);
        QWidget::setTabOrder(leReceptionTax, leNoVATDept);
        QWidget::setTabOrder(leNoVATDept, chAuto);
        QWidget::setTabOrder(chAuto, chRest);
        QWidget::setTabOrder(chRest, btnOk);
        QWidget::setTabOrder(btnOk, tnCancel);
        QWidget::setTabOrder(tnCancel, tblTaxPrint);
        QWidget::setTabOrder(tblTaxPrint, ArmSoft);

        retranslateUi(REInvoiceItem);

        ArmSoft->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(REInvoiceItem);
    } // setupUi

    void retranslateUi(QDialog *REInvoiceItem)
    {
        REInvoiceItem->setWindowTitle(QCoreApplication::translate("REInvoiceItem", "Invoice Item", nullptr));
        label_2->setText(QCoreApplication::translate("REInvoiceItem", "Group", nullptr));
        leTaxName->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_taxName", nullptr)));
        label_3->setText(QCoreApplication::translate("REInvoiceItem", "Name, am", nullptr));
        leASCode->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_ascode", nullptr)));
        lePrice->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_price", nullptr)));
        leVaucher->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_vaucher", nullptr)));
        label_6->setText(QCoreApplication::translate("REInvoiceItem", "Price", nullptr));
        label_12->setText(QCoreApplication::translate("REInvoiceItem", "Voucher type", nullptr));
        label_13->setText(QCoreApplication::translate("REInvoiceItem", "Tax, reception", nullptr));
        label_14->setText(QCoreApplication::translate("REInvoiceItem", "AS code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_id", nullptr)));
        label_15->setText(QCoreApplication::translate("REInvoiceItem", "AS type", nullptr));
        label_5->setText(QCoreApplication::translate("REInvoiceItem", "Name, ru", nullptr));
        chAuto->setText(QString());
        chAuto->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_auto", nullptr)));
        label_11->setText(QCoreApplication::translate("REInvoiceItem", "Tax an AS name", nullptr));
        leADGT->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_adgt", nullptr)));
        label_10->setText(QCoreApplication::translate("REInvoiceItem", "No manual charge", nullptr));
        leNameRu->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_ru", nullptr)));
        label_4->setText(QCoreApplication::translate("REInvoiceItem", "Name, en", nullptr));
        leNameEn->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_en", nullptr)));
        leASType->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_astype", nullptr)));
        leGroupCode->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_group", nullptr)));
        label_9->setText(QCoreApplication::translate("REInvoiceItem", "Tax No VAT dept", nullptr));
        label_8->setText(QCoreApplication::translate("REInvoiceItem", "Tax VAT dept", nullptr));
        chRest->setText(QCoreApplication::translate("REInvoiceItem", "Available in restaurant", nullptr));
        chRest->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_rest", nullptr)));
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_am", nullptr)));
        label->setText(QCoreApplication::translate("REInvoiceItem", "Code", nullptr));
        leVATDept->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_vatDept", nullptr)));
        leNoVATDept->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_noVatDept", nullptr)));
        label_7->setText(QCoreApplication::translate("REInvoiceItem", "ADGT code", nullptr));
        ArmSoft->setTabText(ArmSoft->indexOf(tab), QCoreApplication::translate("REInvoiceItem", "Main", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tblTaxPrint->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("REInvoiceItem", "Computer", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tblTaxPrint->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("REInvoiceItem", "Department", nullptr));
        ArmSoft->setTabText(ArmSoft->indexOf(tab_2), QCoreApplication::translate("REInvoiceItem", "Tax Print", nullptr));
        label_16->setText(QCoreApplication::translate("REInvoiceItem", "Acc income", nullptr));
        leAccIncome->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_asaccincome", nullptr)));
        label_17->setText(QCoreApplication::translate("REInvoiceItem", "Acc income no VAT", nullptr));
        leAccIncomeNoVat->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_accincome_novat", nullptr)));
        label_18->setText(QCoreApplication::translate("REInvoiceItem", "Acc VAT type", nullptr));
        leAccVAT->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_accvat", nullptr)));
        label_19->setText(QCoreApplication::translate("REInvoiceItem", "Acc no VAT type", nullptr));
        leAccNOVAT->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_accnovat", nullptr)));
        leByerAcc->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_byeracc", nullptr)));
        label_20->setText(QCoreApplication::translate("REInvoiceItem", "Bayer acc", nullptr));
        label_21->setText(QCoreApplication::translate("REInvoiceItem", "Acc expense", nullptr));
        leAccExpense->setProperty("Field", QVariant(QCoreApplication::translate("REInvoiceItem", "f_asaccexpense", nullptr)));
        ArmSoft->setTabText(ArmSoft->indexOf(tab_3), QCoreApplication::translate("REInvoiceItem", "ArmSoft", nullptr));
        btnOk->setText(QCoreApplication::translate("REInvoiceItem", "OK", nullptr));
        tnCancel->setText(QCoreApplication::translate("REInvoiceItem", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REInvoiceItem: public Ui_REInvoiceItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REINVOICEITEM_H
