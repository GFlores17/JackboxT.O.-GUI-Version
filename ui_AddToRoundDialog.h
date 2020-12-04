/********************************************************************************
** Form generated from reading UI file 'AddToRoundDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTOROUNDDIALOG_H
#define UI_ADDTOROUNDDIALOG_H

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

class Ui_AddToRoundDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *tournamentListWidget;
    QListWidget *roundListWidget;
    QLabel *label;
    QPushButton *RemoveFromRoundButton;
    QPushButton *AddToRoundButton;
    QLabel *label_2;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddToRoundDialog)
    {
        if (AddToRoundDialog->objectName().isEmpty())
            AddToRoundDialog->setObjectName(QString::fromUtf8("AddToRoundDialog"));
        AddToRoundDialog->resize(679, 533);
        horizontalLayoutWidget = new QWidget(AddToRoundDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(120, 100, 451, 261));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tournamentListWidget = new QListWidget(horizontalLayoutWidget);
        tournamentListWidget->setObjectName(QString::fromUtf8("tournamentListWidget"));

        horizontalLayout->addWidget(tournamentListWidget);

        roundListWidget = new QListWidget(horizontalLayoutWidget);
        roundListWidget->setObjectName(QString::fromUtf8("roundListWidget"));

        horizontalLayout->addWidget(roundListWidget);

        label = new QLabel(AddToRoundDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 80, 101, 16));
        RemoveFromRoundButton = new QPushButton(AddToRoundDialog);
        RemoveFromRoundButton->setObjectName(QString::fromUtf8("RemoveFromRoundButton"));
        RemoveFromRoundButton->setGeometry(QRect(390, 380, 131, 23));
        AddToRoundButton = new QPushButton(AddToRoundDialog);
        AddToRoundButton->setObjectName(QString::fromUtf8("AddToRoundButton"));
        AddToRoundButton->setGeometry(QRect(170, 380, 121, 23));
        label_2 = new QLabel(AddToRoundDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 80, 71, 16));
        label_3 = new QLabel(AddToRoundDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 40, 231, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(14);
        label_3->setFont(font);
        buttonBox = new QDialogButtonBox(AddToRoundDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(580, 470, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(AddToRoundDialog);

        QMetaObject::connectSlotsByName(AddToRoundDialog);
    } // setupUi

    void retranslateUi(QDialog *AddToRoundDialog)
    {
        AddToRoundDialog->setWindowTitle(QCoreApplication::translate("AddToRoundDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddToRoundDialog", "Tournament Roster", nullptr));
        RemoveFromRoundButton->setText(QCoreApplication::translate("AddToRoundDialog", "Remove From Round", nullptr));
        AddToRoundButton->setText(QCoreApplication::translate("AddToRoundDialog", "Add To Round", nullptr));
        label_2->setText(QCoreApplication::translate("AddToRoundDialog", "Round Roster", nullptr));
        label_3->setText(QCoreApplication::translate("AddToRoundDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddToRoundDialog: public Ui_AddToRoundDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTOROUNDDIALOG_H
