/********************************************************************************
** Form generated from reading UI file 'recardexgroup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECARDEXGROUP_H
#define UI_RECARDEXGROUP_H

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

class Ui_RECardexGroup
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    EQLineEdit *leName;
    EQLineEdit *leCode;
    EQLineEdit *leCounter;
    EQLineEdit *leDescription;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RECardexGroup)
    {
        if (RECardexGroup->objectName().isEmpty())
            RECardexGroup->setObjectName(QString::fromUtf8("RECardexGroup"));
        RECardexGroup->resize(400, 165);
        verticalLayout = new QVBoxLayout(RECardexGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(RECardexGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(RECardexGroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(RECardexGroup);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leName = new EQLineEdit(RECardexGroup);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        leCode = new EQLineEdit(RECardexGroup);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leCounter = new EQLineEdit(RECardexGroup);
        leCounter->setObjectName(QString::fromUtf8("leCounter"));
        leCounter->setReadOnly(true);

        gridLayout->addWidget(leCounter, 2, 1, 1, 1);

        leDescription = new EQLineEdit(RECardexGroup);
        leDescription->setObjectName(QString::fromUtf8("leDescription"));

        gridLayout->addWidget(leDescription, 3, 1, 1, 1);

        label_4 = new QLabel(RECardexGroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget = new QWidget(RECardexGroup);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(leName, leCounter);
        QWidget::setTabOrder(leCounter, leDescription);
        QWidget::setTabOrder(leDescription, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);

        retranslateUi(RECardexGroup);

        QMetaObject::connectSlotsByName(RECardexGroup);
    } // setupUi

    void retranslateUi(QDialog *RECardexGroup)
    {
        RECardexGroup->setWindowTitle(QCoreApplication::translate("RECardexGroup", "Cardex group", nullptr));
        label_2->setText(QCoreApplication::translate("RECardexGroup", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("RECardexGroup", "Counter", nullptr));
        label->setText(QCoreApplication::translate("RECardexGroup", "Code", nullptr));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RECardexGroup", "f_code", nullptr)));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RECardexGroup", "f_id", nullptr)));
        leCounter->setInputMask(QCoreApplication::translate("RECardexGroup", "###", nullptr));
        leCounter->setText(QCoreApplication::translate("RECardexGroup", "000", nullptr));
        leCounter->setProperty("Field", QVariant(QCoreApplication::translate("RECardexGroup", "f_max", nullptr)));
        leDescription->setProperty("Field", QVariant(QCoreApplication::translate("RECardexGroup", "f_description", nullptr)));
        label_4->setText(QCoreApplication::translate("RECardexGroup", "Description", nullptr));
        btnSave->setText(QCoreApplication::translate("RECardexGroup", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("RECardexGroup", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RECardexGroup: public Ui_RECardexGroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECARDEXGROUP_H
