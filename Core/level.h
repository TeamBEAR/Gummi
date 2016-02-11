#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QFinalState>
#include <QStateMachine>
#include <QList>

#include "Entities/agent.h"

#include "LevelStates/States/levelstate.h"

#include "Core/virtualmemory.h"

class Level : public QState
{
    Q_OBJECT
    private:
        QString name;
        QFinalState *finalState;

    protected:
        QStateMachine *levelWorkflow;

    public:
        Level(QString name,
              QList<LevelState *> internalStates);
        LevelState *currentState();
        QString getName();
        void setDisplayBuffer(QString newBufferContents);
        QString getDisplayBuffer();
        void postEvent(QEvent *e);

    signals:
        void solved();
        void unsolvable();
        void displayContentsChanged();

    public slots:
        void changeLevel();
        void changeInternalState();
};

#endif // LEVEL_H
