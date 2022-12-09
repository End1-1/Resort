/********************************************************************************
** Form generated from reading UI file 'dlgselectfiscalmachin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGSELECTFISCALMACHIN_H
#define UI_DLGSELECTFISCALMACHIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgSelectFiscalMachin
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *lst;

    void setupUi(QDialog *DlgSelectFiscalMachin)
    {
        if (DlgSelectFiscalMachin->objectName().isEmpty())
            DlgSelectFiscalMachin->setObjectName(QString::fromUtf8("DlgSelectFiscalMachin"));
        DlgSelectFiscalMachin->resize(400, 480);
        verticalLayout = new QVBoxLayout(DlgSelectFiscalMachin);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lst = new QListWidget(DlgSelectFiscalMachin);
        lst->setObjectName(QString::fromUtf8("lst"));
        lst->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(lst);


        retranslateUi(DlgSelectFiscalMachin);

        QMetaObject::connectSlotsByName(DlgSelectFiscalMachin);
    } // setupUi

    void retranslateUi(QDialog *DlgSelectFiscalMachin)
    {
        DlgSelectFiscalMachin->setWindowTitle(QCoreApplication::translate("DlgSelectFiscalMachin", "Fiscal machine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgSelectFiscalMachin: public Ui_DlgSelectFiscalMachin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGSELECTFISCALMACHIN_H
