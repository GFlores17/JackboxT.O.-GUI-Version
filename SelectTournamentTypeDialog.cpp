#include "SelectTournamentTypeDialog.h"
#include "ui_SelectTournamentTypeDialog.h"

SelectTournamentTypeDialog::SelectTournamentTypeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectTournamentTypeDialog)
{
    ui->setupUi(this);
}

SelectTournamentTypeDialog::~SelectTournamentTypeDialog()
{
    delete ui;
}
