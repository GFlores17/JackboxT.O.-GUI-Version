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
    void on_addToRoundButton_clicked();

    void on_tournamentRosterListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_tournamentRosterListWidget_itemClicked(QListWidgetItem *item);

    void on_buttonBox_accepted();

    void on_removeFromRoundButton_clicked();

    void on_roundRosterListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_roundRosterListWidget_itemClicked(QListWidgetItem *item);

    void on_addAllPlayersButton_clicked();

    void on_removeAllPlayersButton_clicked();

private:
    Ui::AddToRoundDialog *ui;
    QListWidget tournamentRosterListWidget;
    QListWidget roundRosterListWidget;
    QTextEdit textEdit;
    QLabel menuLabel;
    QLabel tournamentRosterLabel;
    QLabel roundRosterLabel;
    QPushButton addToRoundButton;
    QPushButton removeFromRoundButton;
    QPushButton addAllPlayersButton;
    QPushButton removeAllPlayersButton;
    QDialogButtonBox buttonBox;
};
#endif // ADDTOROUNDDIALOG_H
