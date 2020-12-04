/********************************************************************************
** Form generated from reading UI file 'PromptGameNameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMPTGAMENAMEDIALOG_H
#define UI_PROMPTGAMENAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PromptGameNameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *PromptGameNameDialog)
    {
        if (PromptGameNameDialog->objectName().isEmpty())
            PromptGameNameDialog->setObjectName(QString::fromUtf8("PromptGameNameDialog"));
        PromptGameNameDialog->resize(400, 87);
        buttonBox = new QDialogButtonBox(PromptGameNameDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(PromptGameNameDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 10, 101, 16));
        lineEdit = new QLineEdit(PromptGameNameDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 50, 171, 20));

        retranslateUi(PromptGameNameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PromptGameNameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PromptGameNameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PromptGameNameDialog);
    } // setupUi

    void retranslateUi(QDialog *PromptGameNameDialog)
    {
        PromptGameNameDialog->setWindowTitle(QCoreApplication::translate("PromptGameNameDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PromptGameNameDialog", "Enter name of game.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PromptGameNameDialog: public Ui_PromptGameNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMPTGAMENAMEDIALOG_H
