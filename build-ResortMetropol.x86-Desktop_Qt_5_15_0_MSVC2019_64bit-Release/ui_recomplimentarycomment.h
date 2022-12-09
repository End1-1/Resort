/********************************************************************************
** Form generated from reading UI file 'recomplimentarycomment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOMPLIMENTARYCOMMENT_H
#define UI_RECOMPLIMENTARYCOMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_REComplimentaryComment
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    EQLineEdit *leCode;
    QLabel *label_2;
    EQLineEdit *leName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *REComplimentaryComment)
    {
        if (REComplimentaryComment->objectName().isEmpty())
            REComplimentaryComment->setObjectName(QString::fromUtf8("REComplimentaryComment"));
        REComplimentaryComment->resize(336, 111);
        gridLayout = new QGridLayout(REComplimentaryComment);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(REComplimentaryComment);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCode = new EQLineEdit(REComplimentaryComment);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        label_2 = new QLabel(REComplimentaryComment);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leName = new EQLineEdit(REComplimentaryComment);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        widget = new QWidget(REComplimentaryComment);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(63, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);

        QWidget::setTabOrder(leName, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);

        retranslateUi(REComplimentaryComment);

        QMetaObject::connectSlotsByName(REComplimentaryComment);
    } // setupUi

    void retranslateUi(QDialog *REComplimentaryComment)
    {
        REComplimentaryComment->setWindowTitle(QCoreApplication::translate("REComplimentaryComment", "Complimentary comment", nullptr));
        label->setText(QCoreApplication::translate("REComplimentaryComment", "Code", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("REComplimentaryComment", "f_id", nullptr)));
        label_2->setText(QCoreApplication::translate("REComplimentaryComment", "Name", nullptr));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("REComplimentaryComment", "f_name", nullptr)));
        btnOk->setText(QCoreApplication::translate("REComplimentaryComment", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("REComplimentaryComment", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REComplimentaryComment: public Ui_REComplimentaryComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOMPLIMENTARYCOMMENT_H
