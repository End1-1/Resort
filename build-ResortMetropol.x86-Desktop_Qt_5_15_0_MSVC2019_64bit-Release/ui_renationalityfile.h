/********************************************************************************
** Form generated from reading UI file 'renationalityfile.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENATIONALITYFILE_H
#define UI_RENATIONALITYFILE_H

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

class Ui_RENationalityFile
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    EQLineEdit *leCode;
    EQLineEdit *leShort;
    EQLineEdit *leName;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RENationalityFile)
    {
        if (RENationalityFile->objectName().isEmpty())
            RENationalityFile->setObjectName(QString::fromUtf8("RENationalityFile"));
        RENationalityFile->resize(333, 139);
        verticalLayout = new QVBoxLayout(RENationalityFile);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RENationalityFile);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(RENationalityFile);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(RENationalityFile);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leCode = new EQLineEdit(RENationalityFile);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 1);

        leShort = new EQLineEdit(RENationalityFile);
        leShort->setObjectName(QString::fromUtf8("leShort"));
        leShort->setMaxLength(3);

        gridLayout->addWidget(leShort, 1, 1, 1, 1);

        leName = new EQLineEdit(RENationalityFile);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget = new QWidget(RENationalityFile);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(61, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        QWidget::setTabOrder(leShort, leName);
        QWidget::setTabOrder(leName, btnSave);
        QWidget::setTabOrder(btnSave, btnCancel);

        retranslateUi(RENationalityFile);

        QMetaObject::connectSlotsByName(RENationalityFile);
    } // setupUi

    void retranslateUi(QDialog *RENationalityFile)
    {
        RENationalityFile->setWindowTitle(QCoreApplication::translate("RENationalityFile", "Nationality", nullptr));
        label->setText(QCoreApplication::translate("RENationalityFile", "Code", nullptr));
        label_3->setText(QCoreApplication::translate("RENationalityFile", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("RENationalityFile", "Short", nullptr));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RENationalityFile", "f_id", nullptr)));
        leShort->setProperty("Field", QVariant(QCoreApplication::translate("RENationalityFile", "f_short", nullptr)));
        leName->setProperty("Field", QVariant(QCoreApplication::translate("RENationalityFile", "f_name", nullptr)));
        btnSave->setText(QCoreApplication::translate("RENationalityFile", "Save", nullptr));
        btnCancel->setText(QCoreApplication::translate("RENationalityFile", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RENationalityFile: public Ui_RENationalityFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENATIONALITYFILE_H
