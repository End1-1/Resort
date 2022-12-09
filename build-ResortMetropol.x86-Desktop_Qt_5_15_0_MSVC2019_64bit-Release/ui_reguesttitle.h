/********************************************************************************
** Form generated from reading UI file 'reguesttitle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGUESTTITLE_H
#define UI_REGUESTTITLE_H

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

class Ui_REGuestTitle
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leCode;
    EQLineEdit *leName;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *REGuestTitle)
    {
        if (REGuestTitle->objectName().isEmpty())
            REGuestTitle->setObjectName(QString::fromUtf8("REGuestTitle"));
        REGuestTitle->resize(262, 113);
        verticalLayout = new QVBoxLayout(REGuestTitle);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leCode = new EQLineEdit(REGuestTitle);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leName = new EQLineEdit(REGuestTitle);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        label = new QLabel(REGuestTitle);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(REGuestTitle);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget = new QWidget(REGuestTitle);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(26, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(26, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(REGuestTitle);

        QMetaObject::connectSlotsByName(REGuestTitle);
    } // setupUi

    void retranslateUi(QDialog *REGuestTitle)
    {
        REGuestTitle->setWindowTitle(QCoreApplication::translate("REGuestTitle", "Guest title", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("REGuestTitle", "f_id", nullptr)));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("REGuestTitle", "f_en", nullptr)));
        label->setText(QCoreApplication::translate("REGuestTitle", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("REGuestTitle", "Name", nullptr));
        btnSave->setText(QCoreApplication::translate("REGuestTitle", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("REGuestTitle", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REGuestTitle: public Ui_REGuestTitle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGUESTTITLE_H
