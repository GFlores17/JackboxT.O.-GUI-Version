#ifndef TOURNAMENTROSTER_H
#define TOURNAMENTROSTER_H

#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include "Tournament.h"

namespace Ui {
class TournamentRoster;
}

class TournamentRoster : public QWidget
{
    Q_OBJECT

public:
    explicit TournamentRoster(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~TournamentRoster();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::TournamentRoster *ui;
    QListWidget listWidget;
    QTextEdit textEdit;
    std::shared_ptr<Tournament> passedTournament;
};

#endif // TOURNAMENTROSTER_H
