#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QMainWindow>

#include <QMediaPlayer>

#include <QTextBrowser>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    MainMenu(QMainWindow *ptrToMainWindow);
    ~MainMenu();


    void formatPlayersInTournamentFile();

    QWidget* getCenterWidget();

private slots:
    void on_exitButton_clicked();

    void on_startTournamentButton_clicked();

    void on_continueTournamentButton_clicked();

private:
    Ui::MainMenu *ui;

    QTextBrowser textBrowser;
    QTextEdit textEdit;
    QMediaPlayer *player;

    QPushButton exitButton;
    QPushButton startTournamentButton;
    QPushButton continueTournamentButton;

    QWidget *centerWidget;
    QMainWindow *ptrToMainWindow;
};

#endif // MAINMENU_H
