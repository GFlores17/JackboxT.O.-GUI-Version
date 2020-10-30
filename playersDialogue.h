#ifndef PLAYERSDIALOGUE_H
#define PLAYERSDIALOGUE_H

#include <QDialog>
#include <QTextEdit>
#include <QButtonGroup>
#include <QTextBrowser>
#include <QPushButton>

namespace Ui {
class playersDialogue;
}

class playersDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit playersDialogue(QWidget *parent = nullptr);
    ~playersDialogue();

private slots:
    void on_textEdit_textChanged();

    void on_pushButton_clicked();

    void on_textBrowser_anchorClicked(const QUrl &arg1);

    void on_pushButton_pressed();

private:
    Ui::playersDialogue *ui;
    QTextEdit textEdit;
    QPushButton pushButton;
    QTextBrowser textBrowser;
    QString listOfPlayers;
};

#endif // PLAYERSDIALOGUE_H
