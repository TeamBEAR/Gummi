TEMPLATE = app
TARGET = Gummy

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    gamecontrol.cpp \
    eventhandler.cpp \
    gamescene.cpp \
    gameview.cpp \
    movable.cpp \
    agent.cpp

HEADERS += \
    gamecontrol.h \
    eventhandler.h \
    gamescene.h \
    gameview.h \
    movable.h \
    agent.h
