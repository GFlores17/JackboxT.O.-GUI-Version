#include "TournamentMenu.h"
#include "ui_tournamentMenu.h"
#include "Tournament.h"
#include "TournamentRoster.h"
#include "RoundMenu.h"
#include "PlayerRegistrationDialog.h"
#include "ui_playerRegistrationDialog.h"
#include <memory>
#include "RoundNameDialog.h"
#include "SelectRoundDialog.h"
#include "AddToRoundDialog.h"
#include "PromptAddToRoundDialog.h"
#include "Round.h"
#include "MatchMenu.h"
#include <fstream>
#include <MainWindow.h>
#include "MainMenu.h"

TournamentMenu::TournamentMenu(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TournamentMenu)
{
    ui->setupUi(this);
    //ui->textEdit->setText("Welcome to menu.");
    this->setWindowTitle("Tournament Menu");

    //QString meme = QString::fromStdString(this->passedTournament->getTournamentName());
    //this->setWindowTitle(meme);

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    //blue 58CCED
    //creamish F9DFCB
     ui->textEdit->setStyleSheet("QTextEdit {background-color: #FFFFFF}");


     ui->startButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                    "QPushButton {background-color: #FFFFFF;}"
                                    "QPushButton {color: black;}");

     ui->continueButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                       "QPushButton {background-color: #FFFFFF}");

     ui->exitButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                    "QPushButton {background-color: #FFFFFF}");

     ui->registerButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                       "QPushButton {background-color: #FFFFFF}");

     ui->printPlayersButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                           "QPushButton {background-color: #FFFFFF}");

     ;

     passedTournament = T;
     Tournament *T1 = T.get();
     Tournament *T2 = passedTournament.get();

     QString ptrStr = QString("0x%1").arg((quintptr)T1,
                         QT_POINTER_SIZE * 2, 16, QChar('0'));

     QString ptrStr2 = QString("0x%1").arg((quintptr)T2,
                         QT_POINTER_SIZE * 2, 16, QChar('0'));

}

TournamentMenu::TournamentMenu(std::shared_ptr<Tournament> T, QMainWindow *ptrToMainWindow) :
    //Above is a 2nd constructor that passes a reference to the main window for the purposes of resetting the central widget depending on which menu is being used (Tournament, Round, etc.)
    QWidget(),
    ui(new Ui::TournamentMenu)
{
    ui->setupUi(this);
    //ui->textEdit->setText("Welcome to menu.");
    this->setWindowTitle("Tournament Menu");

    //QString meme = QString::fromStdString(this->passedTournament->getTournamentName());
    //this->setWindowTitle(meme);

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    this->ptrToMainWindow = ptrToMainWindow;
    //blue 58CCED
    //creamish F9DFCB
     ui->textEdit->setStyleSheet("QTextEdit {background-color: #FFFFFF}");


     ui->startButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                    "QPushButton {background-color: #FFFFFF;}"
                                    "QPushButton {color: black;}");

     ui->continueButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                       "QPushButton {background-color: #FFFFFF}");

     ui->exitButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                    "QPushButton {background-color: #FFFFFF}");

     ui->registerButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                       "QPushButton {background-color: #FFFFFF}");

     ui->printPlayersButton->setStyleSheet("QPushButton::hover{background-color : #58ED97;}"
                                           "QPushButton {background-color: #FFFFFF}");



     passedTournament = T;
     Tournament *T1 = T.get();
     Tournament *T2 = passedTournament.get();

     QString ptrStr = QString("0x%1").arg((quintptr)T1,
                         QT_POINTER_SIZE * 2, 16, QChar('0'));

     QString ptrStr2 = QString("0x%1").arg((quintptr)T2,
                         QT_POINTER_SIZE * 2, 16, QChar('0'));

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
    int res;
    RoundNameDialog RND(passedTournament);
    RND.setModal(true);
    res = RND.exec();

    if(res == QDialog::Accepted){

        AddToRoundDialog ATRD(passedTournament, passedTournament->getListOfRounds().size()-1);
        ATRD.setModal(true);
        ATRD.exec();

        std::shared_ptr<Round> test = this->passedTournament->getListOfRounds().back();
        //RoundMenu *RM = new RoundMenu(test, this->passedTournament, this->ptrToMainWindow);
        RoundMenu *RM = new RoundMenu(test, this->passedTournament, this->ptrToMainWindow);
        this->ptrToMainWindow->setCentralWidget(RM);
       }
}

void TournamentMenu::on_continueButton_clicked()
{
    SelectRoundDialog SRD(passedTournament, this->ptrToMainWindow);
    SRD.setModal(true);
    bool continueRound = SRD.exec();

    if (continueRound == true){
        int selectedRound = SRD.getSelectedRound();

        //Ask if they'd like to modify round roster with "PromptAddToRound", if user says yes, do the block below, else go straight into making RoundMenu.
        PromptAddToRoundDialog PATRD;
        bool addPlayers = PATRD.exec();
        if(addPlayers == true){
            AddToRoundDialog ATRD(passedTournament, selectedRound);
            ATRD.setModal(true);
            ATRD.exec();
        }

        qDebug() << "Selected Round: " << selectedRound << "\n";
        RoundMenu *RM = new RoundMenu(this->passedTournament->getRound(selectedRound), this->passedTournament, this->ptrToMainWindow);
        this->ptrToMainWindow->setCentralWidget(RM);
    }
    else{

    }

}

void TournamentMenu::on_printPlayersButton_clicked()
{   

    TournamentRoster *TM = new TournamentRoster(passedTournament);
    TM->show();
}

void TournamentMenu::on_exitButton_clicked()
{

    this->passedTournament->serializeTournament();
    MainMenu *MM = new MainMenu(this->ptrToMainWindow);
    this->ptrToMainWindow->setCentralWidget(MM);
    //this->close();

}
