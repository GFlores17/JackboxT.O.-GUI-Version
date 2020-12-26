#include "PromptAddToRoundDialog.h"
#include "ui_PromptAddToRoundDialog.h"
#include "Tournament.h"
#include "AddToRoundDialog.h"

PromptAddToRoundDialog::PromptAddToRoundDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PromptAddToRoundDialog)
{
    ui->setupUi(this);

}

PromptAddToRoundDialog::~PromptAddToRoundDialog()
{
    delete ui;
}

void PromptAddToRoundDialog::on_pushButton_clicked()
{
    accept();

}

void PromptAddToRoundDialog::on_pushButton_2_clicked()
{
    reject();
}
