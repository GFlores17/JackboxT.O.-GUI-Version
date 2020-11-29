#include "Round.h"
#include "Match.h"
#include "Player.h"
#include "GetEntry.h"

int Round::getEntry() {
    int choice;
    std::cin >> choice;
    checkIfInt(choice);

    while (choice < 1 || choice > 3) {
        std::cout << "invalid option. retry now." << std::endl;
        std::cin >> choice;
        checkIfInt(choice);
    }
    std::cout << std::endl;
    return choice;
}

std::string roundName;
std::vector <std::unique_ptr<Match>> listOfMatches;
std::vector <std::shared_ptr<Player>> playersInRound;

Round::Round() {//Constructor
    this->roundName = "default";
}

Round::Round(std::string name){
    this->roundName = name;
}

void Round::menu() {
    std::cout << std::endl;
    std::cout << "1. Start New Match." << std::endl;
    std::cout << "2. Continue Match." << std::endl;
    std::cout << "3. Main Menu." << std::endl;
}

void Round::menuSelect(int choice) {
    switch (choice) {
    case 1: //Start round, create players.
        //addMatch();
        menu();
        menuSelect(getEntry());
        break;

    case 2:
        //selectMatch();
        menu();
        menuSelect(getEntry());
        break;

    case 3: //Exit program.
        //exitProgram();
        break;

    default:
        std::cout << "invalid option. retry now." << std::endl;
        menu();
        menuSelect(getEntry());
    }// end switch statement

}//end menuSelect

std::vector <std::shared_ptr<Player>> Round::getRoundListOfPlayers(){
    return playersInRound;
}

QString Round::getRoundName(){
    return QString::fromStdString(roundName);
}

void Round::addRound(std::shared_ptr<Round> r){

}

void Round::addPlayer(std::shared_ptr<Player> p){
    playersInRound.push_back(std::move(p));
}

void Round::addMatch(std::shared_ptr<Match> m){
    listOfMatches.push_back(std::move(m));
}

std::vector <std::shared_ptr<Match>> Round::getListOfMatches(){
    return listOfMatches;
}

int Round::getNumberOfPlayers(){
    return getRoundListOfPlayers().size();
}
