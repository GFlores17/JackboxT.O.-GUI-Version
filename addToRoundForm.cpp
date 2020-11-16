#include "addToRoundForm.h"
#include "ui_addToRoundForm.h"
#include "tournament.h"
#include "round.h"
#include "RoundNameDialog.h"
#include <QDebug>

addToRoundForm::addToRoundForm(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addToRoundForm)
{
    ui->setupUi(this);
    passedTournament = T;

    QString output;

    for(int i = 0; i < passedTournament->getNumberOfPlayers(); i++){
        int j = i+1;
        output = QString::number(j) + ". " + passedTournament->getListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->tournamentListWidget->addItem(output);
    }

    ui->pushButton->setVisible(false);
}

addToRoundForm::~addToRoundForm()
{
    delete ui;
}

void addToRoundForm::on_pushButton_clicked()
{

    QListWidgetItem *item = ui->tournamentListWidget->currentItem();
    int x = ui->tournamentListWidget->row(item);


    qDebug() << "meme";

    //Duplicating shared ptr from Tournament List to put in Round List.
    std::shared_ptr<Player> p(passedTournament->getListOfPlayers().at(x));

    //Create a variable pointing directly to round instead of having to do Tournament->getRoundList->getPlayerList->.....
    std::shared_ptr<Round> r(passedTournament->getListOfRounds().back());
    r->addPlayer(p);

    ui->roundListWidget->clear();

    //Print players in Round.
    for(int i = 0; i < r->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        qDebug() << r->getRoundListOfPlayers().at(i)->getQName();
        QString output = QString::number(j) + ". " + r->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->roundListWidget->addItem(output);
    }

}


void addToRoundForm::on_tournamentListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int x = ui->tournamentListWidget->row(item);
    ui->textEdit->setText(QString::number(x));
}

void addToRoundForm::on_tournamentListWidget_itemClicked(QListWidgetItem *item)
{
    ui->pushButton->setVisible(true);
}
