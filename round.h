#ifndef ROUND_H
#define ROUND_H

#include "match.h"
#include "player.h"
#include "getEntry.h"

class Round {
private:
    std::string roundName;
    std::vector <std::shared_ptr<Match>> listOfMatches;
    std::vector <std::shared_ptr<Player>> playersInRound;
public:
    static int getEntry();

    Round();
    Round(std::vector <std::shared_ptr<Player>>& vec);

    std::string getName();
    void setRoundName();
    void printName();

    void menu();
    void addMatch();
    void addPlayer(std::vector<std::shared_ptr<Player>>& vec);
    void printPlayers();
    void viewMatches();
    void checkIfMatchInRange(int& choice);
    void selectMatch();
    void exitProgram();
    void menuSelect(int choice);

};

#endif

