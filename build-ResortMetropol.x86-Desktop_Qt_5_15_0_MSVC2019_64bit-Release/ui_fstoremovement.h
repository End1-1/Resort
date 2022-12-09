/********************************************************************************
** Form generated from reading UI file 'fstoremovement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FSTOREMOVEMENT_H
#define UI_FSTOREMOVEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FStoreMovement
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *btnDateLeft;
    EDateEdit *deStart;
    EDateEdit *deEnd;
    QToolButton *btnDateRight;
    QLabel *label_4;
    EQLineEdit *leAction;
    QLabel *label_5;
    EQLineEdit *lePartner;
    QLabel *label_2;
    EQLineEdit *leStore;
    QLabel *label_3;
    EQLineEdit *leMaterial;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FStoreMovement)
    {
        if (FStoreMovement->objectName().isEmpty())
            FStoreMovement->setObjectName(QString::fromUtf8("FStoreMovement"));
        FStoreMovement->resize(1135, 41);
        horizontalLayout = new QHBoxLayout(FStoreMovement);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FStoreMovement);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnDateLeft = new QToolButton(FStoreMovement);
        btnDateLeft->setObjectName(QString::fromUtf8("btnDateLeft"));
        btnDateLeft->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDateLeft->setIcon(icon);

        horizontalLayout->addWidget(btnDateLeft);

        deStart = new EDateEdit(FStoreMovement);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        deEnd = new EDateEdit(FStoreMovement);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));

        horizontalLayout->addWidget(deEnd);

        btnDateRight = new QToolButton(FStoreMovement);
        btnDateRight->setObjectName(QString::fromUtf8("btnDateRight"));
        btnDateRight->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDateRight->setIcon(icon1);

        horizontalLayout->addWidget(btnDateRight);

        label_4 = new QLabel(FStoreMovement);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        leAction = new EQLineEdit(FStoreMovement);
        leAction->setObjectName(QString::fromUtf8("leAction"));
        leAction->setFocusPolicy(Qt::ClickFocus);
        leAction->setProperty("EnableHiddenText", QVariant(true));

        horizontalLayout->addWidget(leAction);

        label_5 = new QLabel(FStoreMovement);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        lePartner = new EQLineEdit(FStoreMovement);
        lePartner->setObjectName(QString::fromUtf8("lePartner"));
        lePartner->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(lePartner);

        label_2 = new QLabel(FStoreMovement);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        leStore = new EQLineEdit(FStoreMovement);
        leStore->setObjectName(QString::fromUtf8("leStore"));
        leStore->setFocusPolicy(Qt::ClickFocus);
        leStore->setProperty("EnableHiddenText", QVariant(true));

        horizontalLayout->addWidget(leStore);

        label_3 = new QLabel(FStoreMovement);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leMaterial = new EQLineEdit(FStoreMovement);
        leMaterial->setObjectName(QString::fromUtf8("leMaterial"));
        leMaterial->setFocusPolicy(Qt::ClickFocus);
        leMaterial->setProperty("EnableHiddenText", QVariant(true));

        horizontalLayout->addWidget(leMaterial);

        horizontalSpacer = new QSpacerItem(140, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FStoreMovement);

        QMetaObject::connectSlotsByName(FStoreMovement);
    } // setupUi

    void retranslateUi(QWidget *FStoreMovement)
    {
        FStoreMovement->setWindowTitle(QCoreApplication::translate("FStoreMovement", "Form", nullptr));
        label->setText(QCoreApplication::translate("FStoreMovement", "Date range", nullptr));
        btnDateLeft->setText(QCoreApplication::translate("FStoreMovement", "...", nullptr));
        btnDateRight->setText(QCoreApplication::translate("FStoreMovement", "...", nullptr));
        label_4->setText(QCoreApplication::translate("FStoreMovement", "Action", nullptr));
        label_5->setText(QCoreApplication::translate("FStoreMovement", "Partner", nullptr));
        label_2->setText(QCoreApplication::translate("FStoreMovement", "Store", nullptr));
        label_3->setText(QCoreApplication::translate("FStoreMovement", "Material", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FStoreMovement: public Ui_FStoreMovement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FSTOREMOVEMENT_H
