#include "round.h"
#include "match.h"
#include "player.h"
#include "getEntry.h"

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
    std::cout << "Enter round name.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, roundName);
    std::cout << "-------------------------------" << "[" << roundName << "]" << "-------------------------------" << std::endl;
    //Set name.

    menu();
    menuSelect(getEntry());
}

Round::Round(std::vector <std::shared_ptr<Player>>& playersInTournament) {//Test function.
    setRoundName();
    printName();

    addPlayer(playersInTournament);
    menu();
    menuSelect(getEntry());
}

std::string Round::getName() {
    return roundName;
}

void Round::setRoundName() {
    std::cout << "Enter round name.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, roundName);
}

void Round::printName() {
    std::cout << "-------------------------------" << "[" << roundName << "]" << "-------------------------------" << std::endl;
}

void Round::addPlayer(std::vector<std::shared_ptr<Player>>& playersInTournament) {
    if (playersInTournament.size() == 0) {
        std::cout << "Empty Tournament. No players to add.\n";
    }

    else {//If tournament has players.
        std::cout << "How many players to add?\n";
        int numOfPlayers;
        std::cin >> numOfPlayers;
        checkIfInt(numOfPlayers);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //Prepare for getline().

        for (int i = 0; i < numOfPlayers; i++) {
            std::cout << "Name of player to add?\n";
            std::string player;
            std::getline(std::cin, player);

            int placement;
            placement = binaryStringSearch(playersInTournament, player, playersInTournament.size());
            //Returns index of player in listOfAllPlayers if it does exist.

            if (placement < 0) {
                std::cout << "Invalid player.\n\n";
            }
            else {
                playersInRound.emplace_back(playersInTournament.at(placement));
                std::cout << "Added successfully.\n\n";
                //Push a copy of a player pointer from playersInTournament to playersInRound.
            }
        }//end Big If/Else.
    }//end for loop

    printPlayers();
    //Confirming Players In Round.
}

void Round::printPlayers() {
    for (int i = 0; i < playersInRound.size(); i++) {
        playersInRound.at(i)->print();
    }
}

void Round::checkIfMatchInRange(int& choice) {
    while (choice < 1 || choice > listOfMatches.size()) {
        std::cout << "Match not in range. Try again.\n";
        std::cin >> choice;
        checkIfInt(choice);
    }
}

void Round::addMatch() {
    std::cout << "Name of Match?\n";
    std::string name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    std::shared_ptr<Match> m = std::make_shared<Match>(name);
    listOfMatches.push_back(move(m));

}//end of addMatch

void Round::viewMatches() {
    std::cout << "-------------------------------" << "[" << roundName << "]" << "-------------------------------" << std::endl;
    std::cout << "-------------------------------" << "[DISPLAYING MATCHES]" << "-------------------------------" << std::endl;
    for (int i = 0; i < listOfMatches.size(); i++) {
        std::cout << i + 1 << ". | " << listOfMatches.at(i)->getName() << "\n";
    }
}

void Round::selectMatch() {
    if (listOfMatches.size() == 0) {
        std::cout << "There are no matches yet.\n";
    }

    else {
        viewMatches();
        std::cout << "Which match would you like to access?" << std::endl;
        int choice;
        std::cin >> choice;

        checkIfInt(choice);
        checkIfMatchInRange(choice);

        --choice;
        listOfMatches.at(choice)->menu();
        listOfMatches.at(choice)->menuSelect(getEntry());
    }
}

void Round::exitProgram() {
    std::cout << "-----------[MAIN MENU]-----------" << std::endl;
    //Switch statement does repeat after this.
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
        addMatch();
        menu();
        menuSelect(getEntry());
        break;

    case 2:
        selectMatch();
        menu();
        menuSelect(getEntry());
        break;

    case 3: //Exit program.
        exitProgram();
        break;

    default:
        std::cout << "invalid option. retry now." << std::endl;
        menu();
        menuSelect(getEntry());
    }// end switch statement

}//end menuSelect

