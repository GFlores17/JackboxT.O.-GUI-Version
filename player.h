#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <QString>


class Player {
private:
    std::string pName;
    int score;

public:
    Player();
    Player(const std::string& Name);

    std::string getName();
    void setName(const std::string& name);

    void print();
    void promptForScore();
    void promptForPlacement();
    void manualScoreAdd(int points);
    void placementScoreAdd(int numOfPlayers, int placement);
    int getScore();
    void setScore(int score);
    QString getQName();
};

#endif // PLAYER_H
