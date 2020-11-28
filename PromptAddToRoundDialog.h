#ifndef PROMPTADDTOROUNDDIALOG_H
#define PROMPTADDTOROUNDDIALOG_H

#include <QDialog>
#include "Tournament.h"

namespace Ui {
class PromptAddToRoundDialog;
}

class PromptAddToRoundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PromptAddToRoundDialog(std::shared_ptr<Tournament> T, int x, QWidget *parent = nullptr);
    ~PromptAddToRoundDialog();

    std::shared_ptr<Tournament> passedTournament;
    int num;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PromptAddToRoundDialog *ui;
};

#endif // PROMPTADDTOROUNDDIALOG_H
