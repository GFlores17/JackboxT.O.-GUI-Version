#define NOMINMAX
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <limits>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <QtDebug>
#include <QDirIterator>
#include <QFileInfo>
#include <QStandardPaths>
//these two headers are already included in the <Windows.h> header

#include "Round.h"
#include "Match.h"
#include "Player.h"
#include "Tournament.h"
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
        tournamentName = "Default Tournament Constructor";
    }

    Tournament::Tournament(std::string &name){
        this->tournamentName = name;
    }

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

    void Tournament::setName(std::string &name){
        this->tournamentName = name;
    }

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

    void Tournament::addRound(std::shared_ptr<Round> roundToAdd){
        listOfRounds.push_back(std::move(roundToAdd));
    }

    std::shared_ptr<Round> Tournament::getRound(int x){
        return listOfRounds.at(x);
    }

    void Tournament::serializeTournament(){
        try{
        std::ofstream OUTFILE;
        OUTFILE.open("C:\\Users\\George\\Desktop\\tournament.txt");


        OUTFILE << "TOURNAMENT NAME" << "\n";
        std::string name;
        name = this->tournamentName;
        //QString qName = QString::fromStdString(name);

        OUTFILE << name << "\n";


        qDebug() << "NUMBER OF Rounds IN Tournament" << this->listOfRounds.size();
        int size = this->listOfRounds.size();

        for(int i = 0; i < this->listOfRounds.size(); i++){
           this->listOfRounds.at(i)->serializeRound(OUTFILE);
        }

        }

        catch(int e){

        }
    }

    void Tournament::deserializeTournament(){
        std::ifstream INFILE;
        INFILE.open("C:\\Users\\George\\Desktop\\tournament.txt", std::ios::in);

        std::string delayLine;
        getline(INFILE, delayLine);

        std::string newTournamentName;
        getline(INFILE, newTournamentName);
        //this->
        //this->setName(newRoundName);

        //qDebug() << "ROUND NAME : " << QString::fromStdString(this->roundName);

        bool playersWrite = false;
        bool resultsWrite = false;
        bool gameNameWrite = false;
        bool matchNameWrite = false;
        bool roundNameWrite = true;
        bool newMatch = false;
        bool newRound = true;

        getline(INFILE, delayLine);

        while(!INFILE.eof()){

            std::shared_ptr<Round> createdRound = std::make_shared<Round>();
            qDebug() << "NEW ROUND CREATED\n";
            newRound = false;

            while(roundNameWrite == true){
                std::string roundName;
                getline(INFILE, roundName);

                if(roundName.compare("MATCHNAME") == 0){
                    roundNameWrite = false;
                    matchNameWrite = true;
                    qDebug() << "NAME == ROUNDNAME\n";
                    break;
                }//end if

                createdRound->setName(roundName);
            }

            while(newRound == false){

                std::shared_ptr<Match> createdMatch = std::make_shared<Match>();
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

                    createdMatch->setName(matchName);
                }//end matchNameWrite while loop.

                qDebug() << "ENTERING newMatch LOOP\n";

                while(newMatch == false){

                    std::shared_ptr<Game>g = std::make_shared<Game>();
                    qDebug() << "NEW GAME CREATED\n";

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

                        if(name.compare("ROUNDNAME")==0){
                            resultsWrite = false;
                            roundNameWrite = true;
                            newMatch = true;
                            newRound = true;
                            //this->addRound(createdRound);
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
                            newRound = true;
                            break;

                            //There are no more rounds to
                            //create, exit all inner loops
                            //and allow the outer while loop
                            //(while !INFILE.eof()) to terminate.
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

                    createdMatch->addGame(g);


                }//end while newMatch == false;

                createdRound->addMatch(createdMatch);
                this->deserializeRoundPlayers(createdRound);

            }//end while newRound == false;
            this->addRound(createdRound);
        }//end EOF
    }



    void Tournament::deserializeTournamentPlayers(){
        std::ifstream INFILE;
        INFILE.open("C:\\Users\\George\\Desktop\\people.txt", std::ios::in);

        std::vector<std::shared_ptr<Player>> vec;

       while(!INFILE.eof()){
            std::string name;
            std::string tScore;

            getline(INFILE,name);
            getline(INFILE,tScore);

            std::stringstream degree(tScore);

            int score;
            degree >> score;

            //getline(INFILE,name);


            std::shared_ptr<Player> p = std::make_shared<Player>(name);
            p->setScore(score);

            listOfAllPlayers.push_back(std::move(p));
        };
       listOfAllPlayers.erase(listOfAllPlayers.begin() + listOfAllPlayers.size()-1);
    }

    void Tournament::serializeAllRoundPlayers(){
        for(int i = 0; i < this->listOfRounds.size();i++){
            this->listOfRounds.at(i)->serializePlayersInRound();
        }
    }

    void Tournament::deserializeRoundPlayers(std::shared_ptr<Round> createdRound){
        QDirIterator it("C:/Users/George/Desktop/SampleRounds/", QDirIterator::Subdirectories);

        while (it.hasNext()) {
            QFileInfo fi = it.next();
            qDebug() << "fi : " << fi << "\n";
            QString base = fi.baseName();
            if(base.compare(createdRound->getRoundName())==0){//If we find the rounds corresponding file of players in C:/Users/George/Desktop/SampleRounds/"
                qDebug() << "FOUND ROUND FILE\n";
                qDebug() << fi << "\n";
                std::ifstream INFILE;
                base = fi.absoluteFilePath();
                INFILE.open(base.toStdString());
                createdRound->deserializePlayersInRound(INFILE);
                break;
            }
        }
    }

    void Tournament::serializeUsingQDir(){
        QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        path = path + "/JBT Saved Tournaments/";
        //qDebug() << path << "CREATED\n";
        //Create a folder to store all tournaments saved by the program if one is not created already.

        if(QDir(path).exists() == false){
            QDir().mkdir(path);
            qDebug() << path << "CREATED\n";
            //If the folder at the path does not exist yet, create 1.
        }
        //Realistically, this step should be done in the "Start Tournament" button of the main window, but I'll fix that later.

        path = this->createTournamentFolder(path);
        this->serializeTournamentName(path);
        this->serializeTournamentPlayers(path);
        QString roundsFolderPath = this->createRoundsFolder(path);

        for(int i = 0; i < this->listOfRounds.size(); i++){
            this->listOfRounds.at(i)->serializeUsingQDir(roundsFolderPath);
        }

    }//end serializeUsingQDir

    void Tournament::serializeTournamentName(QString path){
        QString newFile = path + "/TournamentName" +  + ".txt";

        if(QFileInfo(newFile).exists() == 0){

            QFile file(newFile);
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            out << QString::fromStdString(this->tournamentName);
        }
        else{

        }
    }//end serializeTournamentName

    QString Tournament::createTournamentFolder(QString path){
        path = path + QString::fromStdString(this->tournamentName) + "/";

        if(QDir(path).exists() == false){
            QDir().mkdir(path);
            qDebug() << "TOURNAMENT FOLDER\n";
            qDebug() << path << "CREATED\n";
            //Create a folder for the newly created tournament.
        }
        ;
        return path;
    }//end createTournamentFolder();

    void Tournament::serializeTournamentPlayers(QString path){
        QString newFile = path + "/TounamentPlayers" +  + ".txt";

        if(QFileInfo(newFile).exists() == 0){

            QFile file(newFile);
            for(int i =0; i<listOfAllPlayers.size();i++){
                listOfAllPlayers.at(i)->serializePlayer(file);
            }
        }
        else{

        }
    }//end serializeTournamentPlayers();

    QString Tournament::createRoundsFolder(QString path){
        QString roundFolderPath = path + "Rounds/";

        if(QDir(roundFolderPath).exists() == false){
            QDir().mkdir(roundFolderPath);
            qDebug() << roundFolderPath << "CREATED";
        }
        else{
            //does nothing for now.
        }
        qDebug() << path << "CREATED\n";
        return roundFolderPath;
    }//end createRoundFolder()

    void Tournament::scoreSort(){

        Player player = Player("temp");
            Player* p = &player;
            for (int i = 0; i < listOfAllPlayers.size(); i++) {
                for (int j = i + 1; j < listOfAllPlayers.size(); j++) {
                    if (listOfAllPlayers.at(j)->getScore() > listOfAllPlayers.at(i)->getScore()) {
                        p->setName(listOfAllPlayers.at(i)->getName());
                        p->setScore(listOfAllPlayers.at(i)->getScore());

                        listOfAllPlayers.at(i)->setName(listOfAllPlayers.at(j)->getName());
                        listOfAllPlayers.at(i)->setScore(listOfAllPlayers.at(j)->getScore());

                        listOfAllPlayers.at(j)->setName(p->getName());
                        listOfAllPlayers.at(j)->setScore(p->getScore());
                    }
                }
            }
    }
