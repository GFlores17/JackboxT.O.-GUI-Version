#include "addToRoundForm.h"
#include "ui_addToRoundForm.h"
#include "tournament.h"

addToRoundForm::addToRoundForm(std::shared_ptr<Tournament> T, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addToMatchForm)
{
    ui->setupUi(this);
    passedTournament = T;
}

addToRoundForm::~addToRoundForm()
{
    delete ui;
}
