#include <iostream>
#include <iomanip>
#include <string>
#include "player.h"

std::string pName;
int score;

    Player::Player() {
        pName = "default constructor";
        score = 0;
    }

    Player::Player(const std::string& Name) {
        pName = Name;
        score = 0;
    }

    std::string Player::getName() {
        return pName;
    }

    void Player::setName(const std::string& name) {
        pName = name;
    }

    void Player::print() {//Print formatted player name & stats.
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << pName << std::setw(2) << " : " << std::setw(2) << score << " pts" << std::endl;
    }

    void Player::promptForScore() {//Ask for points scored. [Used /w manualScoreAdd();]
        std::cout << "How many points did " << pName << " score?" << std::endl;
    }

    void Player::promptForPlacement() {//Ask for placement. [Used /w placementScoreAdd();]
        std::cout << "What did " << pName << " they place?" << std::endl;
    }

    void Player::manualScoreAdd(int points) {
        score = score + points;
    }

    void Player::placementScoreAdd(int numOfPlayers, int placement) {
        score = score + ((numOfPlayers + 1) - placement);
    }

    int Player::getScore() {
        return score;
    }

    void Player::setScore(int score) {
        this->score = score;
    }

    QString Player::getQName(){
        return QString::fromStdString(this->pName);
    }

