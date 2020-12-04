#include "MatchMenu.h"
#include "ui_MatchMenu.h"
#include "Round.h"
//#include "match.h"
#include "Game.h"
#include "EnterGameResults.h"
#include "QDebug"
#include "AddPlayerToGame.h"
#include <fstream>


MatchMenu::MatchMenu(std::shared_ptr<Match> m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchMenu)
{
    //PRINT ALL GAMES IN THE MATCH HERE.
    this->match = m;
    ui->setupUi(this);


    std::string name = match->getName() + " Menu";
    this->setWindowTitle(QString::fromStdString(name));
    printGames();

    ui->FinishGameButton->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton->setVisible(false);

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

    std::shared_ptr<Game> gameToPrint = match->getListOfGames().at(x);

    bool test;
    test = gameToPrint->getResultsMap().empty();

    if(gameToPrint->getResultsMap().empty() == true){
        for(int i = 0; i < numOfPlayersInGame; i++){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

            QTableWidgetItem *newName = new QTableWidgetItem(this->match->getListOfGames().at(x)->getPlayers().at(i)->getQName());
            QTableWidgetItem *newScore = new QTableWidgetItem("0");

            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, NAME, newName);
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, SCORE, newScore);
         }
    }
    else{
        for(int i = 0; i < numOfPlayersInGame; i++){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

            std::string searchString = this->match->getListOfGames().at(x)->getPlayers().at(i)->getName();
            int searchedScore = gameToPrint->getMap().at(searchString);

            QTableWidgetItem *newName = new QTableWidgetItem(QString::fromStdString(searchString));
            QTableWidgetItem *newScore = new QTableWidgetItem(QString::number(searchedScore));

            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, NAME, newName);
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, SCORE, newScore);
         }


    }
}

void MatchMenu::on_pushButton_3_clicked()
{
     std::shared_ptr<Game> g1 = std::make_shared<Game>("Game " + std::to_string(this->match->getListOfGames().size()+1));

     for(int i = 0; i < match->getMatchListOfPlayers().size(); i++){
         g1->addPlayerToGame(match->getMatchListOfPlayers().at(i));
     }

     initializeScoresTable(g1);
     match->addGame(g1);

     ui->listWidget->clear();
     printGames();
}

void MatchMenu::on_FinishGameButton_clicked()
{

    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    qDebug() << "GAME : " << x;
    std::shared_ptr<Game> g2 = this->match->getListOfGames().at(x);
    qDebug() << "GAME NAME : " << QString::fromStdString(g2->getName());

    qDebug() << "# of Players : " << g2->getPlayers().size();

    for(int i = 0; i < g2->getPlayers().size(); i++){

        int res;
        EnterGameResults EGR(g2);
        EGR.editLabel("Enter " + g2->getPlayers().at(i)->getQName() + "'s Score");
        EGR.setModal(true);
        res = EGR.exec();

        if(res == QDialog::Accepted){

            int gameScore = EGR.playerScore();
            g2->insertResult(std::pair<std::string, int>(g2->getPlayers().at(i)->getName(), gameScore));
            g2->getPlayers().at(i)->addToScore(gameScore);
            //this->game->addPlayerToGame(p);


            for (std::pair<std::string, int> element : g2->getMap()) {
                    // Accessing KEY from element
                    std::string word = element.first;
                    // Accessing VALUE from element.
                    int count = element.second;
                    std::cout << word << " :: " << count << std::endl;
                }
        }
    }
    printPlayersAndScores();
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

void MatchMenu::initializeScoresTable(std::shared_ptr<Game> g){

    //ui->tableWidget->setRowCount(0);

    int numOfPlayersInGame = g->getPlayers().size();

    for(int i = 0; i < numOfPlayersInGame; i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        QTableWidgetItem *newName = new QTableWidgetItem(g->getPlayers().at(i)->getQName());
        QTableWidgetItem *newScore = new QTableWidgetItem(QString::number(g->getPlayers().at(i)->getScore()));

        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, NAME, newName);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, SCORE, newScore);
    }


}

void MatchMenu::on_ExitButton_clicked()
{

    std::ofstream OUTFILE;
    OUTFILE.open("C:\\Users\\George\\Desktop\\games.txt", std::ofstream::trunc);

    //delete above after you figure out hhow to properly serialize this.

    for(int i = 0; i < this->match->getListOfGames().size(); i ++){
        this->match->getListOfGames().at(i)->serializeGame();
    }
    OUTFILE.close();
}
