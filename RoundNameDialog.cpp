#include "RoundNameDialog.h"
#include "ui_RoundNameDialog.h"

RoundNameDialog::RoundNameDialog(std::shared_ptr<Tournament> T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoundNameDialog)
{
    ui->setupUi(this);
    passedTournament = T;
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
