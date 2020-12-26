#ifndef SELECTROUNDDIALOG_H
#define SELECTROUNDDIALOG_H

#include <QDialog>
#include <QListWidget>
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
    void on_pushButton_clicked();

    void on_RoundsWidget_itemClicked(QListWidgetItem *item);

    void on_RoundsWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::SelectRoundDialog *ui;
    QMainWindow *pointerToMainWindow;
};

#endif // SELECTROUNDDIALOG_H
