#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "TournamentMenu.h"
#include "EnterTournamentName.h"
#include <memory>
#include <fstream>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QStandardPaths>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
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
    ui->textBrowser->setStyleSheet("QTextBrowser {background-color: #FFFFFF}");

    ui->startTournamentButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->continueTournamentButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                "QPushButton {background-color: #FFFFFF}");

    ui->exitButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                  "QPushButton {background-color: #FFFFFF}");

    ui->textEdit->setStyleSheet("QTextEdit {background-color: #FFFFFF}");


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

MainMenu::MainMenu(QMainWindow *ptrToMainWindow) :
    QWidget(),
    ui(new Ui::MainMenu)
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

    this->ptrToMainWindow = ptrToMainWindow;

    ui->textBrowser->setStyleSheet("QTextBrowser {background-color: #FFFFFF}");

    ui->startTournamentButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->continueTournamentButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                "QPushButton {background-color: #FFFFFF}");

    ui->exitButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                  "QPushButton {background-color: #FFFFFF}");

    ui->textEdit->setStyleSheet("QTextEdit {background-color: #FFFFFF}");



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

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_exitButton_clicked()
{
    delete ui;
    this->close();
}

void MainMenu::on_startTournamentButton_clicked()
{

    EnterTournamentName ETR(this);
    ETR.exec();

    std::string tournamentName = ETR.getTournamentName();
    std::shared_ptr<Tournament> T = std::make_shared<Tournament>(tournamentName);
    //QMainWindow *ptrToWindow = this;
    TournamentMenu *TM = new TournamentMenu(std::move(T), this->ptrToMainWindow);
    //TM->show
    //instead of
    this->ptrToMainWindow->setCentralWidget(TM);
    //this->resize(338,528);


}

void MainMenu::on_continueTournamentButton_clicked()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    qDebug() << "PATH : " << path;
    path = path + "/JBT Saved Tournaments";
    QString folder_name = QFileDialog::getExistingDirectory(this, "Choose", path);

    std::shared_ptr<Tournament> T = std::make_shared<Tournament>();
    T->deserializeTournament(folder_name);

    TournamentMenu *TM = new TournamentMenu(std::move(T), this->ptrToMainWindow);
    this->ptrToMainWindow->setCentralWidget(TM);
}




