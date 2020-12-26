#include "TournamentRoster.h"
#include "ui_tournamentRoster.h"
#include "EditPlayerDialog.h"


TournamentRoster::TournamentRoster(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TournamentRoster)
{
    ui->setupUi(this);
    passedTournament = T;

    passedTournament->scoreSort();
    printPlayersAndScores();

    ui->label->setAlignment(Qt::AlignCenter);

    if(this->passedTournament->getListOfRounds().size() > 0){
        ui->label->setText("Standings after " + this->passedTournament->getListOfRounds().back()->getRoundName());

    }

    this->setStyleSheet("color: black;"
                            "background-color: #F9DFCB;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    ui->tableWidget->setStyleSheet("QTableWidget{background-color: #FFFFFF}");

    ui->pushButton->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: #FFFFFF;}");
    ui->pushButton_2->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: #FFFFFF;}");

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    ui->pushButton->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: grey;}");
    ui->pushButton_2->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: grey;}");

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

void TournamentRoster::on_pushButton_clicked()
{
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    int x = ui->tableWidget->row(item);

    EditPlayerDialog EPD;
    EPD.setModal(true);
    EPD.exec();

    std::string name = EPD.getName();
    this->passedTournament->getListOfPlayers().at(x)->setName(name);

    printPlayersAndScores();

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    ui->pushButton->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: grey;}");
    ui->pushButton_2->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: grey;}");

}

void TournamentRoster::on_pushButton_2_clicked()
{
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    int x = ui->tableWidget->row(item);

    this->passedTournament->deletePlayer(x);
    printPlayersAndScores();

    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    ui->pushButton->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: grey;}");
    ui->pushButton_2->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: grey;}");
}

void TournamentRoster::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);

    ui->pushButton->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: #FFFFFF;}");
    ui->pushButton_2->setStyleSheet("QPushButton::hover{background-color : cyan;}"
                                    "QPushButton{background-color: #FFFFFF;}");
}
