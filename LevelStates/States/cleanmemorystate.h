#ifndef CLEANMEMORYSTATE_H
#define CLEANMEMORYSTATE_H

#include "LevelStates/States/levelstate.h"
#include <QString>

class CleanMemoryState : public LevelState
{
    Q_OBJECT
    public:
        CleanMemoryState(QString displayBuffer="");
    public slots:
        void cleanMemory();
};

#endif // CLEANMEMORYSTATE_H
