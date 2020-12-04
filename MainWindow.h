#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QButtonGroup>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QWindow>
#include <QTextBrowser>
#include <QMediaPlayer>
#include "secondwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void formatPlayersInTournamentFile();

private slots:
    void on_exitButton_clicked();

    void on_startTournamentButton_clicked();

    void on_continueTournamentButton_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit lineEdit;
    QPushButton pushButton;
    QPushButton newWindowButton;
    SecondWindow *s;
    QTextBrowser textBrowser;
    QMediaPlayer *player;
    QPushButton exitButton;
    QPushButton startTournamentButton;
};
#endif // MAINWINDOW_H
