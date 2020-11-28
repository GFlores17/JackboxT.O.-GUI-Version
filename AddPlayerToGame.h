#ifndef ADDPLAYERTOGAME_H
#define ADDPLAYERTOGAME_H

#include <QDialog>

namespace Ui {
class AddPlayerToGame;
}

class AddPlayerToGame : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayerToGame(QWidget *parent = nullptr);
    ~AddPlayerToGame();

    std::string playerName() const;

private:
    Ui::AddPlayerToGame *ui;
};

#endif // ADDPLAYERTOGAME_H
