/********************************************************************************
** Form generated from reading UI file 'rerestdishtype.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RERESTDISHTYPE_H
#define UI_RERESTDISHTYPE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ecolorlineedit.h>
#include <eqcheckbox.h>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RERestDishType
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    EQLineEdit *lePartCode;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_5;
    EQLineEdit *lePartName;
    EQLineEdit *leNameAm;
    QPushButton *btnBgColor;
    QPushButton *btnTextColor;
    EQLineEdit *leCode;
    EQLineEdit *leNameEn;
    EColorLineEdit *leTextColor;
    EColorLineEdit *leBgColor;
    EQLineEdit *leNameRu;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    EQLineEdit *leQueue;
    EQCheckBox *chActive;
    QLabel *label_9;

    void setupUi(QDialog *RERestDishType)
    {
        if (RERestDishType->objectName().isEmpty())
            RERestDishType->setObjectName(QString::fromUtf8("RERestDishType"));
        RERestDishType->resize(330, 299);
        verticalLayout = new QVBoxLayout(RERestDishType);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lePartCode = new EQLineEdit(RERestDishType);
        lePartCode->setObjectName(QString::fromUtf8("lePartCode"));
        lePartCode->setMaximumSize(QSize(70, 16777215));
        lePartCode->setProperty("ShowButton", QVariant(true));

        gridLayout->addWidget(lePartCode, 1, 1, 1, 1);

        label = new QLabel(RERestDishType);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(RERestDishType);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(RERestDishType);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(RERestDishType);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_7 = new QLabel(RERestDishType);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_8 = new QLabel(RERestDishType);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label_6 = new QLabel(RERestDishType);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_5 = new QLabel(RERestDishType);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lePartName = new EQLineEdit(RERestDishType);
        lePartName->setObjectName(QString::fromUtf8("lePartName"));
        lePartName->setFocusPolicy(Qt::NoFocus);
        lePartName->setReadOnly(true);

        gridLayout->addWidget(lePartName, 1, 2, 1, 2);

        leNameAm = new EQLineEdit(RERestDishType);
        leNameAm->setObjectName(QString::fromUtf8("leNameAm"));

        gridLayout->addWidget(leNameAm, 2, 1, 1, 3);

        btnBgColor = new QPushButton(RERestDishType);
        btnBgColor->setObjectName(QString::fromUtf8("btnBgColor"));
        btnBgColor->setMinimumSize(QSize(25, 25));
        btnBgColor->setMaximumSize(QSize(25, 25));
        btnBgColor->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/selection.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnBgColor->setIcon(icon);

        gridLayout->addWidget(btnBgColor, 5, 3, 1, 1);

        btnTextColor = new QPushButton(RERestDishType);
        btnTextColor->setObjectName(QString::fromUtf8("btnTextColor"));
        btnTextColor->setMinimumSize(QSize(25, 25));
        btnTextColor->setMaximumSize(QSize(25, 25));
        btnTextColor->setFocusPolicy(Qt::NoFocus);
        btnTextColor->setIcon(icon);

        gridLayout->addWidget(btnTextColor, 6, 3, 1, 1);

        leCode = new EQLineEdit(RERestDishType);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setReadOnly(true);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 3);

        leNameEn = new EQLineEdit(RERestDishType);
        leNameEn->setObjectName(QString::fromUtf8("leNameEn"));

        gridLayout->addWidget(leNameEn, 3, 1, 1, 3);

        leTextColor = new EColorLineEdit(RERestDishType);
        leTextColor->setObjectName(QString::fromUtf8("leTextColor"));

        gridLayout->addWidget(leTextColor, 6, 1, 1, 2);

        leBgColor = new EColorLineEdit(RERestDishType);
        leBgColor->setObjectName(QString::fromUtf8("leBgColor"));

        gridLayout->addWidget(leBgColor, 5, 1, 1, 2);

        leNameRu = new EQLineEdit(RERestDishType);
        leNameRu->setObjectName(QString::fromUtf8("leNameRu"));

        gridLayout->addWidget(leNameRu, 4, 1, 1, 3);

        widget = new QWidget(RERestDishType);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(widget);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(widget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 9, 0, 1, 4);

        leQueue = new EQLineEdit(RERestDishType);
        leQueue->setObjectName(QString::fromUtf8("leQueue"));

        gridLayout->addWidget(leQueue, 7, 1, 1, 3);

        chActive = new EQCheckBox(RERestDishType);
        chActive->setObjectName(QString::fromUtf8("chActive"));

        gridLayout->addWidget(chActive, 8, 1, 1, 1);

        label_9 = new QLabel(RERestDishType);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(leCode, lePartCode);
        QWidget::setTabOrder(lePartCode, lePartName);
        QWidget::setTabOrder(lePartName, leNameAm);
        QWidget::setTabOrder(leNameAm, leNameEn);
        QWidget::setTabOrder(leNameEn, leNameRu);
        QWidget::setTabOrder(leNameRu, leBgColor);
        QWidget::setTabOrder(leBgColor, leTextColor);
        QWidget::setTabOrder(leTextColor, leQueue);
        QWidget::setTabOrder(leQueue, chActive);
        QWidget::setTabOrder(chActive, btnOk);
        QWidget::setTabOrder(btnOk, btnCancel);
        QWidget::setTabOrder(btnCancel, btnTextColor);
        QWidget::setTabOrder(btnTextColor, btnBgColor);

        retranslateUi(RERestDishType);

        QMetaObject::connectSlotsByName(RERestDishType);
    } // setupUi

    void retranslateUi(QDialog *RERestDishType)
    {
        RERestDishType->setWindowTitle(QCoreApplication::translate("RERestDishType", "Dish type", nullptr));
        lePartCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_part", nullptr)));
        label->setText(QCoreApplication::translate("RERestDishType", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("RERestDishType", "Part", nullptr));
        label_4->setText(QCoreApplication::translate("RERestDishType", "Name, en", nullptr));
        label_3->setText(QCoreApplication::translate("RERestDishType", "Name, am", nullptr));
        label_7->setText(QCoreApplication::translate("RERestDishType", "Text color", nullptr));
        label_8->setText(QCoreApplication::translate("RERestDishType", "Queue", nullptr));
        label_6->setText(QCoreApplication::translate("RERestDishType", "Background color", nullptr));
        label_5->setText(QCoreApplication::translate("RERestDishType", "Name, ru", nullptr));
        leNameAm->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_am", nullptr)));
        btnBgColor->setText(QString());
        btnTextColor->setText(QString());
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_id", nullptr)));
        leNameEn->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_en", nullptr)));
        leTextColor->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_textColor", nullptr)));
        leBgColor->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_bgColor", nullptr)));
        leNameRu->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_ru", nullptr)));
        btnOk->setText(QCoreApplication::translate("RERestDishType", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RERestDishType", "Cancel", nullptr));
        leQueue->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_queue", nullptr)));
        chActive->setText(QString());
        chActive->setProperty("Field", QVariant(QCoreApplication::translate("RERestDishType", "f_active", nullptr)));
        label_9->setText(QCoreApplication::translate("RERestDishType", "Enabled", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RERestDishType: public Ui_RERestDishType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RERESTDISHTYPE_H
