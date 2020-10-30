#include "gamewindow.h"
#include "secondwindow.h"
#include "ui_gamewindow.h"

gameWindow::gameWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);
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
    ui->textEdit->setText(output);

}
