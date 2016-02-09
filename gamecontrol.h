#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include <QStateMachine>
#include <QLabel>
#include "workflow.h"
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
        Workflow *gameFlow;
        CommandLine *commandLine;
        QLabel display;
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

};

#endif // GAMECONTROL_H
