#include "MatchMenu.h"
#include "ui_MatchMenu.h"
#include "round.h"
//#include "match.h"
#include "Game.h"
#include "EnterGameResults.h"
#include "QDebug"


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

    match->addGame(m1);
    match->addGame(m3);
    match->addGame(m2);
    match->addGame(m7);

    //match->addGame()
    this->setWindowTitle("Match Menu");
    printGames();

    qDebug() << "SIZE : " << this->match->getListOfGames().size();

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QTableWidgetItem *newItem = new QTableWidgetItem("TEST");
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, newItem);
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

void MatchMenu::on_pushButton_3_clicked()
{

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
