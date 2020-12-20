#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <QButtonGroup>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QWindow>
#include <QTextBrowser>
#include <QMediaPlayer>
#include <QMainWindow>

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
    QLineEdit lineEdit;
    QPushButton pushButton;
    QPushButton newWindowButton;
    QTextBrowser textBrowser;
    QMediaPlayer *player;
    QPushButton exitButton;
    QPushButton startTournamentButton;
    QWidget *centerWidget;
    QMainWindow *ptrToMainWindow;
};

#endif // MAINMENU_H
