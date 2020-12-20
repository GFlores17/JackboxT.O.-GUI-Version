#include "PlayerRegistrationDialog.h"
#include "ui_playerRegistrationDialog.h"
#include "fstream"

PlayerRegistrationDialog::PlayerRegistrationDialog(std::shared_ptr<Tournament>T, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerRegistrationDialog)
{
    ui->setupUi(this);
    tournamentPtr = T;

    this->setWindowTitle("Player Registration Dialog");

}

PlayerRegistrationDialog::~PlayerRegistrationDialog()
{
    delete ui;
}

void PlayerRegistrationDialog::on_lineEdit_returnPressed()
{
    /*
    QString name = ui->lineEdit->text();
    ui->lineEdit->setText("");

    std::shared_ptr<Player> p = std::make_shared<Player>(name.toStdString());
    tournamentPtr->registerPlayer(p);
    */

}

void PlayerRegistrationDialog::on_OKButton_clicked()
{

    QString name = ui->lineEdit->text();
    ui->lineEdit->setText("");
    std::shared_ptr<Player> p = std::make_shared<Player>(name.toStdString());
    tournamentPtr->registerPlayer(p);

}

void PlayerRegistrationDialog::on_CancelButton_clicked()
{
    this->close();
}
