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

    ui->menuLabel->setText(QString::fromStdString(match->getName()) + " Menu");
    ui->menuLabel->setWordWrap(true);
    ui->menuLabel->setAlignment(Qt::AlignCenter);

    printRoundPlayers();
    printMatchPlayers();

    //removeFromMatchButton
    ui->addToMatchButton->setEnabled(false);
    ui->removeFromMatchButton->setEnabled(false);

    ui->addAllPlayersButton->setEnabled(true);
    ui->removeAllPlayersButton->setEnabled(true);

    this->setStyleSheet("background-color: #58CCED;");
    ui->roundRosterListWidget->setStyleSheet("background-color: #FFFFFF;");
    ui->matchRosterListWidget->setStyleSheet("background-color: #FFFFFF;");

    ui->addToMatchButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                        "QPushButton{background-color: #FFFFFF;}");

    ui->removeFromMatchButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                    "QPushButton{background-color: #FFFFFF;}");

    ui->addAllPlayersButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                        "QPushButton{background-color: #FFFFFF;}");

    ui->removeAllPlayersButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
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
        ui->roundRosterListWidget->addItem(output);
    }
}

void AddPlayerToMatchDialog::printMatchPlayers(){
    QString output;

    ui->matchRosterListWidget->clear();

    if(match->getMatchListOfPlayers().size() > 0){
        for(int i = 0; i < match->getNumOfPlayers(); i++){
            int j = i+1;
            output = QString::number(j) + ". " + match->getMatchListOfPlayers().at(i)->getQName();
            //output = output + "\n";
            ui->matchRosterListWidget->addItem(output);
        }
    }

}

void AddPlayerToMatchDialog::on_addToMatchButton_clicked()
{

    QListWidgetItem *item = ui->roundRosterListWidget->currentItem();
    int x = ui->roundRosterListWidget->row(item);

    //Duplicating shared ptr from Tournament List to put in Round List.
    std::shared_ptr<Player> p(round->getRoundListOfPlayers().at(x));

    //Create a variable pointing directly to round instead of having to do Tournament->getRoundList->getPlayerList->.....
    std::shared_ptr<Match> m(round->getListOfMatches().back());
    match->addPlayer(p);

    ui->matchRosterListWidget->clear();

    //Print players in Match.
    printMatchPlayers();

}

void AddPlayerToMatchDialog::on_roundRosterListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    item = ui->roundRosterListWidget->currentItem();
    int x = ui->roundRosterListWidget->row(item);

    //Duplicating shared ptr from Tournament List to put in Round List.
    std::shared_ptr<Player> p(round->getRoundListOfPlayers().at(x));

    //Create a variable pointing directly to round instead of having to do Tournament->getRoundList->getPlayerList->.....
    std::shared_ptr<Match> m(round->getListOfMatches().back());
    match->addPlayer(p);

    ui->matchRosterListWidget->clear();

    //Print players in Round.
    printMatchPlayers();
}

void AddPlayerToMatchDialog::on_roundRosterListWidget_itemClicked(QListWidgetItem *item)
{
    ui->addToMatchButton->setEnabled(true);
}

void AddPlayerToMatchDialog::on_buttonBox_accepted()
{
    this->close();
}

void AddPlayerToMatchDialog::on_removeFromMatchButton_clicked()
{
    //ui->matchRosterListWidget->clear();

    QListWidgetItem *item = ui->matchRosterListWidget->currentItem();
    int x = ui->matchRosterListWidget->row(item);

    match->deletePlayer(x);

    ui->matchRosterListWidget->clear();
    qDebug() << "CLEARED\n";


    //Print players in match.
    printMatchPlayers();

    ui->removeFromMatchButton->setEnabled(false);
}

void AddPlayerToMatchDialog::on_matchRosterListWidget_itemClicked(QListWidgetItem *item)
{
     ui->removeFromMatchButton->setEnabled(true);
}

void AddPlayerToMatchDialog::on_matchRosterListWidget_itemDoubleClicked(QListWidgetItem *item)
{

    item = ui->matchRosterListWidget->currentItem();
    int indexToDelete = ui->matchRosterListWidget->row(item);

    match->deletePlayer(indexToDelete);

    ui->matchRosterListWidget->clear();

    printMatchPlayers();
    //Updates players in match roster.

    ui->removeFromMatchButton->setEnabled(false);
    //Prevent out_of_range errors.
}

void AddPlayerToMatchDialog::on_addAllPlayersButton_clicked()
{
    for(int i = 0; i < round->getRoundListOfPlayers().size(); i++){
        std::shared_ptr<Player>p = round->getRoundListOfPlayers().at(i);
        match->addPlayer(p);
    }
    printMatchPlayers();
}

void AddPlayerToMatchDialog::on_removeAllPlayersButton_clicked()
{
    match->deleteAllPlayers();
    printMatchPlayers();
}
