#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QStateMachine>
#include <iostream>
#include <QList>
#include "agent.h"

using namespace std;

class Level : public QState
{
    Q_OBJECT
    private:
        string name;
        QList<Agent*> agents;
        QStateMachine *levelWorkflow;

    public:
        Level(string name);
        Agent *createAgent(string name);
        QList<Agent*> getAgents();
        string getName();

    signals:
        void solved();
        void unsolvable();

};

#endif // LEVEL_H
