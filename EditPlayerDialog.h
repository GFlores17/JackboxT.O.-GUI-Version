#ifndef EDITPLAYERDIALOG_H
#define EDITPLAYERDIALOG_H

#include <QDialog>

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
};

#endif // EDITPLAYERDIALOG_H
