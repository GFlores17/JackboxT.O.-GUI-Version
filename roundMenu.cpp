#include "roundMenu.h"
#include "ui_roundMenu.h"
#include "round.h"

RoundMenu::RoundMenu(std::shared_ptr<Round> R, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoundMenu)
{
    ui->setupUi(this);
    this->round = R;

    for(int i = 0; i < R->getListOfMatches().size(); i++){
        int j = i+1;
        QString output = QString::number(j) + ". " + QString::fromStdString(R->getListOfMatches().at(i)->getName());
        //output = output + "\n";
        ui->listWidget->addItem(output);
    }
}

RoundMenu::~RoundMenu()
{
    delete ui;
}

void RoundMenu::on_addMatchButton_clicked()
{
    //ui->exitButton->setVisible(false);


}

void RoundMenu::on_selectMatchButton_clicked()
{
     //ui->exitButton->setVisible(true);
}

void RoundMenu::on_exitButton_clicked()
{
    this->close();
}



void RoundMenu::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}
