#include "AddPlayerToMatchDialog.h"
#include "ui_AddPlayerToMatchDialog.h"
#include <QDebug>

AddPlayerToMatchDialog::AddPlayerToMatchDialog(std::shared_ptr<Round> r, int x, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPlayerToMatchDialog)
{
    ui->setupUi(this);
    round = r;
    match = r->getListOfMatches().at(x);
    this->setWindowTitle("Add To Match Dialog");

    QString output;

    //std::shared_ptr<Round> r = passedTournament->getListOfRounds().at(x);
    //std::shared_ptr<Match> m = r->getListOfMatches().at(x);
    //ui->label_3
    ui->label_3->setText(QString::fromStdString(match->getName()) + " Menu");
    ui->label_3->setWordWrap(true);
    ui->label_3->setAlignment(Qt::AlignCenter);

    printRoundPlayers();
    printGamePlayers();

    ui->AddToMatchButton->setEnabled(false);
    ui->RemoveButton->setEnabled(false);

    this->setStyleSheet("background-color: #58CCED;");
    ui->roundRoster->setStyleSheet("background-color: #FFFFFF;");
    ui->matchRoster->setStyleSheet("background-color: #FFFFFF;");

    ui->AddToMatchButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                        "QPushButton{background-color: #FFFFFF;}");

    ui->RemoveButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: #FFFFFF;}");

    ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

}

AddPlayerToMatchDialog::~AddPlayerToMatchDialog()
{
    delete ui;
}

void AddPlayerToMatchDialog::printRoundPlayers(){
    QString output;

    for(int i = 0; i < this->round->getNumberOfPlayers(); i++){
        int j = i+1;
        output = QString::number(j) + ". " + round->getRoundListOfPlayers().at(i)->getQName();
        //output = output + "\n";
        ui->roundRoster->addItem(output);
    }
}

void AddPlayerToMatchDialog::printGamePlayers(){
    QString output;

    if(match->getMatchListOfPlayers().size() > 0){
        for(int i = 0; i < match->getNumOfPlayers(); i++){
            int j = i+1;
            output = QString::number(j) + ". " + match->getMatchListOfPlayers().at(i)->getQName();
            //output = output + "\n";
            ui->matchRoster->addItem(output);
        }
    }

}

void AddPlayerToMatchDialog::on_AddToMatchButton_clicked()
{

    QListWidgetItem *item = ui->roundRoster->currentItem();
    int x = ui->roundRoster->row(item);


    //qDebug() << "meme";

    //Duplicating shared ptr from Tournament List to put in Round List.
    std::shared_ptr<Player> p(round->getRoundListOfPlayers().at(x));

    //Create a variable pointing directly to round instead of having to do Tournament->getRoundList->getPlayerList->.....
    std::shared_ptr<Match> m(round->getListOfMatches().back());
    match->addPlayer(p);

    ui->matchRoster->clear();

    //Print players in Round.
    printGamePlayers();

}

void AddPlayerToMatchDialog::on_roundRoster_itemDoubleClicked(QListWidgetItem *item)
{
    item = ui->roundRoster->currentItem();
    int x = ui->roundRoster->row(item);


    //qDebug() << "meme";

    //Duplicating shared ptr from Tournament List to put in Round List.
    std::shared_ptr<Player> p(round->getRoundListOfPlayers().at(x));

    //Create a variable pointing directly to round instead of having to do Tournament->getRoundList->getPlayerList->.....
    std::shared_ptr<Match> m(round->getListOfMatches().back());
    match->addPlayer(p);

    ui->matchRoster->clear();

    //Print players in Round.
    printGamePlayers();
}

void AddPlayerToMatchDialog::on_roundRoster_itemClicked(QListWidgetItem *item)
{
    ui->AddToMatchButton->setEnabled(true);
}

void AddPlayerToMatchDialog::on_buttonBox_accepted()
{
    this->close();
}

void AddPlayerToMatchDialog::on_RemoveButton_clicked()
{
    //ui->matchRoster->clear();

    QListWidgetItem *item = ui->matchRoster->currentItem();
    int x = ui->matchRoster->row(item);

    match->deletePlayer(x);

    ui->matchRoster->clear();
    qDebug() << "CLEARED\n";


    //Print players in match.
    printGamePlayers();

    ui->RemoveButton->setEnabled(false);
}

void AddPlayerToMatchDialog::on_matchRoster_itemClicked(QListWidgetItem *item)
{
     ui->RemoveButton->setEnabled(true);
}

void AddPlayerToMatchDialog::on_matchRoster_itemDoubleClicked(QListWidgetItem *item)
{
    //ui->matchRoster->clear();

    item = ui->matchRoster->currentItem();
    int x = ui->matchRoster->row(item);

    match->deletePlayer(x);

    ui->matchRoster->clear();
    qDebug() << "CLEARED\n";


    //Print players in match.
    printGamePlayers();

    ui->RemoveButton->setEnabled(false);
}

void AddPlayerToMatchDialog::on_AddAllPlayersButton_clicked()
{
    for(int i = 0; i < round->getRoundListOfPlayers().size(); i++){
        std::shared_ptr<Player>p = round->getRoundListOfPlayers().at(i);
        match->addPlayer(p);
    }

    printGamePlayers();
}
