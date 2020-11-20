#include "SelectRoundDialog.h"
#include "ui_SelectRoundDialog.h"
#include "roundMenu.h"

SelectRoundDialog::SelectRoundDialog(std::shared_ptr<Tournament> T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectRoundDialog)
{
    ui->setupUi(this);

    passedTournament = T;

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

    RoundMenu *RM = new RoundMenu(passedTournament->getRound(x));
    RM->show();

    this->close();
}

void SelectRoundDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
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
