#ifndef ADDPLAYERTOMATCHDIALOG_H
#define ADDPLAYERTOMATCHDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QTextEdit>
#include <QLabel>
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

private slots:
    void on_pushButton_clicked();

    void on_roundRoster_itemDoubleClicked(QListWidgetItem *item);

    void on_roundRoster_itemClicked(QListWidgetItem *item);

    void on_buttonBox_accepted();

private:
    Ui::AddPlayerToMatchDialog *ui;
    QListWidget roundRoster;
    QListWidget matchRoster;
    QTextEdit textEdit;
    QLabel label_3;
};

#endif // ADDPLAYERTOMATCHDIALOG_H
