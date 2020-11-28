#include "PlayerRegistrationDialog.h"
#include "ui_playerRegistrationDialog.h"

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
    QString name = ui->lineEdit->text();
    ui->lineEdit->setText("");
    tournamentPtr->registerPlayer(name);
}
