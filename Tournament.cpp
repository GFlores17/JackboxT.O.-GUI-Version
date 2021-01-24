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
#include <QTextStream>
#include <QStandardPaths>
//these two headers are already included in the <Windows.h> header

#include "Round.h"
#include "Match.h"
#include "Player.h"
#include "Tournament.h"
#include "GetEntry.h"

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

    void Tournament::deletePlayer(int x){
        listOfAllPlayers.at(x).reset();
        listOfAllPlayers.erase(listOfAllPlayers.begin() + x);
    }

    std::shared_ptr<Round> Tournament::getRound(int x){
        return listOfRounds.at(x);
    }

    void Tournament::serializeTournament(){
        QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        path = path + "/JBT Saved Tournaments/";
        //Create a folder to store all tournaments saved by the program if one is not created already.

        if(QDir(path).exists() == false){
            QDir().mkdir(path);
            //If the folder at the path does not exist yet, create 1.
        }
        //Realistically, this step should be done in the "Start Tournament" button of the main window, but I'll fix that later.

        path = this->createTournamentFolder(path);
        this->serializeTournamentName(path);
        this->serializeTournamentPlayers(path);
        QString roundsFolderPath = this->createRoundsFolder(path);

        for(int i = 0; i < this->listOfRounds.size(); i++){
            this->listOfRounds.at(i)->serializeRound(roundsFolderPath);
        }
    }

    QString Tournament::createTournamentFolder(QString path){
        path = path + QString::fromStdString(this->tournamentName) + "/";

        if(QDir(path).exists() == false){
            QDir().mkdir(path);
            //Create a folder for the newly created tournament.
        }
        return path;
    }//end createTournamentFolder();

    void Tournament::serializeTournamentName(QString path){
        QString newFile = path + "/TournamentName" +  + ".txt";

        if(QFileInfo(newFile).exists() == 0){

            QFile file(newFile);
            file.open(QIODevice::WriteOnly);
            QTextStream out(&file);
            out << QString::fromStdString(this->tournamentName);
            //file.remove();
        }
    }//end serializeTournamentName

    void Tournament::serializeTournamentPlayers(QString path){
        QString newFile = path + "/TournamentPlayers" +  + ".txt";

        QFile file(newFile);
        for(int i =0; i<listOfAllPlayers.size();i++){
            listOfAllPlayers.at(i)->serializePlayer(file);
        }

    }//end serializeTournamentPlayers();

    QString Tournament::createRoundsFolder(QString path){
        QString roundFolderPath = path + "Rounds/";

        if(QDir(roundFolderPath).exists() == false){
            QDir().mkdir(roundFolderPath);
        }

        return roundFolderPath;
    }//end createRoundFolder()


    void Tournament::deserializeTournament(QString folder_name){
        this->deserializeTournamentName(folder_name);
        this->deserializeTournamentPlayers(folder_name);
        this->deserializeAllRounds(folder_name);
    }

    void Tournament::deserializeTournamentName(QString path){
        QDir rootdir(path);
        QDirIterator it(rootdir);


        while (it.hasNext()) {
            QFileInfo file = it.next();

            if(file.fileName() == "TournamentName.txt"){


                QFile tournamentNameFile(file.absoluteFilePath());
                tournamentNameFile.open(QIODevice::ReadOnly);

                QTextStream in(&tournamentNameFile);

                QString readline = in.readLine();

                this->tournamentName = readline.toStdString();

                //tournamentNameFile.remove();
            }

        }//end while
    }

    void Tournament::deserializeTournamentPlayers(QString path){

        QDir rootdir(path);
        //Assign path to a QDir.

        QDirIterator it(rootdir);
        //Iterate through QDir.

        while (it.hasNext()) {//While file not found
            QFileInfo file = it.next();

            if(file.fileName() == "TournamentPlayers.txt"){
                QFile tournamentPlayersFile(file.absoluteFilePath());
                tournamentPlayersFile.open(QIODevice::ReadOnly);
                QTextStream in(&tournamentPlayersFile);

                while(!in.atEnd()){
                     std::string playerName = in.readLine().toStdString();

                     std::string stringPlayerScore = in.readLine().toStdString();


                     std::stringstream ss(stringPlayerScore);
                     int intPlayerScore;
                     ss >> intPlayerScore;

                     std::shared_ptr<Player> p = std::make_shared<Player>(playerName);
                     p->setScore(intPlayerScore);
                     registerPlayer(p);
                }//While loop deserializes all player objects in the text file.

                //tournamentPlayersFile.remove();

            }//end if(TournamentPlayers is found)
        }//end while
    }

    void Tournament::deserializeAllRounds(QString path){

        path = path + "/Rounds/";

        QDir roundsFolder(path);
        //Assign path to a QDir.

        QDirIterator it(roundsFolder);
        //Iterate through QDir.

        while (it.hasNext()) {//While rounds folder has rounds in it.
            QFileInfo INFILE = it.next();
            QString path = INFILE.absoluteFilePath();

            std::shared_ptr<Round> newRound = std::make_shared<Round>();
            newRound->deserializeRoundName(path);
            newRound->deserializeRoundPlayers(path, this->listOfAllPlayers);
            newRound->deserializeAllMatches(path);

            if(newRound->getRoundName().toStdString() != "default"){
                //this is in place until I can figure out why there are ghost directories inside the tournament directories.
                this->addRound(newRound);
            }

        }//end while
    }//end method()



