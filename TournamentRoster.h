#ifndef TOURNAMENTROSTER_H
#define TOURNAMENTROSTER_H

#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
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
    QLabel label;


    std::shared_ptr<Tournament> passedTournament;

    enum PlayerStandingsColumn{
        NAME, SCORE
    };

};

#endif // TOURNAMENTROSTER_H
