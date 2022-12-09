/********************************************************************************
** Form generated from reading UI file 'rerestmenunames.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTMENUNAMES_H
#define UI_RERESTMENUNAMES_H

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
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERestMenuNames
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leNameAm;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    EQLineEdit *leCode;
    EQLineEdit *leNameRu;
    EQLineEdit *leNameEn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RERestMenuNames)
    {
        if (RERestMenuNames->objectName().isEmpty())
            RERestMenuNames->setObjectName(QString::fromUtf8("RERestMenuNames"));
        RERestMenuNames->resize(327, 165);
        verticalLayout = new QVBoxLayout(RERestMenuNames);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leNameAm = new EQLineEdit(RERestMenuNames);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 1, 1, 1, 1);

        label_2 = new QLabel(RERestMenuNames);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(RERestMenuNames);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(RERestMenuNames);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(RERestMenuNames);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leCode = new EQLineEdit(RERestMenuNames);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leNameRu = new EQLineEdit(RERestMenuNames);
        leNameRu->setObjectName(QString::fromUtf8("leNameRu"));

        gridLayout->addWidget(leNameRu, 3, 1, 1, 1);

        leNameEn = new EQLineEdit(RERestMenuNames);
        leNameEn->setObjectName(QString::fromUtf8("leNameEn"));

        gridLayout->addWidget(leNameEn, 2, 1, 1, 1);

        widget = new QWidget(RERestMenuNames);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leNameAm, leNameEn);
        QWidget::setTabOrder(leNameEn, leNameRu);
        QWidget::setTabOrder(leNameRu, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);
        QWidget::setTabOrder(btnCancel, leCode);

        retranslateUi(RERestMenuNames);

        QMetaObject::connectSlotsByName(RERestMenuNames);
    } // setupUi

    void retranslateUi(QDialog *RERestMenuNames)
    {
        RERestMenuNames->setWindowTitle(QCoreApplication::translate("RERestMenuNames", "Name of menu", nullptr));
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("RERestMenuNames", "f_am", nullptr)));
        label_2->setText(QCoreApplication::translate("RERestMenuNames", "Name, am", nullptr));
        label->setText(QCoreApplication::translate("RERestMenuNames", "Code", nullptr));
        label_4->setText(QCoreApplication::translate("RERestMenuNames", "Name, ru", nullptr));
        label_3->setText(QCoreApplication::translate("RERestMenuNames", "Name, en", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestMenuNames", "f_id", nullptr)));
        leNameRu->setProperty("Field", QVariant(QCoreApplication::translate("RERestMenuNames", "f_ru", nullptr)));
        leNameEn->setProperty("Field", QVariant(QCoreApplication::translate("RERestMenuNames", "f_en", nullptr)));
        btnOk->setText(QCoreApplication::translate("RERestMenuNames", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestMenuNames", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERestMenuNames: public Ui_RERestMenuNames {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTMENUNAMES_H
