/********************************************************************************
** Form generated from reading UI file 'DialogButtonBottom.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBUTTONBOTTOM_H
#define UI_DIALOGBUTTONBOTTOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *nameLabel;
    QLabel *emailLabel;
    QHBoxLayout *OkContainer;
    QPushButton *okButton;

    void setupUi(QDialog *InfoDialog)
    {
        if (InfoDialog->objectName().isEmpty())
            InfoDialog->setObjectName("InfoDialog");
        InfoDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(InfoDialog);
        verticalLayout->setObjectName("verticalLayout");
        nameLabel = new QLabel(InfoDialog);
        nameLabel->setObjectName("nameLabel");

        verticalLayout->addWidget(nameLabel);

        emailLabel = new QLabel(InfoDialog);
        emailLabel->setObjectName("emailLabel");

        verticalLayout->addWidget(emailLabel);

        OkContainer = new QHBoxLayout();
#ifndef Q_OS_MAC
        OkContainer->setSpacing(6);
#endif
        OkContainer->setContentsMargins(0, 0, 0, 0);
        OkContainer->setObjectName("OkContainer");
        okButton = new QPushButton(InfoDialog);
        okButton->setObjectName("okButton");

        OkContainer->addWidget(okButton);


        verticalLayout->addLayout(OkContainer);


        retranslateUi(InfoDialog);
        QObject::connect(okButton, &QPushButton::clicked, InfoDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(InfoDialog);
    } // setupUi

    void retranslateUi(QDialog *InfoDialog)
    {
        InfoDialog->setWindowTitle(QCoreApplication::translate("InfoDialog", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("InfoDialog", "Developed by Ferenc Szab\303\263", nullptr));
        emailLabel->setText(QCoreApplication::translate("InfoDialog", "Email: irkm813@gmail.com", nullptr));
        okButton->setText(QCoreApplication::translate("InfoDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoDialog: public Ui_InfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBUTTONBOTTOM_H
