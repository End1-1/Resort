/********************************************************************************
** Form generated from reading UI file 'recarclient.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECARCLIENT_H
#define UI_RECARCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <eqlineedit.h>

QT_BEGIN_NAMESPACE

class Ui_RECarClient
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbMode1;
    QRadioButton *rbMode2;
    QRadioButton *rbMode3;
    QLabel *label_2;
    QLabel *label;
    EQLineEdit *leCarmodel;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_6;
    EQLineEdit *leModel;
    EQLineEdit *leCostumer;
    EQLineEdit *leCode;
    EQLineEdit *leCargovnumber;
    EQLineEdit *leInfo;
    EQLineEdit *leCardcode;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnReject;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    EQLineEdit *leVisits;
    QLabel *label_8;
    EQLineEdit *leValue;
    QLabel *label_9;
    EQLineEdit *leItems;

    void setupUi(QDialog *RECarClient)
    {
        if (RECarClient->objectName().isEmpty())
            RECarClient->setObjectName(QString::fromUtf8("RECarClient"));
        RECarClient->resize(395, 352);
        gridLayout = new QGridLayout(RECarClient);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_2 = new QWidget(RECarClient);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbMode1 = new QRadioButton(widget_2);
        rbMode1->setObjectName(QString::fromUtf8("rbMode1"));
        rbMode1->setChecked(true);

        horizontalLayout_2->addWidget(rbMode1);

        rbMode2 = new QRadioButton(widget_2);
        rbMode2->setObjectName(QString::fromUtf8("rbMode2"));

        horizontalLayout_2->addWidget(rbMode2);

        rbMode3 = new QRadioButton(widget_2);
        rbMode3->setObjectName(QString::fromUtf8("rbMode3"));

        horizontalLayout_2->addWidget(rbMode3);


        gridLayout->addWidget(widget_2, 6, 0, 1, 3);

        label_2 = new QLabel(RECarClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(RECarClient);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leCarmodel = new EQLineEdit(RECarClient);
        leCarmodel->setObjectName(QString::fromUtf8("leCarmodel"));
        leCarmodel->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(leCarmodel, 1, 1, 1, 1);

        label_5 = new QLabel(RECarClient);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_4 = new QLabel(RECarClient);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(RECarClient);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(RECarClient);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        leModel = new EQLineEdit(RECarClient);
        leModel->setObjectName(QString::fromUtf8("leModel"));
        leModel->setEnabled(false);

        gridLayout->addWidget(leModel, 1, 2, 1, 1);

        leCostumer = new EQLineEdit(RECarClient);
        leCostumer->setObjectName(QString::fromUtf8("leCostumer"));

        gridLayout->addWidget(leCostumer, 3, 1, 1, 2);

        leCode = new EQLineEdit(RECarClient);
        leCode->setObjectName(QString::fromUtf8("leCode"));
        leCode->setEnabled(false);
        leCode->setFocusPolicy(Qt::NoFocus);
        leCode->setProperty("PrimaryKey", QVariant(true));

        gridLayout->addWidget(leCode, 0, 1, 1, 2);

        leCargovnumber = new EQLineEdit(RECarClient);
        leCargovnumber->setObjectName(QString::fromUtf8("leCargovnumber"));

        gridLayout->addWidget(leCargovnumber, 2, 1, 1, 2);

        leInfo = new EQLineEdit(RECarClient);
        leInfo->setObjectName(QString::fromUtf8("leInfo"));

        gridLayout->addWidget(leInfo, 4, 1, 1, 2);

        leCardcode = new EQLineEdit(RECarClient);
        leCardcode->setObjectName(QString::fromUtf8("leCardcode"));

        gridLayout->addWidget(leCardcode, 5, 1, 1, 2);

        widget = new QWidget(RECarClient);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(93, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnReject = new QPushButton(widget);
        btnReject->setObjectName(QString::fromUtf8("btnReject"));

        horizontalLayout->addWidget(btnReject);

        horizontalSpacer_2 = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 8, 0, 1, 3);

        widget_3 = new QWidget(RECarClient);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        leVisits = new EQLineEdit(widget_3);
        leVisits->setObjectName(QString::fromUtf8("leVisits"));

        gridLayout_2->addWidget(leVisits, 0, 1, 1, 1);

        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        leValue = new EQLineEdit(widget_3);
        leValue->setObjectName(QString::fromUtf8("leValue"));

        gridLayout_2->addWidget(leValue, 1, 1, 1, 1);

        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 2, 0, 1, 1);

        leItems = new EQLineEdit(widget_3);
        leItems->setObjectName(QString::fromUtf8("leItems"));

        gridLayout_2->addWidget(leItems, 2, 1, 1, 1);


        gridLayout->addWidget(widget_3, 7, 0, 1, 3);


        retranslateUi(RECarClient);

        QMetaObject::connectSlotsByName(RECarClient);
    } // setupUi

    void retranslateUi(QDialog *RECarClient)
    {
        RECarClient->setWindowTitle(QCoreApplication::translate("RECarClient", "Costumer", nullptr));
        rbMode1->setText(QCoreApplication::translate("RECarClient", "Mode #1", nullptr));
        rbMode2->setText(QCoreApplication::translate("RECarClient", "Mode #2", nullptr));
        rbMode3->setText(QCoreApplication::translate("RECarClient", "Mode #3", nullptr));
        label_2->setText(QCoreApplication::translate("RECarClient", "Car model", nullptr));
        label->setText(QCoreApplication::translate("RECarClient", "Code", nullptr));
        leCarmodel->setProperty("Field", QVariant(QCoreApplication::translate("RECarClient", "f_model", nullptr)));
        label_5->setText(QCoreApplication::translate("RECarClient", "Info", nullptr));
        label_4->setText(QCoreApplication::translate("RECarClient", "Costumer name", nullptr));
        label_3->setText(QCoreApplication::translate("RECarClient", "Car gov. number", nullptr));
        label_6->setText(QCoreApplication::translate("RECarClient", "Card code", nullptr));
        leCostumer->setProperty("Field", QVariant(QCoreApplication::translate("RECarClient", "f_name", nullptr)));
        leCode->setProperty("Field", QVariant(QCoreApplication::translate("RECarClient", "f_id", nullptr)));
        leCargovnumber->setProperty("Field", QVariant(QCoreApplication::translate("RECarClient", "f_govNumber", nullptr)));
        leInfo->setProperty("Field", QVariant(QCoreApplication::translate("RECarClient", "f_info", nullptr)));
        leCardcode->setProperty("Field", QVariant(QCoreApplication::translate("RECarClient", "f_card", nullptr)));
        btnSave->setText(QCoreApplication::translate("RECarClient", "Save", nullptr));
        btnReject->setText(QCoreApplication::translate("RECarClient", "Reject", nullptr));
        label_7->setText(QCoreApplication::translate("RECarClient", "Count of visit", nullptr));
        label_8->setText(QCoreApplication::translate("RECarClient", "Value", nullptr));
        label_9->setText(QCoreApplication::translate("RECarClient", "Items", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RECarClient: public Ui_RECarClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECARCLIENT_H
