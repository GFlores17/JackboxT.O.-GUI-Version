/********************************************************************************
** Form generated from reading UI file 'tournamentMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURNAMENTMENU_H
#define UI_TOURNAMENTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TournamentMenu
{
public:
    QTextEdit *textEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *registerButton;
    QPushButton *startButton;
    QPushButton *continueButton;
    QPushButton *printPlayersButton;
    QPushButton *exitButton;
    QLabel *label;

    void setupUi(QWidget *TournamentMenu)
    {
        if (TournamentMenu->objectName().isEmpty())
            TournamentMenu->setObjectName(QString::fromUtf8("TournamentMenu"));
        TournamentMenu->resize(663, 491);
        textEdit = new QTextEdit(TournamentMenu);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(40, 70, 340, 311));
        textEdit->setAutoFillBackground(true);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        verticalLayoutWidget = new QWidget(TournamentMenu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(410, 180, 201, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        registerButton = new QPushButton(verticalLayoutWidget);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(10);
        registerButton->setFont(font);

        verticalLayout->addWidget(registerButton);

        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setFont(font);

        verticalLayout->addWidget(startButton);

        continueButton = new QPushButton(verticalLayoutWidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setFont(font);

        verticalLayout->addWidget(continueButton);

        printPlayersButton = new QPushButton(verticalLayoutWidget);
        printPlayersButton->setObjectName(QString::fromUtf8("printPlayersButton"));
        printPlayersButton->setFont(font);

        verticalLayout->addWidget(printPlayersButton);

        exitButton = new QPushButton(verticalLayoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font);

        verticalLayout->addWidget(exitButton);

        label = new QLabel(TournamentMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 120, 181, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        retranslateUi(TournamentMenu);

        QMetaObject::connectSlotsByName(TournamentMenu);
    } // setupUi

    void retranslateUi(QWidget *TournamentMenu)
    {
        TournamentMenu->setWindowTitle(QCoreApplication::translate("TournamentMenu", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("TournamentMenu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/new/prefix1/Jackbox Logo.png\" /></p></body></html>", nullptr));
        registerButton->setText(QCoreApplication::translate("TournamentMenu", "1. Register Players", nullptr));
        startButton->setText(QCoreApplication::translate("TournamentMenu", "2. Start Round", nullptr));
        continueButton->setText(QCoreApplication::translate("TournamentMenu", "3. Continue Round", nullptr));
        printPlayersButton->setText(QCoreApplication::translate("TournamentMenu", "4. Display Tournament Roster", nullptr));
        exitButton->setText(QCoreApplication::translate("TournamentMenu", "5. Exit", nullptr));
        label->setText(QCoreApplication::translate("TournamentMenu", "Tournament Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TournamentMenu: public Ui_TournamentMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURNAMENTMENU_H
