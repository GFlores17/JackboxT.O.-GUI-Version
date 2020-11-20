#define NOMINMAX
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <limits>
#include <windows.h>
//these two headers are already included in the <Windows.h> header

#include "round.h"
#include "match.h"
#include "player.h"
#include "tournament.h"
#include "GetEntry.h"

    static void helloMessage() {
        std::cout << std::setfill(' ') << std::setw(45) << "***************************************************" << std::endl;
        std::cout << std::setfill(' ') << std::setw(33) << "Welcome to the" << std::endl << std::setfill(' ') << std::setw(39) << "JACKBOX TOURNAMENT MANAGER" << std::endl << std::setfill(' ') << std::setw(30) << "program." << std::endl;
        std::cout << std::setfill(' ') << std::setw(45) << "***************************************************" << std::endl << std::endl;

        std::cout << "This is a small scorekeeping software program written in C++\n";
        std::cout << "that allows the user to organize tournament play using 3 functions.\n\n";
    }

    int Tournament::getEntry() {
        int choice;
        std::cin >> choice;
        checkIfInt(choice);

        while (choice < 1 || choice > 5) {
            std::cout << "Invalid option. Try again." << std::endl;
            std::cin >> choice;
            checkIfInt(choice);
        }

        std::cout << std::endl;
        return choice;
    }

    std::string tournamentName;
    std::vector<std::shared_ptr<Player>> listOfAllPlayers;
    std::vector<std::shared_ptr<Round>> listOfRounds;

    Tournament::Tournament() {
        /*
        std::cout << "Please enter Tournament name.\n";
        std::getline(std::cin, tournamentName);
        std::cout << "--------------[" << tournamentName << "]--------------" << "\n";
        //Initialize name.

        tournamentMenu();
        menuSelect(getEntry());
        //Start tournament.
    }

    void Tournament::printAllPlayers() {
        if (listOfAllPlayers.size() == 0) {//If no people in tournament.
            std::cout << "ERROR : Empty Tournament. No players registered." << std::endl;
        }

        else {
            for (int i = 0; i < listOfAllPlayers.size(); i++) {//Print the names of all "Player" objects in the Tournament "arrayOfPlayers."
                listOfAllPlayers.at(i)->print();
            }

        }

        std::cout << std::endl;
        */
        tournamentName = "Default Constructor";
    }


    void Tournament::menuSelect(int choice) {
        /*
        switch (choice) {
        case 1: //Start round, create players.
            registerPlayers();

            //Remove these 2 eventually.
            nameSort(listOfAllPlayers);
            printAllPlayers();
            //^^

            tournamentMenu();
            menuSelect(getEntry());
            break;

        case 2: //Start next round.
            startRound();
            tournamentMenu();
            menuSelect(getEntry());
            break;

        case 3: //Continue Round
            continueRound();
            tournamentMenu();
            menuSelect(getEntry());
            break;

        case 4: //Print all registered players.
            scoreSort(listOfAllPlayers);
            printAllPlayers();
            tournamentMenu();
            menuSelect(getEntry());
            break;

        case 5: //Exit program.
            exitProgram();
            break;

        default:
            std::cout << "invalid option. retry now." << std::endl;
            menuSelect(getEntry());
        }// end switch statement

        */
    }//end menuSelect

    std::vector<std::shared_ptr<Player>> Tournament::getListOfPlayers(){
        return listOfAllPlayers;
    }

    std::vector<std::shared_ptr<Round>> Tournament::getListOfRounds(){
        return listOfRounds;
    }

    std::string Tournament::getTournamentName(){
        return tournamentName;
    }

    //BELOW ARE QT SPECIFIC FUNCTIONS FOR TOURNAMENT

    void Tournament::registerPlayer(std::shared_ptr<Player> player){
        listOfAllPlayers.push_back(std::move(player));
    }

    void Tournament::duplicatePlayer(std::shared_ptr<Player> player){
        listOfAllPlayers.emplace_back(player);
    }

    void Tournament::registerPlayer(QString name){
        std::string stdName = name.toStdString();
        std::shared_ptr<Player> p = std::make_shared<Player>(stdName);
        registerPlayer(p);
    }

    int Tournament::getTournamentSize(){
        return listOfAllPlayers.size();
    }

    QString Tournament::getPlayerName(int x){
        return listOfAllPlayers.at(x)->getQName();
    }

    int Tournament::getNumberOfPlayers(){
        return listOfAllPlayers.size();
    }

    void Tournament::addRound(){
        std::shared_ptr<Round>newRound = std::make_shared<Round>();
        listOfRounds.push_back(std::move(newRound));
    }

    void Tournament::addRound(QString roundName){
        std::shared_ptr<Round>newRound = std::make_shared<Round>(roundName.toStdString());
        listOfRounds.push_back(std::move(newRound));
    }

    std::shared_ptr<Round> Tournament::getRound(int x){
        return listOfRounds.at(x);
    }

