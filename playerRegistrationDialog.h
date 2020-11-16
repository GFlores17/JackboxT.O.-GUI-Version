#ifndef PLAYERREGISTRATIONDIALOG_H
#define PLAYERREGISTRATIONDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include "tournament.h"

namespace Ui {
class PlayerRegistrationDialog;
}

class PlayerRegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerRegistrationDialog(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~PlayerRegistrationDialog();
    std::shared_ptr<Tournament> tournamentPtr;


private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::PlayerRegistrationDialog *ui;
    QLineEdit lineEdit;

};

#endif // PLAYERREGISTRATIONDIALOG_H
