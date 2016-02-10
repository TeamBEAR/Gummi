#include <QApplication>
#include <unistd.h>
#include <iostream>

#include "globals.h"
#include "Core/gamecontrol.h"
#include "Core/level.h"

#include "LevelStates/States/levelstate.h"
#include "LevelStates/States/comparisonstate.h"
#include "LevelStates/States/anyinputstate.h"
#include "LevelStates/States/createagentstate.h"

Level *createLevelOne(){
    //AnyInputState *initial = new AnyInputState("Quel est ton nom, petit d'homme ?");
    CreateAgentState *initial = new CreateAgentState("Quel est ton nom, petit d'homme ?");
    ComparisonState *second = new ComparisonState("tu peux <font color=\"green\">accelerer</font>",
                                                  "accelerer");
    QList<LevelState *> params;
    params.append(initial);
    params.append(second);
    return new Level("one", params);
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    GameControl *handler = new GameControl();
    // TODO: The state machine framework directs
    // how scenes are created and populated, depending
    // on level.

    // Create a demo level
    Level *level1 = createLevelOne();

    // Create a demo player in the level
    Agent *player = gameMemory->newAgent("Demo");

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
