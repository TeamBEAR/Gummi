#ifndef COMPARISONSTATE_H
#define COMPARISONSTATE_H

#include "levelstate.h"

class ComparisonState : public LevelState
{
    public:
        ComparisonState(QString displayBuffer,
                        QString stringToMatch);
};

#endif // COMPARISONSTATE_H
