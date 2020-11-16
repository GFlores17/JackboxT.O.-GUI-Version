#include "match.h"
#include "Game.h"
#include "GetEntry.h"
#include <memory>

int Match::getEntry() {
    int choice;
    std::cin >> choice;
    checkIfInt(choice);

    while (choice < 1 || choice > 4) {
        std::cout << "invalid option. retry now." << std::endl;
        std::cin >> choice;
        checkIfInt(choice);
    }
    std::cout << std::endl;
    return choice;
}

std::string matchName;
std::vector<std::unique_ptr<Game>> listOfGames;

/*Match::Match()
{
    setMatchName();
    std::cout << "How many games in this match?\n";
    int numOfGames;
    std::cin >> numOfGames;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numOfGames; i++) {
        addGame(listOfGames.size() + 1);
    }

    menu();
    menuSelect(getEntry());
}*/

Match::Match() {
    std::cout << "Default Constructor do nothing.\n";
}

Match::Match(std::string name)
    : matchName(name)
{
    std::cout << "PASS NAME AS PARAMETER CONSTRUCTOR\n";
    std::cout << "How many games in this match?\n";
    int numOfGames;
    std::cin >> numOfGames;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < numOfGames; i++) {
        addGame(listOfGames.size()+1);
    }

    menu();
    menuSelect(getEntry());
}

void Match::printName() {
    std::cout << matchName << std::endl;
}

void Match::printResults() {
    std::cout << matchName << std::endl;
    for (int i = 0; i < listOfGames.size(); i++) {
        listOfGames.at(i)->printGameResults();
    }
}

std::string Match::getName() {
    return matchName;
}

void Match::setMatchName() {
    std::cout << "Enter match name.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, matchName);
}

/*void Match::addGame() {
    std::unique_ptr<Game> createdGame = std::make_unique<Game>();
    listOfGames.push_back(move(createdGame));
    std::cout << "Successfully added\n";
}*/

void Match::addGame() {
    std::shared_ptr<Game> createdGame = std::make_shared<Game>();
    listOfGames.push_back(move(createdGame));
}//end addGames();

void Match::addGame(int num) {
    std::shared_ptr<Game> createdGame = std::make_shared<Game>(num);
    listOfGames.push_back(move(createdGame));
}//end addGames();

void Match::viewGamesResults() {
    for (int i = 0; i < listOfGames.size(); i++) {
        if (listOfGames.at(i)->getMap().empty() == true) {
            std::cout << "----------[" << listOfGames.at(i)->getName() << "]----------\n";
            std::cout << "GAME NOT CONCLUDED\n\n\n";
        }
        else {
            std::cout << "----------[" << listOfGames.at(i)->getName() << "]----------\n";
            listOfGames.at(i)->printGameResults();
            std::cout << "\n\n";
        }
    }//end for loop
}//end viewGamesResults()

void Match::startGame() {
    std::cout << "How many players in game?" << std::endl;
    int num;
    std::cin >> num;

}

void Match::enterGameResults() {
    printGames();
    std::cout << "Which game has ended?" << std::endl;
    int game;
    std::cin >> game;
    checkIfInt(game);
    while (game < 1 || game > listOfGames.size()) {
        std::cout << "Game does not exist, try again." << std::endl;
        std::cin >> game;
        checkIfInt(game);
    }
    --game;
    listOfGames.at(game)->addPlayerToGame();
    //Above is test line. Fix addPlayerToGame later by checking with match vector.
    listOfGames.at(game)->setGameResults();
}

void Match::printGames() {
    for (int i = 0; i < listOfGames.size(); i++) {
        std::cout << "| " << i + 1 << ". | " << listOfGames.at(i)->getName() << " | \n";
    }
}

void Match::menu() {
    std::cout << "----------[" << this->matchName << "]----------\n";
    std::cout << "----------[Match Menu]----------\n";
    std::cout << "1. Add Game to Match.\n"
        << "2. Enter Game Results.\n"
        << "3. View Game Results.\n"
        << "4. Round Menu.\n";
}

void Match::exitProgram() {
    std::cout << "Exiting match." << std::endl;
}

void Match::menuSelect(int choice) {
    switch (choice) {
    case 1: //Start round, create players.
        addGame(listOfGames.size()+1);
        menu();
        menuSelect(getEntry());
        break;

    case 2:
        enterGameResults();
        menu();
        menuSelect(getEntry());
        break;

    case 3:
        viewGamesResults();
        menu();
        menuSelect(getEntry());
        break;

    case 4: //Exit program.
        exitProgram();
        break;

    default:
        std::cout << "invalid option. retry now." << std::endl;
        menu();
        menuSelect(getEntry());
    }// end switch statement

}//end menuSelect
