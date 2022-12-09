/********************************************************************************
** Form generated from reading UI file 'remodelofcars.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMODELOFCARS_H
#define UI_REMODELOFCARS_H

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

class Ui_REModelOfCars
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leClass;
    QLabel *label_3;
    EQLineEdit *leCode;
    QLabel *label_2;
    EQLineEdit *leModel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *REModelOfCars)
    {
        if (REModelOfCars->objectName().isEmpty())
            REModelOfCars->setObjectName(QString::fromUtf8("REModelOfCars"));
        REModelOfCars->resize(307, 137);
        gridLayout = new QGridLayout(REModelOfCars);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(REModelOfCars);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leClass = new EQLineEdit(REModelOfCars);
        leClass->setObjectName(QString::fromUtf8("leClass"));

        gridLayout->addWidget(leClass, 2, 1, 1, 1);

        label_3 = new QLabel(REModelOfCars);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leCode = new EQLineEdit(REModelOfCars);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(REModelOfCars);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leModel = new EQLineEdit(REModelOfCars);
        leModel->setObjectName(QString::fromUtf8("leModel"));

        gridLayout->addWidget(leModel, 1, 1, 1, 1);

        widget = new QWidget(REModelOfCars);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 3, 0, 1, 2);

        QWidget::setTabOrder(leModel, leClass);
        QWidget::setTabOrder(leClass, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);
        QWidget::setTabOrder(btnCancel, leCode);

        retranslateUi(REModelOfCars);

        QMetaObject::connectSlotsByName(REModelOfCars);
    } // setupUi

    void retranslateUi(QDialog *REModelOfCars)
    {
        REModelOfCars->setWindowTitle(QCoreApplication::translate("REModelOfCars", "Model of car", nullptr));
        label->setText(QCoreApplication::translate("REModelOfCars", "Code", nullptr));
        leClass->setProperty("Field", QVariant(QCoreApplication::translate("REModelOfCars", "f_class", nullptr)));
        label_3->setText(QCoreApplication::translate("REModelOfCars", "Class", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("REModelOfCars", "f_id", nullptr)));
        label_2->setText(QCoreApplication::translate("REModelOfCars", "Model", nullptr));
        leModel->setProperty("Field", QVariant(QCoreApplication::translate("REModelOfCars", "f_model", nullptr)));
        btnSave->setText(QCoreApplication::translate("REModelOfCars", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("REModelOfCars", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REModelOfCars: public Ui_REModelOfCars {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMODELOFCARS_H
