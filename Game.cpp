#include <iterator>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <QtDebug>
#include <QDir>
#include <QDirIterator>
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

    bool Game::isFinished(){
        return !this->getMap().empty();
    }

    void Game::setGameResults() {//Creates map according to
        for (int i = 0; i < playersInGame.size(); i++) {
            //playersInGame.at(i)->print();
            //playersInGame.at(i)->promptForScore();

            int gameScore;
            std::cin >> gameScore;

            playersInGame.at(i)->addToScore(gameScore);
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

    void Game::clearResultsMap(){
        this->gameResults.clear();

        /* Need to develop a custom method.
         * Delete pairs 1 by 1 from the map.
         * As each pair is deleted from the map, update the corresponding player's total score based on the game score that was just deleted.
         * This is needed to keep consistency with regards to total player's scores.
         */
    }

    void Game::serializeGame(QString path){
        QString gameFolderPath = createGameFolder(path);
        serializeGameName(gameFolderPath);
        serializeGamePlayers(gameFolderPath);
        serializeGameResults(gameFolderPath);
    }

    QString Game::createGameFolder(QString path){
        QString gameFolderPath = path + QString::fromStdString(this->gameName) + "/";

        if(QDir(gameFolderPath).exists() == false){
            QDir().mkdir(gameFolderPath);
        }

        return gameFolderPath;
    }
    void Game::serializeGameName(QString path){
        QString newFile = path + "GameName" +  + ".txt";

        if(QFileInfo(newFile).exists() == 0){

            QFile file(newFile);
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            out << QString::fromStdString(this->gameName);
        }
        else{

        }
    }
    void Game::serializeGamePlayers(QString path){
        QString newFile = path + "GamePlayers" +  + ".txt";

        if(QFileInfo(newFile).exists() == 0){

            QFile file(newFile);
            for(int i =0; i<playersInGame.size();i++){
                playersInGame.at(i)->serializePlayer(file);
            }
        }
        else{

        }
    }
    void Game::serializeGameResults(QString path){

        QString newFile = path + "GameResults" +  + ".txt";

        if(QFileInfo(newFile).exists() == 0){

            QFile file(newFile);
            file.open(QIODevice::WriteOnly);
            QTextStream OUTFILE(&file);

            for (std::map<std::string,int>::iterator it=this->gameResults.begin(); it!=this->gameResults.end(); ++it){
                OUTFILE << QString::fromStdString(it->first) << "\n";
                OUTFILE << it->second << "\n";
            }

        }//If file exists, write results to it.

        else{

            QFile file(newFile);
            file.open(QIODevice::WriteOnly);
            QTextStream OUTFILE(&file);

            for (std::map<std::string,int>::iterator it=this->gameResults.begin(); it!=this->gameResults.end(); ++it){
                OUTFILE << QString::fromStdString(it->first) << "\n";
                OUTFILE << it->second << "\n";
            }


        }


    }

    void Game::deserializeGameName(QString path){
        //QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

        //path = path + "/JBT Saved Tournaments/Testes";
        QDir rootdir(path);
        QDirIterator it(rootdir);



        while (it.hasNext()) {
            QFileInfo file = it.next();

            if(file.fileName() == "GameName.txt"){


                QFile gameNameFile(file.absoluteFilePath());
                gameNameFile.open(QIODevice::ReadOnly);
                QTextStream in(&gameNameFile);

                QString readline = in.readLine();


                std::string newName = readline.toStdString();
                this->setName(newName);

                //gameNameFile.remove();
                break;
            }
        }
    }

    void Game::deserializeGamePlayers(QString path, std::vector<std::shared_ptr<Player>> matchPlayersArray){
        QDir rootdir(path);
        QDirIterator it(rootdir);

        while (it.hasNext()) {
            QFileInfo file = it.next();

            if(file.fileName() == "GamePlayers.txt"){

                QFile gamePlayersFile(file.absoluteFilePath());
                gamePlayersFile.open(QIODevice::ReadOnly);
                QTextStream in(&gamePlayersFile);

                while(!in.atEnd()){

                    std::string playerName = in.readLine().toStdString();

                    std::string stringPlayerScore = in.readLine().toStdString();


                    std::stringstream ss(stringPlayerScore);
                    int intPlayerScore;
                    ss >> intPlayerScore;

                    for(int i = 0; i < matchPlayersArray.size(); i++){
                        if(playerName==matchPlayersArray.at(i)->getName()){
                            std::shared_ptr<Player>newPlayer = matchPlayersArray.at(i);
                            addPlayerToGame(newPlayer);
                            break;
                        }//Check for matching player pointer in tournament roster.
                    }//End for loop()
                }//EOF reached.

                //gamePlayersFile.remove();
            }           
        }
    }

    void Game::deserializeGameResults(QString path){
        QDir rootdir(path);
        QDirIterator it(rootdir);

        while (it.hasNext()) {
            QFileInfo file = it.next();

            if(file.fileName() == "GameResults.txt"){


                QFile gameResultsFile(file.absoluteFilePath());
                gameResultsFile.open(QIODevice::ReadOnly);
                QTextStream in(&gameResultsFile);

                while(!in.atEnd()){
                    std::string playerName = in.readLine().toStdString();

                    std::string stringPlayerScore = in.readLine().toStdString();

                    std::stringstream ss(stringPlayerScore);
                    int intPlayerScore;
                    ss >> intPlayerScore;

                    std::pair<std::string, int> singularGameResult = std::make_pair(playerName, intPlayerScore);
                    this->insertResult(std::pair<std::string, int>(playerName, intPlayerScore));
                }

                //gameResultsFile.remove();
                //All results have been inserted, this causes already saved but unfinished games to be uneditable because their respective results map is already filled.
                //Below, we check if everyone's points is zero, if it is, then reset the map.

            }
        }
    }


