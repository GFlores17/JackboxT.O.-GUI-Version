#ifndef ROUND_H
#define ROUND_H

#include "match.h"
#include "player.h"
#include "GetEntry.h"

class Round {
private:
    std::string roundName;
    std::vector <std::shared_ptr<Match>> listOfMatches;
    std::vector <std::shared_ptr<Player>> playersInRound;
public:
    static int getEntry();

    Round();
    Round(std::string name);
    void menu();
    void menuSelect(int choice);
    std::vector <std::shared_ptr<Player>> getRoundListOfPlayers();
    QString getRoundName();
    void addRound(std::shared_ptr<Round> r);
    void addPlayer(std::shared_ptr<Player> p);
    void addMatch(std::shared_ptr<Match>m);

    std::vector <std::shared_ptr<Match>> getListOfMatches();

};

#endif

