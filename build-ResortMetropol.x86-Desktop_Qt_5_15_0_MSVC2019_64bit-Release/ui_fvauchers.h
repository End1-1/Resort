/********************************************************************************
** Form generated from reading UI file 'fvauchers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FVAUCHERS_H
#define UI_FVAUCHERS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <edateedit.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_FVauchers
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *toolButton;
    EDateEdit *deFrom;
    QLabel *label_2;
    EDateEdit *deTo;
    QToolButton *toolButton_2;
    QLabel *label_3;
    EQLineEdit *leVaucherCode;
    EQLineEdit *leVacherName;
    QSpacerItem *horizontalSpacer;
    QCheckBox *chNoVAT;
    QCheckBox *chCanceled;

    void setupUi(QWidget *FVauchers)
    {
        if (FVauchers->objectName().isEmpty())
            FVauchers->setObjectName(QString::fromUtf8("FVauchers"));
        FVauchers->resize(786, 41);
        horizontalLayout = new QHBoxLayout(FVauchers);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FVauchers);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        toolButton = new QToolButton(FVauchers);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout->addWidget(toolButton);

        deFrom = new EDateEdit(FVauchers);
        deFrom->setObjectName(QString::fromUtf8("deFrom"));

        horizontalLayout->addWidget(deFrom);

        label_2 = new QLabel(FVauchers);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        deTo = new EDateEdit(FVauchers);
        deTo->setObjectName(QString::fromUtf8("deTo"));

        horizontalLayout->addWidget(deTo);

        toolButton_2 = new QToolButton(FVauchers);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);

        horizontalLayout->addWidget(toolButton_2);

        label_3 = new QLabel(FVauchers);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        leVaucherCode = new EQLineEdit(FVauchers);
        leVaucherCode->setObjectName(QString::fromUtf8("leVaucherCode"));
        leVaucherCode->setMaximumSize(QSize(50, 16777215));
        leVaucherCode->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(leVaucherCode);

        leVacherName = new EQLineEdit(FVauchers);
        leVacherName->setObjectName(QString::fromUtf8("leVacherName"));
        leVacherName->setMaximumSize(QSize(300, 16777215));
        leVacherName->setFocusPolicy(Qt::ClickFocus);
        leVacherName->setReadOnly(true);

        horizontalLayout->addWidget(leVacherName);

        horizontalSpacer = new QSpacerItem(233, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        chNoVAT = new QCheckBox(FVauchers);
        chNoVAT->setObjectName(QString::fromUtf8("chNoVAT"));
        chNoVAT->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chNoVAT);

        chCanceled = new QCheckBox(FVauchers);
        chCanceled->setObjectName(QString::fromUtf8("chCanceled"));
        chCanceled->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(chCanceled);


        retranslateUi(FVauchers);

        QMetaObject::connectSlotsByName(FVauchers);
    } // setupUi

    void retranslateUi(QWidget *FVauchers)
    {
        FVauchers->setWindowTitle(QCoreApplication::translate("FVauchers", "Form", nullptr));
        label->setText(QCoreApplication::translate("FVauchers", "From", nullptr));
        toolButton->setText(QCoreApplication::translate("FVauchers", "...", nullptr));
        label_2->setText(QCoreApplication::translate("FVauchers", "To", nullptr));
        toolButton_2->setText(QCoreApplication::translate("FVauchers", "...", nullptr));
        label_3->setText(QCoreApplication::translate("FVauchers", "Type", nullptr));
        chNoVAT->setText(QCoreApplication::translate("FVauchers", "No VAT", nullptr));
        chCanceled->setText(QCoreApplication::translate("FVauchers", "Canceled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FVauchers: public Ui_FVauchers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FVAUCHERS_H
