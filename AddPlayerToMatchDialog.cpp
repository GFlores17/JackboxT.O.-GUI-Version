#include "AddPlayerToMatchDialog.h"
#include "ui_AddPlayerToMatchDialog.h"

AddPlayerToMatchDialog::AddPlayerToMatchDialog(std::shared_ptr<Round> r, int x, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPlayerToMatchDialog)
{
    ui->setupUi(this);
    round = r;
    match = r->getListOfMatches().at(x);
    this->setWindowTitle("Add To Round Dialog");

    QString output;

    //std::shared_ptr<Round> r = passedTournament->getListOfRounds().at(x);
    //std::shared_ptr<Match> m = r->getListOfMatches().at(x);
    //ui->label_3
    ui->label_3->setText(QString::fromStdString(match->getName()) + " Menu");
    ui->label_3->setWordWrap(true);
    ui->label_3->setAlignment(Qt::AlignCenter);

    printRoundPlayers();
    printGamePlayers();

    ui->pushButton->setEnabled(false);

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

void AddPlayerToMatchDialog::on_pushButton_clicked()
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
    int x = ui->roundRoster->row(item);
}

void AddPlayerToMatchDialog::on_roundRoster_itemClicked(QListWidgetItem *item)
{
    ui->pushButton->setEnabled(true);
}

void AddPlayerToMatchDialog::on_buttonBox_accepted()
{
    this->close();
}
