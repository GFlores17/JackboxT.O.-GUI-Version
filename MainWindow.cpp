#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "playersDialogue.h"
#include "secondwindow.h"
#include "TournamentMenu.h"
#include "gamewindow.h"
#include <memory>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("color: black;"
                            "background-color: #33FFE3;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    ui->textBrowser->setStyleSheet("QTextBrowser {background-color: #FFFFFF}");

    ui->startTournamentButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->continueTournamentButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                "QPushButton {background-color: #FFFFFF}");

    ui->exitButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                  "QPushButton {background-color: #FFFFFF}");



    //ui->continueTournamentButton->setEnabled(true);

    this->setWindowTitle("Jackbox Tournament Manager");
    this->setMinimumWidth(100);
    this->setMinimumHeight(50);

    QMediaPlayer *player = new QMediaPlayer;
    this->player = player;

    // ...
    //player->setMedia(QUrl::fromLocalFile("C:\\TestDirectory"));
    player->setVolume(100);
    player->play();

}

MainWindow::~MainWindow()
{      
    delete ui;
}



void MainWindow::on_exitButton_clicked()
{
    delete ui;
    this->close();
}

void MainWindow::on_startTournamentButton_clicked()
{

    formatPlayersInTournamentFile();
    std::shared_ptr<Tournament> T = std::make_shared<Tournament>();
    TournamentMenu *TM = new TournamentMenu(std::move(T));
    TM->show();
}

void MainWindow::on_continueTournamentButton_clicked()
{
    std::shared_ptr<Tournament> T = std::make_shared<Tournament>();
    //formatPlayersInTournamentFile();
    T->deserializePlayers();
    T->deserializeTournament();



    TournamentMenu *TM = new TournamentMenu(std::move(T));
    TM->show();
}

void MainWindow::formatPlayersInTournamentFile(){
    std::ofstream OUTFILE;
    OUTFILE.open("C:\\Users\\George\\Desktop\\people.txt");
    //OUTFILE << "LIST OF PLAYERS IN TOURNAMENT" << "\n";
    OUTFILE.close();

}
