#include <iostream>
#include <iomanip>
#include <string>
#include "Player.h"

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
