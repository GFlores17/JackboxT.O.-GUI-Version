#include "gamewindow.h"
#include "secondwindow.h"
#include "ui_gamewindow.h"

gameWindow::gameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);

    //STYLING BETWEEN

    //ui->label->setStyleSheet("QLabel { background-color : red; color : blue; }");




    //STYLING BETWEEN


    std::shared_ptr<Player> p = std::make_shared<Player>("p");
    std::shared_ptr<Player> q = std::make_shared<Player>("q");
    std::shared_ptr<Player> r = std::make_shared<Player>("r");
    std::shared_ptr<Player> s = std::make_shared<Player>("s");
    testTourneyVec.push_back(p);
    testTourneyVec.push_back(q);
    testTourneyVec.push_back(r);
    testTourneyVec.push_back(s);

    QString output;
    for(int i = 0; i < testTourneyVec.size(); i++){
        int j = i+1;
        output = QString::number(j) + ". " + testTourneyVec.at(i)->getQName();
        //output = output + "\n";
        ui->listWidget->addItem(output);

    }
    //ui->textEdit->setText("Players In Tournament: \n" + output);
}

gameWindow::~gameWindow()
{
    delete ui;
}

void gameWindow::on_buttonBox_accepted(){
    this->hide();
}

void gameWindow::on_pushButton_clicked()
{
    //Takes vector of all players and displays them into the 2nd lineEdit window.

    std::shared_ptr<Player> p = std::make_shared<Player>();
    QString qs;
    ui->lineEdit->text();
    qs = ui->lineEdit->text();
    //ui->lineEdit_2->setText(qs);

    std::string name;
    name = qs.toStdString();
    p->setName(name);
    ui->lineEdit->setText("Name set.");
    vec.push_back(p);

    QString output;
    for(int i = 0; i < vec.size(); i++){
        int j = i+1;
        output = output + QString::number(j) + ". " + vec.at(i)->getQName();
        output = output + "\n";
    }
    //ui->textEdit->setText(output);

}

void gameWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
     QString output;

}

void gameWindow::on_addToGameButton_clicked()
{
    std::shared_ptr<Player> p = std::make_shared<Player>();
    //p = ui->listWidget->currentItem();
}
