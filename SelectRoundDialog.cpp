#include "SelectRoundDialog.h"
#include "ui_SelectRoundDialog.h"
#include "roundMenu.h"
#include "addToRoundForm.h"
#include "AddToRoundDialog.h"
#include "PromptAddToRoundDialog.h"

SelectRoundDialog::SelectRoundDialog(std::shared_ptr<Tournament> T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectRoundDialog)
{
    ui->setupUi(this);

    passedTournament = T;

    ui->pushButton->setEnabled(false);

    this->setWindowTitle("Select Round Dialog");

    for(int i = 0; i < passedTournament->getListOfRounds().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + passedTournament->getListOfRounds().at(i)->getRoundName();
        //output = output + "\n";
        ui->listWidget->addItem(output);
    }
}

SelectRoundDialog::~SelectRoundDialog()
{
    delete ui;
}

void SelectRoundDialog::on_pushButton_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    PromptAddToRoundDialog PATRD(this->passedTournament, x);
    PATRD.setModal(true);
    this->close();
    PATRD.exec();

    RoundMenu *RM = new RoundMenu(this->passedTournament->getRound(x));
    RM->show();

    this->close();
}

void SelectRoundDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->pushButton->setEnabled(true);

    item = ui->listWidget->currentItem();
    int x = ui->listWidget->row(item);

    std::shared_ptr<Round>r(passedTournament->getListOfRounds().at(x));
    //r = passedTournament->getListOfRounds().at(x);

    ui->listWidget_2->clear();

    for(int i = 0; i < r->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + r->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->listWidget_2->addItem(output);
    }

}
