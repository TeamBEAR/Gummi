#include "gamecontrol.h"
#include "agent.h"

GameControl::GameControl(){

    running = true;

    scene = new GameScene();
    handler = new EventHandler();
    if(scene != NULL){
        view = new GameView(this->scene);
        if(view != NULL){
            view->show();
        }
    }
    view->setWindowState(Qt::WindowMaximized);
    Agent *player = new Agent(QSize(view->width(),
                                    view->height()));
    scene->addItem(player);
    player->goUp();
}

bool GameControl::isRunning(){
    return this->running;
}

void GameControl::setRunning(bool value){
    this->running = value;
}
