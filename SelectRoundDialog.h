#ifndef SELECTROUNDDIALOG_H
#define SELECTROUNDDIALOG_H

#include <QDialog>
#include <QListWidget>
#include "QMainWindow"
#include "Tournament.h"

namespace Ui {
class SelectRoundDialog;
}

class SelectRoundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectRoundDialog(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    SelectRoundDialog(std::shared_ptr<Tournament> T, QMainWindow *pointerToMainWindow);
    ~SelectRoundDialog();
    std::shared_ptr<Tournament> passedTournament;
private slots:
    void on_pushButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::SelectRoundDialog *ui;
    QMainWindow *pointerToMainWindow;
};

#endif // SELECTROUNDDIALOG_H
