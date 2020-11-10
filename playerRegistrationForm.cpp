#include "playerRegistrationForm.h"
#include "ui_playerRegistrationForm.h"
#include "tournament.h"

PlayerRegistrationForm::PlayerRegistrationForm(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerRegistrationForm)
{
    ui->setupUi(this);

    passedTournament = T;
}

PlayerRegistrationForm::~PlayerRegistrationForm()
{
    delete ui;
}

void PlayerRegistrationForm::on_lineEdit_returnPressed()
{

    QString name = ui->lineEdit->text();
    ui->lineEdit->setText("");
    passedTournament->registerPlayer(name);
}
