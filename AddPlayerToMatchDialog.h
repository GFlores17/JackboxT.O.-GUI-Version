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

    void printMatchPlayers();
    void printRoundPlayers();

signals:
    void RemoveFromMatchButton_clicked();

private slots:
    void on_addToMatchButton_clicked();

    void on_roundRosterListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_roundRosterListWidget_itemClicked(QListWidgetItem *item);

    void on_buttonBox_accepted();

    void on_removeFromMatchButton_clicked();

    void on_matchRosterListWidget_itemClicked(QListWidgetItem *item);

    void on_matchRosterListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_addAllPlayersButton_clicked();

    void on_removeAllPlayersButton_clicked();

private:
    Ui::AddPlayerToMatchDialog *ui;
    QListWidget roundRosterListWidget;
    QListWidget matchRosterListWidget;
    QTextEdit textEdit;
    QLabel menuLabel;
    QLabel roundRosterLabel;
    QLabel matchRosterLabel;


};

#endif // ADDPLAYERTOMATCHDIALOG_H
