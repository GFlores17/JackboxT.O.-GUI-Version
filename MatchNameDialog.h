#ifndef MATCHNAMEDIALOG_H
#define MATCHNAMEDIALOG_H

#include <QDialog>
#include "Round.h"

namespace Ui {
class MatchNameDialog;
}

class MatchNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MatchNameDialog(std::shared_ptr<Round> r, QWidget *parent = nullptr);
    ~MatchNameDialog();
    std::shared_ptr<Round> round;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::MatchNameDialog *ui;
};

#endif // MATCHNAMEDIALOG_H
