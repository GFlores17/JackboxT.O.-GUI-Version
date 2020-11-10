#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <map>
#include <iterator>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include "game.h"
#include "match.h"
#include "player.h"
#include "round.h"
#include "getEntry.h"

class Tournament {

private:
    std::string tournamentName;
    std::vector<std::shared_ptr<Player>> listOfAllPlayers;
    std::vector<std::shared_ptr<Round>> listOfRounds;

public:
    static int getEntry();

    Tournament();
    void printAllPlayers();
    void registerPlayers();
    void startRound();
    void continueRound();
    void exitProgram();
    void tournamentMenu();
    void menuSelect(int choice);
    std::vector<std::shared_ptr<Player>> getListOfPlayers();
    std::vector<std::shared_ptr<Round>> getListOfRounds();
    std::string getTournamentName();


    //BELOW ARE QT SPECIFIC FUNCTIONS FOR TOURNAMENT

    void registerPlayer(std::shared_ptr<Player> player);
    void registerPlayer(QString name);
    int getTournamentSize();
    QString getPlayerName(int x);
    int getNumberOfPlayers();


}; //end Tournament class

#endif //TOURNAMENT_H
