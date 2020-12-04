/********************************************************************************
** Form generated from reading UI file 'tournamentRoster.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOURNAMENTROSTER_H
#define UI_TOURNAMENTROSTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TournamentRoster
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *TournamentRoster)
    {
        if (TournamentRoster->objectName().isEmpty())
            TournamentRoster->setObjectName(QString::fromUtf8("TournamentRoster"));
        TournamentRoster->resize(400, 300);
        listWidget = new QListWidget(TournamentRoster);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(70, 60, 256, 192));
        label = new QLabel(TournamentRoster);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 30, 111, 16));
        pushButton = new QPushButton(TournamentRoster);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 10, 75, 23));
        textEdit = new QTextEdit(TournamentRoster);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(150, 260, 104, 31));

        retranslateUi(TournamentRoster);

        QMetaObject::connectSlotsByName(TournamentRoster);
    } // setupUi

    void retranslateUi(QWidget *TournamentRoster)
    {
        TournamentRoster->setWindowTitle(QCoreApplication::translate("TournamentRoster", "Form", nullptr));
        label->setText(QCoreApplication::translate("TournamentRoster", "Players In Tournament", nullptr));
        pushButton->setText(QCoreApplication::translate("TournamentRoster", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TournamentRoster: public Ui_TournamentRoster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOURNAMENTROSTER_H
