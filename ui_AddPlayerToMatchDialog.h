/********************************************************************************
** Form generated from reading UI file 'AddPlayerToMatchDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYERTOMATCHDIALOG_H
#define UI_ADDPLAYERTOMATCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPlayerToMatchDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *roundRoster;
    QListWidget *matchRoster;

    void setupUi(QDialog *AddPlayerToMatchDialog)
    {
        if (AddPlayerToMatchDialog->objectName().isEmpty())
            AddPlayerToMatchDialog->setObjectName(QString::fromUtf8("AddPlayerToMatchDialog"));
        AddPlayerToMatchDialog->resize(656, 532);
        buttonBox = new QDialogButtonBox(AddPlayerToMatchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(540, 470, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_3 = new QLabel(AddPlayerToMatchDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 50, 231, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(14);
        label_3->setFont(font);
        label = new QLabel(AddPlayerToMatchDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 90, 101, 16));
        pushButton = new QPushButton(AddPlayerToMatchDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 390, 121, 23));
        label_2 = new QLabel(AddPlayerToMatchDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(400, 90, 71, 16));
        pushButton_2 = new QPushButton(AddPlayerToMatchDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 390, 131, 23));
        horizontalLayoutWidget = new QWidget(AddPlayerToMatchDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(90, 110, 451, 261));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        roundRoster = new QListWidget(horizontalLayoutWidget);
        roundRoster->setObjectName(QString::fromUtf8("roundRoster"));

        horizontalLayout->addWidget(roundRoster);

        matchRoster = new QListWidget(horizontalLayoutWidget);
        matchRoster->setObjectName(QString::fromUtf8("matchRoster"));

        horizontalLayout->addWidget(matchRoster);


        retranslateUi(AddPlayerToMatchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddPlayerToMatchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddPlayerToMatchDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddPlayerToMatchDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPlayerToMatchDialog)
    {
        AddPlayerToMatchDialog->setWindowTitle(QCoreApplication::translate("AddPlayerToMatchDialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("AddPlayerToMatchDialog", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("AddPlayerToMatchDialog", "Round Roster", nullptr));
        pushButton->setText(QCoreApplication::translate("AddPlayerToMatchDialog", "Add To Match", nullptr));
        label_2->setText(QCoreApplication::translate("AddPlayerToMatchDialog", "Match Roster", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AddPlayerToMatchDialog", "Remove From Match", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPlayerToMatchDialog: public Ui_AddPlayerToMatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYERTOMATCHDIALOG_H
