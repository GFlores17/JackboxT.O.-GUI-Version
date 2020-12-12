#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Player.h"
#include <memory>
#include "Tournament.h"
#include <QtDebug>
#include <sstream>

#include <QDir>
#include <QDirIterator>
#include <QFileInfo>
#include <QTextStream>

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


    void Player::setName(const std::string& name) {
        pName = name;
    }

    void Player::setScore(int points) {
        this->totalPoints = points;
    }

    std::string Player::getName() {
        return pName;
    }

    int Player::getScore() {
        return totalPoints;
    }

    void Player::addToScore(int points){
        this->totalPoints = this->totalPoints + points;
    }

    QString Player::getQName(){
        return QString::fromStdString(this->pName);
    }

    void Player::serializePlayer(){
        try{

        std::ofstream OUTFILE;
        OUTFILE.open("C:\\Users\\George\\Desktop\\people.txt", std::ios_base::app);
        qDebug() << "SERIALIZING PLAYER\n";
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

    void Player::serializePlayer(QFile &file){
        file.open(QIODevice::WriteOnly);
        QTextStream OUTFILE(&file);
        OUTFILE << QString::fromStdString(this->pName) + "\n";
        OUTFILE << this->totalPoints << "\n";
    }

    std::shared_ptr<Player> Player::deserializePlayer(std::ifstream &INFILE){
        std::vector<std::shared_ptr<Player>> vec;

        std::shared_ptr<Player> createdPlayer = std::make_shared<Player>();

        std::string playerName;
        std::string totalScore;

        getline(INFILE, playerName);
        getline(INFILE, totalScore);

        std::stringstream stringToIntConverter(totalScore);
        int intScore;
        stringToIntConverter >> intScore;

        createdPlayer->setName(playerName);
        createdPlayer->setScore(intScore);

        return createdPlayer;
    }

