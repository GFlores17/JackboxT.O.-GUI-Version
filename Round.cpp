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


void Round::setName(std::string &name){
    this->roundName = name;
}

std::vector <std::shared_ptr<Match>> Round::getListOfMatches(){
    return listOfMatches;
}

int Round::getNumberOfPlayers(){
    return getRoundListOfPlayers().size();
}

void Round::serializePlayersInRound(){


    std::ofstream OUTFILE;
    qDebug() << "PLAYERS IN ROUND : " << this->playersInRound.size() << "\n";

    for(int i = 0; i < this->playersInRound.size(); i++){
        std::string filePath = "C:\\Users\\George\\Desktop\\SampleRounds\\" + this->roundName + ".txt";
        OUTFILE.open(filePath);

        qDebug() << "SAVED\n";

        OUTFILE << this->playersInRound.at(i)->getName() << "\n";
        OUTFILE << this->playersInRound.at(i)->getScore() << "\n";
    }
    OUTFILE.close();
}

void Round::deserializePlayersInRound(){

    QDirIterator it("C:/Users/George/Desktop/SampleRounds/", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        qDebug() << it.next();

        std::string fileName = it.fileName().toStdString();

        std::ifstream INFILE;
        INFILE.open(fileName, std::ios::in);

        while(!INFILE.eof()){
            std::string name;
            std::string tScore;

            getline(INFILE,name);

            /*
             * if(INFILE.eof()){
                break;
            }
            */

            getline(INFILE,tScore);

            std::stringstream degree(tScore);

            int score;
            degree >> score;

            //getline(INFILE,name);


            std::shared_ptr<Player> p = std::make_shared<Player>(name);
            p->setScore(score);

            this->addPlayer(p);
        }
    this->playersInRound.erase(this->playersInRound.begin() + this->playersInRound.size()-1);
    //The program always adds 1 extra blank player pointer for some reason. Just delete the dead data at the end
    //until you learn why.
    //this->getRoundListOfPlayers().erase(this->getRoundListOfPlayers().begin() + this->getRoundListOfPlayers().size()-1);
    }
}

void Round::serializeRound(std::ofstream &OUTFILE){
    try{
    //std::ofstream OUTFILE;
    //OUTFILE.open("C:\\Users\\George\\Desktop\\round.txt");


    OUTFILE << "ROUNDNAME" << "\n";
    std::string name;
    name = this->getRoundName().toStdString();
    //QString qName = QString::fromStdString(name);

    OUTFILE << name << "\n";


    qDebug() << "NUMBER OF MATCHES IN ROUND" << this->listOfMatches.size();
    int size = this->listOfMatches.size();

    for(int i = 0; i < this->listOfMatches.size(); i++){
       this->listOfMatches.at(i)->serializeMatch(OUTFILE);
    }



    }

    catch(int e){

    }

}
void Round::deserializeRound(){
    std::ifstream INFILE;
    INFILE.open("C:\\Users\\George\\Desktop\\round.txt", std::ios::in);

    std::string delayLine;
    getline(INFILE, delayLine);

    std::string newRoundName;
    getline(INFILE, newRoundName);
    this->setName(newRoundName);

    qDebug() << "ROUND NAME : " << QString::fromStdString(this->roundName);

    bool playersWrite = false;
    bool resultsWrite = false;
    bool gameNameWrite = false;
    bool matchNameWrite = true;
    bool newMatch = true;

    getline(INFILE, delayLine);

    while(!INFILE.eof()){


            std::shared_ptr<Match> m = std::make_shared<Match>();
            qDebug() << "NEW MATCH CREATED\n";
            newMatch = false;

            while(matchNameWrite == true){

                std::string matchName;
                getline(INFILE, matchName);

                if(matchName.compare("GAMENAME") == 0){
                    matchNameWrite = false;
                    gameNameWrite = true;
                    qDebug() << "NAME == GAMENAME\n";
                    break;
                }//end if

                m->setName(matchName);
            }//end matchNameWrite while loop.

            qDebug() << "ENTERING newMatch LOOP\n";

            while(newMatch == false){

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
                        qDebug() << "DUMB LINE TO CHECK\n";
                        resultsWrite = false;
                        gameNameWrite = true;
                        //m->addGame(g);
                        qDebug() << "GAMENAME==0, ADDING GAME\n";
                        break;
                    }

                    if(name.compare("MATCHNAME")==0){
                        resultsWrite = false;
                        matchNameWrite = true;
                        newMatch = true;
                        qDebug() << "Adding Match To Round\n";
                        //this->addMatch(m);
                        qDebug() << "Creating New Match\n";
                        break;
                    }

                    if(INFILE.eof()){
                        qDebug() << "BREAK" << "\n";
                        newMatch = true;
                        break;
                    }

                    getline(INFILE,stringGameScore);

                    std::stringstream stringToIntConverter(stringGameScore);

                    int intGameScore;
                    stringToIntConverter >> intGameScore;

                    gameResult = std::make_pair(name, intGameScore);

                    qDebug() << "RESULT" << QString::fromStdString(name) << " : " << QString::fromStdString(stringGameScore) << "\n";
                    g->insertResult(gameResult);
                    qDebug() << "RESULT INSERTED" << "\n";

                }//end ResultsWrite

                m->addGame(g);
                //this->addMatch(m);

                //qDebug() << "ADDED\n";
                qDebug() << "GAMES IN ROUND : " << this->getListOfMatches().size() << "\n";

            }//end while newMatch == false;
            this->addMatch(m);
    }//end EOF
}
