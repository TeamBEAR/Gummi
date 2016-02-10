#include "LevelStates/States/createagentstate.h"
#include "LevelStates/Transitions/createagenttransition.h"

CreateAgentState::CreateAgentState(QString displayBuffer):
    LevelState(displayBuffer)
{
    guardedTransition = new CreateAgentTransition();
    this->addTransition(guardedTransition);
}
