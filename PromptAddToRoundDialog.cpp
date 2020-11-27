#include "PromptAddToRoundDialog.h"
#include "ui_PromptAddToRoundDialog.h"
#include "tournament.h"
#include "AddToRoundDialog.h"

PromptAddToRoundDialog::PromptAddToRoundDialog(std::shared_ptr<Tournament> T, int x, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PromptAddToRoundDialog)
{
    ui->setupUi(this);
    passedTournament = T;
    num = x;
    int y;
}

PromptAddToRoundDialog::~PromptAddToRoundDialog()
{
    delete ui;
}

void PromptAddToRoundDialog::on_pushButton_clicked()
{
    AddToRoundDialog ATRD(passedTournament, this->num);
    ATRD.setModal(true);
    this->close();
    ATRD.exec();

}

void PromptAddToRoundDialog::on_pushButton_2_clicked()
{
    this->close();
}
