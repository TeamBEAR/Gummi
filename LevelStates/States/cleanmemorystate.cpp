#include "LevelStates/States/cleanmemorystate.h"
#include "LevelStates/Transitions/cleanmemorytransition.h"
#include "LevelStates/customevents.h"
#include "globals.h"

#include <QStateMachine>

CleanMemoryState::CleanMemoryState(QString displayBuffer):
    LevelState(displayBuffer)
{
    guardedTransition = new CleanMemoryTransition();
    this->addTransition(guardedTransition);
    QObject::connect(this,
                     SIGNAL(entered()),
                     this,
                     SLOT(cleanMemory())
                     );
}

void CleanMemoryState::cleanMemory(){
    gameMemory->clear();
    QStateMachine *machine = this->machine();
    machine->postEvent(new CleanMemoryEvent());
}
