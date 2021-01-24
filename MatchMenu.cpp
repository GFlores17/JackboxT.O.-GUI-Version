#include "MatchMenu.h"
#include "ui_MatchMenu.h"
#include "Round.h"
//#include "match.h"
#include "Game.h"
#include "EnterGameResultsDialog.h"
#include "QDebug"
#include "AddPlayerToGameDialog.h"
#include <fstream>


MatchMenu::MatchMenu(std::shared_ptr<Match> m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatchMenu)
{
    //PRINT ALL GAMES IN THE MATCH HERE.
    this->match = m;
    ui->setupUi(this);

    ui->gameResultsLabel->setText("Results Of All Games.");
    printMatchStandings();

    std::string name = match->getName() + " Menu";
    this->setWindowTitle(QString::fromStdString(name));
    printGames();

    ui->finishGameButton->setEnabled(false);

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");


    ui->deleteGameButton->setEnabled(false);

    ui->listWidget->setStyleSheet("QListWidget{background-color: #FFFFFF}");
    ui->listWidget->setStyleSheet("QListWidget{background-color: #FFFFFF}");
    ui->tableWidget->setStyleSheet("QTableWidget{background-color: #FFFFFF}");

    ui->addGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: #FFFFFF;}");

    ui->deleteGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: gray;}");

    ui->finishGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: gray;}");

    ui->exitButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: #FFFFFF;}");



    ui->tableWidget->viewport()->setAutoFillBackground(false);
    ui->listWidget->viewport()->setAutoFillBackground(false);
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

void MatchMenu::on_addGameButton_clicked()
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

void MatchMenu::on_finishGameButton_clicked()
{

    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    std::shared_ptr<Game> g2 = this->match->getListOfGames().at(x);


    if(g2->getMap().empty() == 0){
        g2->clearResultsMap();

        printPlayersAndScores();
        _sleep(300);
    }
    else{
        g2->clearResultsMap();
    }

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
                    //std::cout << word << " :: " << count << std::endl;
                }
        }
    }

    ui->finishGameButton->setEnabled(false);
    ui->finishGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: gray;}");
    printPlayersAndScores();
}
void MatchMenu::on_listWidget_itemClicked(QListWidgetItem *item)
{



    ui->finishGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: #FFFFFF;}");

    ui->deleteGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: #FFFFFF;}");

    ui->finishGameButton->setEnabled(true);

    ui->deleteGameButton->setEnabled(true);

    printPlayersAndScores();


    item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    /*
    if(match->getListOfGames().at(x)->isFinished()){
        ui->finishGameButton->setEnabled(false);
        ui->finishGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                        "QPushButton{background-color: gray;}");
    }
    */


    ui->gameResultsLabel->setText("Game Results");

    for(int i = 0; i < this->match->getListOfGames().at(x)->getPlayers().size(); i++){
    }
    //checking if players are successfully added during deserialization

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

void MatchMenu::printMatchStandings(){

    if(match->getListOfGames().empty() == 0 && match->getListOfGames().at(0)->getMap().empty() == 0){

        ui->tableWidget->setRowCount(0);

        for(int i = 0; i < match->getMatchListOfPlayers().size(); i++){
            std::string searchString = this->match->getMatchListOfPlayers().at(i)->getName();
            int TotalMatchScore = 0;

                for(int j = 0; j < match->getListOfGames().size(); j++){
                    if(match->getListOfGames().at(j)->isFinished()){
                        std::shared_ptr<Game> gameToPrint = match->getListOfGames().at(j);
                        TotalMatchScore = TotalMatchScore + gameToPrint->getMap().at(searchString);
                    }
                }

                ui->tableWidget->insertRow(ui->tableWidget->rowCount());

                QTableWidgetItem *newName = new QTableWidgetItem(QString::fromStdString(searchString));
                QTableWidgetItem *newScore = new QTableWidgetItem(QString::number(TotalMatchScore));

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, NAME, newName);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, SCORE, newScore);
         }
    }

}

void MatchMenu::on_exitButton_clicked()
{

    this->close();
}

void MatchMenu::on_deleteGameButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    if(this->match->getGame(x)->isFinished()==1){
        for(int i = 0; i < this->match->getGame(x)->getPlayers().size(); i++){
            std::map<std::string, int>::iterator it;
            for (it = this->match->getGame(x)->getMap().begin(); it != this->match->getGame(x)->getMap().end(); it++)
            {
                if(this->match->getMatchListOfPlayers().at(i)->getName() == it->first){
                    this->match->getMatchListOfPlayers().at(i)->addToScore(-it->second);
                    break;
                }
            }
        }//end of updating players score
    }

    this->match->deleteGame(x);
    printGames();
    //printMatchStandings();

    ui->deleteGameButton->setEnabled(false);

    ui->deleteGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: gray;}");

    ui->finishGameButton->setEnabled(false);

    ui->finishGameButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: gray;}");
}
