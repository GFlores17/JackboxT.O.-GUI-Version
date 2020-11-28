#include "MatchNameDialog.h"
#include "ui_MatchNameDialog.h"
#include "Round.h"

MatchNameDialog::MatchNameDialog(std::shared_ptr<Round> r, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatchNameDialog)
{
    ui->setupUi(this);
    this->round = r;
}

MatchNameDialog::~MatchNameDialog()
{
    delete ui;
}

void MatchNameDialog::on_buttonBox_accepted()
{
    std::shared_ptr<Match> m = std::make_shared<Match>(ui->lineEdit->text());
    this->round->addMatch(m);
}
