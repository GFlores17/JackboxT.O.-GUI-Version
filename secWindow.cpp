#include "secWindow.h"

secWindow::secWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secWindow)
{
    ui->setupUi(this);
}

secWindow::~secWindow()
{
    delete ui;
}
