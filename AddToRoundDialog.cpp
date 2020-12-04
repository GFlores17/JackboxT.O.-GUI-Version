#include "AddToRoundDialog.h"
#include "ui_AddToRoundDialog.h"
#include <QtDebug>

AddToRoundDialog::AddToRoundDialog(std::shared_ptr<Tournament> T, int x, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToRoundDialog)
{
    ui->setupUi(this);
    passedTournament = T;

    this->setWindowTitle("Add To Round Dialog");

    QString output;

    std::shared_ptr<Round> r = passedTournament->getListOfRounds().at(x);

    //ui->label_3
    ui->label_3->setText(r->getRoundName() + " Menu");
    ui->label_3->setWordWrap(true);
    ui->label_3->setAlignment(Qt::AlignCenter);

    ui->AddToRoundButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                        "QPushButton {background-color: #FFFFFF}");

    ui->RemoveFromRoundButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    for(int i = 0; i < passedTournament->getNumberOfPlayers(); i++){
        int j = i+1;
        output = QString::number(j) + ". " + passedTournament->getListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->tournamentListWidget->addItem(output);
    }

    if(r->getRoundListOfPlayers().size()>0){
        for(int i = 0; i < r->getRoundListOfPlayers().size(); i++){
            int j = i+1;
            output = QString::number(j) + ". " + r->getRoundListOfPlayers().at(i)->getQName();
            //output = output + "\n";
            ui->roundListWidget->addItem(output);
        }
    }

    ui->AddToRoundButton->setEnabled(false);
}

AddToRoundDialog::~AddToRoundDialog()
{
    delete ui;
}

void AddToRoundDialog::on_AddToRoundButton_clicked()
{

    QListWidgetItem *item = ui->tournamentListWidget->currentItem();
    int x = ui->tournamentListWidget->row(item);


    qDebug() << "meme";

    //Duplicating shared ptr from Tournament List to put in Round List.
    std::shared_ptr<Player> p(passedTournament->getListOfPlayers().at(x));

    //Create a variable pointing directly to round instead of having to do Tournament->getRoundList->getPlayerList->.....
    std::shared_ptr<Round> r(passedTournament->getListOfRounds().back());
    r->addPlayer(p);

    ui->roundListWidget->clear();

    //Print players in Round.
    for(int i = 0; i < r->getRoundListOfPlayers().size(); i++){
        int j = i+1;
        qDebug() << r->getRoundListOfPlayers().at(i)->getQName();
        QString output = QString::number(j) + ". " + r->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->roundListWidget->addItem(output);
    }

}


void AddToRoundDialog::on_tournamentListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int x = ui->tournamentListWidget->row(item);
}

void AddToRoundDialog::on_tournamentListWidget_itemClicked(QListWidgetItem *item)
{
    ui->AddToRoundButton->setEnabled(true);
}

void AddToRoundDialog::on_buttonBox_accepted()
{
    this->close();
}
