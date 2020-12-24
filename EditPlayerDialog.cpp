#include "EditPlayerDialog.h"
#include "ui_EditPlayerDialog.h"

EditPlayerDialog::EditPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPlayerDialog)
{
    ui->setupUi(this);
}

EditPlayerDialog::~EditPlayerDialog()
{
    delete ui;
}

std::string EditPlayerDialog::getName(){
    return ui->lineEdit->text().toStdString();
}
