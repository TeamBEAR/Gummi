#include "LevelStates/States/comparisonstate.h"
#include "LevelStates/Transitions/stringmatchtransition.h"

ComparisonState::ComparisonState(QString displayBuffer, QString stringToMatch):
    LevelState(displayBuffer)
{
    guardedTransition = new StringMatchTransition(stringToMatch);
    this->addTransition(guardedTransition);
}
