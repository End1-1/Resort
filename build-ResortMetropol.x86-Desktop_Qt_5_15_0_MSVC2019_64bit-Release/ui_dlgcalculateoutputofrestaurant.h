/********************************************************************************
** Form generated from reading UI file 'dlgcalculateoutputofrestaurant.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCALCULATEOUTPUTOFRESTAURANT_H
#define UI_DLGCALCULATEOUTPUTOFRESTAURANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgCalculateOutputOfRestaurant
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EDateEdit *deStart;
    EDateEdit *deEnd;
    QProgressBar *pb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnGo;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgCalculateOutputOfRestaurant)
    {
        if (DlgCalculateOutputOfRestaurant->objectName().isEmpty())
            DlgCalculateOutputOfRestaurant->setObjectName(QString::fromUtf8("DlgCalculateOutputOfRestaurant"));
        DlgCalculateOutputOfRestaurant->resize(484, 112);
        gridLayout = new QGridLayout(DlgCalculateOutputOfRestaurant);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgCalculateOutputOfRestaurant);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        deStart = new EDateEdit(DlgCalculateOutputOfRestaurant);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 0, 1, 1, 1);

        deEnd = new EDateEdit(DlgCalculateOutputOfRestaurant);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 0, 2, 1, 1);

        pb = new QProgressBar(DlgCalculateOutputOfRestaurant);
        pb->setObjectName(QString::fromUtf8("pb"));
        pb->setValue(0);

        gridLayout->addWidget(pb, 1, 0, 1, 3);

        widget = new QWidget(DlgCalculateOutputOfRestaurant);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(137, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnGo = new QPushButton(widget);
        btnGo->setObjectName(QString::fromUtf8("btnGo"));

        horizontalLayout->addWidget(btnGo);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(137, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 3);


        retranslateUi(DlgCalculateOutputOfRestaurant);

        QMetaObject::connectSlotsByName(DlgCalculateOutputOfRestaurant);
    } // setupUi

    void retranslateUi(QDialog *DlgCalculateOutputOfRestaurant)
    {
        DlgCalculateOutputOfRestaurant->setWindowTitle(QCoreApplication::translate("DlgCalculateOutputOfRestaurant", "Calulate output of restaurant", nullptr));
        label->setText(QCoreApplication::translate("DlgCalculateOutputOfRestaurant", "Date range", nullptr));
        btnGo->setText(QCoreApplication::translate("DlgCalculateOutputOfRestaurant", "Calculate", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgCalculateOutputOfRestaurant", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgCalculateOutputOfRestaurant: public Ui_DlgCalculateOutputOfRestaurant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCALCULATEOUTPUTOFRESTAURANT_H
