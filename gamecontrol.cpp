#include "gamecontrol.h"
#include "agent.h"

GameControl::GameControl(){

    // Game is running
    running = true;

    // Creates a new scene
    scene = new GameScene();
    if(scene != NULL){

        // Adds the created scene to a view
        view = new GameView(this->scene);
        if(view != NULL){
            view->show();

            // Everything looks good,
            // start event handling
            handler = new EventHandler();
        }
    }

    // Maximize view's associated widget
    view->setWindowState(Qt::WindowMaximized);

    // Create a demo player
    // We pass the window's size to know
    // where its borders are
    Agent *player = new Agent(QSize(view->width(),
                                    view->height()));

    // Add demo player to the scene
    scene->addItem(player);
    player->goUp();
}

bool GameControl::isRunning(){
    return this->running;
}

void GameControl::setRunning(bool value){
    this->running = value;
}
