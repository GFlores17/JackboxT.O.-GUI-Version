#include "Round.h"
#include "Match.h"
#include "Player.h"
#include "GetEntry.h"
#include <fstream>
#include <QDebug>
#include <sstream>
#include <QDir>
#include <QDirIterator>
#include <QFileInfo>

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

void Round::deletePlayer(int x){
    playersInRound.at(x).reset();
    playersInRound.erase(playersInRound.begin() + x);
}

void Round::menu() {
    std::cout << std::endl;
    std::cout << "1. Start New Match." << std::endl;
    std::cout << "2. Continue Match." << std::endl;
    std::cout << "3. Main Menu." << std::endl;
}

void Round::deleteAllPlayers(){

    for(int i = 0; i < playersInRound.size(); i++){
        playersInRound.at(i).reset();
    }
    playersInRound.clear();
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


void Round::setName(std::string &name){
    this->roundName = name;
}

std::vector <std::shared_ptr<Match>> Round::getListOfMatches(){
    return listOfMatches;
}

int Round::getNumberOfPlayers(){
    return getRoundListOfPlayers().size();
}

void Round::serializeRound(QString tournamentFolderPath){
    QString roundFolderPath = createRoundFolder(tournamentFolderPath);
    //Append to the path to create a new directory.
    //Ex "C:/Tournament1" + "/" + "Round1"

    serializeRoundName(roundFolderPath);
    serializeRoundPlayers(roundFolderPath);
    QString matchesPath = createMatchesFolder(roundFolderPath);

    for(int i = 0; i < listOfMatches.size(); i++){
        listOfMatches.at(i)->serializeMatch(matchesPath);
    }
}

QString Round::createRoundFolder(QString roundPath){
    roundPath = roundPath + QString::fromStdString(this->roundName) + "/";

    if(QDir(roundPath).exists() == false){
        QDir().mkdir(roundPath);
    }

    return roundPath;
}

void Round::serializeRoundName(QString path){
    QString newFile = path + "RoundName" +  + ".txt";

    if(QFileInfo(newFile).exists() == 0){

        QFile file(newFile);
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << QString::fromStdString(this->roundName);
    }
    else{

    }
}


void Round::serializeRoundPlayers(QString path){
    QString newFile = path + "RoundPlayers" +  + ".txt";

    if(QFileInfo(newFile).exists() == 0){

        QFile file(newFile);
        for(int i =0; i<playersInRound.size();i++){
            playersInRound.at(i)->serializePlayer(file);
        }
    }
    else{

    }
}

QString Round::createMatchesFolder(QString path){
    QString matchesFolderPath = path + "Matches/";
    //Append to the path to create a new directory.
    //Ex "C:/Tournament1" + "/" + "Round1"


    if(QDir(matchesFolderPath).exists() == false){
        QDir().mkdir(matchesFolderPath);
        //serializeRoundName(roundPath);
        //serializeRoundPlayers(roundPath);
    }
    else{
        //does nothing for now.
    }

    return matchesFolderPath;
}


void Round::deserializeRoundName(QString path){
    QDir rootdir(path);
    QDirIterator it(rootdir);

    while (it.hasNext()) {
        QFileInfo file = it.next();

        if(file.fileName() == "RoundName.txt"){



            QFile roundNameFile(file.absoluteFilePath());

            roundNameFile.open(QIODevice::ReadOnly);

            QTextStream in(&roundNameFile);

            QString readline = in.readLine();

            std::string newName = readline.toStdString();
            this->setName(newName);
            //roundNameFile.remove();
            break;
        }

    }

}


void Round::deserializeRoundPlayers(QString path, std::vector<std::shared_ptr<Player>> tournamentPlayersArray){ 
    QDir rootdir(path);
    QDirIterator it(rootdir);



    while (it.hasNext()) {
        QFileInfo file = it.next();

        if(file.fileName() == "RoundPlayers.txt"){

            QFile roundPlayersFile(file.absoluteFilePath());
            roundPlayersFile.open(QIODevice::ReadOnly);
            QTextStream in(&roundPlayersFile);

            while(!in.atEnd()){

                std::string playerName = in.readLine().toStdString();

                std::string stringPlayerScore = in.readLine().toStdString();


                std::stringstream ss(stringPlayerScore);
                int intPlayerScore;
                ss >> intPlayerScore;

                //Block below makes it so a player deserialized in round is cross referenced with an existing player in the tournamentPlayers array, and their shared_pointers
                //are made to point to the same object.

                for(int i = 0; i < tournamentPlayersArray.size(); i++){
                    if(playerName==tournamentPlayersArray.at(i)->getName()){
                        std::shared_ptr<Player>newPlayer = tournamentPlayersArray.at(i);
                        addPlayer(newPlayer);
                        break;
                    }//Check for matching player pointer in tournament roster.
                }//End for loop()
            }//EOF reached.
            //roundPlayersFile.remove();
        }
        else{
        }
    }
}

void Round::deserializeAllMatches(QString path){
    path = path + "/Matches/";

    QDir matchesFolder(path);
    //Assign path to a QDir.

    QDirIterator it(matchesFolder);
    //Iterate through QDir.

    while (it.hasNext()) {//While rounds folder has rounds in it.
        QFileInfo INFILE = it.next();
        QString path = INFILE.absoluteFilePath();

        std::shared_ptr<Match> newMatch = std::make_shared<Match>();
        newMatch->deserializeMatchName(path);
        newMatch->deserializeMatchPlayers(path, this->getRoundListOfPlayers());
        newMatch->deserializeAllGames(path);

        if(newMatch->getName() != "default match constructor"){
            //this is in place until I can figure out why there are ghost directories inside the tournament directories.
            this->addMatch(newMatch);
        }

    }//end while
}//end method()

