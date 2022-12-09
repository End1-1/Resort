/********************************************************************************
** Form generated from reading UI file 'dlghelp.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGHELP_H
#define UI_DLGHELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgHelp
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *teHelp;

    void setupUi(QDialog *DlgHelp)
    {
        if (DlgHelp->objectName().isEmpty())
            DlgHelp->setObjectName(QString::fromUtf8("DlgHelp"));
        DlgHelp->resize(688, 726);
        verticalLayout = new QVBoxLayout(DlgHelp);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        teHelp = new QTextBrowser(DlgHelp);
        teHelp->setObjectName(QString::fromUtf8("teHelp"));

        verticalLayout->addWidget(teHelp);


        retranslateUi(DlgHelp);

        QMetaObject::connectSlotsByName(DlgHelp);
    } // setupUi

    void retranslateUi(QDialog *DlgHelp)
    {
        DlgHelp->setWindowTitle(QCoreApplication::translate("DlgHelp", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgHelp: public Ui_DlgHelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGHELP_H
