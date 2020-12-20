#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include "playersDialogue.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_returnButton_clicked();

    void on_returnButton2_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
