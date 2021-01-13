#include "EditPlayerDialog.h"
#include "ui_EditPlayerDialog.h"

EditPlayerDialog::EditPlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPlayerDialog)
{
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

}

EditPlayerDialog::~EditPlayerDialog()
{
    delete ui;
}

std::string EditPlayerDialog::getName(){
    return ui->lineEdit->text().toStdString();
}
