/********************************************************************************
** Form generated from reading UI file 'EnterGameResults.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERGAMERESULTS_H
#define UI_ENTERGAMERESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnterGameResults
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *EnterGameResults)
    {
        if (EnterGameResults->objectName().isEmpty())
            EnterGameResults->setObjectName(QString::fromUtf8("EnterGameResults"));
        EnterGameResults->resize(400, 111);
        verticalLayoutWidget = new QWidget(EnterGameResults);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 30, 160, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        retranslateUi(EnterGameResults);

        QMetaObject::connectSlotsByName(EnterGameResults);
    } // setupUi

    void retranslateUi(QDialog *EnterGameResults)
    {
        EnterGameResults->setWindowTitle(QCoreApplication::translate("EnterGameResults", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EnterGameResults", "Enter Score For:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterGameResults: public Ui_EnterGameResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERGAMERESULTS_H
