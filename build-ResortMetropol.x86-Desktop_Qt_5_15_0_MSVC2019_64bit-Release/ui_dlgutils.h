/********************************************************************************
** Form generated from reading UI file 'dlgutils.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGUTILS_H
#define UI_DLGUTILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DlgUtils
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *btnGenNumbers;
    QLineEdit *lePrefix;
    QPushButton *btnCorrectReservGrantTotal;
    QLabel *label_2;
    QLineEdit *leCount;
    QLabel *lbInfo;

    void setupUi(QDialog *DlgUtils)
    {
        if (DlgUtils->objectName().isEmpty())
            DlgUtils->setObjectName(QString::fromUtf8("DlgUtils"));
        DlgUtils->resize(540, 141);
        gridLayout = new QGridLayout(DlgUtils);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgUtils);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        btnGenNumbers = new QPushButton(DlgUtils);
        btnGenNumbers->setObjectName(QString::fromUtf8("btnGenNumbers"));

        gridLayout->addWidget(btnGenNumbers, 2, 0, 1, 2);

        lePrefix = new QLineEdit(DlgUtils);
        lePrefix->setObjectName(QString::fromUtf8("lePrefix"));

        gridLayout->addWidget(lePrefix, 0, 1, 1, 1);

        btnCorrectReservGrantTotal = new QPushButton(DlgUtils);
        btnCorrectReservGrantTotal->setObjectName(QString::fromUtf8("btnCorrectReservGrantTotal"));

        gridLayout->addWidget(btnCorrectReservGrantTotal, 3, 0, 1, 2);

        label_2 = new QLabel(DlgUtils);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leCount = new QLineEdit(DlgUtils);
        leCount->setObjectName(QString::fromUtf8("leCount"));

        gridLayout->addWidget(leCount, 1, 1, 1, 1);

        lbInfo = new QLabel(DlgUtils);
        lbInfo->setObjectName(QString::fromUtf8("lbInfo"));

        gridLayout->addWidget(lbInfo, 4, 0, 1, 2);


        retranslateUi(DlgUtils);

        QMetaObject::connectSlotsByName(DlgUtils);
    } // setupUi

    void retranslateUi(QDialog *DlgUtils)
    {
        DlgUtils->setWindowTitle(QCoreApplication::translate("DlgUtils", "Utils", nullptr));
        label->setText(QCoreApplication::translate("DlgUtils", "Prefix", nullptr));
        btnGenNumbers->setText(QCoreApplication::translate("DlgUtils", "Gen UUID", nullptr));
        btnCorrectReservGrantTotal->setText(QCoreApplication::translate("DlgUtils", "Correct reservation grand totals", nullptr));
        label_2->setText(QCoreApplication::translate("DlgUtils", "Count", nullptr));
        lbInfo->setText(QCoreApplication::translate("DlgUtils", "Progress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgUtils: public Ui_DlgUtils {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGUTILS_H
