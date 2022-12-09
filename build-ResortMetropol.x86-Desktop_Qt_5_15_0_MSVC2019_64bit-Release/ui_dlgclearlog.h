/********************************************************************************
** Form generated from reading UI file 'dlgclearlog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCLEARLOG_H
#define UI_DLGCLEARLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DlgClearLog
{
public:
    QHBoxLayout *horizontalLayout;
    QComboBox *cbUser;
    QPushButton *btnClear;

    void setupUi(QDialog *DlgClearLog)
    {
        if (DlgClearLog->objectName().isEmpty())
            DlgClearLog->setObjectName(QString::fromUtf8("DlgClearLog"));
        DlgClearLog->resize(582, 50);
        horizontalLayout = new QHBoxLayout(DlgClearLog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbUser = new QComboBox(DlgClearLog);
        cbUser->setObjectName(QString::fromUtf8("cbUser"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbUser->sizePolicy().hasHeightForWidth());
        cbUser->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(cbUser);

        btnClear = new QPushButton(DlgClearLog);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        horizontalLayout->addWidget(btnClear);


        retranslateUi(DlgClearLog);

        QMetaObject::connectSlotsByName(DlgClearLog);
    } // setupUi

    void retranslateUi(QDialog *DlgClearLog)
    {
        DlgClearLog->setWindowTitle(QCoreApplication::translate("DlgClearLog", "Clear log", nullptr));
        btnClear->setText(QCoreApplication::translate("DlgClearLog", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgClearLog: public Ui_DlgClearLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCLEARLOG_H
