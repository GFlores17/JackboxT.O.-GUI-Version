#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class secWindow;
}

class secWindow : public QWidget
{
    Q_OBJECT

public:
    explicit secWindow(QWidget *parent = nullptr);
    ~secWindow();

private:
    Ui::secWindow *ui;
};

#endif // FORM_H
