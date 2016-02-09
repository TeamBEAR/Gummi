#ifndef WORKFLOW_H
#define WORKFLOW_H

#include "level.h"
#include <QObject>
#include <QList>
#include <QStateMachine>
#include <QFinalState>
#include <QSignalTransition>

class Workflow : public QStateMachine
{
    private:
        QList<Level *> flow;
        QFinalState *finalState;
        QSignalTransition *finalTransition;

    public:
        Workflow();
        void insertToWorkflow(Level *newState);
};

#endif // WORKFLOW_H
