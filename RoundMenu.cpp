#include "RoundMenu.h"
#include "ui_roundMenu.h"
#include "Round.h"
#include "MatchNameDialog.h"
#include "MatchMenu.h"
#include "qdebug.h"
#include "AddPlayerToMatchDialog.h"
#include "Match.h"

RoundMenu::RoundMenu(std::shared_ptr<Round> R, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoundMenu)
{
    ui->setupUi(this);
    this->round = R;

    ui->selectMatchButton->setEnabled(false);
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
    //this->round->serializeRound();
    this->close();
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
}
