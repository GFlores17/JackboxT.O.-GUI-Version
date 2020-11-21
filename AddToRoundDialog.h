#ifndef ADDTOROUNDDIALOG_H
#define ADDTOROUNDDIALOG_H

#include "tournament.h"
#include <QDialog>
#include <QListWidget>
#include <QTextEdit>
#include <QLabel>

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

private slots:
    void on_pushButton_clicked();

    void on_tournamentListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_tournamentListWidget_itemClicked(QListWidgetItem *item);

    void on_buttonBox_accepted();

private:
    Ui::AddToRoundDialog *ui;
    QListWidget tournamentListWidget;
    QListWidget roundListWidget;
    QTextEdit textEdit;
    QLabel label_3;
};
#endif // ADDTOROUNDDIALOG_H
