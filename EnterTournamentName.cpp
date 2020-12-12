#include "EnterTournamentName.h"
#include "ui_EnterTournamentName.h"

EnterTournamentName::EnterTournamentName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterTournamentName)
{
    ui->setupUi(this);
}

EnterTournamentName::~EnterTournamentName()
{
    delete ui;
}

std::string EnterTournamentName::getTournamentName(){
    return (ui->lineEdit->text()).toStdString();
}

void EnterTournamentName::on_buttonBox_accepted()
{
    //this->getTournamentName();
    close();
}
