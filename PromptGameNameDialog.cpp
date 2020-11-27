#include "PromptGameNameDialog.h"
#include "ui_PromptGameNameDialog.h"
#include "match.h"

PromptGameNameDialog::PromptGameNameDialog(std::shared_ptr<Match> m, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PromptGameNameDialog)
{
    this->match = m;
    ui->setupUi(this);

}

PromptGameNameDialog::~PromptGameNameDialog()
{
    delete ui;
}

void PromptGameNameDialog::on_buttonBox_accepted()
{

}
