#ifndef EDITPLAYERDIALOG_H
#define EDITPLAYERDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>


namespace Ui {
class EditPlayerDialog;
}

class EditPlayerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditPlayerDialog(QWidget *parent = nullptr);
    ~EditPlayerDialog();

    std::string getName();

private:
    Ui::EditPlayerDialog *ui;
    QLabel lable;
    QLineEdit lineEdit;
    QDialogButtonBox buttonBox;
};

#endif // EDITPLAYERDIALOG_H
