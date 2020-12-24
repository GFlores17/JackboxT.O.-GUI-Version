#ifndef ROUNDMENU_H
#define ROUNDMENU_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>
#include "Tournament.h"
#include "TournamentMenu.h"

namespace Ui {
class RoundMenu;
}

class RoundMenu : public QWidget
{
    Q_OBJECT

public:
    explicit RoundMenu(std::shared_ptr<Round> R, QWidget *parent = nullptr);
    RoundMenu(std::shared_ptr<Round> R, std::shared_ptr<Tournament> T, QMainWindow *pointerToMainWindow);
    ~RoundMenu();
    std::shared_ptr<Tournament> passedTournament;
    std::shared_ptr<Round>round;

    void printMatches();
    void printMatchStandings();

private slots:


    void on_addMatchButton_clicked();

    void on_selectMatchButton_clicked();

    void on_exitButton_clicked();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::RoundMenu *ui;
    QPushButton addMatchButton;
    QPushButton selectMatchButton;
    QPushButton exitMatchButton;
    QLabel label;
    QListWidget listWidget;
    QMainWindow *pointerToMainWindow;
    std::shared_ptr<Tournament> hostTournament;
    std::shared_ptr<TournamentMenu> testMenu;

    enum MatchResultsColumn{
        NAME, SCORE
    };
};

#endif // ROUNDMENU_H
