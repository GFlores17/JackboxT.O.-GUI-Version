#include "AddPlayerToGameDialog.h"
#include "ui_AddPlayerToGame.h"

AddPlayerToGame::AddPlayerToGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPlayerToGame)
{
    ui->setupUi(this);
}

AddPlayerToGame::~AddPlayerToGame()
{
    delete ui;
}

std::string AddPlayerToGame::getPlayerName() const{
    return ui->playerName->text().toStdString();
}
