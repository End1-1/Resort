/********************************************************************************
** Form generated from reading UI file 'dlgoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGOPTIONS_H
#define UI_DLGOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgOptions
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *tb;

    void setupUi(QDialog *DlgOptions)
    {
        if (DlgOptions->objectName().isEmpty())
            DlgOptions->setObjectName(QString::fromUtf8("DlgOptions"));
        DlgOptions->resize(1072, 816);
        verticalLayout = new QVBoxLayout(DlgOptions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tb = new QTextBrowser(DlgOptions);
        tb->setObjectName(QString::fromUtf8("tb"));

        verticalLayout->addWidget(tb);


        retranslateUi(DlgOptions);

        QMetaObject::connectSlotsByName(DlgOptions);
    } // setupUi

    void retranslateUi(QDialog *DlgOptions)
    {
        DlgOptions->setWindowTitle(QCoreApplication::translate("DlgOptions", "Option", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgOptions: public Ui_DlgOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGOPTIONS_H
