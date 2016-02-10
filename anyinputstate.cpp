#include "anyinputstate.h"
#include "anystringtransition.h"

AnyInputState::AnyInputState(QString displayBuffer):
    LevelState(displayBuffer)
{
    guardedTransition = new AnyStringTransition();
    this->addTransition(guardedTransition);
}
