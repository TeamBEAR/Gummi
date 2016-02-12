#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include <QStateMachine>
#include <QLabel>
#include <QGraphicsItem>
#include "gameflow.h"
#include "gamescene.h"
#include "gameview.h"
#include "level.h"
#include "commandline.h"

class GameControl : public QObject
{
    Q_OBJECT
    private:
        GameView *view;
        GameScene *scene;
        GameFlow *gameFlow;
        CommandLine *commandLine;
        QLabel display;
        Level *currentLevel;
        bool running;

    public:
        GameControl();
        bool isRunning();
        void setRunning(bool value);
        void addLevel(Level *level);
        void start();
        void stop();

    public slots:
        void loadLevel();
        void unloadLevel();
        void refreshDisplay();
        void processCL();
        void refresh();

};

#endif // GAMECONTROL_H
