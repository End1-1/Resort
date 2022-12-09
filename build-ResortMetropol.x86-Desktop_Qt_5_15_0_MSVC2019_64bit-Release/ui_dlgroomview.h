/********************************************************************************
** Form generated from reading UI file 'dlgroomview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGROOMVIEW_H
#define UI_DLGROOMVIEW_H

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

class Ui_DlgRoomView
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *l;
    EQLineEdit *leDescrAM;
    EQLineEdit *leCode;
    EQLineEdit *leDescrEN;
    EQLineEdit *leShortName;
    EQLineEdit *leDescrRU;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgRoomView)
    {
        if (DlgRoomView->objectName().isEmpty())
            DlgRoomView->setObjectName(QString::fromUtf8("DlgRoomView"));
        DlgRoomView->resize(400, 191);
        verticalLayout = new QVBoxLayout(DlgRoomView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(DlgRoomView);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(DlgRoomView);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(DlgRoomView);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        l = new QLabel(DlgRoomView);
        l->setObjectName(QString::fromUtf8("l"));

        gridLayout->addWidget(l, 3, 0, 1, 1);

        leDescrAM = new EQLineEdit(DlgRoomView);
        leDescrAM->setObjectName(QString::fromUtf8("leDescrAM"));

        gridLayout->addWidget(leDescrAM, 2, 1, 1, 1);

        leCode = new EQLineEdit(DlgRoomView);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leDescrEN = new EQLineEdit(DlgRoomView);
        leDescrEN->setObjectName(QString::fromUtf8("leDescrEN"));

        gridLayout->addWidget(leDescrEN, 3, 1, 1, 1);

        leShortName = new EQLineEdit(DlgRoomView);
        leShortName->setObjectName(QString::fromUtf8("leShortName"));

        gridLayout->addWidget(leShortName, 1, 1, 1, 1);

        leDescrRU = new EQLineEdit(DlgRoomView);
        leDescrRU->setObjectName(QString::fromUtf8("leDescrRU"));

        gridLayout->addWidget(leDescrRU, 4, 1, 1, 1);

        label_4 = new QLabel(DlgRoomView);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget = new QWidget(DlgRoomView);
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


        retranslateUi(DlgRoomView);

        QMetaObject::connectSlotsByName(DlgRoomView);
    } // setupUi

    void retranslateUi(QDialog *DlgRoomView)
    {
        DlgRoomView->setWindowTitle(QCoreApplication::translate("DlgRoomView", "Room view", nullptr));
        label_2->setText(QCoreApplication::translate("DlgRoomView", "Short name", nullptr));
        label->setText(QCoreApplication::translate("DlgRoomView", "Code", nullptr));
        label_3->setText(QCoreApplication::translate("DlgRoomView", "Description, AM", nullptr));
        l->setText(QCoreApplication::translate("DlgRoomView", "Description, EN", nullptr));
        leDescrAM->setProperty("Field", QVariant(QCoreApplication::translate("DlgRoomView", "f_am", nullptr)));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("DlgRoomView", "f_id", nullptr)));
        leDescrEN->setProperty("Field", QVariant(QCoreApplication::translate("DlgRoomView", "f_en", nullptr)));
        leShortName->setProperty("Field", QVariant(QCoreApplication::translate("DlgRoomView", "f_short", nullptr)));
        leDescrRU->setProperty("Field", QVariant(QCoreApplication::translate("DlgRoomView", "f_ru", nullptr)));
        label_4->setText(QCoreApplication::translate("DlgRoomView", "Description, RU", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgRoomView", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgRoomView", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgRoomView: public Ui_DlgRoomView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGROOMVIEW_H
