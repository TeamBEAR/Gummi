#include "createagentstate.h"
#include "createagenttransition.h"

CreateAgentState::CreateAgentState(QString displayBuffer):
    LevelState(displayBuffer)
{
    guardedTransition = new CreateAgentTransition();
    this->addTransition(guardedTransition);
}
