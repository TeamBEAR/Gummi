#include "gamecontrol.h"

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
}

bool GameControl::isRunning(){
    return this->running;
}

void GameControl::setRunning(bool value){
    this->running = value;
}
