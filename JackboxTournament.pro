QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddMatchDialog.cpp \
    AddPlayerToGame.cpp \
    AddPlayerToMatchDialog.cpp \
    AddToRoundDialog.cpp \
    EnterGameResults.cpp \
    EnterTournamentName.cpp \
    Game.cpp \
    MainMenu.cpp \
    MainWindow.cpp \
    Match.cpp \
    MatchMenu.cpp \
    MatchNameDialog.cpp \
    Player.cpp \
    PlayerRegistrationDialog.cpp \
    PromptAddToRoundDialog.cpp \
    PromptGameNameDialog.cpp \
    Round.cpp \
    RoundMenu.cpp \
    RoundNameDialog.cpp \
    SelectRoundDialog.cpp \
    Tournament.cpp \
    TournamentMenu.cpp \
    TournamentRoster.cpp \
    getEntry.cpp \
    main.cpp

HEADERS += \
    AddMatchDialog.h \
    AddPlayerToGame.h \
    AddPlayerToMatchDialog.h \
    AddToRoundDialog.h \
    EnterGameResults.h \
    EnterTournamentName.h \
    Game.h \
    GetEntry.h \
    MainMenu.h \
    MainWindow.h \
    Match.h \
    MatchMenu.h \
    MatchNameDialog.h \
    Player.h \
    PlayerRegistrationDialog.h \
    PromptAddToRoundDialog.h \
    PromptGameNameDialog.h \
    Round.h \
    RoundMenu.h \
    RoundNameDialog.h \
    SelectRoundDialog.h \
    Tournament.h \
    TournamentMenu.h \
    TournamentRoster.h

FORMS += \
    AddMatchDialog.ui \
    AddPlayerToGame.ui \
    AddPlayerToMatchDialog.ui \
    AddToRoundDialog.ui \
    EnterGameResults.ui \
    EnterTournamentName.ui \
    MainMenu.ui \
    MatchMenu.ui \
    MatchNameDialog.ui \
    PromptAddToRoundDialog.ui \
    PromptGameNameDialog.ui \
    RoundNameDialog.ui \
    SelectRoundDialog.ui \
    mainwindow.ui \
    playerRegistrationDialog.ui \
    roundMenu.ui \
    tournamentMenu.ui \
    tournamentRoster.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ImagesInProgram.qrc
