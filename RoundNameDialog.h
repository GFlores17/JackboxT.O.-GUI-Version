#ifndef ROUNDNAMEDIALOG_H
#define ROUNDNAMEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QDialogButtonBox>
#include "Tournament.h"

namespace Ui {
class RoundNameDialog;
}

class RoundNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoundNameDialog(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~RoundNameDialog();
    std::shared_ptr<Tournament> passedTournament;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RoundNameDialog *ui;
    QDialogButtonBox buttonBox;
};

#endif // ROUNDNAMEDIALOG_H
