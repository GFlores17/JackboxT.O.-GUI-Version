#ifndef ADDTOROUNDMENU_H
#define ADDTOROUNDMENU_H

#include <QWidget>

namespace Ui {
class AddToRoundMenu;
}

class AddToRoundMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AddToRoundMenu(QWidget *parent = nullptr);
    ~AddToRoundMenu();

private:
    Ui::AddToRoundMenu *ui;
};

#endif // ADDTOROUNDMENU_H
