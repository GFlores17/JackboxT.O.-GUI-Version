#ifndef TOURNAMENTMENU_H
#define TOURNAMENTMENU_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include "tournament.h"


namespace Ui {
class TournamentMenu;
}

class TournamentMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TournamentMenu(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    //TournamentMenu(QWidget *parent = nullptr, Tournament T);
    ~TournamentMenu();

    std::shared_ptr<Tournament> passedTournament;

private slots:
    void on_registerButton_clicked();

    void on_startButton_clicked();

    void on_continueButton_clicked();

    void on_printPlayersButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::TournamentMenu *ui;
    QTextEdit textEdit;
    QTextEdit textEdit_2;
    //QLineEdit lineEdit;
    QLineEdit lineEdit_2;
    QPushButton registerButton;
    QPushButton startButton;
    QPushButton continueButton;
    QPushButton printPlayersButton;
    QPushButton exitButton;
    QListWidget listWidget;
};

#endif // TOURNAMENTMENU_H
