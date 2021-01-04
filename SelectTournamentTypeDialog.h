#ifndef SELECTTOURNAMENTTYPEDIALOG_H
#define SELECTTOURNAMENTTYPEDIALOG_H

#include <QDialog>

namespace Ui {
class SelectTournamentTypeDialog;
}

class SelectTournamentTypeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectTournamentTypeDialog(QWidget *parent = nullptr);
    ~SelectTournamentTypeDialog();

private:
    Ui::SelectTournamentTypeDialog *ui;
};

#endif // SELECTTOURNAMENTTYPEDIALOG_H
