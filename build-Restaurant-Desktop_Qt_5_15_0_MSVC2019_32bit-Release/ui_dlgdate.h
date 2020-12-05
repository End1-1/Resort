/********************************************************************************
** Form generated from reading UI file 'dlgdate.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGDATE_H
#define UI_DLGDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_DlgDate
{
public:
    QGridLayout *gridLayout;
    EDateEdit *leDate;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgDate)
    {
        if (DlgDate->objectName().isEmpty())
            DlgDate->setObjectName(QString::fromUtf8("DlgDate"));
        DlgDate->resize(400, 120);
        gridLayout = new QGridLayout(DlgDate);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leDate = new EDateEdit(DlgDate);
        leDate->setObjectName(QString::fromUtf8("leDate"));
        QFont font;
        font.setPointSize(20);
        leDate->setFont(font);

        gridLayout->addWidget(leDate, 0, 0, 1, 2);

        btnOk = new QPushButton(DlgDate);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        gridLayout->addWidget(btnOk, 1, 0, 1, 1);

        btnCancel = new QPushButton(DlgDate);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 1, 1, 1, 1);


        retranslateUi(DlgDate);

        QMetaObject::connectSlotsByName(DlgDate);
    } // setupUi

    void retranslateUi(QDialog *DlgDate)
    {
        DlgDate->setWindowTitle(QCoreApplication::translate("DlgDate", "Date", nullptr));
        btnOk->setText(QCoreApplication::translate("DlgDate", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgDate", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgDate: public Ui_DlgDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGDATE_H
