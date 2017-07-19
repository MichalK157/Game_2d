#-------------------------------------------------
#
# Project created by QtCreator 2017-07-19T05:02:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
        game.cpp \
    player.cpp \
    shot.cpp \
    enemy.cpp

HEADERS  += game.h \
    player.h \
    shot.h \
    enemy.h

FORMS    += game.ui
