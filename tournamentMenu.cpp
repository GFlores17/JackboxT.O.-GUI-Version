#include "tournamentMenu.h"
#include "ui_tournamentMenu.h"
#include "tournament.h"
#include "playerRegistrationForm.h"
#include "tournamentRoster.h"
#include "roundMenu.h"
#include <memory>

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
     //ui->listWidget->setStyleSheet("QListWidget {background-color: #FFFFFF}");

     passedTournament = T;
     Tournament *T1 = T.get();
     Tournament *T2 = passedTournament.get();

     QString ptrStr = QString("0x%1").arg((quintptr)T1,
                         QT_POINTER_SIZE * 2, 16, QChar('0'));

     QString ptrStr2 = QString("0x%1").arg((quintptr)T2,
                         QT_POINTER_SIZE * 2, 16, QChar('0'));



     ui->lineEdit->setText(ptrStr + " : " + ptrStr2);
     //ui->textEdit_2->setText(QString::number(passedTournament.use_count()) + " : " + QString::number(T.use_count()));

}

TournamentMenu::~TournamentMenu()
{
    delete ui;
}

void TournamentMenu::on_registerButton_clicked()
{
    PlayerRegistrationForm *registerForm = new PlayerRegistrationForm(passedTournament);
    registerForm->show();
}

void TournamentMenu::on_startButton_clicked()
{
    RoundMenu *RM = new RoundMenu(passedTournament);
    RM->show();
}

void TournamentMenu::on_continueButton_clicked()
{

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
