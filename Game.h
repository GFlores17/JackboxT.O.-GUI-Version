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

    void addPlayerToGame(std::shared_ptr<Player> p);
    void setGameResults();
    void printGameResults();

    void insertResult(std::pair<std::string, int>);

    std::vector<std::shared_ptr<Player>> getPlayers();
    std::map<std::string,int> getResultsMap();

    void serializeGame();
    void deserializeGame(std::shared_ptr<Game> g);

};

#endif //GAME_H
