#ifndef ADDTOROUNDDIALOG_H
#define ADDTOROUNDDIALOG_H

#include "Tournament.h"
#include <QDialog>
#include <QListWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>

namespace Ui {
class AddToRoundDialog;
}

class AddToRoundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddToRoundDialog(std::shared_ptr<Tournament> T, int x, QWidget *parent = nullptr);
    //int x helps us select a specific round from the Tournament listOfRounds vector.

    ~AddToRoundDialog();
    std::shared_ptr<Tournament> passedTournament;
    std::shared_ptr<Round> round;

    void printRoundPlayers();
private slots:
    void on_AddToRoundButton_clicked();

    void on_tournamentListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_tournamentListWidget_itemClicked(QListWidgetItem *item);

    void on_buttonBox_accepted();

    void on_RemoveFromRoundButton_clicked();

    void on_roundListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_roundListWidget_itemClicked(QListWidgetItem *item);

    void on_AddAllPlayersButton_clicked();

    void on_RemoveAllPlayersButton_clicked();

private:
    Ui::AddToRoundDialog *ui;
    QListWidget tournamentListWidget;
    QListWidget roundListWidget;
    QTextEdit textEdit;
    QLabel label_3;
    QPushButton AddToRoundButton;
    QPushButton RemoveFromRoundButton;
    QDialogButtonBox buttonBox;
};
#endif // ADDTOROUNDDIALOG_H
