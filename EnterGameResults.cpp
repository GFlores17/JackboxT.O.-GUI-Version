#include "EnterGameResults.h"
#include "ui_EnterGameResults.h"
#include "Match.h"
#include "Game.h"
#include <QtDebug>

EnterGameResults::EnterGameResults(std::shared_ptr<Game> g, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterGameResults)
{
    this->game = g;
    ui->setupUi(this);
}

EnterGameResults::~EnterGameResults()
{
    delete ui;
}

void EnterGameResults::on_lineEdit_returnPressed()
{
    std::shared_ptr<Player> p = std::make_shared<Player>();
    int score = ui->lineEdit->text().toInt();
    p->setScore(score);
    this->game->addPlayerToGame(p);
    qDebug()<< score;
}

