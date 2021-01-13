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
    ui->okButton->setEnabled(false);

    this->setWindowTitle("Select Round Dialog");

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    ui->playersListWidget->setStyleSheet("background-color: #FFFFFF;");
    ui->roundsListWidget->setStyleSheet("background-color: #FFFFFF;");

    ui->okButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->cancelButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
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

    ui->playersListWidget->setStyleSheet("background-color: #FFFFFF;");
    ui->roundsListWidget->setStyleSheet("background-color: #FFFFFF;");

    ui->okButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->cancelButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->okButton->setEnabled(false);


    printRounds();
}

SelectRoundDialog::~SelectRoundDialog()
{
    delete ui;
}

void SelectRoundDialog::on_okButton_clicked()
{
    accept();
    this->close();
}

void SelectRoundDialog::on_roundsListWidget_itemClicked(QListWidgetItem *item)
{   //When a round is selected, its players are display in the righthand listWidget.

    ui->okButton->setEnabled(true);

    item = ui->roundsListWidget->currentItem();
    int x = ui->roundsListWidget->row(item);

    std::shared_ptr<Round>r(passedTournament->getListOfRounds().at(x));
    //r = passedTournament->getListOfRounds().at(x);

    ui->playersListWidget->clear();

    for(int i = 0; i < r->getListOfMatches().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + QString::fromStdString(r->getListOfMatches().at(i)->getName());
        //output = output + "\n";
        ui->playersListWidget->addItem(output);
    }
}

void SelectRoundDialog::on_roundsListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    accept();
    this->close();
}

int SelectRoundDialog::getSelectedRound(){
    QListWidgetItem *item = ui->roundsListWidget->currentItem();
    int x = ui->roundsListWidget->row(item);
    return x;
}

void SelectRoundDialog::printRounds(){
    for(int i = 0; i < passedTournament->getListOfRounds().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + passedTournament->getListOfRounds().at(i)->getRoundName();
        //output = output + "\n";
        ui->roundsListWidget->addItem(output);
    }
}

void SelectRoundDialog::printRoundPlayers(int selectedRound){
    std::shared_ptr<Round>r(passedTournament->getListOfRounds().at(selectedRound));
    //r = passedTournament->getListOfRounds().at(x);

    ui->playersListWidget->clear();

    for(int i = 0; i < r->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + r->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->playersListWidget->addItem(output);
    }
}
