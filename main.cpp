#include <QApplication>
#include <unistd.h>
#include <iostream>

#include "globals.h"
#include "Entities/sprite.h"
#include "Core/gamecontrol.h"
#include "Core/level.h"

#include "LevelStates/States/levelstate.h"
#include "LevelStates/States/comparisonstate.h"
#include "LevelStates/States/anyinputstate.h"
#include "LevelStates/States/createagentstate.h"
#include "LevelStates/States/cleanmemorystate.h"

Level *createLevelOne(){
    ComparisonState *initial = new ComparisonState("Tapes <font color=\"blue\">commencer</font>",
                                                  "commencer");
    CleanMemoryState *first = new CleanMemoryState();
    CreateAgentState *second = new CreateAgentState("Quel est ton nom, petit d'homme ?");
    ComparisonState *third = new ComparisonState("tu peux <font color=\"green\">accelerer</font>",
                                                  "accelerer");
    ComparisonState *fourth = new ComparisonState("tu peux <font color=\"blue\">allumer radar</font>",
                                                  "allumer radar");
    ComparisonState *fifth = new ComparisonState("tu peux <font color=\"red\">arreter</font>",
                                                  "arreter");
    ComparisonState *sixth = new ComparisonState(
                "Tapes <font color=\"green\">accelerer</font> et <font color=\"blue\">continuer</font>",
                "accelerer et continuer");
    QList<LevelState *> params;
    params.append(initial);
    params.append(first);
    params.append(second);
    params.append(third);
    params.append(fourth);
    params.append(fifth);
    params.append(sixth);
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

    // Create a demo player in memory
    Agent *player = gameMemory->newAgent("Demo");

    // Make the player move
    player->goUp();
    player->goRight();

    // Demo player's radar
    player->toggleRadar();

    // Create a demo animation in memory
    Sprite *doggy = gameMemory->newDoggy();

    // Make the animation move
    doggy->goRight();
    doggy->show();

    // Add first level to the scene
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
