/********************************************************************************
** Form generated from reading UI file 'reroomcategory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REROOMCATEGORY_H
#define UI_REROOMCATEGORY_H

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

class Ui_RERoomCategory
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    EQLineEdit *leDescription;
    EQLineEdit *leCode;
    EQLineEdit *leShort;
    QLabel *label;
    QLabel *label_4;
    EQLineEdit *leOrder;

    void setupUi(QDialog *RERoomCategory)
    {
        if (RERoomCategory->objectName().isEmpty())
            RERoomCategory->setObjectName(QString::fromUtf8("RERoomCategory"));
        RERoomCategory->resize(286, 165);
        verticalLayout = new QVBoxLayout(RERoomCategory);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(RERoomCategory);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        widget = new QWidget(RERoomCategory);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 2);

        label_2 = new QLabel(RERoomCategory);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leDescription = new EQLineEdit(RERoomCategory);
        leDescription->setObjectName(QString::fromUtf8("leDescription"));

        gridLayout->addWidget(leDescription, 2, 1, 1, 1);

        leCode = new EQLineEdit(RERoomCategory);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leShort = new EQLineEdit(RERoomCategory);
        leShort->setObjectName(QString::fromUtf8("leShort"));

        gridLayout->addWidget(leShort, 1, 1, 1, 1);

        label = new QLabel(RERoomCategory);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(RERoomCategory);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leOrder = new EQLineEdit(RERoomCategory);
        leOrder->setObjectName(QString::fromUtf8("leOrder"));

        gridLayout->addWidget(leOrder, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leShort, leDescription);
        QWidget::setTabOrder(leDescription, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(RERoomCategory);

        QMetaObject::connectSlotsByName(RERoomCategory);
    } // setupUi

    void retranslateUi(QDialog *RERoomCategory)
    {
        RERoomCategory->setWindowTitle(QCoreApplication::translate("RERoomCategory", "Room category", nullptr));
        label_3->setText(QCoreApplication::translate("RERoomCategory", "Description", nullptr));
        btnOk->setText(QCoreApplication::translate("RERoomCategory", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERoomCategory", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("RERoomCategory", "Short", nullptr));
        leDescription->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategory", "f_description", nullptr)));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategory", "f_id", nullptr)));
        leShort->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategory", "f_short", nullptr)));
        label->setText(QCoreApplication::translate("RERoomCategory", "Code", nullptr));
        label_4->setText(QCoreApplication::translate("RERoomCategory", "Order", nullptr));
        leOrder->setProperty("Field", QVariant(QCoreApplication::translate("RERoomCategory", "f_queue", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class RERoomCategory: public Ui_RERoomCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REROOMCATEGORY_H
