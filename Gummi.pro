TEMPLATE = app
TARGET = Gummy

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    gamecontrol.cpp \
    gamescene.cpp \
    gameview.cpp \
    movable.cpp \
    agent.cpp \
    growable.cpp \
    radar.cpp \
    commandline.cpp \
    level.cpp \
    gameflow.cpp \
    levelstate.cpp \
    stringmatchtransition.cpp \
    anystringtransition.cpp

HEADERS += \
    gamecontrol.h \
    gamescene.h \
    gameview.h \
    movable.h \
    agent.h \
    growable.h \
    radar.h \
    commandline.h \
    level.h \
    gameflow.h \
    levelstate.h \
    stringmatchtransition.h \
    anystringtransition.h
