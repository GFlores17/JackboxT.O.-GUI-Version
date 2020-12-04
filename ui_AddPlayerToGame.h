/********************************************************************************
** Form generated from reading UI file 'AddPlayerToGame.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPLAYERTOGAME_H
#define UI_ADDPLAYERTOGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPlayerToGame
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *playerName;
    QLabel *label;

    void setupUi(QDialog *AddPlayerToGame)
    {
        if (AddPlayerToGame->objectName().isEmpty())
            AddPlayerToGame->setObjectName(QString::fromUtf8("AddPlayerToGame"));
        AddPlayerToGame->resize(400, 84);
        buttonBox = new QDialogButtonBox(AddPlayerToGame);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        playerName = new QLineEdit(AddPlayerToGame);
        playerName->setObjectName(QString::fromUtf8("playerName"));
        playerName->setGeometry(QRect(110, 50, 113, 20));
        label = new QLabel(AddPlayerToGame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 111, 20));

        retranslateUi(AddPlayerToGame);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddPlayerToGame, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddPlayerToGame, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddPlayerToGame);
    } // setupUi

    void retranslateUi(QDialog *AddPlayerToGame)
    {
        AddPlayerToGame->setWindowTitle(QCoreApplication::translate("AddPlayerToGame", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddPlayerToGame", "Enter Player Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPlayerToGame: public Ui_AddPlayerToGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPLAYERTOGAME_H
