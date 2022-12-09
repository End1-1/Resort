/********************************************************************************
** Form generated from reading UI file 'wquickreservationspax.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WQUICKRESERVATIONSPAX_H
#define UI_WQUICKRESERVATIONSPAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <eqspinbox.h>

QT_BEGIN_NAMESPACE

class Ui_WQuickReservationsPax
{
public:
    QGridLayout *gridLayout;
    EQSpinBox *sbMan;
    EQSpinBox *sbBaby;
    QLabel *label_21;
    EQSpinBox *sbWoman;
    EQSpinBox *sbChild;
    QLabel *label_28;
    QLabel *label_22;
    QLabel *label_19;
    QLabel *lbRoom;

    void setupUi(QDialog *WQuickReservationsPax)
    {
        if (WQuickReservationsPax->objectName().isEmpty())
            WQuickReservationsPax->setObjectName(QString::fromUtf8("WQuickReservationsPax"));
        WQuickReservationsPax->resize(281, 43);
        gridLayout = new QGridLayout(WQuickReservationsPax);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        sbMan = new EQSpinBox(WQuickReservationsPax);
        sbMan->setObjectName(QString::fromUtf8("sbMan"));
        sbMan->setMaximumSize(QSize(30, 16777215));
        sbMan->setMinimum(0);
        sbMan->setValue(1);

        gridLayout->addWidget(sbMan, 1, 1, 1, 1);

        sbBaby = new EQSpinBox(WQuickReservationsPax);
        sbBaby->setObjectName(QString::fromUtf8("sbBaby"));
        sbBaby->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(sbBaby, 1, 7, 1, 1);

        label_21 = new QLabel(WQuickReservationsPax);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setMaximumSize(QSize(24, 24));
        label_21->setLayoutDirection(Qt::RightToLeft);
        label_21->setPixmap(QPixmap(QString::fromUtf8(":/images/boss.png")));
        label_21->setScaledContents(true);
        label_21->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_21, 1, 0, 1, 1);

        sbWoman = new EQSpinBox(WQuickReservationsPax);
        sbWoman->setObjectName(QString::fromUtf8("sbWoman"));
        sbWoman->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(sbWoman, 1, 3, 1, 1);

        sbChild = new EQSpinBox(WQuickReservationsPax);
        sbChild->setObjectName(QString::fromUtf8("sbChild"));
        sbChild->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(sbChild, 1, 5, 1, 1);

        label_28 = new QLabel(WQuickReservationsPax);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMaximumSize(QSize(24, 24));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/images/boy.png")));
        label_28->setScaledContents(true);
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_28, 1, 4, 1, 1);

        label_22 = new QLabel(WQuickReservationsPax);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMaximumSize(QSize(24, 24));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/images/feeding-bottle.png")));
        label_22->setScaledContents(true);

        gridLayout->addWidget(label_22, 1, 6, 1, 1);

        label_19 = new QLabel(WQuickReservationsPax);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMaximumSize(QSize(24, 24));
        label_19->setPixmap(QPixmap(QString::fromUtf8(":/images/woman.png")));
        label_19->setScaledContents(true);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_19, 1, 2, 1, 1);

        lbRoom = new QLabel(WQuickReservationsPax);
        lbRoom->setObjectName(QString::fromUtf8("lbRoom"));
        lbRoom->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lbRoom, 0, 0, 1, 8);


        retranslateUi(WQuickReservationsPax);

        QMetaObject::connectSlotsByName(WQuickReservationsPax);
    } // setupUi

    void retranslateUi(QDialog *WQuickReservationsPax)
    {
        WQuickReservationsPax->setWindowTitle(QCoreApplication::translate("WQuickReservationsPax", "Pax", nullptr));
        label_21->setText(QString());
        label_28->setText(QString());
        label_22->setText(QString());
        label_19->setText(QString());
        lbRoom->setText(QCoreApplication::translate("WQuickReservationsPax", "ROOM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WQuickReservationsPax: public Ui_WQuickReservationsPax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WQUICKRESERVATIONSPAX_H
