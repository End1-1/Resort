/********************************************************************************
** Form generated from reading UI file 'wdate2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WDATE2_H
#define UI_WDATE2_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>

QT_BEGIN_NAMESPACE

class Ui_WDate2
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *btnLeft;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QPushButton *btnRight;

    void setupUi(QWidget *WDate2)
    {
        if (WDate2->objectName().isEmpty())
            WDate2->setObjectName(QString::fromUtf8("WDate2"));
        WDate2->resize(473, 25);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WDate2->sizePolicy().hasHeightForWidth());
        WDate2->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(WDate2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(WDate2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        btnLeft = new QPushButton(WDate2);
        btnLeft->setObjectName(QString::fromUtf8("btnLeft"));
        btnLeft->setMinimumSize(QSize(25, 25));
        btnLeft->setMaximumSize(QSize(25, 25));
        btnLeft->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLeft->setIcon(icon);

        horizontalLayout->addWidget(btnLeft);

        deStart = new EDateEdit(WDate2);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deStart->sizePolicy().hasHeightForWidth());
        deStart->setSizePolicy(sizePolicy1);
        deStart->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(WDate2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(WDate2);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        sizePolicy1.setHeightForWidth(deEnd->sizePolicy().hasHeightForWidth());
        deEnd->setSizePolicy(sizePolicy1);
        deEnd->setMinimumSize(QSize(150, 0));

        horizontalLayout->addWidget(deEnd);

        btnRight = new QPushButton(WDate2);
        btnRight->setObjectName(QString::fromUtf8("btnRight"));
        btnRight->setMinimumSize(QSize(25, 25));
        btnRight->setMaximumSize(QSize(25, 25));
        btnRight->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRight->setIcon(icon1);

        horizontalLayout->addWidget(btnRight);


        retranslateUi(WDate2);

        QMetaObject::connectSlotsByName(WDate2);
    } // setupUi

    void retranslateUi(QWidget *WDate2)
    {
        WDate2->setWindowTitle(QCoreApplication::translate("WDate2", "Form", nullptr));
        label->setText(QCoreApplication::translate("WDate2", "Date start", nullptr));
        btnLeft->setText(QString());
        btnLeft->setProperty("touchscreen", QVariant(QCoreApplication::translate("WDate2", "2", nullptr)));
        label_2->setText(QCoreApplication::translate("WDate2", "Date end", nullptr));
        btnRight->setText(QString());
        btnRight->setProperty("touchscreen", QVariant(QCoreApplication::translate("WDate2", "2", nullptr)));
    } // retranslateUi

};

namespace Ui {
    class WDate2: public Ui_WDate2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WDATE2_H
