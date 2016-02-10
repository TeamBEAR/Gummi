#include "comparisonstate.h"
#include "stringmatchtransition.h"

ComparisonState::ComparisonState(QString displayBuffer, QString stringToMatch):
    LevelState(displayBuffer)
{
    guardedTransition = new StringMatchTransition(stringToMatch);
    this->addTransition(guardedTransition);
}
