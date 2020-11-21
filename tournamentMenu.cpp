#include "tournamentMenu.h"
#include "ui_tournamentMenu.h"
#include "tournament.h"
#include "tournamentRoster.h"
#include "roundMenu.h"
#include "addToRoundForm.h"
#include "ui_addToRoundForm.h"
#include "playerRegistrationDialog.h"
#include "ui_playerRegistrationDialog.h"
#include <memory>
#include "RoundNameDialog.h"
#include "SelectRoundDialog.h"
#include "AddToRoundDialog.h"

TournamentMenu::TournamentMenu(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TournamentMenu)
{
    ui->setupUi(this);
    //ui->textEdit->setText("Welcome to menu.");
    this->setWindowTitle("Tournament Menu");

    this->setStyleSheet("color: black;"
                            "background-color: cyan;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

     ui->textEdit->setStyleSheet("QTextEdit {background-color: #FFFFFF}");


     ui->startButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");
     ui->continueButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");
     ui->exitButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");
     ui->registerButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");
     ui->printPlayersButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");

     passedTournament = T;
     Tournament *T1 = T.get();
     Tournament *T2 = passedTournament.get();

     QString ptrStr = QString("0x%1").arg((quintptr)T1,
                         QT_POINTER_SIZE * 2, 16, QChar('0'));

     QString ptrStr2 = QString("0x%1").arg((quintptr)T2,
                         QT_POINTER_SIZE * 2, 16, QChar('0'));



     ui->lineEdit->setText(ptrStr + " : " + ptrStr2);

}

TournamentMenu::~TournamentMenu()
{
    delete ui;
}

void TournamentMenu::on_registerButton_clicked()
{
    PlayerRegistrationDialog playerReg(passedTournament);
    playerReg.setModal(true);
    playerReg.exec();

}

void TournamentMenu::on_startButton_clicked()
{
    RoundNameDialog RND(passedTournament);
    RND.setModal(true);
    RND.exec();

    //addToRoundForm *ATRF = new addToRoundForm(passedTournament, passedTournament->getListOfRounds().size()-1);
    //ATRF->show();

    AddToRoundDialog ATRD(passedTournament, passedTournament->getListOfRounds().size()-1);
    ATRD.setModal(true);
    ATRD.exec();

}

void TournamentMenu::on_continueButton_clicked()
{
    SelectRoundDialog SRD(passedTournament);
    SRD.setModal(true);
    SRD.exec();
}

void TournamentMenu::on_printPlayersButton_clicked()
{   
    //Takes vector of all players and displays them into the 2nd lineEdit window.
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

    TournamentRoster *TM = new TournamentRoster(passedTournament);
    TM->show();
}

void TournamentMenu::on_exitButton_clicked()
{
    this->close();
}
