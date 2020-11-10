#include "tournamentRoster.h"
#include "ui_tournamentRoster.h"

TournamentRoster::TournamentRoster(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TournamentRoster)
{
    ui->setupUi(this);
    passedTournament = T;

    ui->listWidget->clear();
    QString output;

    for(int i = 0; i < passedTournament->getNumberOfPlayers(); i++){
        int j = i+1;
        output = QString::number(j) + ". " + passedTournament->getListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->listWidget->addItem(output);
    }
}

TournamentRoster::~TournamentRoster()
{
    delete ui;
}

void TournamentRoster::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString output;

    for(int i = 0; i < passedTournament->getNumberOfPlayers(); i++){
        int j = i+1;
        output = QString::number(j) + ". " + passedTournament->getListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->listWidget->addItem(output);
    }

}
