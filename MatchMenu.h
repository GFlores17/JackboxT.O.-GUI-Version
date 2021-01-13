#ifndef MATCHMENU_H
#define MATCHMENU_H

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>

#include "Round.h"
#include "Match.h"

namespace Ui {
class MatchMenu;
}

class MatchMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MatchMenu(std::shared_ptr<Match> m, QWidget *parent = nullptr);
    ~MatchMenu();

    std::shared_ptr<Match> match;
    void printGames();

    void printPlayersAndScores();
    void initializeScoresTable(std::shared_ptr<Game> g);

    void printMatchStandings();
private slots:
    void on_addGameButton_clicked();

    void on_finishGameButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_exitButton_clicked();

    void on_deleteGameButton_clicked();

private:
    Ui::MatchMenu *ui;

    QPushButton addGameButton;
    QPushButton finishGameButton;
    QPushButton deleteGameButton;
    QPushButton exitButton;

    QLabel listOfGamesLabel;
    QLabel gameResultsLabel;

    enum GameResultsColumns{
        NAME, SCORE
    };
};

#endif // MATCHMENU_H
