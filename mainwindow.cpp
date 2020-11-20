#include "mainWindow.h"
#include "ui_mainwindow.h"
#include "playersDialogue.h"
#include "secondwindow.h"
#include "tournamentMenu.h"
#include "gamewindow.h"
#include <memory>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("color: black;"
                            "background-color: #33FFE3;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    ui->textBrowser->setText("This is a small scorekeeping software "
                          "program written in C++"
                          "that allows the user to organize "
                          "tournament play using 3 functions.");

    ui->textBrowser->setStyleSheet("QTextBrowser {background-color: #FFFFFF}");
    ui->pushButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");
    ui->newWindowButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");
    ui->startTournamentButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");
    ui->exitButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");

    this->setWindowTitle("Jackbox Tournament Manager");
    this->setMinimumWidth(100);
    this->setMinimumHeight(50);
    //this->setWindowIcon()

    QMediaPlayer *player = new QMediaPlayer;
    this->player = player;

    // ...
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\George\\Documents\\JackboxTournament\\Kronicle-Chill Noons.mp3"));
    player->setVolume(100);
    player->play();

}

MainWindow::~MainWindow()
{      
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->setText("MAIN MENU");
}

void MainWindow::on_newWindowButton_clicked()
{
    this->player->stop();
    //this->hide();
    ui->textBrowser->setText("NEW WINDOW BUTTON CLICKED");
}


void MainWindow::on_exitButton_clicked()
{
    delete ui;
    this->close();
}

void MainWindow::on_startTournamentButton_clicked()
{
    //this->hide();
    std::shared_ptr<Tournament> T = std::make_shared<Tournament>();
    TournamentMenu *TM = new TournamentMenu(std::move(T));
    TM->show();
}
