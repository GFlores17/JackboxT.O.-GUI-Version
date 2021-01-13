#ifndef ADDPLAYERTOGAME_H
#define ADDPLAYERTOGAME_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>

namespace Ui {
class AddPlayerToGame;
}

class AddPlayerToGame : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayerToGame(QWidget *parent = nullptr);
    ~AddPlayerToGame();

    std::string getPlayerName() const;

private:
    Ui::AddPlayerToGame *ui;

    QLabel lineEditLabel;
    QLineEdit lineEdit;
    QDialogButtonBox buttonBox;

};

#endif // ADDPLAYERTOGAME_H
