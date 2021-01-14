#include "AddPlayerToGameDialog.h"
#include "ui_AddPlayerToGameDialog.h"

AddPlayerToGameDialog::AddPlayerToGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPlayerToGameDialog)
{
    ui->setupUi(this);
}

AddPlayerToGameDialog::~AddPlayerToGameDialog()
{
    delete ui;
}

std::string AddPlayerToGameDialog::getPlayerName() const{
    return ui->lineEdit->text().toStdString();
}
