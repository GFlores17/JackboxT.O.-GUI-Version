#ifndef ADDPLAYERTOMATCHDIALOG_H
#define ADDPLAYERTOMATCHDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include "Round.h"

namespace Ui {
class AddPlayerToMatchDialog;
}

class AddPlayerToMatchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayerToMatchDialog(std::shared_ptr<Round> r, int x, QWidget *parent = nullptr);
    ~AddPlayerToMatchDialog();

    std::shared_ptr<Round> round;
    std::shared_ptr<Match> match;

    void printRoundPlayers();
    void printGamePlayers();

signals:
    void RemoveFromMatchButton_clicked();

private slots:
    void on_AddToMatchButton_clicked();

    void on_roundRoster_itemDoubleClicked(QListWidgetItem *item);

    void on_roundRoster_itemClicked(QListWidgetItem *item);

    void on_buttonBox_accepted();

    void on_RemoveButton_clicked();

    void on_matchRoster_itemClicked(QListWidgetItem *item);

    void on_matchRoster_itemDoubleClicked(QListWidgetItem *item);

    void on_AddAllPlayersButton_clicked();

private:
    Ui::AddPlayerToMatchDialog *ui;
    QListWidget roundRoster;
    QListWidget matchRoster;
    QTextEdit textEdit;
    QLabel label_3;


};

#endif // ADDPLAYERTOMATCHDIALOG_H
