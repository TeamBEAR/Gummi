#include <QApplication>
#include <unistd.h>
#include <iostream>
#include "gamecontrol.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    GameControl game;

    /*// Manual game loop
    while(game.isRunning()){
        app.processEvents();

        // 24pfs
        usleep(40000);
    }
    return 0;*/
    return app.exec();

}
