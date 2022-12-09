/********************************************************************************
** Form generated from reading UI file 'dlgopengrouporsingle.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGOPENGROUPORSINGLE_H
#define UI_DLGOPENGROUPORSINGLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgOpenGroupOrSingle
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btnOpenGroup;
    QPushButton *btnOpenSingle;

    void setupUi(QDialog *DlgOpenGroupOrSingle)
    {
        if (DlgOpenGroupOrSingle->objectName().isEmpty())
            DlgOpenGroupOrSingle->setObjectName(QString::fromUtf8("DlgOpenGroupOrSingle"));
        DlgOpenGroupOrSingle->resize(266, 184);
        verticalLayout = new QVBoxLayout(DlgOpenGroupOrSingle);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnOpenGroup = new QPushButton(DlgOpenGroupOrSingle);
        btnOpenGroup->setObjectName(QString::fromUtf8("btnOpenGroup"));
        btnOpenGroup->setMinimumSize(QSize(50, 50));
        btnOpenGroup->setMaximumSize(QSize(5555, 200));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/groupreservation.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpenGroup->setIcon(icon);
        btnOpenGroup->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(btnOpenGroup);

        btnOpenSingle = new QPushButton(DlgOpenGroupOrSingle);
        btnOpenSingle->setObjectName(QString::fromUtf8("btnOpenSingle"));
        btnOpenSingle->setMinimumSize(QSize(50, 50));
        btnOpenSingle->setMaximumSize(QSize(5555, 200));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/boss.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpenSingle->setIcon(icon1);
        btnOpenSingle->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(btnOpenSingle);


        retranslateUi(DlgOpenGroupOrSingle);

        QMetaObject::connectSlotsByName(DlgOpenGroupOrSingle);
    } // setupUi

    void retranslateUi(QDialog *DlgOpenGroupOrSingle)
    {
        DlgOpenGroupOrSingle->setWindowTitle(QCoreApplication::translate("DlgOpenGroupOrSingle", "Selection mode", nullptr));
        btnOpenGroup->setText(QCoreApplication::translate("DlgOpenGroupOrSingle", "Open group", nullptr));
        btnOpenSingle->setText(QCoreApplication::translate("DlgOpenGroupOrSingle", "Open selected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgOpenGroupOrSingle: public Ui_DlgOpenGroupOrSingle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGOPENGROUPORSINGLE_H
