/********************************************************************************
** Form generated from reading UI file 'reroomcategoryraterow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REROOMCATEGORYRATEROW_H
#define UI_REROOMCATEGORYRATEROW_H

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

class Ui_RERoomCategoryRateRow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *lbCode;
    EQLineEdit *leCode;
    QLabel *label_4;
    EQLineEdit *leRate;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    EQLineEdit *leMonth1;
    EQLineEdit *leDay1;
    EQLineEdit *leMonth2;
    EQLineEdit *leBedCode;
    EQLineEdit *leBedName;
    EQLineEdit *leDay2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbCategory;
    EQLineEdit *leCategory;

    void setupUi(QDialog *RERoomCategoryRateRow)
    {
        if (RERoomCategoryRateRow->objectName().isEmpty())
            RERoomCategoryRateRow->setObjectName(QString::fromUtf8("RERoomCategoryRateRow"));
        RERoomCategoryRateRow->resize(325, 217);
        verticalLayout = new QVBoxLayout(RERoomCategoryRateRow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbCode = new QLabel(RERoomCategoryRateRow);
        lbCode->setObjectName(QString::fromUtf8("lbCode"));

        gridLayout->addWidget(lbCode, 0, 0, 1, 1);

        leCode = new EQLineEdit(RERoomCategoryRateRow);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 2);

        label_4 = new QLabel(RERoomCategoryRateRow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        leRate = new EQLineEdit(RERoomCategoryRateRow);
        leRate->setObjectName(QString::fromUtf8("leRate"));

        gridLayout->addWidget(leRate, 5, 1, 1, 2);

        label = new QLabel(RERoomCategoryRateRow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_3 = new QLabel(RERoomCategoryRateRow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_2 = new QLabel(RERoomCategoryRateRow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        leMonth1 = new EQLineEdit(RERoomCategoryRateRow);
        leMonth1->setObjectName(QString::fromUtf8("leMonth1"));

        gridLayout->addWidget(leMonth1, 2, 1, 1, 1);

        leDay1 = new EQLineEdit(RERoomCategoryRateRow);
        leDay1->setObjectName(QString::fromUtf8("leDay1"));

        gridLayout->addWidget(leDay1, 2, 2, 1, 1);

        leMonth2 = new EQLineEdit(RERoomCategoryRateRow);
        leMonth2->setObjectName(QString::fromUtf8("leMonth2"));

        gridLayout->addWidget(leMonth2, 3, 1, 1, 1);

        leBedCode = new EQLineEdit(RERoomCategoryRateRow);
        leBedCode->setObjectName(QString::fromUtf8("leBedCode"));
        leBedCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leBedCode, 4, 1, 1, 1);

        leBedName = new EQLineEdit(RERoomCategoryRateRow);
        leBedName->setObjectName(QString::fromUtf8("leBedName"));
        leBedName->setReadOnly(true);

        gridLayout->addWidget(leBedName, 4, 2, 1, 1);

        leDay2 = new EQLineEdit(RERoomCategoryRateRow);
        leDay2->setObjectName(QString::fromUtf8("leDay2"));

        gridLayout->addWidget(leDay2, 3, 2, 1, 1);

        widget = new QWidget(RERoomCategoryRateRow);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(57, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 6, 0, 1, 3);

        lbCategory = new QLabel(RERoomCategoryRateRow);
        lbCategory->setObjectName(QString::fromUtf8("lbCategory"));

        gridLayout->addWidget(lbCategory, 1, 0, 1, 1);

        leCategory = new EQLineEdit(RERoomCategoryRateRow);
        leCategory->setObjectName(QString::fromUtf8("leCategory"));

        gridLayout->addWidget(leCategory, 1, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leMonth1, leDay1);
        QWidget::setTabOrder(leDay1, leMonth2);
        QWidget::setTabOrder(leMonth2, leDay2);
        QWidget::setTabOrder(leDay2, leBedCode);
        QWidget::setTabOrder(leBedCode, leBedName);
        QWidget::setTabOrder(leBedName, leRate);
        QWidget::setTabOrder(leRate, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);
        QWidget::setTabOrder(btnCancel, leCode);
        QWidget::setTabOrder(leCode, leCategory);

        retranslateUi(RERoomCategoryRateRow);

        QMetaObject::connectSlotsByName(RERoomCategoryRateRow);
    } // setupUi

    void retranslateUi(QDialog *RERoomCategoryRateRow)
    {
        RERoomCategoryRateRow->setWindowTitle(QCoreApplication::translate("RERoomCategoryRateRow", "Category rate", nullptr));
        lbCode->setText(QCoreApplication::translate("RERoomCategoryRateRow", "Code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategoryRateRow", "f_id", nullptr)));
        label_4->setText(QCoreApplication::translate("RERoomCategoryRateRow", "Rate", nullptr));
        leRate->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategoryRateRow", "f_rate", nullptr)));
        label->setText(QCoreApplication::translate("RERoomCategoryRateRow", "Starting", nullptr));
        label_3->setText(QCoreApplication::translate("RERoomCategoryRateRow", "Bed", nullptr));
        label_2->setText(QCoreApplication::translate("RERoomCategoryRateRow", "Ending", nullptr));
        leMonth1->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategoryRateRow", "f_month1", nullptr)));
        leDay1->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategoryRateRow", "f_day1", nullptr)));
        leMonth2->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategoryRateRow", "f_month2", nullptr)));
        leBedCode->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategoryRateRow", "f_bed", nullptr)));
        leDay2->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategoryRateRow", "f_day2", nullptr)));
        btnOk->setText(QCoreApplication::translate("RERoomCategoryRateRow", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERoomCategoryRateRow", "Cancel", nullptr));
        lbCategory->setText(QCoreApplication::translate("RERoomCategoryRateRow", "Category", nullptr));
        leCategory->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategoryRateRow", "f_category", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class RERoomCategoryRateRow: public Ui_RERoomCategoryRateRow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REROOMCATEGORYRATEROW_H
