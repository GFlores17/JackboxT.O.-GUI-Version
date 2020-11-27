QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddMatchDialog.cpp \
    AddToRoundDialog.cpp \
    EnterGameResults.cpp \
    Match.cpp \
    MatchMenu.cpp \
    MatchNameDialog.cpp \
    PromptAddToRoundDialog.cpp \
    PromptGameNameDialog.cpp \
    RoundNameDialog.cpp \
    SelectRoundDialog.cpp \
    game.cpp \
    getEntry.cpp \
    main.cpp \
    mainWindow.cpp \
    player.cpp \
    playerRegistrationDialog.cpp \
    round.cpp \
    roundMenu.cpp \
    tournament.cpp \
    tournamentMenu.cpp \
    tournamentRoster.cpp

HEADERS += \
    AddMatchDialog.h \
    AddToRoundDialog.h \
    EnterGameResults.h \
    Game.h \
    GetEntry.h \
    MatchMenu.h \
    MatchNameDialog.h \
    PromptAddToRoundDialog.h \
    PromptGameNameDialog.h \
    RoundNameDialog.h \
    SelectRoundDialog.h \
    mainWindow.h \
    match.h \
    player.h \
    playerRegistrationDialog.h \
    round.h \
    roundMenu.h \
    tournament.h \
    tournamentMenu.h \
    tournamentRoster.h

FORMS += \
    AddMatchDialog.ui \
    AddToRoundDialog.ui \
    EnterGameResults.ui \
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
    Test.qrc
