#ifndef ROUNDMENU_H
#define ROUNDMENU_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include "tournament.h"

namespace Ui {
class RoundMenu;
}

class RoundMenu : public QWidget
{
    Q_OBJECT

public:
    explicit RoundMenu(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~RoundMenu();

private slots:


    void on_addMatchButton_clicked();

    void on_selectMatchButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::RoundMenu *ui;
    QPushButton addMatchButton;
    QPushButton selectMatchButton;
    QPushButton exitMatchButton;
    QListWidget listWidget;
    std::shared_ptr<Tournament> passedTournament;

};

#endif // ROUNDMENU_H
