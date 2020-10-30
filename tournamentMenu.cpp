#include "tournamentMenu.h"
#include "ui_tournamentMenu.h"

TournamentMenu::TournamentMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TournamentMenu)
{
    ui->setupUi(this);
    ui->textEdit->setText("Welcome to menu.");
    this->setWindowTitle("Tournament Menu");

    this->setStyleSheet("color: black;"
                            "background-color: yellow;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

     ui->lineEdit->setStyleSheet("QLineEdit {background-color: #FFFFFF}");
     ui->textEdit->setStyleSheet("QTextEdit {background-color: #FFFFFF}");

}

TournamentMenu::~TournamentMenu()
{
    delete ui;
}
