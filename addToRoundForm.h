#ifndef ADDTOMATCHFORM_H
#define ADDTOMATCHFORM_H
#include "tournament.h"

#include <QWidget>
#include <QListWidget>
#include <QPushButton>

namespace Ui {
class addToMatchForm; //This should be addToRoundForm
}

class addToRoundForm : public QWidget
{
    Q_OBJECT

public:
    explicit addToRoundForm(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~addToRoundForm();
    std::shared_ptr<Tournament> passedTournament;

private:
    Ui::addToMatchForm *ui;
    QListWidget tournamentListWidget;
    QListWidget roundListWidget;
};

#endif // ADDTOMATCHFORM_H
