#ifndef TOURNAMENTMENU_H
#define TOURNAMENTMENU_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QMainWindow>
#include <QLabel>

#include "Tournament.h"


namespace Ui {
class TournamentMenu;
}

class TournamentMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TournamentMenu(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    TournamentMenu(std::shared_ptr<Tournament> T, QMainWindow *ptrToMainWindow);

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

    QLabel label;

    QPushButton registerButton;
    QPushButton startButton;
    QPushButton continueButton;
    QPushButton printPlayersButton;
    QPushButton exitButton;

    QMainWindow *ptrToMainWindow;
};

#endif // TOURNAMENTMENU_H
