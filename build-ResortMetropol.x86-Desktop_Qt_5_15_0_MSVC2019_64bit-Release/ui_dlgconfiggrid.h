/********************************************************************************
** Form generated from reading UI file 'dlgconfiggrid.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCONFIGGRID_H
#define UI_DLGCONFIGGRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgConfigGrid
{
public:
    QGridLayout *gridLayout;
    QFontComboBox *fcbFontName;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *chFontBold;
    QSpinBox *spFontSize;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnReset;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QWidget *wdtAdd;
    QCheckBox *chReadOnly;
    QLabel *label_5;
    QSpinBox *sbRowHeight;

    void setupUi(QDialog *DlgConfigGrid)
    {
        if (DlgConfigGrid->objectName().isEmpty())
            DlgConfigGrid->setObjectName(QString::fromUtf8("DlgConfigGrid"));
        DlgConfigGrid->resize(358, 191);
        gridLayout = new QGridLayout(DlgConfigGrid);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fcbFontName = new QFontComboBox(DlgConfigGrid);
        fcbFontName->setObjectName(QString::fromUtf8("fcbFontName"));

        gridLayout->addWidget(fcbFontName, 0, 1, 1, 1);

        label = new QLabel(DlgConfigGrid);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(DlgConfigGrid);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(DlgConfigGrid);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        chFontBold = new QCheckBox(DlgConfigGrid);
        chFontBold->setObjectName(QString::fromUtf8("chFontBold"));

        gridLayout->addWidget(chFontBold, 2, 1, 1, 1);

        spFontSize = new QSpinBox(DlgConfigGrid);
        spFontSize->setObjectName(QString::fromUtf8("spFontSize"));

        gridLayout->addWidget(spFontSize, 1, 1, 1, 1);

        label_2 = new QLabel(DlgConfigGrid);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        widget = new QWidget(DlgConfigGrid);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnReset = new QPushButton(widget);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));

        horizontalLayout->addWidget(btnReset);

        btnOK = new QPushButton(widget);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(32, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 6, 0, 1, 2);

        wdtAdd = new QWidget(DlgConfigGrid);
        wdtAdd->setObjectName(QString::fromUtf8("wdtAdd"));

        gridLayout->addWidget(wdtAdd, 5, 0, 1, 2);

        chReadOnly = new QCheckBox(DlgConfigGrid);
        chReadOnly->setObjectName(QString::fromUtf8("chReadOnly"));

        gridLayout->addWidget(chReadOnly, 3, 1, 1, 1);

        label_5 = new QLabel(DlgConfigGrid);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        sbRowHeight = new QSpinBox(DlgConfigGrid);
        sbRowHeight->setObjectName(QString::fromUtf8("sbRowHeight"));
        sbRowHeight->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(sbRowHeight, 4, 1, 1, 1);


        retranslateUi(DlgConfigGrid);

        QMetaObject::connectSlotsByName(DlgConfigGrid);
    } // setupUi

    void retranslateUi(QDialog *DlgConfigGrid)
    {
        DlgConfigGrid->setWindowTitle(QCoreApplication::translate("DlgConfigGrid", "Report options", nullptr));
        label->setText(QCoreApplication::translate("DlgConfigGrid", "Font name", nullptr));
        label_3->setText(QCoreApplication::translate("DlgConfigGrid", "Font bold", nullptr));
        label_4->setText(QCoreApplication::translate("DlgConfigGrid", "Read only", nullptr));
        chFontBold->setText(QString());
        label_2->setText(QCoreApplication::translate("DlgConfigGrid", "Font size", nullptr));
        btnReset->setText(QCoreApplication::translate("DlgConfigGrid", "Reset", nullptr));
        btnOK->setText(QCoreApplication::translate("DlgConfigGrid", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgConfigGrid", "Cancel", nullptr));
        chReadOnly->setText(QString());
        label_5->setText(QCoreApplication::translate("DlgConfigGrid", "Row height", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgConfigGrid: public Ui_DlgConfigGrid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCONFIGGRID_H
