/********************************************************************************
** Form generated from reading UI file 'dlgroom.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGROOM_H
#define UI_DLGROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_DlgRoom
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *leDescription;
    EQLineEdit *leBedName;
    EQLineEdit *leQueue;
    QLabel *label_3;
    QLabel *label_9;
    EQLineEdit *leQty;
    QLabel *label_2;
    EQLineEdit *leClassCode;
    QCheckBox *chSmoking;
    QLabel *label_12;
    EQLineEdit *leViewCode;
    QLabel *label_11;
    EQLineEdit *lePhone;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_4;
    EQLineEdit *leClassName;
    EQLineEdit *leCode;
    EQLineEdit *leRate;
    EQLineEdit *leFloor;
    EQLineEdit *leBedCode;
    EQLineEdit *leShortName;
    QLabel *label_10;
    QLabel *label_5;
    EQLineEdit *leViewName;
    QLabel *label_13;
    EQLineEdit *leBuild;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgRoom)
    {
        if (DlgRoom->objectName().isEmpty())
            DlgRoom->setObjectName(QString::fromUtf8("DlgRoom"));
        DlgRoom->resize(400, 376);
        verticalLayout = new QVBoxLayout(DlgRoom);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leDescription = new EQLineEdit(DlgRoom);
        leDescription->setObjectName(QString::fromUtf8("leDescription"));

        gridLayout->addWidget(leDescription, 6, 1, 1, 2);

        leBedName = new EQLineEdit(DlgRoom);
        leBedName->setObjectName(QString::fromUtf8("leBedName"));
        leBedName->setFocusPolicy(Qt::NoFocus);
        leBedName->setReadOnly(true);

        gridLayout->addWidget(leBedName, 8, 2, 1, 1);

        leQueue = new EQLineEdit(DlgRoom);
        leQueue->setObjectName(QString::fromUtf8("leQueue"));

        gridLayout->addWidget(leQueue, 10, 1, 1, 2);

        label_3 = new QLabel(DlgRoom);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label_9 = new QLabel(DlgRoom);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 13, 0, 1, 1);

        leQty = new EQLineEdit(DlgRoom);
        leQty->setObjectName(QString::fromUtf8("leQty"));

        gridLayout->addWidget(leQty, 9, 1, 1, 2);

        label_2 = new QLabel(DlgRoom);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leClassCode = new EQLineEdit(DlgRoom);
        leClassCode->setObjectName(QString::fromUtf8("leClassCode"));
        leClassCode->setMaximumSize(QSize(60, 16777215));
        leClassCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leClassCode, 1, 1, 1, 1);

        chSmoking = new QCheckBox(DlgRoom);
        chSmoking->setObjectName(QString::fromUtf8("chSmoking"));

        gridLayout->addWidget(chSmoking, 13, 1, 1, 1);

        label_12 = new QLabel(DlgRoom);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 11, 0, 1, 1);

        leViewCode = new EQLineEdit(DlgRoom);
        leViewCode->setObjectName(QString::fromUtf8("leViewCode"));
        leViewCode->setMaximumSize(QSize(60, 16777215));
        leViewCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leViewCode, 2, 1, 1, 1);

        label_11 = new QLabel(DlgRoom);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 9, 0, 1, 1);

        lePhone = new EQLineEdit(DlgRoom);
        lePhone->setObjectName(QString::fromUtf8("lePhone"));

        gridLayout->addWidget(lePhone, 11, 1, 1, 2);

        label_6 = new QLabel(DlgRoom);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        label_7 = new QLabel(DlgRoom);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label = new QLabel(DlgRoom);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_8 = new QLabel(DlgRoom);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 10, 0, 1, 1);

        label_4 = new QLabel(DlgRoom);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        leClassName = new EQLineEdit(DlgRoom);
        leClassName->setObjectName(QString::fromUtf8("leClassName"));
        leClassName->setFocusPolicy(Qt::NoFocus);
        leClassName->setReadOnly(true);

        gridLayout->addWidget(leClassName, 1, 2, 1, 1);

        leCode = new EQLineEdit(DlgRoom);
        leCode->setObjectName(QString::fromUtf8("leCode"));

        gridLayout->addWidget(leCode, 0, 1, 1, 2);

        leRate = new EQLineEdit(DlgRoom);
        leRate->setObjectName(QString::fromUtf8("leRate"));

        gridLayout->addWidget(leRate, 7, 1, 1, 2);

        leFloor = new EQLineEdit(DlgRoom);
        leFloor->setObjectName(QString::fromUtf8("leFloor"));

        gridLayout->addWidget(leFloor, 3, 1, 1, 2);

        leBedCode = new EQLineEdit(DlgRoom);
        leBedCode->setObjectName(QString::fromUtf8("leBedCode"));
        leBedCode->setMaximumSize(QSize(60, 16777215));
        leBedCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(leBedCode, 8, 1, 1, 1);

        leShortName = new EQLineEdit(DlgRoom);
        leShortName->setObjectName(QString::fromUtf8("leShortName"));

        gridLayout->addWidget(leShortName, 5, 1, 1, 2);

        label_10 = new QLabel(DlgRoom);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        label_5 = new QLabel(DlgRoom);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        leViewName = new EQLineEdit(DlgRoom);
        leViewName->setObjectName(QString::fromUtf8("leViewName"));
        leViewName->setFocusPolicy(Qt::NoFocus);
        leViewName->setReadOnly(true);

        gridLayout->addWidget(leViewName, 2, 2, 1, 1);

        label_13 = new QLabel(DlgRoom);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 4, 0, 1, 1);

        leBuild = new EQLineEdit(DlgRoom);
        leBuild->setObjectName(QString::fromUtf8("leBuild"));
        leBuild->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(leBuild, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget = new QWidget(DlgRoom);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(leCode, leClassCode);
        QWidget::setTabOrder(leClassCode, leViewCode);
        QWidget::setTabOrder(leViewCode, leFloor);
        QWidget::setTabOrder(leFloor, leBuild);
        QWidget::setTabOrder(leBuild, leShortName);
        QWidget::setTabOrder(leShortName, leDescription);
        QWidget::setTabOrder(leDescription, leRate);
        QWidget::setTabOrder(leRate, leBedCode);
        QWidget::setTabOrder(leBedCode, leQty);
        QWidget::setTabOrder(leQty, leQueue);
        QWidget::setTabOrder(leQueue, lePhone);
        QWidget::setTabOrder(lePhone, chSmoking);
        QWidget::setTabOrder(chSmoking, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);
        QWidget::setTabOrder(btnCancel, leBedName);
        QWidget::setTabOrder(leBedName, leViewName);
        QWidget::setTabOrder(leViewName, leClassName);

        retranslateUi(DlgRoom);

        QMetaObject::connectSlotsByName(DlgRoom);
    } // setupUi

    void retranslateUi(QDialog *DlgRoom)
    {
        DlgRoom->setWindowTitle(QCoreApplication::translate("DlgRoom", "Room", nullptr));
        label_3->setText(QCoreApplication::translate("DlgRoom", "Short", nullptr));
        label_9->setText(QCoreApplication::translate("DlgRoom", "Smoking", nullptr));
        label_2->setText(QCoreApplication::translate("DlgRoom", "Class", nullptr));
        chSmoking->setText(QString());
        label_12->setText(QCoreApplication::translate("DlgRoom", "Internal phone", nullptr));
        label_11->setText(QCoreApplication::translate("DlgRoom", "Qty", nullptr));
        label_6->setText(QCoreApplication::translate("DlgRoom", "Bed", nullptr));
        label_7->setText(QCoreApplication::translate("DlgRoom", "Floor", nullptr));
        label->setText(QCoreApplication::translate("DlgRoom", "Code", nullptr));
        label_8->setText(QCoreApplication::translate("DlgRoom", "Queue", nullptr));
        label_4->setText(QCoreApplication::translate("DlgRoom", "Description", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("DlgRoom", "f_id", nullptr)));
        label_10->setText(QCoreApplication::translate("DlgRoom", "View", nullptr));
        label_5->setText(QCoreApplication::translate("DlgRoom", "Rate", nullptr));
        label_13->setText(QCoreApplication::translate("DlgRoom", "Building number", nullptr));
        btnOK->setText(QCoreApplication::translate("DlgRoom", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgRoom", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgRoom: public Ui_DlgRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGROOM_H
