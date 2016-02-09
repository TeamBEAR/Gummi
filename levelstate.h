#ifndef LEVELSTATE_H
#define LEVELSTATE_H

#include <QObject>
#include <QState>
#include <iostream>

using namespace std;

class LevelState : public QState
{
    public:
        LevelState();
        bool test(string textInput);
};

#endif // LEVELSTATE_H
