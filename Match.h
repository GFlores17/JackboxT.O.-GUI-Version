#ifndef MATCH_H
#define MATCH_H

#include "Player.h"
#include "Game.h"

class Match {
private:
    std::string matchName;
    std::vector<std::shared_ptr<Game>> listOfGames;
    std::vector <std::shared_ptr<Player>> playersInMatch;

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
    void addGame(std::shared_ptr<Game> g);

    void viewGamesResults();
    void startGame();
    void enterGameResults();
    void printGames();
    void menu();
    void menuSelect(int choice);
    void exitProgram();

    std::vector<std::shared_ptr<Game>> getListOfGames();
    std::vector <std::shared_ptr<Player>> getMatchListOfPlayers();

    void addPlayer(std::shared_ptr<Player> p);
    int getNumOfPlayers();
};

#endif
