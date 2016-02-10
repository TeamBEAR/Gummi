#include "levelstate.h"

LevelState::LevelState():
    QState()
{
    QObject::connect(this,
                     SIGNAL(succeded()),
                     this,
                     SLOT(changeState())
                     );

}

void LevelState::changeState(){

}
