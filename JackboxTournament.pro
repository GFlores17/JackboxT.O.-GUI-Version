QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addToRoundForm.cpp \
    game.cpp \
    getEntry.cpp \
    main.cpp \
    mainWindow.cpp \
    match.cpp \
    player.cpp \
    playerRegistrationForm.cpp \
    round.cpp \
    roundMenu.cpp \
    tournament.cpp \
    tournamentMenu.cpp \
    tournamentRoster.cpp

HEADERS += \
    addToRoundForm.h \
    game.h \
    getEntry.h \
    mainWindow.h \
    match.h \
    player.h \
    playerRegistrationForm.h \
    round.h \
    roundMenu.h \
    tournament.h \
    tournamentMenu.h \
    tournamentRoster.h

FORMS += \
    addToRoundForm.ui \
    mainwindow.ui \
    playerRegistrationForm.ui \
    roundMenu.ui \
    tournamentMenu.ui \
    tournamentRoster.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc \
    Test.qrc
