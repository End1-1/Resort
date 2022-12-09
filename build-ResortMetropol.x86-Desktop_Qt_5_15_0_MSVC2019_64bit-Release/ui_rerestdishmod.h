/********************************************************************************
** Form generated from reading UI file 'rerestdishmod.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTDISHMOD_H
#define UI_RERESTDISHMOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERestDishMod
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    EQLineEdit *leCode;
    EQLineEdit *leNameAm;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLabel *label_4;
    EQLineEdit *leNameEn;
    EQLineEdit *leNameRu;

    void setupUi(QDialog *RERestDishMod)
    {
        if (RERestDishMod->objectName().isEmpty())
            RERestDishMod->setObjectName(QString::fromUtf8("RERestDishMod"));
        RERestDishMod->resize(400, 165);
        horizontalLayout = new QHBoxLayout(RERestDishMod);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(RERestDishMod);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(RERestDishMod);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        leCode = new EQLineEdit(RERestDishMod);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leNameAm = new EQLineEdit(RERestDishMod);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 1, 1, 1, 1);

        widget = new QWidget(RERestDishMod);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 2);

        label_3 = new QLabel(RERestDishMod);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(RERestDishMod);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leNameEn = new EQLineEdit(RERestDishMod);
        leNameEn->setObjectName(QString::fromUtf8("leNameEn"));

        gridLayout->addWidget(leNameEn, 2, 1, 1, 1);

        leNameRu = new EQLineEdit(RERestDishMod);
        leNameRu->setObjectName(QString::fromUtf8("leNameRu"));

        gridLayout->addWidget(leNameRu, 3, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leNameAm, leNameEn);
        QWidget::setTabOrder(leNameEn, leNameRu);
        QWidget::setTabOrder(leNameRu, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(RERestDishMod);

        QMetaObject::connectSlotsByName(RERestDishMod);
    } // setupUi

    void retranslateUi(QDialog *RERestDishMod)
    {
        RERestDishMod->setWindowTitle(QCoreApplication::translate("RERestDishMod", "Dish modifier", nullptr));
        label_2->setText(QCoreApplication::translate("RERestDishMod", "Code", nullptr));
        label->setText(QCoreApplication::translate("RERestDishMod", "Name, am", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishMod", "f_id", nullptr)));
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishMod", "f_am", nullptr)));
        btnOk->setText(QCoreApplication::translate("RERestDishMod", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestDishMod", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("RERestDishMod", "Name, en", nullptr));
        label_4->setText(QCoreApplication::translate("RERestDishMod", "Name, ru", nullptr));
        leNameEn->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishMod", "f_en", nullptr)));
        leNameRu->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishMod", "f_ru", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class RERestDishMod: public Ui_RERestDishMod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTDISHMOD_H
