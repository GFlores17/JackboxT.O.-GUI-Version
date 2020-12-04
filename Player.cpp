#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Player.h"
#include <memory>
#include "Tournament.h"

std::string pName;
int totalPoints;

    Player::Player() {
        pName = "default constructor";
        totalPoints = 0;
    }

    Player::Player(const std::string& Name) {
        pName = Name;
        totalPoints = 0;
    }

    std::string Player::getName() {
        return pName;
    }

    void Player::setName(const std::string& name) {
        pName = name;
    }

    void Player::print() {//Print formatted player name & stats.
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << pName << std::setw(2) << " : " << std::setw(2) << totalPoints << " pts" << std::endl;
    }

    void Player::promptForScore() {//Ask for points scored. [Used /w manualScoreAdd();]
        std::cout << "How many points did " << pName << " score?" << std::endl;
    }

    void Player::promptForPlacement() {//Ask for placement. [Used /w placementScoreAdd();]
        std::cout << "What did " << pName << " they place?" << std::endl;
    }

    void Player::manualScoreAdd(int points) {
        totalPoints = totalPoints + points;
    }

    void Player::placementScoreAdd(int numOfPlayers, int placement) {
        totalPoints = totalPoints + ((numOfPlayers + 1) - placement);
    }

    int Player::getScore() {
        return totalPoints;
    }

    void Player::setScore(int points) {
        this->totalPoints = points;
    }

    QString Player::getQName(){
        return QString::fromStdString(this->pName);
    }

    void Player::addToScore(int points){
        this->totalPoints = this->totalPoints + points;
    }

    void Player::serializePlayer(){
        try{

        std::ofstream OUTFILE;
        OUTFILE.open("C:\\Users\\George\\Desktop\\people.txt", std::ios_base::app);

        OUTFILE << this->getName() << "\n";
        OUTFILE << this->getScore() << "\n";
        //OUTFILE.close();
        }
        catch(int e){

        }
    }

    std::vector<std::shared_ptr<Player>> Player::deserializePlayer(){
        std::ifstream INFILE;
        INFILE.open("C:\\Users\\George\\Desktop\\people.txt", std::ios::in);

        std::vector<std::shared_ptr<Player>> vec;

        while(!INFILE.eof()){
            std::string name;

            std::string tScore;
            getline(INFILE,tScore);

            int score = stoi(tScore);

            getline(INFILE,name);


            std::shared_ptr<Player> p = std::make_shared<Player>(name);
            p->setScore(score);

            vec.push_back(std::move(p));
        }
        return vec;
    }

