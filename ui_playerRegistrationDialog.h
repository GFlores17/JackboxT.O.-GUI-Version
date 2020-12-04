/********************************************************************************
** Form generated from reading UI file 'playerRegistrationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERREGISTRATIONDIALOG_H
#define UI_PLAYERREGISTRATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PlayerRegistrationDialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *PlayerRegistrationDialog)
    {
        if (PlayerRegistrationDialog->objectName().isEmpty())
            PlayerRegistrationDialog->setObjectName(QString::fromUtf8("PlayerRegistrationDialog"));
        PlayerRegistrationDialog->resize(400, 71);
        lineEdit = new QLineEdit(PlayerRegistrationDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 40, 113, 20));
        label = new QLabel(PlayerRegistrationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 101, 16));

        retranslateUi(PlayerRegistrationDialog);

        QMetaObject::connectSlotsByName(PlayerRegistrationDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayerRegistrationDialog)
    {
        PlayerRegistrationDialog->setWindowTitle(QCoreApplication::translate("PlayerRegistrationDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PlayerRegistrationDialog", "Enter player names.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerRegistrationDialog: public Ui_PlayerRegistrationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERREGISTRATIONDIALOG_H
