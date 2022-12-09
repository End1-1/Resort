/********************************************************************************
** Form generated from reading UI file 'fforecastoccupancycategory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFORECASTOCCUPANCYCATEGORY_H
#define UI_FFORECASTOCCUPANCYCATEGORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FForecastOccupancyCategory
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EDateEdit *deStart;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label;
    EDateEdit *deEnd;

    void setupUi(QWidget *FForecastOccupancyCategory)
    {
        if (FForecastOccupancyCategory->objectName().isEmpty())
            FForecastOccupancyCategory->setObjectName(QString::fromUtf8("FForecastOccupancyCategory"));
        FForecastOccupancyCategory->resize(400, 40);
        verticalLayout = new QVBoxLayout(FForecastOccupancyCategory);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        deStart = new EDateEdit(FForecastOccupancyCategory);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        gridLayout->addWidget(deStart, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        label_2 = new QLabel(FForecastOccupancyCategory);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(FForecastOccupancyCategory);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        deEnd = new EDateEdit(FForecastOccupancyCategory);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        gridLayout->addWidget(deEnd, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(FForecastOccupancyCategory);

        QMetaObject::connectSlotsByName(FForecastOccupancyCategory);
    } // setupUi

    void retranslateUi(QWidget *FForecastOccupancyCategory)
    {
        FForecastOccupancyCategory->setWindowTitle(QCoreApplication::translate("FForecastOccupancyCategory", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("FForecastOccupancyCategory", "Start", nullptr));
        label->setText(QCoreApplication::translate("FForecastOccupancyCategory", "End", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FForecastOccupancyCategory: public Ui_FForecastOccupancyCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFORECASTOCCUPANCYCATEGORY_H
