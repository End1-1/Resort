/********************************************************************************
** Form generated from reading UI file 'dlgviewinvoicecorrections.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGVIEWINVOICECORRECTIONS_H
#define UI_DLGVIEWINVOICECORRECTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgViewInvoiceCorrections
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tblData;

    void setupUi(QDialog *DlgViewInvoiceCorrections)
    {
        if (DlgViewInvoiceCorrections->objectName().isEmpty())
            DlgViewInvoiceCorrections->setObjectName(QString::fromUtf8("DlgViewInvoiceCorrections"));
        DlgViewInvoiceCorrections->resize(1250, 495);
        horizontalLayout = new QHBoxLayout(DlgViewInvoiceCorrections);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tblData = new QTableWidget(DlgViewInvoiceCorrections);
        tblData->setObjectName(QString::fromUtf8("tblData"));

        horizontalLayout->addWidget(tblData);


        retranslateUi(DlgViewInvoiceCorrections);

        QMetaObject::connectSlotsByName(DlgViewInvoiceCorrections);
    } // setupUi

    void retranslateUi(QDialog *DlgViewInvoiceCorrections)
    {
        DlgViewInvoiceCorrections->setWindowTitle(QCoreApplication::translate("DlgViewInvoiceCorrections", "Corrections", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgViewInvoiceCorrections: public Ui_DlgViewInvoiceCorrections {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGVIEWINVOICECORRECTIONS_H
