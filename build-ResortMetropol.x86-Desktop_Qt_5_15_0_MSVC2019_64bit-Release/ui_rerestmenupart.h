/********************************************************************************
** Form generated from reading UI file 'rerestmenupart.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTMENUPART_H
#define UI_RERESTMENUPART_H

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

class Ui_RERestMenuPart
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *Codd;
    QLabel *label_3;
    EQLineEdit *leCode;
    EQLineEdit *leNameAm;
    QLabel *label_4;
    EQLineEdit *leNameEn;
    EQLineEdit *leNameRu;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RERestMenuPart)
    {
        if (RERestMenuPart->objectName().isEmpty())
            RERestMenuPart->setObjectName(QString::fromUtf8("RERestMenuPart"));
        RERestMenuPart->resize(334, 165);
        horizontalLayout = new QHBoxLayout(RERestMenuPart);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(RERestMenuPart);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        Codd = new QLabel(RERestMenuPart);
        Codd->setObjectName(QString::fromUtf8("Codd"));

        gridLayout->addWidget(Codd, 0, 0, 1, 1);

        label_3 = new QLabel(RERestMenuPart);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leCode = new EQLineEdit(RERestMenuPart);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leNameAm = new EQLineEdit(RERestMenuPart);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 1, 1, 1, 1);

        label_4 = new QLabel(RERestMenuPart);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        leNameEn = new EQLineEdit(RERestMenuPart);
        leNameEn->setObjectName(QString::fromUtf8("leNameEn"));

        gridLayout->addWidget(leNameEn, 2, 1, 1, 1);

        leNameRu = new EQLineEdit(RERestMenuPart);
        leNameRu->setObjectName(QString::fromUtf8("leNameRu"));

        gridLayout->addWidget(leNameRu, 3, 1, 1, 1);

        widget = new QWidget(RERestMenuPart);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(61, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_2->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(61, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 4, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(RERestMenuPart);

        QMetaObject::connectSlotsByName(RERestMenuPart);
    } // setupUi

    void retranslateUi(QDialog *RERestMenuPart)
    {
        RERestMenuPart->setWindowTitle(QCoreApplication::translate("RERestMenuPart", "Menu partition", nullptr));
        label_2->setText(QCoreApplication::translate("RERestMenuPart", "Name, am", nullptr));
        Codd->setText(QCoreApplication::translate("RERestMenuPart", "Code", nullptr));
        label_3->setText(QCoreApplication::translate("RERestMenuPart", "Name, en", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestMenuPart", "f_id", nullptr)));
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("RERestMenuPart", "f_am", nullptr)));
        label_4->setText(QCoreApplication::translate("RERestMenuPart", "Name, ru", nullptr));
        leNameEn->setProperty("Field", QVariant(QCoreApplication::translate("RERestMenuPart", "f_en", nullptr)));
        leNameRu->setProperty("Field", QVariant(QCoreApplication::translate("RERestMenuPart", "f_ru", nullptr)));
        btnOk->setText(QCoreApplication::translate("RERestMenuPart", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestMenuPart", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERestMenuPart: public Ui_RERestMenuPart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTMENUPART_H
