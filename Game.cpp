#include <iterator>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <QtDebug>
#include <QDir>
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

    void Game::serializeGame(std::ofstream &OUTFILE){
        try{
        //std::ofstream OUTFILE;
        //OUTFILE.open("C:\\Users\\George\\Desktop\\match.txt", std::ios_base::app);
        OUTFILE << "GAMENAME" << "\n";
        OUTFILE << this->gameName << "\n";

        OUTFILE << "PLAYERSLIST" << "\n";

        for(int i = 0; i < this->playersInGame.size(); i++){
            OUTFILE << this->playersInGame.at(i)->getName() << "\n";
            OUTFILE << this->playersInGame.at(i)->getScore() << "\n";
        }

        OUTFILE<< "GAMERESULT" << "\n";
        for (std::map<std::string,int>::iterator it=this->gameResults.begin(); it!=this->gameResults.end(); ++it){
            //std::cout << it->first << " => " << it->second << '\n';
            OUTFILE << it->first << "\n";
            OUTFILE << it->second << "\n";
        }

            //OUTFILE.close();
        }

        catch(int e){

        }

    }//serializeGame end.

    void Game::deserializeGame(std::shared_ptr<Game> g){
        std::ifstream INFILE;
        INFILE.open("C:\\Users\\George\\Desktop\\games.txt", std::ios::in);

        //std::vector<std::shared_ptr<Player>> vec;

        bool playersWrite = true;
        bool resultsWrite = false;
        bool gameNameWrite = false;

        while(!INFILE.eof()){

                while(gameNameWrite == true){
                    std::string gameName;
                    getline(INFILE, gameName);

                    if(gameName.compare("PLAYERLIST") == 0){
                        gameNameWrite = false;
                        playersWrite = true;
                        break;
                    }
                    qDebug() << QString::fromStdString(gameName) << "\n";
                    g->setName(gameName);
                }

                while(playersWrite == true){
                    std::string name;
                    std::string stringTotalScore;

                    getline(INFILE,name);

                    if(name.compare("GAMERESULT")==0){
                        playersWrite = false;
                        resultsWrite = true;
                        break;
                    }

                    getline(INFILE,stringTotalScore);

                    std::stringstream stringToIntConverter(stringTotalScore);
                    //Convert the score saved as string to int.

                    int intTotalScore;
                    stringToIntConverter >> intTotalScore;
                    //Store converted score in int variable.

                    std::shared_ptr<Player> p = std::make_shared<Player>(name);
                    p->setScore(intTotalScore);

                    qDebug() << p->getQName() << " : " << QString::fromStdString(stringTotalScore);

                    this->playersInGame.push_back(std::move(p));
                }

                while(resultsWrite == true){
                    std::string name;
                    std::string stringGameScore;

                    getline(INFILE,name);

                    if(name.compare("")==0){
                        qDebug() << "BREAK" << "\n";
                        break;
                    }

                    getline(INFILE,stringGameScore);

                    std::stringstream stringToIntConverter(stringGameScore);

                    int intGameScore;
                    stringToIntConverter >> intGameScore;

                    std::pair<std::string,int> gameResult (name, intGameScore);

                    qDebug() << QString::fromStdString(name) << " : " << QString::fromStdString(stringGameScore);
                    this->insertResult(gameResult);
                }

        }

    }//end deserializeGame

    void Game::serializeUsingQDir(QString path){
        QString gameFolderPath = createGameFolder(path);
        qDebug() << "CREATED FOLDER:" << gameFolderPath << "\n";
        serializeGameName(gameFolderPath);
        serializeGamePlayers(gameFolderPath);
        serializeGameResults(gameFolderPath);
    }

    QString Game::createGameFolder(QString path){
        QString gameFolderPath = path + QString::fromStdString(this->gameName) + "/";

        if(QDir(gameFolderPath).exists() == false){
            QDir().mkdir(gameFolderPath);
            qDebug() << gameFolderPath << "CREATED\n";
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

        }


    }
