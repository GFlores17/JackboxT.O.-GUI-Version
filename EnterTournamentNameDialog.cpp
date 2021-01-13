#include "EnterTournamentNameDialog.h"
#include "ui_EnterTournamentName.h"
#include "QPushButton"

EnterTournamentName::EnterTournamentName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterTournamentName)
{
    ui->setupUi(this);

    this->setStyleSheet("color: black;"
                            "background-color: #F9DFCB;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    ui->lineEdit->setStyleSheet("background-color: white;");



    ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");
}

EnterTournamentName::~EnterTournamentName()
{
    delete ui;
}

std::string EnterTournamentName::getTournamentName(){
    return (ui->lineEdit->text()).toStdString();
}

void EnterTournamentName::on_buttonBox_accepted()
{
    //this->getTournamentName();
    close();
}
