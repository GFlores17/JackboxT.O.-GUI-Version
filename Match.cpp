#include "Match.h"
#include "Game.h"
#include "GetEntry.h"
#include <memory>
#include <fstream>
#include <QDebug>
#include <sstream>
#include <QDir>
#include <QDirIterator>

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
std::vector<std::shared_ptr<Game>> listOfGames;
std::vector<std::shared_ptr<Player>> playersInMatch;

Match::Match()
{
    matchName = "default match constructor";
}

Match::Match(std::string name) {
    matchName = name;
}

Match::Match(QString name){
    matchName = name.toStdString();
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

void Match::deleteGame(int indexOfGame){
    listOfGames.at(indexOfGame).reset();
    listOfGames.erase(listOfGames.begin()+indexOfGame);
}

std::shared_ptr<Game> Match::getGame(int indexOfGame){
    return listOfGames.at(indexOfGame);
}
void Match::deletePlayer(int x){
    playersInMatch.at(x).reset();
    playersInMatch.erase(playersInMatch.begin()+x);
}

void Match::deleteAllPlayers(){

    /*
    for(int i = 0; i < playersInMatch.size(); i++){
        playersInMatch.at(i).reset();
    }
    */

    while(playersInMatch.empty() != true){
        playersInMatch.erase(playersInMatch.begin());
    }



}
void Match::setMatchName() {
    std::cout << "Enter match name.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, matchName);
}

void Match::setName(std::string &name){
    this->matchName = name;
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

void Match::addGame(std::shared_ptr<Game> g){
    this->listOfGames.push_back(std::move(g));
}

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
    //listOfGames.at(game)->addPlayerToGame();
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

std::vector<std::shared_ptr<Game>> Match::getListOfGames(){
    return listOfGames;
}

std::vector <std::shared_ptr<Player>> Match::getMatchListOfPlayers(){
    return playersInMatch;
}

void Match::addPlayer(std::shared_ptr<Player> p){
    playersInMatch.push_back(std::move(p));
}

int Match::getNumOfPlayers(){
    return playersInMatch.size();
}

void Match::serializeMatch(QString roundFolderPath){
    QString matchFolder = createMatchFolder(roundFolderPath);
    //Append to the path to create a new directory.
    //Ex "C:/Tournament1" + "/" + "Round1"

    serializeMatchName(matchFolder);
    serializeMatchPlayers(matchFolder);
    QString gamesFolderPath = createGamesFolder(matchFolder);

    for(int i = 0; i < listOfGames.size(); i++){
        listOfGames.at(i)->serializeGame(gamesFolderPath);
    }
}

QString Match::createMatchFolder(QString path){
    QString matchPath = path + QString::fromStdString(this->matchName) + "/";

    if(QDir(matchPath).exists() == false){
        QDir().mkdir(matchPath);
    }

    return matchPath;
}
void Match::serializeMatchName(QString path){
    QString newFile = path + "MatchName" +  + ".txt";

    if(QFileInfo(newFile).exists() == 0){

        QFile file(newFile);
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << QString::fromStdString(this->matchName);
    }
    else{

    }
}
void Match::serializeMatchPlayers(QString path){
    QString newFile = path + "MatchPlayers" +  + ".txt";

    if(QFileInfo(newFile).exists() == 0){

        QFile file(newFile);
        for(int i =0; i<playersInMatch.size();i++){
            playersInMatch.at(i)->serializePlayer(file);
        }
    }
    else{

    }
}
QString Match::createGamesFolder(QString path){
    QString gamesFolderPath = path + "Games/";
    //Append to the path to create a new directory.
    //Ex "C:/Tournament1" + "/" + "Round1"


    if(QDir(gamesFolderPath).exists() == false){
        QDir().mkdir(gamesFolderPath);
        //serializeRoundName(roundPath);
        //serializeRoundPlayers(roundPath);
    }
    else{
        //does nothing for now.
    }

    return gamesFolderPath;
}

void Match::deserializeMatchName(QString path){
    //QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    //path = path + "/JBT Saved Tournaments/Testes";
    QDir rootdir(path);
    QDirIterator it(rootdir);



    while (it.hasNext()) {
        QFileInfo file = it.next();

        if(file.fileName() == "MatchName.txt"){

            QFile matchNameFile(file.absoluteFilePath());
            matchNameFile.open(QIODevice::ReadOnly);
            QTextStream in(&matchNameFile);

            QString readline = in.readLine();
            std::string newName = readline.toStdString();
            this->setName(newName);

            //matchNameFile.remove();

            break;
        }

    }
}

void Match::deserializeMatchPlayers(QString path, std::vector<std::shared_ptr<Player>> roundPlayersArray){
    //QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    //path = path + "/JBT Saved Tournaments/Testes";
    QDir rootdir(path);
    QDirIterator it(rootdir);



    while (it.hasNext()) {
        QFileInfo file = it.next();

        if(file.fileName() == "MatchPlayers.txt"){

            QFile matchPlayersFile(file.absoluteFilePath());
            matchPlayersFile.open(QIODevice::ReadOnly);
            QTextStream in(&matchPlayersFile);

            while(!in.atEnd()){

                std::string playerName = in.readLine().toStdString();

                std::string stringPlayerScore = in.readLine().toStdString();


                std::stringstream ss(stringPlayerScore);
                int intPlayerScore;
                ss >> intPlayerScore;

                for(int i = 0; i < roundPlayersArray.size(); i++){
                    if(playerName==roundPlayersArray.at(i)->getName()){
                        std::shared_ptr<Player>newPlayer = roundPlayersArray.at(i);
                        addPlayer(newPlayer);
                        break;
                    }//Check for matching player pointer in tournament roster.
                }//End for loop()
            }//EOF reached.

            //matchPlayersFile.remove();
        }

    }
}

void Match::deserializeAllGames(QString path){
    path = path + "/Games/";

    QDir gamesFolder(path);
    //Assign path to a QDir.

    QDirIterator it(gamesFolder);
    //Iterate through QDir.

    while (it.hasNext()) {//While rounds folder has rounds in it.
        QFileInfo INFILE = it.next();
        QString path = INFILE.absoluteFilePath();

        std::shared_ptr<Game> newGame = std::make_shared<Game>();
        newGame->deserializeGameName(path);
        newGame->deserializeGamePlayers(path, this->getMatchListOfPlayers());
        newGame->deserializeGameResults(path);

        if(newGame->getName() != "default"){
            this->addGame(newGame);
        }

    }//end while
}
