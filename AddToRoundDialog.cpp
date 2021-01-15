#include "AddToRoundDialog.h"
#include "ui_AddToRoundDialog.h"
#include <QtDebug>

AddToRoundDialog::AddToRoundDialog(std::shared_ptr<Tournament> T, int x, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToRoundDialog)
{
    ui->setupUi(this);
    passedTournament = T;

    this->setWindowTitle("Add To Round Dialog");

    QString output;

    this->round = passedTournament->getListOfRounds().at(x);

    //ui->menuLabel
    ui->menuLabel->setText(round->getRoundName() + " Menu");
    ui->menuLabel->setWordWrap(true);
    ui->menuLabel->setAlignment(Qt::AlignCenter);

    this->setStyleSheet("background-color: #58CCED;");

    ui->tournamentRosterListWidget->setStyleSheet("background-color: #FFFFFF;");
    ui->roundRosterListWidget->setStyleSheet("background-color: #FFFFFF;");

    ui->addToRoundButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                        "QPushButton {background-color: #FFFFFF}");

    ui->removeFromRoundButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->addAllPlayersButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                        "QPushButton{background-color: #FFFFFF;}");

    ui->removeAllPlayersButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                        "QPushButton{background-color: #FFFFFF;}");

    ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    for(int i = 0; i < passedTournament->getNumberOfPlayers(); i++){
        int j = i+1;
        output = QString::number(j) + ". " + passedTournament->getListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->tournamentRosterListWidget->addItem(output);
    }

    if(round->getRoundListOfPlayers().size()>0){
        for(int i = 0; i < round->getRoundListOfPlayers().size(); i++){
            int j = i+1;
            output = QString::number(j) + ". " + round->getRoundListOfPlayers().at(i)->getQName();
            //output = output + "\n";
            ui->roundRosterListWidget->addItem(output);
        }
    }

    ui->addToRoundButton->setEnabled(false);
    ui->removeFromRoundButton->setEnabled(false);
}

AddToRoundDialog::~AddToRoundDialog()
{
    delete ui;
}

void AddToRoundDialog::on_addToRoundButton_clicked()
{

    QListWidgetItem *item = ui->tournamentRosterListWidget->currentItem();
    int x = ui->tournamentRosterListWidget->row(item);



    //Duplicating shared ptr from Tournament List to put in Round List.
    std::shared_ptr<Player> p(passedTournament->getListOfPlayers().at(x));

    //Create a variable pointing directly to round instead of having to do Tournament->getRoundList->getPlayerList->.....
    std::shared_ptr<Round> r(passedTournament->getListOfRounds().back());
    r->addPlayer(p);

    ui->roundRosterListWidget->clear();

    //Print players in Round.
    for(int i = 0; i < round->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + round->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->roundRosterListWidget->addItem(output);
    }

}


void AddToRoundDialog::on_tournamentRosterListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    item = ui->tournamentRosterListWidget->currentItem();
    int x = ui->tournamentRosterListWidget->row(item);



    //Duplicating shared ptr from Tournament List to put in Round List.
    std::shared_ptr<Player> p(passedTournament->getListOfPlayers().at(x));

    //Create a variable pointing directly to round instead of having to do Tournament->getRoundList->getPlayerList->.....
    //std::shared_ptr<Round> r(passedTournament->getListOfRounds().back());
    round->addPlayer(p);

    ui->roundRosterListWidget->clear();

    //Print players in Round.
    for(int i = 0; i < round->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + round->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->roundRosterListWidget->addItem(output);
    }

    //ui->roundRosterListWidget->clear();
}

void AddToRoundDialog::on_tournamentRosterListWidget_itemClicked(QListWidgetItem *item)
{
    ui->addToRoundButton->setEnabled(true);
}

void AddToRoundDialog::on_buttonBox_accepted()
{
    this->close();
}



void AddToRoundDialog::on_removeFromRoundButton_clicked()
{
    //ui->roundRosterListWidget->clear();

    QListWidgetItem *item = ui->roundRosterListWidget->currentItem();
    int x = ui->roundRosterListWidget->row(item);


    //round->getRoundListOfPlayers().at(x).reset();
    round->deletePlayer(x);


    ui->roundRosterListWidget->clear();


    //Print players in Round.
    for(int i = 0; i < round->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + round->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->roundRosterListWidget->addItem(output);
    }

    ui->removeFromRoundButton->setEnabled(false);

}

void AddToRoundDialog::on_roundRosterListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    item = ui->roundRosterListWidget->currentItem();
    int x = ui->roundRosterListWidget->row(item);


    //round->getRoundListOfPlayers().at(x).reset();
    round->deletePlayer(x);


    ui->roundRosterListWidget->clear();


    //Print players in Round.
    for(int i = 0; i < round->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + round->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->roundRosterListWidget->addItem(output);
    }

    ui->removeFromRoundButton->setEnabled(false);
}

void AddToRoundDialog::on_roundRosterListWidget_itemClicked(QListWidgetItem *item)
{
    ui->removeFromRoundButton->setEnabled(true);
}

void AddToRoundDialog::on_addAllPlayersButton_clicked()
{
    for(int i = 0; i < passedTournament->getListOfPlayers().size(); i++){
        std::shared_ptr<Player> newPlayer = passedTournament->getListOfPlayers().at(i);
        round->addPlayer(newPlayer);
    }

    printRoundPlayers();

}

void AddToRoundDialog::printRoundPlayers(){
    ui->roundRosterListWidget->clear();

    for(int i = 0; i < round->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + round->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->roundRosterListWidget->addItem(output);
    }
}

void AddToRoundDialog::on_removeAllPlayersButton_clicked()
{
    round->deleteAllPlayers();
    printRoundPlayers();
}
