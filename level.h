#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QFinalState>
#include <QStateMachine>
#include <QList>
#include "agent.h"
#include "levelstate.h"

class Level : public QState
{
    Q_OBJECT
    private:
        QString name;
        QList<Agent*> agents;
        QFinalState *finalState;

    protected:
        QStateMachine *levelWorkflow;

    public:
        Level(QString name,
              QList<LevelState *> internalStates);
        LevelState *currentState();
        Agent *createAgent(QString name);
        QList<Agent*> getAgents();
        QString getName();
        void setDisplayBuffer(QString newBufferContents);
        QString getDisplayBuffer();
        void interpret(QString command);

    signals:
        void solved();
        void unsolvable();
        void displayContentsChanged();

    public slots:
        void changeLevel();
        void changeInternalState();
};

#endif // LEVEL_H
