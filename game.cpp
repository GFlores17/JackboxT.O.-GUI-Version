#include <iterator>
#include <map>
#include <vector>
#include <memory>

#include "Game.h"
#include "player.h"

    std::map <std::string, int> gameResults;
    std::vector<std::shared_ptr<Player>> playersInGame;
    std::string gameName;

    Game::Game() {
        gameName = "default";
    }



    Game::Game(int num) {
        gameName = "Game " + std::to_string(num);
    }

    Game::Game(std::string name){
        this->gameName = name;
    }

    void Game::setName(const std::string& name) {
        gameName = name;
    }

    std::map <std::string, int> Game::getMap() {
        return gameResults;
    }

    std::string Game::getName() {
        return gameName;
    }

    void Game::addPlayerToGame() {
        std::shared_ptr<Player> p = std::make_shared<Player>("a");
        std::shared_ptr<Player> q = std::make_shared<Player>("b");
        std::shared_ptr<Player> r = std::make_shared<Player>("d");
        std::shared_ptr<Player> s = std::make_shared<Player>("c");
        playersInGame.push_back(p);
        playersInGame.push_back(q);
        playersInGame.push_back(r);
        playersInGame.push_back(s);
    }

    void Game::addPlayerToGame(std::shared_ptr<Player> p){
        playersInGame.push_back(std::move(p));
    }

    void Game::setGameResults() {//Creates map according to
        for (int i = 0; i < playersInGame.size(); i++) {
            playersInGame.at(i)->print();
            playersInGame.at(i)->promptForScore();

            int gameScore;
            std::cin >> gameScore;

            playersInGame.at(i)->manualScoreAdd(gameScore);
            gameResults.insert(std::pair<std::string, int>(playersInGame.at(i)->getName(), gameScore));
        }
    }

    void Game::printGameResults() {
        std::map<std::string, int>::iterator itr;
        std::cout << "\nThe game results are : \n";
        std::cout << "\tPLAYER\tSCORE\n";
        for (itr = gameResults.begin(); itr != gameResults.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
    }

    /*void Game::addPlayerToGame(vector<shared_ptr<Player>>& playersInTournament) {
        std::string playerToAdd;
        std::cout << "Select player to add." << std::endl;
        std::cin >> playerToAdd;
        for (int i = 0; i < playersInTournament.size(); i++) {

            cout << "size : " << playersInTournament.size() << std::endl;
            cout << i << std::endl;

            if (playerToAdd == playersInTournament.at(i)->pName) {
                cout << "loop " << i << endl;
                playersInGame.push_back(playersInTournament.at(i));
                cout << "REFERENCES TO " << playersInTournament.at(i)->pName
                    << " : " << playersInTournament.at(i).use_count() << endl;
            }
        }
    }*/

    std::vector<std::shared_ptr<Player>> getPlayers(){
        return playersInGame;
    }
