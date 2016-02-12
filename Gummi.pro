TEMPLATE = app
TARGET = Gummy

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    globals.cpp \
    Core/gamecontrol.cpp \
    Core/gamescene.cpp \
    Core/gameview.cpp \
    Core/commandline.cpp \
    Core/level.cpp \
    Core/gameflow.cpp \
    Core/virtualmemory.cpp \
    Entities/movable.cpp \
    Entities/agent.cpp \
    Entities/growable.cpp \
    Entities/radar.cpp \
    LevelStates/States/levelstate.cpp \
    LevelStates/States/comparisonstate.cpp \
    LevelStates/States/anyinputstate.cpp \
    LevelStates/States/createagentstate.cpp \
    LevelStates/Transitions/stringmatchtransition.cpp \
    LevelStates/Transitions/anystringtransition.cpp \
    LevelStates/Transitions/createagenttransition.cpp \
    LevelStates/States/cleanmemorystate.cpp \
    LevelStates/Transitions/cleanmemorytransition.cpp \
    Core/interpreter.cpp \
    Entities/sprite.cpp


HEADERS += \
    globals.h \
    Core/gamecontrol.h \
    Core/gamescene.h \
    Core/gameview.h \
    Core/commandline.h \
    Core/level.h \
    Core/gameflow.h \
    Core/virtualmemory.h \
    Entities/movable.h \
    Entities/agent.h \
    Entities/growable.h \
    Entities/radar.h \
    LevelStates/customevents.h \
    LevelStates/States/levelstate.h \
    LevelStates/States/comparisonstate.h \
    LevelStates/States/anyinputstate.h \
    LevelStates/States/createagentstate.h \
    LevelStates/Transitions/stringmatchtransition.h \
    LevelStates/Transitions/anystringtransition.h \
    LevelStates/Transitions/createagenttransition.h \
    LevelStates/States/cleanmemorystate.h \
    LevelStates/Transitions/cleanmemorytransition.h \
    Core/interpreter.h \
    Entities/sprite.h

DISTFILES += \
    Core/Parser/lexicaltokens.l \
    Core/Parser/grammar.y \
    Core/Parser/Makefile

copyres.commands = $(COPY_DIR) $$PWD/Res $$OUT_PWD
first.depends = $(first) copyres
export(first.depends)
export(copyres.commands)
QMAKE_EXTRA_TARGETS += first copyres
