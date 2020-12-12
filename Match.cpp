#include "Match.h"
#include "Game.h"
#include "GetEntry.h"
#include <memory>
#include <fstream>
#include <QDebug>
#include <sstream>
#include <QDir>

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

void Match::serializeMatch(std::ofstream &OUTFILE){
    try{
    //std::ofstream OUTFILE;
    //OUTFILE.open("C:\\Users\\George\\Desktop\\match.txt", std::ios_base::app);

    OUTFILE << "MATCHNAME" << "\n";
    std::string name;
    name = this->getName();
    //QString qName = QString::fromStdString(name);

    OUTFILE << this->getName() << "\n";


    qDebug() << "NUMBER OF GAMES IN MATCH" << this->listOfGames.size();
    int size = this->listOfGames.size();

    for(int i = 0; i < this->getListOfGames().size(); i++){
        this->listOfGames.at(i)->serializeGame(OUTFILE);
    }

    }

    catch(int e){

    }

}


void Match::deserializeMatch(){
    std::ifstream INFILE;
    INFILE.open("C:\\Users\\George\\Desktop\\match.txt", std::ios::in);

    std::string delayLine;

    std::string newMatchName;
    getline(INFILE, newMatchName);
    this->matchName = newMatchName;
    qDebug() << "MATCH NAME : " << QString::fromStdString(this->matchName);

    //std::string delayLine;
    getline(INFILE, delayLine);

    bool playersWrite = false;
    bool resultsWrite = false;
    bool gameNameWrite = true;

    //std::string matchName;
    //getline(INFILE, matchName);

    while(!INFILE.eof()){
            std::shared_ptr<Game>g = std::make_shared<Game>();

            while(gameNameWrite == true){
                std::string gameName;
                getline(INFILE, gameName);

                if(gameName.compare("PLAYERSLIST") == 0){
                    gameNameWrite = false;
                    playersWrite = true;
                    qDebug() << "NAME == PLAYERSLIST\n";
                    break;
                }


                g->setName(gameName);
                qDebug() << "GAME NAME : " << QString::fromStdString(g->getName()) << "\n";
            }

            while(playersWrite == true){
                std::string name;
                std::string stringTotalScore;

                getline(INFILE,name);

                if(name.compare("GAMERESULT")==0){
                    playersWrite = false;
                    resultsWrite = true;
                    qDebug() << "NAME == GAMERESULT\n";
                    break;
                }

                getline(INFILE,stringTotalScore);

                std::stringstream stringToIntConverter(stringTotalScore);
                //Convert the score saved as string to int.

                int intTotalScore;
                stringToIntConverter >> intTotalScore;
                //Store converted score in int variable.

                std::shared_ptr<Player> p = std::make_shared<Player>(name);
                p->setScore(intTotalScore);

                qDebug() << "NAME : " << p->getQName() << "| SCORE : " << QString::number(p->getScore()) << "\n";

                g->addPlayerToGame(p);
            }

            while(resultsWrite == true){
                qDebug() << "START RESULTWRITE\n";
                std::pair<std::string,int> gameResult;

                std::string name;
                std::string stringGameScore;

                getline(INFILE,name);

                if(name.compare("GAMENAME")==0){
                    resultsWrite = false;
                    gameNameWrite = true;
                    break;
                }

                if(INFILE.eof()){
                    qDebug() << "BREAK" << "\n";
                    break;
                }

                getline(INFILE,stringGameScore);

                std::stringstream stringToIntConverter(stringGameScore);

                int intGameScore;
                stringToIntConverter >> intGameScore;

                //std::pair<std::string,int> gameResult = std::make_pair(name, intGameScore);
                //results = std::make_pair<std::string,int> gameResult (name, intGameScore);

                gameResult = std::make_pair(name, intGameScore);

                qDebug() << "RESULT" << QString::fromStdString(name) << " : " << QString::fromStdString(stringGameScore) << "\n";
                g->insertResult(gameResult);
                qDebug() << "RESULT INSERTED" << "\n";
            }

            this->addGame(g);
            qDebug() << "ADDED\n";
            qDebug() << "GAMES IN MATCH : " << this->getListOfGames().size() << "\n";
    }//end EOF.
}//end deserialize

void Match::serializeUsingQDir(QString roundFolderPath){
    QString matchFolder = createMatchFolder(roundFolderPath);
    //Append to the path to create a new directory.
    //Ex "C:/Tournament1" + "/" + "Round1"

    serializeMatchName(matchFolder);
    serializeMatchPlayers(matchFolder);
    QString gamesFolderPath = createGamesFolder(matchFolder);

    for(int i = 0; i < listOfGames.size(); i++){
        listOfGames.at(i)->serializeUsingQDir(gamesFolderPath);
    }
}

QString Match::createMatchFolder(QString path){
    QString matchPath = path + QString::fromStdString(this->matchName) + "/";

    if(QDir(matchPath).exists() == false){
        QDir().mkdir(matchPath);
        qDebug() << matchPath << "CREATED\n";
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

    qDebug() << gamesFolderPath << "\n";

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

