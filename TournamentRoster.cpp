#include "TournamentRoster.h"
#include "ui_tournamentRoster.h"


TournamentRoster::TournamentRoster(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TournamentRoster)
{
    ui->setupUi(this);
    passedTournament = T;

    passedTournament->scoreSort();
    printPlayersAndScores();

}

TournamentRoster::~TournamentRoster()
{
    delete ui;
}

void TournamentRoster::printPlayers(){
    /*
    ui->listWidget->clear();
    QString output;
    for(int i = 0; i < passedTournament->getNumberOfPlayers(); i++){
        int j = i+1;
        output = QString::number(j) + ". " + passedTournament->getListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->listWidget->addItem(output);
    }
    */
}

void TournamentRoster::printPlayersAndScores(){
    ui->tableWidget->setRowCount(0);

    for(int i = 0; i < this->passedTournament->getNumberOfPlayers(); i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        std::string searchString = this->passedTournament->getListOfPlayers().at(i)->getName();
        int searchedScore = this->passedTournament->getListOfPlayers().at(i)->getScore();

        QTableWidgetItem *newName = new QTableWidgetItem(QString::fromStdString(searchString));
        QTableWidgetItem *newScore = new QTableWidgetItem(QString::number(searchedScore));

        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, NAME, newName);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, SCORE, newScore);
    }



}
