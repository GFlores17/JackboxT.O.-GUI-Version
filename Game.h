#ifndef GAME_H
#define GAME_H

#include <iterator>
#include <map>
#include <vector>
#include <memory>
#include "Player.h"
//Player.h has <iostream>, <iomanip>, and <string>.

class Game {
private:
    std::map <std::string, int> gameResults;
    std::vector<std::shared_ptr<Player>> playersInGame;
    std::string gameName;

public:
    Game();
    Game(int num);
    Game(std::string name);
    void setName(const std::string& name);
    std::string getName();

    std::map <std::string, int> getMap();
    void clearResultsMap();

    void addPlayerToGame(std::shared_ptr<Player> p);
    void setGameResults();
    void printGameResults();

    void insertResult(std::pair<std::string, int>);

    bool isFinished();

    std::vector<std::shared_ptr<Player>> getPlayers();
    std::map<std::string,int> getResultsMap();

    void serializeGame(std::ofstream &OUTFILE);
    void deserializeGame(std::shared_ptr<Game> g);


    void deserializeUsingQDir();

    void serializeUsingQDir(QString path);
    QString createGameFolder(QString path);
    void serializeGameName(QString path);
    void serializeGamePlayers(QString path);
    void serializeGameResults(QString path);

    void deserializeGameName(QString path);
    void deserializeGamePlayers(QString path);
    void deserializeGameResults(QString path  );

};

#endif //GAME_H
