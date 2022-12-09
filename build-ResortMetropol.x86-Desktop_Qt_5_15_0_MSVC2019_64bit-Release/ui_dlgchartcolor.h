/********************************************************************************
** Form generated from reading UI file 'dlgchartcolor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCHARTCOLOR_H
#define UI_DLGCHARTCOLOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <ecolorlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgChartColor
{
public:
    QGridLayout *gridLayout;
    QCheckBox *chShowRoomDescription;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    EColorLineEdit *leReserveColor;
    EColorLineEdit *leCheckinColor;
    QLabel *label_3;
    QLabel *label_4;
    EColorLineEdit *leDoNotDisturbeColor;

    void setupUi(QDialog *DlgChartColor)
    {
        if (DlgChartColor->objectName().isEmpty())
            DlgChartColor->setObjectName(QString::fromUtf8("DlgChartColor"));
        DlgChartColor->resize(400, 156);
        gridLayout = new QGridLayout(DlgChartColor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        chShowRoomDescription = new QCheckBox(DlgChartColor);
        chShowRoomDescription->setObjectName(QString::fromUtf8("chShowRoomDescription"));

        gridLayout->addWidget(chShowRoomDescription, 3, 1, 1, 1);

        label = new QLabel(DlgChartColor);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DlgChartColor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        widget = new QWidget(DlgChartColor);
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


        gridLayout->addWidget(widget, 5, 0, 1, 2);

        leReserveColor = new EColorLineEdit(DlgChartColor);
        leReserveColor->setObjectName(QString::fromUtf8("leReserveColor"));

        gridLayout->addWidget(leReserveColor, 0, 1, 1, 1);

        leCheckinColor = new EColorLineEdit(DlgChartColor);
        leCheckinColor->setObjectName(QString::fromUtf8("leCheckinColor"));

        gridLayout->addWidget(leCheckinColor, 1, 1, 1, 1);

        label_3 = new QLabel(DlgChartColor);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(DlgChartColor);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        leDoNotDisturbeColor = new EColorLineEdit(DlgChartColor);
        leDoNotDisturbeColor->setObjectName(QString::fromUtf8("leDoNotDisturbeColor"));

        gridLayout->addWidget(leDoNotDisturbeColor, 2, 1, 1, 1);

        QWidget::setTabOrder(leReserveColor, leCheckinColor);
        QWidget::setTabOrder(leCheckinColor, leDoNotDisturbeColor);
        QWidget::setTabOrder(leDoNotDisturbeColor, chShowRoomDescription);
        QWidget::setTabOrder(chShowRoomDescription, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);

        retranslateUi(DlgChartColor);

        QMetaObject::connectSlotsByName(DlgChartColor);
    } // setupUi

    void retranslateUi(QDialog *DlgChartColor)
    {
        DlgChartColor->setWindowTitle(QCoreApplication::translate("DlgChartColor", "Chart color schema", nullptr));
        chShowRoomDescription->setText(QString());
        label->setText(QCoreApplication::translate("DlgChartColor", "Reserved color", nullptr));
        label_2->setText(QCoreApplication::translate("DlgChartColor", "Checkin color", nullptr));
        btnSave->setText(QCoreApplication::translate("DlgChartColor", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgChartColor", "Cancel", nullptr));
        label_3->setText(QCoreApplication::translate("DlgChartColor", "Show room description", nullptr));
        label_4->setText(QCoreApplication::translate("DlgChartColor", "Do not disturbe color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgChartColor: public Ui_DlgChartColor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCHARTCOLOR_H
