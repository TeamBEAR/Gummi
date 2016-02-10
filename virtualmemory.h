#ifndef VIRTUALMEMORY_H
#define VIRTUALMEMORY_H

#include <QObject>
#include <QList>
#include <QString>

#include "agent.h"

class VirtualMemory : public QObject
{
    Q_OBJECT
    private:
        QList<Agent *> agents;

    public:
        explicit VirtualMemory(QObject *parent = 0);
        QList<Agent*> getAgents();
        Agent *newAgent(QString agentName);
        void createAgent(QString agentName);

    signals:
        void addedAgent();

    public slots:
};

#endif // VIRTUALMEMORY_H
