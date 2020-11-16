#ifndef ADDTOROUNDFORM_H
#define ADDTOROUNDFORM_H

#include "tournament.h"

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QTextEdit>

namespace Ui {
class addToRoundForm; //This should be addToRoundForm
}

class addToRoundForm : public QWidget
{
    Q_OBJECT

public:
    explicit addToRoundForm(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~addToRoundForm();
    std::shared_ptr<Tournament> passedTournament;

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
