#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include <QDialog>
#include <QTextEdit>
#include <QButtonGroup>
#include <QTextBrowser>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <vector>
#include <memory.h>
#include "player.h"

namespace Ui {
class gameWindow;
}

class gameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = nullptr);
    ~gameWindow();

private slots:
    void on_buttonBox_accepted();



    void on_pushButton_clicked();

private:
    Ui::gameWindow *ui;
    std::vector<std::shared_ptr<Player>> vec;


    QLineEdit lineEdit;
    QLineEdit lineEdit_2;
    QTextEdit textEdit;
    QPushButton buttonBox;
    QPushButton pushButton;

};

#endif // GAMEWINDOW_H
