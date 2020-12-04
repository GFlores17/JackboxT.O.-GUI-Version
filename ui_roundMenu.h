/********************************************************************************
** Form generated from reading UI file 'roundMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDMENU_H
#define UI_ROUNDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoundMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addMatchButton;
    QPushButton *selectMatchButton;
    QPushButton *exitButton;
    QListWidget *listWidget;
    QLabel *label;

    void setupUi(QWidget *RoundMenu)
    {
        if (RoundMenu->objectName().isEmpty())
            RoundMenu->setObjectName(QString::fromUtf8("RoundMenu"));
        RoundMenu->resize(523, 300);
        verticalLayoutWidget = new QWidget(RoundMenu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(310, 110, 160, 107));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addMatchButton = new QPushButton(verticalLayoutWidget);
        addMatchButton->setObjectName(QString::fromUtf8("addMatchButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        addMatchButton->setFont(font);
        addMatchButton->setAutoFillBackground(false);
        addMatchButton->setFlat(false);

        verticalLayout->addWidget(addMatchButton);

        selectMatchButton = new QPushButton(verticalLayoutWidget);
        selectMatchButton->setObjectName(QString::fromUtf8("selectMatchButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font1.setPointSize(14);
        selectMatchButton->setFont(font1);

        verticalLayout->addWidget(selectMatchButton);

        exitButton = new QPushButton(verticalLayoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setFont(font1);

        verticalLayout->addWidget(exitButton);

        listWidget = new QListWidget(RoundMenu);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 40, 256, 192));
        label = new QLabel(RoundMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 70, 121, 16));
        label->setFont(font1);

        retranslateUi(RoundMenu);

        addMatchButton->setDefault(false);


        QMetaObject::connectSlotsByName(RoundMenu);
    } // setupUi

    void retranslateUi(QWidget *RoundMenu)
    {
        RoundMenu->setWindowTitle(QCoreApplication::translate("RoundMenu", "Form", nullptr));
        addMatchButton->setText(QCoreApplication::translate("RoundMenu", "1. Add Match", nullptr));
        selectMatchButton->setText(QCoreApplication::translate("RoundMenu", "2. Select Match", nullptr));
        exitButton->setText(QCoreApplication::translate("RoundMenu", "3. Exit", nullptr));
        label->setText(QCoreApplication::translate("RoundMenu", "Round Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoundMenu: public Ui_RoundMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDMENU_H
