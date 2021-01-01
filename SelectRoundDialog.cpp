#include "SelectRoundDialog.h"
#include "ui_SelectRoundDialog.h"
#include "RoundMenu.h"
#include "AddToRoundDialog.h"
#include "PromptAddToRoundDialog.h"
#include "QMainWindow"
#include "QDebug"

SelectRoundDialog::SelectRoundDialog(std::shared_ptr<Tournament> T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectRoundDialog)
{
    ui->setupUi(this);

    passedTournament = T;
    ui->pushButton->setEnabled(false);

    this->setWindowTitle("Select Round Dialog");

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    ui->PlayersWidget->setStyleSheet("background-color: #FFFFFF;");
    ui->RoundsWidget->setStyleSheet("background-color: #FFFFFF;");

    ui->pushButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->pushButton_2->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

}

SelectRoundDialog::SelectRoundDialog(std::shared_ptr<Tournament> passedTournament, QMainWindow *pointerToMainWindow) :
    QDialog(),
    ui(new Ui::SelectRoundDialog)
{
    ui->setupUi(this);

    this->pointerToMainWindow = pointerToMainWindow;
    this->passedTournament = passedTournament;


    this->setWindowTitle("Select Round Dialog");

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    ui->PlayersWidget->setStyleSheet("background-color: #FFFFFF;");
    ui->RoundsWidget->setStyleSheet("background-color: #FFFFFF;");

    ui->pushButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->pushButton_2->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->pushButton->setEnabled(false);


    printRounds();
}

SelectRoundDialog::~SelectRoundDialog()
{
    delete ui;
}

void SelectRoundDialog::on_pushButton_clicked()
{
    accept();
    this->close();
}

void SelectRoundDialog::on_RoundsWidget_itemClicked(QListWidgetItem *item)
{   //When a round is selected, its players are display in the righthand listWidget.

    ui->pushButton->setEnabled(true);

    item = ui->RoundsWidget->currentItem();
    int x = ui->RoundsWidget->row(item);

    std::shared_ptr<Round>r(passedTournament->getListOfRounds().at(x));
    //r = passedTournament->getListOfRounds().at(x);

    ui->PlayersWidget->clear();

    for(int i = 0; i < r->getListOfMatches().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + QString::fromStdString(r->getListOfMatches().at(i)->getName());
        //output = output + "\n";
        ui->PlayersWidget->addItem(output);
    }
}

void SelectRoundDialog::on_RoundsWidget_itemDoubleClicked(QListWidgetItem *item)
{
    accept();
    this->close();
}

int SelectRoundDialog::getSelectedRound(){
    QListWidgetItem *item = ui->RoundsWidget->currentItem();
    int x = ui->RoundsWidget->row(item);
    return x;
}

void SelectRoundDialog::printRounds(){
    for(int i = 0; i < passedTournament->getListOfRounds().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + passedTournament->getListOfRounds().at(i)->getRoundName();
        //output = output + "\n";
        ui->RoundsWidget->addItem(output);
    }
}

void SelectRoundDialog::printRoundPlayers(int selectedRound){
    std::shared_ptr<Round>r(passedTournament->getListOfRounds().at(selectedRound));
    //r = passedTournament->getListOfRounds().at(x);

    ui->PlayersWidget->clear();

    for(int i = 0; i < r->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + r->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->PlayersWidget->addItem(output);
    }
}
