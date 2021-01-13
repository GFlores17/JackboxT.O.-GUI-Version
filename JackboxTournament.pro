QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddMatchDialog.cpp \
    AddPlayerToGameDialog.cpp \
    AddPlayerToMatchDialog.cpp \
    AddToRoundDialog.cpp \
    EditPlayerDialog.cpp \
    EnterGameResultsDialog.cpp \
    EnterTournamentNameDialog.cpp \
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
    SelectTournamentTypeDialog.cpp \
    Tournament.cpp \
    TournamentMenu.cpp \
    TournamentRoster.cpp \
    getEntry.cpp \
    main.cpp

HEADERS += \
    AddMatchDialog.h \
    AddPlayerToGameDialog.h \
    AddPlayerToMatchDialog.h \
    AddToRoundDialog.h \
    EditPlayerDialog.h \
    EnterGameResultsDialog.h \
    EnterTournamentNameDialog.h \
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
    SelectTournamentTypeDialog.h \
    Tournament.h \
    TournamentMenu.h \
    TournamentRoster.h

FORMS += \
    AddMatchDialog.ui \
    AddPlayerToGameDialog.ui \
    AddPlayerToMatchDialog.ui \
    AddToRoundDialog.ui \
    EditPlayerDialog.ui \
    EnterGameResultsDialog.ui \
    EnterTournamentNameDialog.ui \
    MainMenu.ui \
    MainWindow.ui \
    MainWindow.ui \
    MatchMenu.ui \
    MatchNameDialog.ui \
    PlayerRegistrationDialog.ui \
    PromptAddToRoundDialog.ui \
    PromptGameNameDialog.ui \
    RoundMenu.ui \
    RoundNameDialog.ui \
    SelectRoundDialog.ui \
    SelectTournamentTypeDialog.ui \
    TournamentMenu.ui \
    TournamentRoster.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ImagesInProgram.qrc



FORMS += \
    AddMatchDialog.ui \
    AddPlayerToGameDialog.ui \
    AddPlayerToMatchDialog.ui \
    AddToRoundDialog.ui \
    EditPlayerDialog.ui \
    EnterGameResultsDialog.ui \
    EnterTournamentNameDialog.ui \
    MainMenu.ui \
    MainWindow.ui \
    MatchMenu.ui \
    MatchNameDialog.ui \
    PlayerRegistrationDialog.ui \
    PromptAddToRoundDialog.ui \
    PromptGameNameDialog.ui \
    RoundMenu.ui \
    RoundNameDialog.ui \
    SelectRoundDialog.ui \
    SelectTournamentTypeDialog.ui \
    TournamentMenu.ui \
    TournamentRoster.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ImagesInProgram.qrc

