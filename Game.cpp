#include <iterator>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <QtDebug>
#include "Game.h"
#include "Player.h"

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

    std::vector<std::shared_ptr<Player>> Game::getPlayers(){
        return playersInGame;
    }

    void Game::insertResult(std::pair<std::string, int> pair){
        this->gameResults.insert(pair);
    }
    std::map<std::string,int> Game::getResultsMap(){
        return this->gameResults;
    }

    void Game::serializeGame(){
        try{
        std::ofstream OUTFILE;
        OUTFILE.open("C:\\Users\\George\\Desktop\\games.txt", std::ios_base::app);

        for (std::map<std::string,int>::iterator it=this->gameResults.begin(); it!=this->gameResults.end(); ++it){
            std::cout << it->first << " => " << it->second << '\n';
            OUTFILE << it->first << "\n";
            OUTFILE << it->second << "\n";
        }

        OUTFILE << "PLAYERSLIST" << "\n";

        for(int i = 0; i < this->playersInGame.size(); i++){
            OUTFILE << this->playersInGame.at(i)->getName() << "\n";
        }

            OUTFILE.close();
        }

        catch(int e){

        }
    }

    void Game::deserializeGame(std::shared_ptr<Game> g){
        std::ifstream INFILE;
        INFILE.open("C:\\Users\\George\\Desktop\\games.txt", std::ios::in);

        std::vector<std::shared_ptr<Player>> vec;

        bool playersWrite = true;
        bool resultsWrite = false;
        bool gameNameWrite = false;

        while(!INFILE.eof()){

                while(playersWrite == true){
                    std::string name;
                    std::string tScore;

                    getline(INFILE,name);

                    if(name.compare("PLAYERSLIST")==0){
                        playersWrite = false;
                        resultsWrite = true;
                        break;
                    }

                    getline(INFILE,tScore);

                    std::stringstream degree(tScore);

                    int score;
                    degree >> score;




                    std::shared_ptr<Player> p = std::make_shared<Player>(name);
                    p->setScore(score);

                    this->playersInGame.push_back(std::move(p));
                }

                while(resultsWrite == true){
                    std::string name;
                    std::string gameScore;

                    getline(INFILE,name);

                    if(name.compare("")==0){
                        qDebug() << "BREAK" << "\n";
                        break;
                    }

                    getline(INFILE,gameScore);

                    std::stringstream degree(gameScore);

                    int score;
                    degree >> score;

                    std::pair<std::string,int> gameResult (name, score);

                    this->insertResult(gameResult);
                }


        }

    }
