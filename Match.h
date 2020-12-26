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
    void setName(std::string &name);

    void addGame();
    void addGame(int num);
    void addGame(std::shared_ptr<Game> g);

    void deletePlayer(int x);
    void deleteAllPlayers();
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

    void serializeMatch(std::ofstream &OUTFILE);
    void deserializeMatch();

    void serializeUsingQDir(QString path);
    QString createMatchFolder(QString path);
    void serializeMatchName(QString path);
    void serializeMatchPlayers(QString path);
    QString createGamesFolder(QString path);

    void deserializeMatchName(QString path);
    void deserializeMatchPlayers(QString path, std::vector<std::shared_ptr<Player>> roundPlayersArray);
    void deserializeAllGames(QString path  );
};

#endif
