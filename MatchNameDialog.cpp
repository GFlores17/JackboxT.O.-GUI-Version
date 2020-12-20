#include "MatchNameDialog.h"
#include "ui_MatchNameDialog.h"
#include "Round.h"

MatchNameDialog::MatchNameDialog(std::shared_ptr<Round> r, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatchNameDialog)
{
    ui->setupUi(this);
    this->round = r;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    ui->buttonBox->button(QDialogButtonBox::Cancel)->setStyleSheet("QPushButton::hover{background-color : lightgreen;}"
                                                               "QPushButton {background-color: #FFFFFF}");

    this->setStyleSheet("color: black;"
                            "background-color: #58CCED;"
                            "selection-color: white;"
                            "selection-background-color: blue;");

    ui->lineEdit->setStyleSheet("QLineEdit{background-color:#FFFFFF}");
}

MatchNameDialog::~MatchNameDialog()
{
    delete ui;
}

void MatchNameDialog::on_buttonBox_accepted()
{
    std::shared_ptr<Match> m = std::make_shared<Match>(ui->lineEdit->text());
    this->round->addMatch(m);
}
