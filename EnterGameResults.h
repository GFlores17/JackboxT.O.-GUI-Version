#ifndef ENTERGAMERESULTS_H
#define ENTERGAMERESULTS_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include "Match.h"

namespace Ui {
class EnterGameResults;
}

class EnterGameResults : public QDialog
{
    Q_OBJECT

public:
    explicit EnterGameResults(std::shared_ptr<Game> g, QWidget *parent = nullptr);
    ~EnterGameResults();

    std::shared_ptr<Game> game;

    QLineEdit lineEdit;
    QLabel label;

    void editLabel(QString str);

    int playerScore() const;

    void enterScores();
private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::EnterGameResults *ui;

};

#endif // ENTERGAMERESULTS_H
