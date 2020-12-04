/********************************************************************************
** Form generated from reading UI file 'MatchNameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHNAMEDIALOG_H
#define UI_MATCHNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_MatchNameDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *MatchNameDialog)
    {
        if (MatchNameDialog->objectName().isEmpty())
            MatchNameDialog->setObjectName(QString::fromUtf8("MatchNameDialog"));
        MatchNameDialog->resize(400, 87);
        buttonBox = new QDialogButtonBox(MatchNameDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(MatchNameDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 101, 16));
        lineEdit = new QLineEdit(MatchNameDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 50, 211, 20));

        retranslateUi(MatchNameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MatchNameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MatchNameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MatchNameDialog);
    } // setupUi

    void retranslateUi(QDialog *MatchNameDialog)
    {
        MatchNameDialog->setWindowTitle(QCoreApplication::translate("MatchNameDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MatchNameDialog", "Enter Match Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatchNameDialog: public Ui_MatchNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHNAMEDIALOG_H
