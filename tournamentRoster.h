#ifndef TOURNAMENTROSTER_H
#define TOURNAMENTROSTER_H

#include <QWidget>
#include <QListWidget>
#include "tournament.h"

namespace Ui {
class TournamentRoster;
}

class TournamentRoster : public QWidget
{
    Q_OBJECT

public:
    explicit TournamentRoster(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~TournamentRoster();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TournamentRoster *ui;
    QListWidget listWidget;
    std::shared_ptr<Tournament> passedTournament;
};

#endif // TOURNAMENTROSTER_H
