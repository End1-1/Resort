/********************************************************************************
** Form generated from reading UI file 'dlgcontact.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCONTACT_H
#define UI_DLGCONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgContact
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *leId;
    QLineEdit *leName;
    QLineEdit *leTel1;
    QLineEdit *leTel2;
    QLineEdit *leFax;
    QLineEdit *leEmail;
    QTextEdit *teNotes;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DlgContact)
    {
        if (DlgContact->objectName().isEmpty())
            DlgContact->setObjectName(QString::fromUtf8("DlgContact"));
        DlgContact->resize(400, 300);
        verticalLayout = new QVBoxLayout(DlgContact);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgContact);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DlgContact);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(DlgContact);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(DlgContact);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_7 = new QLabel(DlgContact);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_5 = new QLabel(DlgContact);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(DlgContact);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        leId = new QLineEdit(DlgContact);
        leId->setObjectName(QString::fromUtf8("leId"));
        leId->setFocusPolicy(Qt::NoFocus);
        leId->setReadOnly(true);

        gridLayout->addWidget(leId, 0, 1, 1, 1);

        leName = new QLineEdit(DlgContact);
        leName->setObjectName(QString::fromUtf8("leName"));

        gridLayout->addWidget(leName, 1, 1, 1, 1);

        leTel1 = new QLineEdit(DlgContact);
        leTel1->setObjectName(QString::fromUtf8("leTel1"));

        gridLayout->addWidget(leTel1, 2, 1, 1, 1);

        leTel2 = new QLineEdit(DlgContact);
        leTel2->setObjectName(QString::fromUtf8("leTel2"));

        gridLayout->addWidget(leTel2, 3, 1, 1, 1);

        leFax = new QLineEdit(DlgContact);
        leFax->setObjectName(QString::fromUtf8("leFax"));

        gridLayout->addWidget(leFax, 4, 1, 1, 1);

        leEmail = new QLineEdit(DlgContact);
        leEmail->setObjectName(QString::fromUtf8("leEmail"));

        gridLayout->addWidget(leEmail, 5, 1, 1, 1);

        teNotes = new QTextEdit(DlgContact);
        teNotes->setObjectName(QString::fromUtf8("teNotes"));

        gridLayout->addWidget(teNotes, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(DlgContact);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(leName, leTel1);
        QWidget::setTabOrder(leTel1, leTel2);
        QWidget::setTabOrder(leTel2, leFax);
        QWidget::setTabOrder(leFax, leEmail);
        QWidget::setTabOrder(leEmail, teNotes);
        QWidget::setTabOrder(teNotes, leId);

        retranslateUi(DlgContact);
        QObject::connect(buttonBox, SIGNAL(accepted()), DlgContact, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DlgContact, SLOT(reject()));

        QMetaObject::connectSlotsByName(DlgContact);
    } // setupUi

    void retranslateUi(QDialog *DlgContact)
    {
        DlgContact->setWindowTitle(QCoreApplication::translate("DlgContact", "Contact", nullptr));
        label->setText(QCoreApplication::translate("DlgContact", "Code", nullptr));
        label_2->setText(QCoreApplication::translate("DlgContact", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("DlgContact", "Tel. 1", nullptr));
        label_4->setText(QCoreApplication::translate("DlgContact", "Tel. 2", nullptr));
        label_7->setText(QCoreApplication::translate("DlgContact", "Notes", nullptr));
        label_5->setText(QCoreApplication::translate("DlgContact", "Fax", nullptr));
        label_6->setText(QCoreApplication::translate("DlgContact", "E-mail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgContact: public Ui_DlgContact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCONTACT_H
