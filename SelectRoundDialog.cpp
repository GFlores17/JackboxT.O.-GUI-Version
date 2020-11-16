#include "SelectRoundDialog.h"
#include "ui_SelectRoundDialog.h"

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
