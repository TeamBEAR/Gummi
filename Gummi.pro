TEMPLATE = app
TARGET = Gummy

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    scenario.cpp \
    gummiworld.cpp

HEADERS += \
    scenario.h \
    gummiworld.h
