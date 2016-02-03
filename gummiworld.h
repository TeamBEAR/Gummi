#ifndef GUMMIWORLD_H
#define GUMMIWORLD_H
#include "scenario.h"
#include <QWidget>

class GummiWorld
{
    private:
        Scenario *scenario;
        bool running;

    public:
        GummiWorld();
        bool isRunning();
        void setRunning(bool value);
};

#endif // GUMMIWORLD_H
