/********************************************************************************
** Form generated from reading UI file 'fcallhistory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCALLHISTORY_H
#define UI_FCALLHISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqcheckbox.h>

QT_BEGIN_NAMESPACE

class Ui_FCallHistory
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *toolButton;
    EDateEdit *deStart;
    QLabel *label_2;
    EDateEdit *deEnd;
    QToolButton *toolButton_2;
    EQCheckBox *chIn;
    EQCheckBox *chOut;
    EQCheckBox *chInt;
    EQCheckBox *chTOut;
    EQCheckBox *chTIn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FCallHistory)
    {
        if (FCallHistory->objectName().isEmpty())
            FCallHistory->setObjectName(QString::fromUtf8("FCallHistory"));
        FCallHistory->resize(987, 41);
        horizontalLayout = new QHBoxLayout(FCallHistory);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FCallHistory);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        toolButton = new QToolButton(FCallHistory);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout->addWidget(toolButton);

        deStart = new EDateEdit(FCallHistory);
        deStart->setObjectName(QString::fromUtf8("deStart"));
        deStart->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deStart);

        label_2 = new QLabel(FCallHistory);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deEnd = new EDateEdit(FCallHistory);
        deEnd->setObjectName(QString::fromUtf8("deEnd"));
        deEnd->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deEnd);

        toolButton_2 = new QToolButton(FCallHistory);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);

        horizontalLayout->addWidget(toolButton_2);

        chIn = new EQCheckBox(FCallHistory);
        chIn->setObjectName(QString::fromUtf8("chIn"));
        chIn->setFocusPolicy(Qt::NoFocus);
        chIn->setChecked(false);

        horizontalLayout->addWidget(chIn);

        chOut = new EQCheckBox(FCallHistory);
        chOut->setObjectName(QString::fromUtf8("chOut"));
        chOut->setFocusPolicy(Qt::NoFocus);
        chOut->setChecked(false);

        horizontalLayout->addWidget(chOut);

        chInt = new EQCheckBox(FCallHistory);
        chInt->setObjectName(QString::fromUtf8("chInt"));
        chInt->setFocusPolicy(Qt::NoFocus);
        chInt->setChecked(false);

        horizontalLayout->addWidget(chInt);

        chTOut = new EQCheckBox(FCallHistory);
        chTOut->setObjectName(QString::fromUtf8("chTOut"));
        chTOut->setFocusPolicy(Qt::NoFocus);
        chTOut->setChecked(false);

        horizontalLayout->addWidget(chTOut);

        chTIn = new EQCheckBox(FCallHistory);
        chTIn->setObjectName(QString::fromUtf8("chTIn"));
        chTIn->setFocusPolicy(Qt::NoFocus);
        chTIn->setChecked(false);

        horizontalLayout->addWidget(chTIn);

        horizontalSpacer = new QSpacerItem(324, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(FCallHistory);

        QMetaObject::connectSlotsByName(FCallHistory);
    } // setupUi

    void retranslateUi(QWidget *FCallHistory)
    {
        FCallHistory->setWindowTitle(QCoreApplication::translate("FCallHistory", "Form", nullptr));
        label->setText(QCoreApplication::translate("FCallHistory", "From", nullptr));
        toolButton->setText(QCoreApplication::translate("FCallHistory", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FCallHistory", "To", nullptr));
        toolButton_2->setText(QCoreApplication::translate("FCallHistory", "...", nullptr));
        chIn->setText(QCoreApplication::translate("FCallHistory", "Incoming", nullptr));
        chOut->setText(QCoreApplication::translate("FCallHistory", "Outgoing", nullptr));
        chInt->setText(QCoreApplication::translate("FCallHistory", "Internal", nullptr));
        chTOut->setText(QCoreApplication::translate("FCallHistory", "Transfer out", nullptr));
        chTIn->setText(QCoreApplication::translate("FCallHistory", "Transfer in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCallHistory: public Ui_FCallHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCALLHISTORY_H
