#include "MainWindow.h"
#include "ui_mainwindow.h"
\
#include "TournamentMenu.h"

#include "EnterTournamentName.h"

#include "MainMenu.h"
#include <QVBoxLayout>
#include <memory>
#include <fstream>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QStandardPaths>
#include <QCloseEvent>
#include <QMessageBox>


#include "RoundMenu.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    //white FFFFFF
    //creamish F9DFCB
    //light blue CBEFF9
    //medium blue 58CCED

    pointerToMainWindow = this;

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

    MainMenu *MM = new MainMenu(this->pointerToMainWindow);
    this->setCentralWidget(MM);

    //setStyleSheet("QMessageBox{background: rgb(255,0,0);  border: none;font-family: Arial; font-style: normal;  font-size: 15pt; color: #000000 ; }");

}

MainWindow::MainWindow(QMainWindow *pointerToMainWindow){

    this->pointerToMainWindow = pointerToMainWindow;
    MainMenu *MM = new MainMenu(this->pointerToMainWindow);
    this->setCentralWidget(MM);

    //setStyleSheet("QMessageBox{background: rgb(255,0,0);  border: none;font-family: Arial; font-style: normal;  font-size: 15pt; color: #000000 ; }");


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_exitButton_clicked()
{
    //delete ui;
    //this->close();
}

void MainWindow::on_startTournamentButton_clicked()
{

    EnterTournamentName ETR(this);
    ETR.exec();

    std::string tournamentName = ETR.getTournamentName();
    formatPlayersInTournamentFile();
    std::shared_ptr<Tournament> T = std::make_shared<Tournament>(tournamentName);
    QMainWindow *ptrToWindow = this;
    TournamentMenu *TM = new TournamentMenu(std::move(T), ptrToWindow);
    //TM->show()
    //instead of the above ^^^
    setCentralWidget(TM);
    //This makes it so that instead of popping up an entirely new window, we just update the main window by changing the central widget contents.
    //(For every menu I want to do this with, it requires me adding a QMainWindow *PointerToMainWindow so I have a way to reference the main window and change the central widget.
    //this->resize(338,528);


}

void MainWindow::on_continueTournamentButton_clicked()
{
    std::shared_ptr<Tournament> T = std::make_shared<Tournament>();

    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    path = path + "/JBT Saved Tournaments";
    QString folder_name = QFileDialog::getExistingDirectory(this, "Choose a tournament to load.", path);

    T->deserializeTournamentName(folder_name);
    T->deserializeTournamentPlayers(folder_name);
    T->deserializeAllRounds(folder_name);

    TournamentMenu *TM = new TournamentMenu(std::move(T));
    TM->show();
}

void MainWindow::formatPlayersInTournamentFile(){
    std::ofstream OUTFILE;
    OUTFILE.open("C:\\Users\\George\\Desktop\\people.txt");
    //OUTFILE << "LIST OF PLAYERS IN TOURNAMENT" << "\n";
    OUTFILE.close();

}

QWidget* MainWindow::getCenterWidget(){
    return this->centerWidget;
}

void MainWindow::closeEvent(QCloseEvent *event)  // show prompt when user wants to close app
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Exit?\nUNSAVED CHANGES WILL BE LOST", QMessageBox::Yes | QMessageBox::No))
    {
        event->accept();
    }


}
