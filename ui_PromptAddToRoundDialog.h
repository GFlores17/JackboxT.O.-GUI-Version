/********************************************************************************
** Form generated from reading UI file 'PromptAddToRoundDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMPTADDTOROUNDDIALOG_H
#define UI_PROMPTADDTOROUNDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PromptAddToRoundDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *PromptAddToRoundDialog)
    {
        if (PromptAddToRoundDialog->objectName().isEmpty())
            PromptAddToRoundDialog->setObjectName(QString::fromUtf8("PromptAddToRoundDialog"));
        PromptAddToRoundDialog->resize(400, 104);
        horizontalLayoutWidget = new QWidget(PromptAddToRoundDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 50, 311, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        label = new QLabel(PromptAddToRoundDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 221, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(14);
        label->setFont(font);

        retranslateUi(PromptAddToRoundDialog);

        QMetaObject::connectSlotsByName(PromptAddToRoundDialog);
    } // setupUi

    void retranslateUi(QDialog *PromptAddToRoundDialog)
    {
        PromptAddToRoundDialog->setWindowTitle(QCoreApplication::translate("PromptAddToRoundDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("PromptAddToRoundDialog", "Yes", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PromptAddToRoundDialog", "No", nullptr));
        label->setText(QCoreApplication::translate("PromptAddToRoundDialog", "Update players in round?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PromptAddToRoundDialog: public Ui_PromptAddToRoundDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMPTADDTOROUNDDIALOG_H
