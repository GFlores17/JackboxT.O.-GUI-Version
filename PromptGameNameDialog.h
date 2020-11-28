#ifndef PROMPTGAMENAMEDIALOG_H
#define PROMPTGAMENAMEDIALOG_H

#include <QDialog>
#include "Match.h"

namespace Ui {
class PromptGameNameDialog;
}

class PromptGameNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PromptGameNameDialog(std::shared_ptr<Match> m, QWidget *parent = nullptr);
    ~PromptGameNameDialog();

    std::shared_ptr<Match> match;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::PromptGameNameDialog *ui;
};

#endif // PROMPTGAMENAMEDIALOG_H
