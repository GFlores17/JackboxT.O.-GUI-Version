/********************************************************************************
** Form generated from reading UI file 'MatchMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHMENU_H
#define UI_MATCHMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatchMenu
{
public:
    QLabel *label;
    QLabel *label_2;
    QListWidget *listWidget;
    QTableWidget *tableWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ExitButton;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *FinishGameButton;

    void setupUi(QWidget *MatchMenu)
    {
        if (MatchMenu->objectName().isEmpty())
            MatchMenu->setObjectName(QString::fromUtf8("MatchMenu"));
        MatchMenu->resize(633, 300);
        label = new QLabel(MatchMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 30, 111, 20));
        label_2 = new QLabel(MatchMenu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 30, 71, 16));
        listWidget = new QListWidget(MatchMenu);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 50, 256, 192));
        tableWidget = new QTableWidget(MatchMenu);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(340, 50, 256, 192));
        horizontalLayoutWidget = new QWidget(MatchMenu);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 260, 421, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ExitButton = new QPushButton(horizontalLayoutWidget);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));

        horizontalLayout->addWidget(ExitButton);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        FinishGameButton = new QPushButton(horizontalLayoutWidget);
        FinishGameButton->setObjectName(QString::fromUtf8("FinishGameButton"));

        horizontalLayout->addWidget(FinishGameButton);


        retranslateUi(MatchMenu);

        QMetaObject::connectSlotsByName(MatchMenu);
    } // setupUi

    void retranslateUi(QWidget *MatchMenu)
    {
        MatchMenu->setWindowTitle(QCoreApplication::translate("MatchMenu", "Form", nullptr));
        label->setText(QCoreApplication::translate("MatchMenu", "List of Games", nullptr));
        label_2->setText(QCoreApplication::translate("MatchMenu", "Game Results", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MatchMenu", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MatchMenu", "Score", nullptr));
        ExitButton->setText(QCoreApplication::translate("MatchMenu", "Exit", nullptr));
        pushButton->setText(QCoreApplication::translate("MatchMenu", "Add Player", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MatchMenu", "Add Game", nullptr));
        FinishGameButton->setText(QCoreApplication::translate("MatchMenu", "Finish Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MatchMenu: public Ui_MatchMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHMENU_H
