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

#include "Game.h"
#include "Match.h"
#include "Player.h"
#include "Round.h"
#include "GetEntry.h"

class Tournament {

private:
    std::string tournamentName;
    std::vector<std::shared_ptr<Player>> listOfAllPlayers;
    std::vector<std::shared_ptr<Round>> listOfRounds;

public:
    static int getEntry();

    Tournament();
    Tournament(std::string &name);
    std::vector<std::shared_ptr<Player>> getListOfPlayers();
    std::vector<std::shared_ptr<Round>> getListOfRounds();
    std::string getTournamentName();
    void setName(std::string &name);

    //BELOW ARE QT SPECIFIC FUNCTIONS FOR TOURNAMENT

    void registerPlayer(std::shared_ptr<Player> player);
    int getTournamentSize();
    QString getPlayerName(int x);
    int getNumberOfPlayers();
    void addRound();
    void addRound(QString roundName);
    void addRound(std::shared_ptr<Round> roundToAdd);

    std::shared_ptr<Round> getRound(int x);


    void deserializeTournament(QString folder_name);
    void deserializeTournamentName(QString path);
    void deserializeTournamentPlayers(QString path);
    void deserializeAllRounds(QString path);

    void serializeTournament();
    QString createTournamentFolder(QString path);
    void serializeTournamentPlayers(QString path);
    void serializeTournamentName(QString path);
    QString createRoundsFolder(QString path);

    void scoreSort();
}; //end Tournament class

#endif //TOURNAMENT_H
