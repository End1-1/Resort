/********************************************************************************
** Form generated from reading UI file 'dlgusergroup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGUSERGROUP_H
#define UI_DLGUSERGROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgUserGroup
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    EQLineEdit *leNameAm;
    QLabel *label_2;
    EQLineEdit *leCode;
    QLabel *label_4;
    EQLineEdit *leNameEn;
    EQLineEdit *leNameRu;
    EDateEdit *deDate;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgUserGroup)
    {
        if (DlgUserGroup->objectName().isEmpty())
            DlgUserGroup->setObjectName(QString::fromUtf8("DlgUserGroup"));
        DlgUserGroup->resize(400, 206);
        verticalLayout = new QVBoxLayout(DlgUserGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgUserGroup);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(DlgUserGroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leNameAm = new EQLineEdit(DlgUserGroup);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 1, 1, 1, 1);

        label_2 = new QLabel(DlgUserGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leCode = new EQLineEdit(DlgUserGroup);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_4 = new QLabel(DlgUserGroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leNameEn = new EQLineEdit(DlgUserGroup);
        leNameEn->setObjectName(QString::fromUtf8("leNameEn"));

        gridLayout->addWidget(leNameEn, 2, 1, 1, 1);

        leNameRu = new EQLineEdit(DlgUserGroup);
        leNameRu->setObjectName(QString::fromUtf8("leNameRu"));

        gridLayout->addWidget(leNameRu, 3, 1, 1, 1);

        deDate = new EDateEdit(DlgUserGroup);
        deDate->setObjectName(QString::fromUtf8("deDate"));

        gridLayout->addWidget(deDate, 4, 1, 1, 1);

        label_5 = new QLabel(DlgUserGroup);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget = new QWidget(DlgUserGroup);
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


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(leNameAm, leNameEn);
        QWidget::setTabOrder(leNameEn, leNameRu);
        QWidget::setTabOrder(leNameRu, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(DlgUserGroup);

        QMetaObject::connectSlotsByName(DlgUserGroup);
    } // setupUi

    void retranslateUi(QDialog *DlgUserGroup)
    {
        DlgUserGroup->setWindowTitle(QCoreApplication::translate("DlgUserGroup", "User group", nullptr));
        label->setText(QCoreApplication::translate("DlgUserGroup", "Code", nullptr));
        label_3->setText(QCoreApplication::translate("DlgUserGroup", "Name, en", nullptr));
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("DlgUserGroup", "f_am", nullptr)));
        label_2->setText(QCoreApplication::translate("DlgUserGroup", "Name, am", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("DlgUserGroup", "f_id", nullptr)));
        label_4->setText(QCoreApplication::translate("DlgUserGroup", "Name, ru", nullptr));
        leNameEn->setProperty("Field", QVariant(QCoreApplication::translate("DlgUserGroup", "f_en", nullptr)));
        leNameRu->setProperty("Field", QVariant(QCoreApplication::translate("DlgUserGroup", "f_ru", nullptr)));
        deDate->setProperty("Field", QVariant(QCoreApplication::translate("DlgUserGroup", "f_minDate", nullptr)));
        label_5->setText(QCoreApplication::translate("DlgUserGroup", "Min date", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgUserGroup", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgUserGroup", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgUserGroup: public Ui_DlgUserGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGUSERGROUP_H
