#ifndef ENTERGAMERESULTS_H
#define ENTERGAMERESULTS_H

#include <QDialog>
#include <QLineEdit>
#include "match.h"

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
private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::EnterGameResults *ui;
};

#endif // ENTERGAMERESULTS_H
