#include "EnterGameResultsDialog.h"
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
    ui->label->setAlignment(Qt::AlignCenter);
}

EnterGameResults::~EnterGameResults()
{
    delete ui;
}

void EnterGameResults::on_lineEdit_returnPressed()
{
    //std::shared_ptr<Player> p = std::make_shared<Player>();
    accept();
    close();
}

void EnterGameResults::enterScores(){
    std::shared_ptr<Player> p = std::make_shared<Player>();

    for(int i = 0; i < this->game->getPlayers().size(); i++){

        ui->label->setText("Enter " + this->game->getPlayers().at(i)->getQName() + "'s Score");
        int gameScore = ui->lineEdit->text().toInt();

        game->insertResult(std::pair<std::string, int>(game->getPlayers().at(i)->getName(), gameScore));

        //int score = ui->lineEdit->text().toInt();

        p->setScore(gameScore);
        //this->game->addPlayerToGame(p);
        qDebug()<< gameScore;
    }
}

int EnterGameResults::playerScore() const{
    return ui->lineEdit->text().toInt();
};

void EnterGameResults::editLabel(QString str){
    ui->label->setText(str);
}
