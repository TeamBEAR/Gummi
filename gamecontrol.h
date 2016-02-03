#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "gamescene.h"
#include "gameview.h"
#include "eventhandler.h"

class GameControl
{
    private:
        GameView *view;
        GameScene *scene;
        EventHandler *handler;
        bool running;

    public:
        GameControl();
        bool isRunning();
        void setRunning(bool value);
};

#endif // GAMECONTROL_H
