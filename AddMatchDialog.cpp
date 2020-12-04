#include "AddMatchDialog.h"
#include "ui_AddMatchDialog.h"
#include "Match.h"

AddMatchDialog::AddMatchDialog(std::shared_ptr<Round> R, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMatchDialog)
{
    ui->setupUi(this);

    ui->pushButton->setVisible(false);
    this->round = R;

    ui->pushButton->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");

    ui->pushButton_2->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                             "QPushButton {background-color: #FFFFFF}");
}

AddMatchDialog::~AddMatchDialog()
{
    delete ui;
}

void AddMatchDialog::on_lineEdit_textChanged(const QString &arg1)
{
    ui->pushButton->setVisible(true);
}


void AddMatchDialog::on_pushButton_clicked()
{
    std::string name =   (ui->lineEdit->text()).toStdString();
    std::shared_ptr<Match> m = std::make_shared<Match>(name);
    this->round->addMatch(m);
}
