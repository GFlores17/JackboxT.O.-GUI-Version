#include "PromptGameNameDialog.h"
#include "ui_PromptGameNameDialog.h"
#include "Match.h"

PromptGameNameDialog::PromptGameNameDialog(std::shared_ptr<Match> m, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PromptGameNameDialog)
{
    this->match = m;
    ui->setupUi(this);

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

}

PromptGameNameDialog::~PromptGameNameDialog()
{
    delete ui;
}

void PromptGameNameDialog::on_buttonBox_accepted()
{

}
