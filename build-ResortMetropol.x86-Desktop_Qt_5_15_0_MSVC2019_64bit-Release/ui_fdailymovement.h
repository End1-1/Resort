/********************************************************************************
** Form generated from reading UI file 'fdailymovement.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FDAILYMOVEMENT_H
#define UI_FDAILYMOVEMENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FDailyMovement
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnPrevDate;
    EDateEdit *deStart;
    QPushButton *btnNextDate;
    QLabel *label_3;
    EQLineEdit *leSale;
    QCheckBox *chCanceled;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FDailyMovement)
    {
        if (FDailyMovement->objectName().isEmpty())
            FDailyMovement->setObjectName(QString::fromUtf8("FDailyMovement"));
        FDailyMovement->resize(866, 43);
        horizontalLayout = new QHBoxLayout(FDailyMovement);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FDailyMovement);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnPrevDate = new QPushButton(FDailyMovement);
        btnPrevDate->setObjectName(QString::fromUtf8("btnPrevDate"));
        btnPrevDate->setMinimumSize(QSize(25, 25));
        btnPrevDate->setMaximumSize(QSize(25, 25));
        btnPrevDate->setFocusPolicy(Qt::ClickFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrevDate->setIcon(icon);

        horizontalLayout->addWidget(btnPrevDate);

        deStart = new EDateEdit(FDailyMovement);
        deStart->setObjectName(QString::fromUtf8("deStart"));

        horizontalLayout->addWidget(deStart);

        btnNextDate = new QPushButton(FDailyMovement);
        btnNextDate->setObjectName(QString::fromUtf8("btnNextDate"));
        btnNextDate->setMinimumSize(QSize(25, 25));
        btnNextDate->setMaximumSize(QSize(25, 25));
        btnNextDate->setFocusPolicy(Qt::ClickFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNextDate->setIcon(icon1);

        horizontalLayout->addWidget(btnNextDate);

        label_3 = new QLabel(FDailyMovement);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leSale = new EQLineEdit(FDailyMovement);
        leSale->setObjectName(QString::fromUtf8("leSale"));
        leSale->setFocusPolicy(Qt::ClickFocus);
        leSale->setProperty("EnableHiddenText", QVariant(true));

        horizontalLayout->addWidget(leSale);

        chCanceled = new QCheckBox(FDailyMovement);
        chCanceled->setObjectName(QString::fromUtf8("chCanceled"));
        chCanceled->setFocusPolicy(Qt::ClickFocus);
        chCanceled->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(chCanceled);

        horizontalSpacer = new QSpacerItem(142, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FDailyMovement);

        QMetaObject::connectSlotsByName(FDailyMovement);
    } // setupUi

    void retranslateUi(QWidget *FDailyMovement)
    {
        FDailyMovement->setWindowTitle(QCoreApplication::translate("FDailyMovement", "Form", nullptr));
        label->setText(QCoreApplication::translate("FDailyMovement", "Date", nullptr));
        btnPrevDate->setText(QString());
        btnNextDate->setText(QString());
        label_3->setText(QCoreApplication::translate("FDailyMovement", "Sale type", nullptr));
        chCanceled->setText(QCoreApplication::translate("FDailyMovement", "Canceled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FDailyMovement: public Ui_FDailyMovement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FDAILYMOVEMENT_H
