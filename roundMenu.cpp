#include "roundMenu.h"
#include "ui_roundMenu.h"
#include "round.h"
#include "MatchNameDialog.h"
#include "MatchMenu.h"
#include "qdebug.h"

RoundMenu::RoundMenu(std::shared_ptr<Round> R, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoundMenu)
{
    ui->setupUi(this);
    this->round = R;

    this->setWindowTitle("Round Menu");

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

    printMatches();

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
