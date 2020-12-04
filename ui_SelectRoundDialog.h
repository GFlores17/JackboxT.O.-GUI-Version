/********************************************************************************
** Form generated from reading UI file 'SelectRoundDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTROUNDDIALOG_H
#define UI_SELECTROUNDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectRoundDialog
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *SelectRoundDialog)
    {
        if (SelectRoundDialog->objectName().isEmpty())
            SelectRoundDialog->setObjectName(QString::fromUtf8("SelectRoundDialog"));
        SelectRoundDialog->resize(529, 300);
        listWidget = new QListWidget(SelectRoundDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(50, 50, 161, 192));
        pushButton = new QPushButton(SelectRoundDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 100, 75, 23));
        pushButton_2 = new QPushButton(SelectRoundDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 130, 75, 23));
        listWidget_2 = new QListWidget(SelectRoundDialog);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(240, 50, 161, 192));
        label = new QLabel(SelectRoundDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 30, 61, 16));
        label_2 = new QLabel(SelectRoundDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 30, 47, 13));

        retranslateUi(SelectRoundDialog);

        QMetaObject::connectSlotsByName(SelectRoundDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectRoundDialog)
    {
        SelectRoundDialog->setWindowTitle(QCoreApplication::translate("SelectRoundDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SelectRoundDialog", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SelectRoundDialog", "Cancel", nullptr));
        label->setText(QCoreApplication::translate("SelectRoundDialog", "Round Name", nullptr));
        label_2->setText(QCoreApplication::translate("SelectRoundDialog", "Players", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectRoundDialog: public Ui_SelectRoundDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTROUNDDIALOG_H
