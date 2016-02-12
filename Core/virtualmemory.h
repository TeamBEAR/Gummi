#ifndef VIRTUALMEMORY_H
#define VIRTUALMEMORY_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QString>

#include "Entities/agent.h"
#include "Entities/sprite.h"

class VirtualMemory : public QObject
{
    Q_OBJECT
    private:
        QList<Agent *> agents;
        QList<Sprite *> sprites;
        QMap<QString, Agent *> agentsMap;

    public:
        explicit VirtualMemory(QObject *parent = 0);
        QList<Agent*> getAgents();
        QList<Sprite*> getSprites();
        Agent *newAgent(QString agentName);
        Sprite *newDoggy();
        void createAgent(QString agentName);
        Agent *getAgentByName(QString agentName);

    signals:
        void addedAgent();
        void clearedMemory();

    public slots:
        void clear();
};

#endif // VIRTUALMEMORY_H
