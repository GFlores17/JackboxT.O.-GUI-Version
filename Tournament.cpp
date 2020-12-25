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
    }

    QString Tournament::createTournamentFolder(QString path){
        path = path + QString::fromStdString(this->tournamentName) + "/";

        if(QDir(path).exists() == false){
            QDir().mkdir(path);
            qDebug() << "TOURNAMENT FOLDER\n";
            qDebug() << path << "CREATED\n";
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
        }
        else{

        }
    }//end serializeTournamentName

    void Tournament::serializeTournamentPlayers(QString path){
        QString newFile = path + "/TournamentPlayers" +  + ".txt";

        if(QFileInfo(newFile).exists() == 0){

            QFile file(newFile);
            for(int i =0; i<listOfAllPlayers.size();i++){
                listOfAllPlayers.at(i)->serializePlayer(file);
            }
        }
        else{
            QFile file(newFile);
            for(int i =0; i<listOfAllPlayers.size();i++){
                listOfAllPlayers.at(i)->serializePlayer(file);
            }
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


    void Tournament::deserializeTournament(QString folder_name){
        this->deserializeTournamentName(folder_name);
        //qDebug () << "T NAME : " << QString::fromStdString(T->getTournamentName()) << "\n";
        this->deserializeTournamentPlayers(folder_name);
        this->deserializeAllRounds(folder_name);
    }

    void Tournament::deserializeTournamentName(QString path){
        QDir rootdir(path);
        QDirIterator it(rootdir);

        //qDebug() << "CURRENT NAME" << QString::fromStdString(this->tournamentName);

        while (it.hasNext()) {
            QFileInfo file = it.next();

            if(file.fileName() == "TournamentName.txt"){

                //qDebug() << "found tournament name file\n";

                QFile TestFile(file.absoluteFilePath());
                TestFile.open(QIODevice::ReadOnly);

                QTextStream in(&TestFile);

                QString readline = in.readLine();

                //qDebug() << "READLINE : " << readline;
                this->tournamentName = readline.toStdString();
            }
            else{
                //qDebug() << "wrong file\n";
            }

        }//end while
        //qDebug() << "NEW NAME: " << QString::fromStdString(this->tournamentName) << "\n";
    }

    void Tournament::deserializeTournamentPlayers(QString path){

        QDir rootdir(path);
        //Assign path to a QDir.

        QDirIterator it(rootdir);
        //Iterate through QDir.

        while (it.hasNext()) {//While file not found
            QFileInfo file = it.next();

            if(file.fileName() == "TournamentPlayers.txt"){
                QFile TestFile(file.absoluteFilePath());
                //qDebug() << "FILE PATH" << file.absoluteFilePath() << "\n";
                TestFile.open(QIODevice::ReadOnly);
                QTextStream in(&TestFile);

                while(!in.atEnd()){
                     std::string playerName = in.readLine().toStdString();
                     //qDebug () << QString::fromStdString(playerName) << "\n";

                     std::string stringPlayerScore = in.readLine().toStdString();
                     //qDebug () << QString::fromStdString(stringPlayerScore) << "\n";


                     std::stringstream ss(stringPlayerScore);
                     int intPlayerScore;
                     ss >> intPlayerScore;

                     std::shared_ptr<Player> p = std::make_shared<Player>(playerName);
                     p->setScore(intPlayerScore);
                     registerPlayer(p);
                }
            }
        }//end while
    }

    void Tournament::deserializeAllRounds(QString path){

        path = path + "/Rounds/";

        QDir roundsFolder(path);
        //Assign path to a QDir.

        QDirIterator it(roundsFolder);
        //Iterate through QDir.

        if(roundsFolder.exists()){
            //qDebug() << roundsFolder << "exists. \n";
        }
        else{
            //qDebug() << "Where tf the folder\n";
        }

        while (it.hasNext()) {//While rounds folder has rounds in it.
            QFileInfo INFILE = it.next();
            QString path = INFILE.absoluteFilePath();
            //qDebug() << "SEARCHING IN : " << path << "\n";
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



