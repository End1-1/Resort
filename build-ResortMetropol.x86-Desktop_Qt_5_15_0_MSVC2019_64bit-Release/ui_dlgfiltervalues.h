/********************************************************************************
** Form generated from reading UI file 'dlgfiltervalues.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGFILTERVALUES_H
#define UI_DLGFILTERVALUES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgFilterValues
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *lst;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgFilterValues)
    {
        if (DlgFilterValues->objectName().isEmpty())
            DlgFilterValues->setObjectName(QString::fromUtf8("DlgFilterValues"));
        DlgFilterValues->resize(421, 463);
        verticalLayout = new QVBoxLayout(DlgFilterValues);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lst = new QListWidget(DlgFilterValues);
        lst->setObjectName(QString::fromUtf8("lst"));

        verticalLayout->addWidget(lst);

        buttonBox = new QDialogButtonBox(DlgFilterValues);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DlgFilterValues);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgFilterValues, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgFilterValues, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgFilterValues);
    } // setupUi

    void retranslateUi(QDialog *DlgFilterValues)
    {
        DlgFilterValues->setWindowTitle(QCoreApplication::translate("DlgFilterValues", "Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgFilterValues: public Ui_DlgFilterValues {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGFILTERVALUES_H
