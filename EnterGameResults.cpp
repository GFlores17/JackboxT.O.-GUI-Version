#include "EnterGameResults.h"
#include "ui_EnterGameResults.h"

EnterGameResults::EnterGameResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterGameResults)
{
    ui->setupUi(this);
}

EnterGameResults::~EnterGameResults()
{
    delete ui;
}

void EnterGameResults::on_lineEdit_returnPressed()
{

}
