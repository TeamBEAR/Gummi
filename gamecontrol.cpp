#include "gamecontrol.h"
#include "agent.h"

GameControl::GameControl(){

    // Game is running
    running = true;

    // Creates a new scene
    scene = new GameScene();
    if(scene != NULL){

        scene->setSceneRect(QRectF(0, 0, 800, 600));
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
    // TODO: Automatically maximize,
    // read Resize event to calculate final
    // window size
    //view->setWindowState(Qt::WindowMaximized);
    view->window()->setGeometry(QRect(100,100,800,600));

    // Create a demo player
    // We pass the window's size to know
    // where its borders are
    Agent *player = new Agent(QSize(800, 600));

    // Add demo player to the scene
    scene->addItem(player);

    player->goUp();
    player->goRight();
}

bool GameControl::isRunning(){
    return this->running;
}

void GameControl::setRunning(bool value){
    this->running = value;
}
