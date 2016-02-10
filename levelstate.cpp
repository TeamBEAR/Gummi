#include "levelstate.h"

LevelState::LevelState(QString displayBuffer):
    QState()
{
    guardedTransition = NULL;
    this->displayBuffer = displayBuffer;
    QObject::connect(this,
                     SIGNAL(succeded()),
                     this,
                     SLOT(changeState())
                     );

}

void LevelState::connectTo(QAbstractState *nextState){
    if(guardedTransition != NULL){
        guardedTransition->setTargetState(nextState);
    }
}

QString LevelState::getDisplayBuffer(){
    return displayBuffer;
}

void LevelState::setDisplayBuffer(QString newDisplayBuffer){
    displayBuffer = newDisplayBuffer;
}

void LevelState::changeState(){

}
