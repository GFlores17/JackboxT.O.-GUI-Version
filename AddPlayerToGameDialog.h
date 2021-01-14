#ifndef ADDPLAYERTOGAMEDIALOG_H
#define ADDPLAYERTOGAMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>

namespace Ui {
class AddPlayerToGameDialog;
}

class AddPlayerToGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlayerToGameDialog(QWidget *parent = nullptr);
    ~AddPlayerToGameDialog();

    std::string getPlayerName() const;

private:
    Ui::AddPlayerToGameDialog *ui;

    QLabel lineEditLabel;
    QLineEdit lineEdit;
    QDialogButtonBox buttonBox;

};

#endif // AddPlayerToGameDialog_H
