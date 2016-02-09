#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QFinalState>
#include <QStateMachine>
#include <iostream>
#include <QList>
#include "agent.h"
#include "levelstate.h"

using namespace std;

class Level : public QState
{
    Q_OBJECT
    private:
        string name;
        string displayBuffer;
        LevelState *currentState;
        QList<Agent*> agents;
        QFinalState *finalState;

    protected:
        QStateMachine *levelWorkflow;

    public:
        Level(string name,
              string displayBuffer="");
        Agent *createAgent(string name);
        QList<Agent*> getAgents();
        string getName();
        void setDisplayBuffer(string newBufferContents);
        string getDisplayBuffer();
        void interpret(string command);
        void addInternalState(LevelState *newState);

    signals:
        void changeInternalState();
        void solved();
        void unsolvable();
        void displayContentsChanged();

    public slots:
        void changeLevel();
};

#endif // LEVEL_H
