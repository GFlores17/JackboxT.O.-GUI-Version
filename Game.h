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
    std::vector<std::shared_ptr<Player>> testVec;

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

    std::vector<std::shared_ptr<Player>> getPlayers();


};

#endif //GAME_H