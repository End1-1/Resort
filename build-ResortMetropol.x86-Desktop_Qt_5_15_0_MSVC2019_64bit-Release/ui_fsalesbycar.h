/********************************************************************************
** Form generated from reading UI file 'fsalesbycar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FSALESBYCAR_H
#define UI_FSALESBYCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_FSalesByCar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FSalesByCar)
    {
        if (FSalesByCar->objectName().isEmpty())
            FSalesByCar->setObjectName(QString::fromUtf8("FSalesByCar"));
        FSalesByCar->resize(878, 41);
        horizontalLayout = new QHBoxLayout(FSalesByCar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FSalesByCar);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        deStart = new EDateEdit(FSalesByCar);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FSalesByCar);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FSalesByCar);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        horizontalSpacer = new QSpacerItem(245, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FSalesByCar);

        QMetaObject::connectSlotsByName(FSalesByCar);
    } // setupUi

    void retranslateUi(QWidget *FSalesByCar)
    {
        FSalesByCar->setWindowTitle(QCoreApplication::translate("FSalesByCar", "Form", nullptr));
        label->setText(QCoreApplication::translate("FSalesByCar", "Date start", nullptr));
        label_2->setText(QCoreApplication::translate("FSalesByCar", "Date end", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FSalesByCar: public Ui_FSalesByCar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSALESBYCAR_H
