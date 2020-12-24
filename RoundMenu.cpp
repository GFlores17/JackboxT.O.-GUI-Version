#include "RoundMenu.h"
#include "ui_roundMenu.h"
#include "Round.h"
#include "MatchNameDialog.h"
#include "Match.h"
#include "MatchMenu.h"
#include "qdebug.h"
#include "AddPlayerToMatchDialog.h"
#include "Match.h"
#include "TournamentMenu.h"

RoundMenu::RoundMenu(std::shared_ptr<Round> R, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoundMenu)
{
    ui->setupUi(this);
    this->round = R;

    ui->selectMatchButton->setEnabled(false);
    this->setWindowTitle("Round Menu");

    ui->label->setText(round->getRoundName() + " Menu");

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");


    ui->addMatchButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                      "QPushButton {background-color: #FFFFFF}");

    ui->selectMatchButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                         "QPushButton {background-color: #FFFFFF}");

    ui->exitButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                  "QPushButton {background-color: #FFFFFF}");

    ui->listWidget->setStyleSheet("QListWidget{background-color: #FFFFFF}");


    printMatches();
}

RoundMenu::RoundMenu(std::shared_ptr<Round> R, std::shared_ptr<Tournament> T, QMainWindow *pointerToMainWindow) :
    QWidget(),
    ui(new Ui::RoundMenu)
{
    ui->setupUi(this);
    this->round = R;

    ui->selectMatchButton->setEnabled(false);
    ui->label->setText(round->getRoundName() + " Menu");

    this->pointerToMainWindow = pointerToMainWindow;
    this->hostTournament = T;

    this->setWindowTitle("Round Menu");

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");


    ui->addMatchButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                      "QPushButton {background-color: #FFFFFF}");

    ui->selectMatchButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                         "QPushButton {background-color: #FFFFFF}");

    ui->exitButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                  "QPushButton {background-color: #FFFFFF}");

    ui->listWidget->setStyleSheet("QListWidget{background-color: #FFFFFF}");
    ui->tableWidget->setStyleSheet("QTableWidget{background-color: #FFFFFF}");

    printMatches();
}

RoundMenu::~RoundMenu()
{
    delete ui;
}

void RoundMenu::on_addMatchButton_clicked()
{
    //ui->exitButton->setVisible(false);
    MatchNameDialog MND(this->round);
    MND.setModal(true);
    MND.exec();

    AddPlayerToMatchDialog ADTMD(this->round, round->getListOfMatches().size()-1);
    ADTMD.setModal(true);
    ADTMD.exec();

    printMatches();

    ui->selectMatchButton->setEnabled(false);

    std::shared_ptr<Match> createdMatch = this->round->getListOfMatches().back();

    MatchMenu *MM = new MatchMenu(createdMatch);
    MM->show();

    /*
    std::shared_ptr<Match> test = this->round->getListOfMatches().back();
    MatchMenu *MM = new MatchMenu(test);
    MM->show();
    */

    //TournamentMenu *TM = new TournamentMenu(this->hostTournament, this->pointerToMainWindow);
}

void RoundMenu::on_selectMatchButton_clicked()
{
     //ui->exitButton->setVisible(true);
    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);
    this->round->getListOfMatches().at(x);

    std::shared_ptr<Match> test;
    test = this->round->getListOfMatches().at(x);

    MatchMenu *MM = new MatchMenu(test);
    MM->show();

}

void RoundMenu::on_exitButton_clicked()
{
    this->round->serializePlayersInRound();

    qDebug() << "BEFORE TM CREATE\n";
    TournamentMenu *TM = new TournamentMenu(this->hostTournament, this->pointerToMainWindow);

    qDebug() << "AFTER TM CREATE\n";
    this->pointerToMainWindow->setCentralWidget(TM);
}



void RoundMenu::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}

void RoundMenu::printMatches(){

    ui->listWidget->clear();

    for(int i = 0; i < this->round->getListOfMatches().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + QString::fromStdString(this->round->getListOfMatches().at(i)->getName());
        //output = output + "\n";
        ui->listWidget->addItem(output);
    }
}

void RoundMenu::on_listWidget_itemClicked(QListWidgetItem *item)
{
     ui->selectMatchButton->setEnabled(true);
     printMatchStandings();
}

void RoundMenu::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);
    this->round->getListOfMatches().at(x);

    std::shared_ptr<Match> test;
    test = this->round->getListOfMatches().at(x);

    MatchMenu *MM = new MatchMenu(test);
    MM->show();
}


void RoundMenu::printMatchStandings(){

    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);
    std::shared_ptr<Match> match = this->round->getListOfMatches().at(x);

    if(match->getListOfGames().empty() == 0 && match->getListOfGames().at(0)->getMap().empty() == 0){

        qDebug() << "ENTERED IF";
        ui->tableWidget->setRowCount(0);

        qDebug() << match->getMatchListOfPlayers().size() << " Players\n";
        for(int i = 0; i < match->getMatchListOfPlayers().size(); i++){
            std::string searchString = match->getMatchListOfPlayers().at(i)->getName();
            qDebug() << "TOTALING : " << match->getMatchListOfPlayers().at(i)->getQName() << "\n";
            int TotalMatchScore = 0;

                for(int j = 0; j < match->getListOfGames().size(); j++){
                    qDebug () << match->getListOfGames().size() << "Games\n";
                    qDebug () << match->getListOfGames().at(j)->isFinished() << "\n";
                    if(match->getListOfGames().at(j)->isFinished()){
                        std::shared_ptr<Game> gameToPrint = match->getListOfGames().at(j);
                        TotalMatchScore = TotalMatchScore + gameToPrint->getMap().at(searchString);
                        qDebug() << "Game : " << j+1 << "\n";
                    }
                }

                ui->tableWidget->insertRow(ui->tableWidget->rowCount());

                QTableWidgetItem *newName = new QTableWidgetItem(QString::fromStdString(searchString));
                QTableWidgetItem *newScore = new QTableWidgetItem(QString::number(TotalMatchScore));

                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, NAME, newName);
                ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, SCORE, newScore);
                qDebug() << "ITEM " << i << " ADDED\n";
         }
    }

    else{
        qDebug() << "No Games finished\n";
    }

}
