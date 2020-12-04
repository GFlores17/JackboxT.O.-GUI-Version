#include "RoundNameDialog.h"
#include "ui_RoundNameDialog.h"

RoundNameDialog::RoundNameDialog(std::shared_ptr<Tournament> T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoundNameDialog)
{
    ui->setupUi(this);
    passedTournament = T;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    this->setWindowTitle("Round Name Dialog");

}

RoundNameDialog::~RoundNameDialog()
{
    delete ui;
}

void RoundNameDialog::on_buttonBox_accepted()
{
    QString name = (ui->lineEdit->text());
    passedTournament->addRound(name);
}
