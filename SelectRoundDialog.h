#ifndef SELECTROUNDDIALOG_H
#define SELECTROUNDDIALOG_H

#include <QDialog>
#include "tournament.h"

namespace Ui {
class SelectRoundDialog;
}

class SelectRoundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectRoundDialog(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~SelectRoundDialog();
    std::shared_ptr<Tournament> passedTournament;
private:
    Ui::SelectRoundDialog *ui;
};

#endif // SELECTROUNDDIALOG_H
