/********************************************************************************
** Form generated from reading UI file 'dlgooroomprop.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGOOROOMPROP_H
#define UI_DLGOOROOMPROP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>
#include <eqtextedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgOORoomProp
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    EDateEdit *deStart;
    EQTextEdit *teRemarks;
    QLabel *label_5;
    EQLineEdit *leRoom;
    EDateEdit *deEnd;
    QLabel *label_3;
    QLabel *lbOO;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btmRemove;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    EQLineEdit *leReserve;

    void setupUi(QDialog *DlgOORoomProp)
    {
        if (DlgOORoomProp->objectName().isEmpty())
            DlgOORoomProp->setObjectName(QString::fromUtf8("DlgOORoomProp"));
        DlgOORoomProp->resize(400, 300);
        gridLayout = new QGridLayout(DlgOORoomProp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgOORoomProp);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(DlgOORoomProp);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        deStart = new EDateEdit(DlgOORoomProp);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 2, 1, 1, 1);

        teRemarks = new EQTextEdit(DlgOORoomProp);
        teRemarks->setObjectName(QString::fromUtf8("teRemarks"));

        gridLayout->addWidget(teRemarks, 5, 1, 1, 1);

        label_5 = new QLabel(DlgOORoomProp);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        leRoom = new EQLineEdit(DlgOORoomProp);
        leRoom->setObjectName(QString::fromUtf8("leRoom"));
        leRoom->setReadOnly(true);

        gridLayout->addWidget(leRoom, 0, 1, 1, 1);

        deEnd = new EDateEdit(DlgOORoomProp);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 3, 1, 1, 1);

        label_3 = new QLabel(DlgOORoomProp);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lbOO = new QLabel(DlgOORoomProp);
        lbOO->setObjectName(QString::fromUtf8("lbOO"));

        gridLayout->addWidget(lbOO, 4, 1, 1, 1);

        widget = new QWidget(DlgOORoomProp);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btmRemove = new QPushButton(widget);
        btmRemove->setObjectName(QString::fromUtf8("btmRemove"));

        horizontalLayout->addWidget(btmRemove);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 6, 0, 1, 2);

        label_6 = new QLabel(DlgOORoomProp);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        leReserve = new EQLineEdit(DlgOORoomProp);
        leReserve->setObjectName(QString::fromUtf8("leReserve"));
        leReserve->setReadOnly(true);

        gridLayout->addWidget(leReserve, 1, 1, 1, 1);

        QWidget::setTabOrder(leRoom, leReserve);
        QWidget::setTabOrder(leReserve, deStart);
        QWidget::setTabOrder(deStart, deEnd);
        QWidget::setTabOrder(deEnd, teRemarks);
        QWidget::setTabOrder(teRemarks, btnOk);
        QWidget::setTabOrder(btnOk, btmRemove);
        QWidget::setTabOrder(btmRemove, btnCancel);

        retranslateUi(DlgOORoomProp);

        QMetaObject::connectSlotsByName(DlgOORoomProp);
    } // setupUi

    void retranslateUi(QDialog *DlgOORoomProp)
    {
        DlgOORoomProp->setWindowTitle(QCoreApplication::translate("DlgOORoomProp", "Out of order", nullptr));
        label->setText(QCoreApplication::translate("DlgOORoomProp", "Start", nullptr));
        label_2->setText(QCoreApplication::translate("DlgOORoomProp", "End", nullptr));
        label_5->setText(QCoreApplication::translate("DlgOORoomProp", "Room", nullptr));
        label_3->setText(QCoreApplication::translate("DlgOORoomProp", "Status", nullptr));
        lbOO->setText(QCoreApplication::translate("DlgOORoomProp", "OK", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgOORoomProp", "OK", nullptr));
        btmRemove->setText(QCoreApplication::translate("DlgOORoomProp", "Remove", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgOORoomProp", "Cancel", nullptr));
        label_6->setText(QCoreApplication::translate("DlgOORoomProp", "Reservation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgOORoomProp: public Ui_DlgOORoomProp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGOOROOMPROP_H
