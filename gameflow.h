#ifndef GAMEFLOW_H
#define GAMEFLOW_H

#include "level.h"
#include <QObject>
#include <QList>
#include <QStateMachine>
#include <QFinalState>
#include <QSignalTransition>

class GameFlow : public QStateMachine
{
    Q_OBJECT
    private:
        QList<Level *> flow;
        QFinalState *finalState;
        QSignalTransition *finalTransition;

    public:
        GameFlow();
        void insertToGameFlow(Level *newState);

    signals:
        void gameFinished();

    public slots:
        void closeGame();
};

#endif // GAMEFLOW_H
