#include "gummiworld.h"

GummiWorld::GummiWorld(){
    this->running = true;
    this->scenario = new Scenario();
    this->scenario->setWindowState(Qt::WindowMaximized);
}

bool GummiWorld::isRunning(){
    return this->running;
}

void GummiWorld::setRunning(bool value){
    this->running = value;
}
