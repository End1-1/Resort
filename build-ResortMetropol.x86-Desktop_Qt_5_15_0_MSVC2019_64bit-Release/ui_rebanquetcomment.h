/********************************************************************************
** Form generated from reading UI file 'rebanquetcomment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REBANQUETCOMMENT_H
#define UI_REBANQUETCOMMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_REBanquetComment
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    EQLineEdit *leCode;
    EQLineEdit *leName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *REBanquetComment)
    {
        if (REBanquetComment->objectName().isEmpty())
            REBanquetComment->setObjectName(QString::fromUtf8("REBanquetComment"));
        REBanquetComment->resize(400, 113);
        verticalLayout = new QVBoxLayout(REBanquetComment);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(REBanquetComment);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(REBanquetComment);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leCode = new EQLineEdit(REBanquetComment);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leName = new EQLineEdit(REBanquetComment);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        widget = new QWidget(REBanquetComment);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(REBanquetComment);

        QMetaObject::connectSlotsByName(REBanquetComment);
    } // setupUi

    void retranslateUi(QDialog *REBanquetComment)
    {
        REBanquetComment->setWindowTitle(QCoreApplication::translate("REBanquetComment", "Banquet comment", nullptr));
        label->setText(QCoreApplication::translate("REBanquetComment", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("REBanquetComment", "Name", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("REBanquetComment", "f_id", nullptr)));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("REBanquetComment", "f_name", nullptr)));
        btnOk->setText(QCoreApplication::translate("REBanquetComment", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("REBanquetComment", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class REBanquetComment: public Ui_REBanquetComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REBANQUETCOMMENT_H
