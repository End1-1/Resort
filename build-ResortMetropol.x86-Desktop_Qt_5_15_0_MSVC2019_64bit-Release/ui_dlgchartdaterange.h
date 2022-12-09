/********************************************************************************
** Form generated from reading UI file 'dlgchartdaterange.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCHARTDATERANGE_H
#define UI_DLGCHARTDATERANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgChartDateRange
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    EDateEdit *deStart;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgChartDateRange)
    {
        if (DlgChartDateRange->objectName().isEmpty())
            DlgChartDateRange->setObjectName(QString::fromUtf8("DlgChartDateRange"));
        DlgChartDateRange->resize(220, 69);
        verticalLayout = new QVBoxLayout(DlgChartDateRange);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgChartDateRange);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        deStart = new EDateEdit(DlgChartDateRange);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(DlgChartDateRange);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DlgChartDateRange);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgChartDateRange, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgChartDateRange, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgChartDateRange);
    } // setupUi

    void retranslateUi(QDialog *DlgChartDateRange)
    {
        DlgChartDateRange->setWindowTitle(QCoreApplication::translate("DlgChartDateRange", "Date range", nullptr));
        label->setText(QCoreApplication::translate("DlgChartDateRange", "Date start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgChartDateRange: public Ui_DlgChartDateRange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCHARTDATERANGE_H
