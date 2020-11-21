#ifndef ADDTOROUNDFORM_H
#define ADDTOROUNDFORM_H

#include "tournament.h"

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>
#include "round.h"

namespace Ui {
class addToRoundForm; //This should be addToRoundForm
}

class addToRoundForm : public QWidget
{
    Q_OBJECT

public:
    explicit addToRoundForm(std::shared_ptr<Tournament> T, int x, QWidget *parent = nullptr);
    //int x helps us select a specific round from the Tournament listOfRounds vector.

    ~addToRoundForm();
    std::shared_ptr<Tournament> passedTournament;
    std::shared_ptr<Round> round;

private slots:
    void on_pushButton_clicked();

    void on_tournamentListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_tournamentListWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::addToRoundForm *ui;
    QListWidget tournamentListWidget;
    QListWidget roundListWidget;
    QTextEdit textEdit;
};

#endif // ADDTOROUNDFORM_H
