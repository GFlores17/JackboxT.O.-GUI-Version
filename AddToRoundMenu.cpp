#include "addToRoundMenu.h"
#include "ui_AddToRoundMenu.h"

AddToRoundMenu::AddToRoundMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddToRoundMenu)
{
    ui->setupUi(this);
}

AddToRoundMenu::~AddToRoundMenu()
{
    delete ui;
}
