#ifndef TOURNAMENTROSTER_H
#define TOURNAMENTROSTER_H

#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QTableWidget>
#include "Tournament.h"

namespace Ui {
class TournamentRoster;
}

class TournamentRoster : public QWidget
{
    Q_OBJECT

public:
    explicit TournamentRoster(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~TournamentRoster();

    void printPlayers();
    void printPlayersAndScores();

private slots:


private:
    Ui::TournamentRoster *ui;
    QListWidget listWidget;
    QTextEdit textEdit;


    std::shared_ptr<Tournament> passedTournament;

    enum PlayerStandingsColumn{
        NAME, SCORE
    };

};

#endif // TOURNAMENTROSTER_H
