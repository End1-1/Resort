/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *label;
    QLabel *lbDebug;
    QDialogButtonBox *buttonBox;
    QLabel *lbVersion;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *lbLicense;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(338, 220);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(About->sizePolicy().hasHeightForWidth());
        About->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(About);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 1, 1, 1);

        label_2 = new QLabel(About);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(About);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/app.png")));

        gridLayout->addWidget(label, 0, 0, 9, 1);

        lbDebug = new QLabel(About);
        lbDebug->setObjectName(QString::fromUtf8("lbDebug"));

        gridLayout->addWidget(lbDebug, 5, 1, 1, 1);

        buttonBox = new QDialogButtonBox(About);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 10, 0, 1, 2);

        lbVersion = new QLabel(About);
        lbVersion->setObjectName(QString::fromUtf8("lbVersion"));
        QFont font1;
        font1.setPointSize(10);
        font1.setItalic(false);
        lbVersion->setFont(font1);

        gridLayout->addWidget(lbVersion, 1, 1, 1, 1);

        label_6 = new QLabel(About);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 1, 1, 1);

        label_5 = new QLabel(About);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 1, 1, 1);

        label_4 = new QLabel(About);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        lbLicense = new QLabel(About);
        lbLicense->setObjectName(QString::fromUtf8("lbLicense"));

        gridLayout->addWidget(lbLicense, 6, 1, 1, 1);


        retranslateUi(About);
        QObject::connect(buttonBox, SIGNAL(accepted()), About, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), About, SLOT(reject()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "About", nullptr));
        label_2->setText(QCoreApplication::translate("About", "SmartHotel", nullptr));
        label->setText(QString());
        lbDebug->setText(QCoreApplication::translate("About", "DEBUG VERSION", nullptr));
        lbVersion->setText(QCoreApplication::translate("About", "v 1.0", nullptr));
        label_6->setText(QCoreApplication::translate("About", "Url: http://www.smarthotel.am", nullptr));
        label_5->setText(QCoreApplication::translate("About", "Email: end1_1@yahoo.com", nullptr));
        label_4->setText(QCoreApplication::translate("About", "(C) Kudryashov Vasili", nullptr));
        lbLicense->setText(QCoreApplication::translate("About", "License:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
