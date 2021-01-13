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
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QMainWindow *pointerToMainWindow);
    ~MainWindow();

    void formatPlayersInTournamentFile();

    QWidget* getCenterWidget();

private slots:
    void on_exitButton_clicked();

    void on_startTournamentButton_clicked();

    void on_continueTournamentButton_clicked();

private:  
    Ui::MainWindow *ui;

    QTextEdit textEdit;
    QTextBrowser textBrowser;

    QMediaPlayer *player;

    QPushButton startTournamentButton;
    QPushButton continueTournamentButton;
    QPushButton exitButton;

    QWidget *centerWidget;
    QMainWindow *pointerToMainWindow;

    void closeEvent(QCloseEvent *event);

};
#endif // MAINWINDOW_H
