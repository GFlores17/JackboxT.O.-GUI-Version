#ifndef TOURNAMENTMENU_H
#define TOURNAMENTMENU_H

#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>

namespace Ui {
class TournamentMenu;
}

class TournamentMenu : public QWidget
{
    Q_OBJECT

public:
    explicit TournamentMenu(QWidget *parent = nullptr);
    ~TournamentMenu();

private:
    Ui::TournamentMenu *ui;
    QTextEdit textEdit;
    QLineEdit lineEdit;
};

#endif // TOURNAMENTMENU_H
