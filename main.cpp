#include <QApplication>
#include <unistd.h>
#include <iostream>
#include "gamecontrol.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    GameControl game;

    while(game.isRunning()){
        app.processEvents();

        // 24pfs
        usleep(40000);
    }

    return 0;
}
