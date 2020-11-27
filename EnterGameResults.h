#ifndef ENTERGAMERESULTS_H
#define ENTERGAMERESULTS_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class EnterGameResults;
}

class EnterGameResults : public QDialog
{
    Q_OBJECT

public:
    explicit EnterGameResults(QWidget *parent = nullptr);
    ~EnterGameResults();

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::EnterGameResults *ui;
};

#endif // ENTERGAMERESULTS_H
