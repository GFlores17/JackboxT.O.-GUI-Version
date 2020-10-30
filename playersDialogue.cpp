#include "playersDialogue.h"
#include "ui_playersdialogue.h"

playersDialogue::playersDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playersDialogue)
{
    ui->setupUi(this);
}

playersDialogue::~playersDialogue()
{
    delete ui;
}

void playersDialogue::on_textEdit_textChanged()
{

}

void playersDialogue::on_pushButton_clicked()
{
    listOfPlayers = listOfPlayers + ui->textEdit->toPlainText() + "\n";
    ui->textBrowser->setText(listOfPlayers);
    ui->textEdit->clear();
}

void playersDialogue::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    QString output;
    output = "";
}

void playersDialogue::on_pushButton_pressed()
{
    listOfPlayers = listOfPlayers + ui->textEdit->toPlainText() + "\n";
    ui->textBrowser->setText(listOfPlayers);
    ui->textEdit->clear();
}
