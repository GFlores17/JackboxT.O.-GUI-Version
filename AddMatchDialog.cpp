#include "AddMatchDialog.h"
#include "ui_AddMatchDialog.h"
#include "Match.h"

AddMatchDialog::AddMatchDialog(std::shared_ptr<Round> R, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMatchDialog)
{
    ui->setupUi(this);

    ui->okButton->setVisible(false);
    this->round = R;

    ui->okButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->cancelButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");
}

AddMatchDialog::~AddMatchDialog()
{
    delete ui;
}

void AddMatchDialog::on_lineEdit_textChanged(const QString &arg1)
{
    ui->okButton->setVisible(true);
}


void AddMatchDialog::on_okButton_clicked()
{
    std::string name =   (ui->lineEdit->text()).toStdString();
    std::shared_ptr<Match> m = std::make_shared<Match>(name);
    this->round->addMatch(m);
}
