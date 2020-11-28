#include "MatchMenu.h"
#include "ui_MatchMenu.h"
#include "Round.h"
//#include "match.h"
#include "Game.h"
#include "EnterGameResults.h"
#include "QDebug"
#include "AddPlayerToGame.h"


MatchMenu::MatchMenu(std::shared_ptr<Match> m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchMenu)
{
    //PRINT ALL GAMES IN THE MATCH HERE.
    this->match = m;
    //printGames();
    ui->setupUi(this);

    std::shared_ptr<Game> m1 = std::make_shared<Game>("Game1");
    std::shared_ptr<Game> m3 = std::make_shared<Game>("Game3");
    std::shared_ptr<Game> m2 = std::make_shared<Game>("Game2");
    std::shared_ptr<Game> m7 = std::make_shared<Game>("Game7");


    //match->addGame()
    std::string name = match->getName() + " Menu";
    this->setWindowTitle(QString::fromStdString(name));
    printGames();

    ui->FinishGameButton->setEnabled(false);
    ui->pushButton->setEnabled(false);

    qDebug() << "SIZE : " << this->match->getListOfGames().size();

    //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    //QTableWidgetItem *newItem = new QTableWidgetItem("TEST");
    //ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, newItem);
}

MatchMenu::~MatchMenu()
{
    delete ui;
}

void MatchMenu::printGames(){
    ui->listWidget->clear();

    if(this->match->getListOfGames().size() > 0){
        for(int i = 0; i < this->match->getListOfGames().size(); i++){
            int j = i+1;
            QString output = QString::number(j) + ". " + QString::fromStdString(this->match->getListOfGames().at(i)->getName());
            //output = output + "\n";
            ui->listWidget->addItem(output);
        }
    }
}

void MatchMenu::printPlayersAndScores(){
    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    int numOfPlayersInGame = this->match->getListOfGames().at(x)->getPlayers().size();
    ui->tableWidget->setRowCount(0);

    for(int i = 0; i < numOfPlayersInGame; i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        QTableWidgetItem *newName = new QTableWidgetItem(this->match->getListOfGames().at(x)->getPlayers().at(i)->getQName());
        QTableWidgetItem *newScore = new QTableWidgetItem(QString::number(this->match->getListOfGames().at(x)->getPlayers().at(i)->getScore()));

        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, NAME, newName);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, SCORE, newScore);
    }
}

void MatchMenu::on_pushButton_3_clicked()
{
     std::shared_ptr<Game> m1 = std::make_shared<Game>("Game " + std::to_string(this->match->getListOfGames().size()+1));
     match->addGame(m1);
     ui->listWidget->clear();
     printGames();
}

void MatchMenu::on_FinishGameButton_clicked()
{

    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    std::shared_ptr<Game> g2 = this->match->getListOfGames().at(x);
    EnterGameResults EGR(g2);
    EGR.setModal(true);
    EGR.exec();
}

void MatchMenu::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->FinishGameButton->setEnabled(true);
    ui->pushButton->setEnabled(true);

    printPlayersAndScores();

}

void MatchMenu::on_pushButton_clicked()
{

    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    AddPlayerToGame APTG;
    APTG.exec();
    APTG.setWindowTitle("Add Player To Game");

    std::shared_ptr<Player> p = std::make_shared<Player>(APTG.playerName());
    qDebug() << p->getQName();

    this->match->getListOfGames().at(x)->addPlayerToGame(p);

    printPlayersAndScores();
}
