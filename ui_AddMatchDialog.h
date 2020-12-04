/********************************************************************************
** Form generated from reading UI file 'AddMatchDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMATCHDIALOG_H
#define UI_ADDMATCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddMatchDialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AddMatchDialog)
    {
        if (AddMatchDialog->objectName().isEmpty())
            AddMatchDialog->setObjectName(QString::fromUtf8("AddMatchDialog"));
        AddMatchDialog->resize(400, 81);
        lineEdit = new QLineEdit(AddMatchDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 231, 20));
        label = new QLabel(AddMatchDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 20, 91, 16));
        pushButton = new QPushButton(AddMatchDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 20, 75, 23));
        pushButton_2 = new QPushButton(AddMatchDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 50, 75, 23));

        retranslateUi(AddMatchDialog);

        QMetaObject::connectSlotsByName(AddMatchDialog);
    } // setupUi

    void retranslateUi(QDialog *AddMatchDialog)
    {
        AddMatchDialog->setWindowTitle(QCoreApplication::translate("AddMatchDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddMatchDialog", "Enter Match Name", nullptr));
        pushButton->setText(QCoreApplication::translate("AddMatchDialog", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddMatchDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMatchDialog: public Ui_AddMatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMATCHDIALOG_H
