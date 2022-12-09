/********************************************************************************
** Form generated from reading UI file 'recallrate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECALLRATE_H
#define UI_RECALLRATE_H

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

class Ui_RECallRate
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leID;
    QLabel *label_2;
    EQLineEdit *leDirection;
    QLabel *label_3;
    EQLineEdit *leLocal;
    QLabel *label_4;
    EQLineEdit *leArea;
    QLabel *label_5;
    EQLineEdit *leCode;
    QLabel *label_6;
    EQLineEdit *leRate;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RECallRate)
    {
        if (RECallRate->objectName().isEmpty())
            RECallRate->setObjectName(QString::fromUtf8("RECallRate"));
        RECallRate->resize(437, 215);
        gridLayout = new QGridLayout(RECallRate);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RECallRate);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leID = new EQLineEdit(RECallRate);
        leID->setObjectName(QString::fromUtf8("leID"));
        leID->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leID, 0, 1, 1, 1);

        label_2 = new QLabel(RECallRate);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leDirection = new EQLineEdit(RECallRate);
        leDirection->setObjectName(QString::fromUtf8("leDirection"));
        leDirection->setMaxLength(1);

        gridLayout->addWidget(leDirection, 1, 1, 1, 1);

        label_3 = new QLabel(RECallRate);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leLocal = new EQLineEdit(RECallRate);
        leLocal->setObjectName(QString::fromUtf8("leLocal"));
        leLocal->setMaxLength(1);

        gridLayout->addWidget(leLocal, 2, 1, 1, 1);

        label_4 = new QLabel(RECallRate);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leArea = new EQLineEdit(RECallRate);
        leArea->setObjectName(QString::fromUtf8("leArea"));

        gridLayout->addWidget(leArea, 3, 1, 1, 1);

        label_5 = new QLabel(RECallRate);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        leCode = new EQLineEdit(RECallRate);
        leCode->setObjectName(QString::fromUtf8("leCode"));

        gridLayout->addWidget(leCode, 4, 1, 1, 1);

        label_6 = new QLabel(RECallRate);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        leRate = new EQLineEdit(RECallRate);
        leRate->setObjectName(QString::fromUtf8("leRate"));

        gridLayout->addWidget(leRate, 5, 1, 1, 1);

        widget = new QWidget(RECallRate);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(114, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(113, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 6, 0, 1, 2);


        retranslateUi(RECallRate);

        QMetaObject::connectSlotsByName(RECallRate);
    } // setupUi

    void retranslateUi(QDialog *RECallRate)
    {
        RECallRate->setWindowTitle(QCoreApplication::translate("RECallRate", "Call rate", nullptr));
        label->setText(QCoreApplication::translate("RECallRate", "Id", nullptr));
        leID->setProperty("Field", QVariant(QCoreApplication::translate("RECallRate", "f_id", nullptr)));
        label_2->setText(QCoreApplication::translate("RECallRate", "Direction", nullptr));
        leDirection->setProperty("Field", QVariant(QCoreApplication::translate("RECallRate", "f_direction", nullptr)));
        label_3->setText(QCoreApplication::translate("RECallRate", "Local", nullptr));
        leLocal->setInputMask(QCoreApplication::translate("RECallRate", "#", nullptr));
        leLocal->setProperty("Field", QVariant(QCoreApplication::translate("RECallRate", "f_local", nullptr)));
        label_4->setText(QCoreApplication::translate("RECallRate", "Area", nullptr));
        leArea->setProperty("Field", QVariant(QCoreApplication::translate("RECallRate", "f_area", nullptr)));
        label_5->setText(QCoreApplication::translate("RECallRate", "Area code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RECallRate", "f_code", nullptr)));
        label_6->setText(QCoreApplication::translate("RECallRate", "Rate", nullptr));
        leRate->setProperty("Field", QVariant(QCoreApplication::translate("RECallRate", "f_rate", nullptr)));
        btnOK->setText(QCoreApplication::translate("RECallRate", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RECallRate", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RECallRate: public Ui_RECallRate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECALLRATE_H
