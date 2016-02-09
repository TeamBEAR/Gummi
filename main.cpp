#include <QApplication>
#include <unistd.h>
#include <iostream>

#include "gamecontrol.h"
#include "level.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    GameControl *handler = new GameControl();
    // TODO: The state machine framework directs
    // how scenes are created and populated, depending
    // on level.

    // Create a demo level
    Level *level1 = new Level("Level 1", "Demo instruction");

    // Create a demo player in the level
    Agent *player = level1->createAgent("Demo");

    // Make the player move
    player->goUp();
    player->goRight();

    // Add demo level to the scene
    handler->addLevel(level1);

    /*// Manual game loop
    while(game.isRunning()){
        app.processEvents();

        // 24pfs
        usleep(40000);
    }
    return 0;*/

    return app.exec();

}
