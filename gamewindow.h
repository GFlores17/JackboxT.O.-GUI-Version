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
#include <QListWidget>
#include <QLabel>
#include <vector>
#include <memory.h>
#include "Player.h"
#include "Game.h"

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

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_addToGameButton_clicked();

private:
    Ui::gameWindow *ui;
    std::vector<std::shared_ptr<Player>> vec;
    std::vector<std::shared_ptr<Player>> testTourneyVec;


    QLineEdit lineEdit;
    QLineEdit lineEdit_2;
    QTextEdit textEdit;
    QPushButton buttonBox;
    QPushButton pushButton;
    QListWidget listWidget;
    //QLabel label;

};

#endif // GAMEWINDOW_H
