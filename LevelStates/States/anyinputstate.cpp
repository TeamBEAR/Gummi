#include "LevelStates/States/anyinputstate.h"
#include "LevelStates/Transitions/anystringtransition.h"

AnyInputState::AnyInputState(QString displayBuffer):
    LevelState(displayBuffer)
{
    guardedTransition = new AnyStringTransition();
    this->addTransition(guardedTransition);
}
