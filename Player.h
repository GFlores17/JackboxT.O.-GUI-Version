#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <QString>
#include <memory>
#include <vector>


class Player {
private:
    std::string pName;
    int totalPoints;

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
    void setScore(int points);
    void addToScore(int points);
    QString getQName();

    //Serialization methods below

    void serializePlayer();
    std::vector<std::shared_ptr<Player>> deserializePlayer();
};

#endif // PLAYER_H
