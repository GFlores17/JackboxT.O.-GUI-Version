#ifndef MATCHMENU_H
#define MATCHMENU_H

#include <QWidget>
#include "round.h"
#include "match.h"

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

private slots:
    void on_pushButton_3_clicked();

    void on_FinishGameButton_clicked();

private:
    Ui::MatchMenu *ui;
};

#endif // MATCHMENU_H
