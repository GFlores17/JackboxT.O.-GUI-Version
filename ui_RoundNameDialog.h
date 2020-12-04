/********************************************************************************
** Form generated from reading UI file 'RoundNameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDNAMEDIALOG_H
#define UI_ROUNDNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_RoundNameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *RoundNameDialog)
    {
        if (RoundNameDialog->objectName().isEmpty())
            RoundNameDialog->setObjectName(QString::fromUtf8("RoundNameDialog"));
        RoundNameDialog->resize(400, 88);
        buttonBox = new QDialogButtonBox(RoundNameDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(RoundNameDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 50, 211, 20));
        label = new QLabel(RoundNameDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 20, 91, 16));

        retranslateUi(RoundNameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RoundNameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RoundNameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RoundNameDialog);
    } // setupUi

    void retranslateUi(QDialog *RoundNameDialog)
    {
        RoundNameDialog->setWindowTitle(QCoreApplication::translate("RoundNameDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RoundNameDialog", "Enter Round Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoundNameDialog: public Ui_RoundNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDNAMEDIALOG_H
