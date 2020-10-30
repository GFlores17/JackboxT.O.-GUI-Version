#include "secondwindow.h"
#include "mainwindow.h"
#include "ui_secondwindow.h"
#include "gamewindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-color: grey");
    //ui->returnButton->setStyleSheet("QPushButton {background-color: #FFFFFF}");
    this->setWindowTitle("YOU DID IT!");
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_returnButton_clicked()
{
    //this->hide();
    MainWindow *main = new MainWindow();
    main->show();
}

void SecondWindow::on_returnButton2_clicked()
{

    gameWindow *gW = new gameWindow();
    //this->hide();
    gW->show();
    //gameWindow pDialogue;
   // pDialogue.setModal(true);
    //pDialogue.exec();
}
