#ifndef PROMPTADDTOROUNDDIALOG_H
#define PROMPTADDTOROUNDDIALOG_H

#include <QDialog>

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>

#include "Tournament.h"

namespace Ui {
class PromptAddToRoundDialog;
}

class PromptAddToRoundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PromptAddToRoundDialog(QWidget *parent = nullptr);
    ~PromptAddToRoundDialog();

    std::shared_ptr<Tournament> passedTournament;
    int num;
    //Clarify variable purpose in name, and look to making this a private variable.

private slots:
    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::PromptAddToRoundDialog *ui;

    QLabel lable;
    QLineEdit lineEdit;
    QDialogButtonBox buttonBox;
    QPushButton yesButton;
    QPushButton noButton;

};

#endif // PROMPTADDTOROUNDDIALOG_H
