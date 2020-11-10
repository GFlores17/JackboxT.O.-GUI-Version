#include "roundMenu.h"
#include "ui_roundMenu.h"

RoundMenu::RoundMenu(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoundMenu)
{
    ui->setupUi(this);
    passedTournament = T;
}

RoundMenu::~RoundMenu()
{
    delete ui;
}

void RoundMenu::on_addMatchButton_clicked()
{
    ui->exitButton->setVisible(false);

}

void RoundMenu::on_selectMatchButton_clicked()
{
     ui->exitButton->setVisible(true);
}

void RoundMenu::on_exitButton_clicked()
{
    this->close();
}


