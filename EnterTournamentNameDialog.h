#ifndef ENTERTOURNAMENTNAME_H
#define ENTERTOURNAMENTNAME_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>

namespace Ui {
class EnterTournamentName;
}

class EnterTournamentName : public QDialog
{
    Q_OBJECT

public:
    explicit EnterTournamentName(QWidget *parent = nullptr);
    ~EnterTournamentName();

    std::string getTournamentName();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EnterTournamentName *ui;
    QLabel lable;
    QLineEdit lineEdit;
    QDialogButtonBox buttonBox;
};

#endif // ENTERTOURNAMENTNAME_H
