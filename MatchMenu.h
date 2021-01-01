#ifndef MATCHMENU_H
#define MATCHMENU_H

#include <QWidget>
#include <QLabel>
#include "QListWidget"
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
    void on_pushButton_3_clicked();

    void on_FinishGameButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_ExitButton_clicked();

    void on_DeleteGameButton_clicked();

private:
    Ui::MatchMenu *ui;
    QLabel label_2;
    enum GameResultsColumns{
        NAME, SCORE
    };
};

#endif // MATCHMENU_H
