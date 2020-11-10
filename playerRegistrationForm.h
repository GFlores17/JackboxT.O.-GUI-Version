#ifndef PLAYERREGISTRATIONFORM_H
#define PLAYERREGISTRATIONFORM_H

#include <QWidget>
#include <QLineEdit>
#include "tournament.h"

namespace Ui {
class PlayerRegistrationForm;
}

class PlayerRegistrationForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerRegistrationForm(std::shared_ptr<Tournament> T, QWidget *parent = nullptr);
    ~PlayerRegistrationForm();
    std::shared_ptr<Tournament> passedTournament;

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::PlayerRegistrationForm *ui;
    QLineEdit lineEdit;

};

#endif // PLAYERREGISTRATIONFORM_H
