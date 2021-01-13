#ifndef ADDMATCHDIALOG_H
#define ADDMATCHDIALOG_H

#include <QDialog>
#include <QLabel>

#include <QPushButton>
#include <QLineEdit>

#include "Round.h"

namespace Ui {
class AddMatchDialog;
}

class AddMatchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMatchDialog(std::shared_ptr<Round> R, QWidget *parent = nullptr);
    ~AddMatchDialog();
    std::shared_ptr<Round>round;

private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_okButton_clicked();

private:

    Ui::AddMatchDialog *ui;

    QLabel label;
    QLineEdit lineEdit;

    QPushButton okButton;
    QPushButton cancelButton;

};

#endif // ADDMATCHDIALOG_H
