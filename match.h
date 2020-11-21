#ifndef MATCH_H
#define MATCH_H

#include "player.h"
#include "Game.h"

class Match {
private:
    std::string matchName;
    std::vector<std::shared_ptr<Game>> listOfGames;

public:
    static int getEntry();

    Match();
    Match(std::vector<Player> &vec);
    Match(std::string name);
    Match(QString name);

    void printResults();
    void printName();
    std::string getName();
    void setMatchName();
    //void addGame();
    void addGame();
    void addGame(int num);

    void viewGamesResults();
    void startGame();
    void enterGameResults();
    void printGames();
    void menu();
    void menuSelect(int choice);
    void exitProgram();
};

#endif
