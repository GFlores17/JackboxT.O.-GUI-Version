#ifndef SELECTROUNDDIALOG_H
#define SELECTROUNDDIALOG_H

#include <QDialog>
#include <QListWidget>

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>

#include "QMainWindow"
#include "Tournament.h"

namespace Ui {
class SelectRoundDialog;
}

class SelectRoundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectRoundDialog(std::shared_ptr<Tournament> passedTournament, QWidget *parent = nullptr);
    SelectRoundDialog(std::shared_ptr<Tournament> passedTournament, QMainWindow *pointerToMainWindow);
    ~SelectRoundDialog();

    std::shared_ptr<Tournament> passedTournament;

    int getSelectedRound();
    void printRounds();
    void printRoundPlayers(int selectedRound);

private slots:
    void on_okButton_clicked();

    void on_roundsListWidget_itemClicked(QListWidgetItem *item);

    void on_roundsListWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::SelectRoundDialog *ui;

    QMainWindow *pointerToMainWindow;

    QLabel roundNameLabel;
    QLabel matchesLabel;

    QListWidget roundsListWidget;
    QListWidget playersListWidget;

    QPushButton okButton;
    QPushButton cancelButton;
};

#endif // SELECTROUNDDIALOG_H
