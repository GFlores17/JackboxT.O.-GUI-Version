#ifndef PLAYERREGISTRATIONDIALOG_H
#define PLAYERREGISTRATIONDIALOG_H

#include <QDialog>

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>

#include "Tournament.h"

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

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::PlayerRegistrationDialog *ui;

    QLabel lable;
    QLineEdit lineEdit;
    QDialogButtonBox buttonBox;
    QPushButton okButton;
    QPushButton cancelButton;

};

#endif // PLAYERREGISTRATIONDIALOG_H
