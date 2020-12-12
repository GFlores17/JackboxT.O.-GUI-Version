#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <QString>
#include <memory>
#include <vector>
#include <QFile>

class Player {
private:
    std::string pName;
    int totalPoints;

public:
    Player();
    Player(const std::string& Name);


    void setName(const std::string& name);
    void setScore(int points);

    std::string getName();
    int getScore();


    void addToScore(int points);
    QString getQName();

    //Serialization methods below

    void serializePlayer();
    std::vector<std::shared_ptr<Player>> deserializePlayer();

    void serializePlayer(QFile &OUTFILE);
    std::shared_ptr<Player> deserializePlayer(std::ifstream &INFILE);
};

#endif // PLAYER_H
