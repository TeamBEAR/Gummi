#include "virtualmemory.h"

VirtualMemory::VirtualMemory(QObject *parent) :
    QObject(parent)
{

}

QList<Agent*> VirtualMemory::getAgents(){
    return agents;
}

QList<Sprite*> VirtualMemory::getSprites(){
    return sprites;
}

Agent *VirtualMemory::newAgent(QString agentName){
    // TODO: Get size dynamically
    Agent *newAgent = new Agent(agentName, QSize(800, 600));
    agents.append(newAgent);
    agentsMap.insert(agentName, newAgent);
    newAgent->show();
    return newAgent;
}

Sprite *VirtualMemory::newDoggy(){
    Sprite *doggy = new Sprite(QSize(800, 600),
                              QSize(80, 80));
    sprites.append(doggy);
    return doggy;
}

void VirtualMemory::createAgent(QString agentName){
    newAgent(agentName);
    emit addedAgent();
}

void VirtualMemory::clear(){
    foreach(Agent *agent, agents){
        if(agentsMap.contains(agent->getName()))
            agentsMap.remove(agent->getName());
        delete agent;
    }
    agents.clear();

    foreach(Sprite *sprite, sprites){
        delete sprite;
    }
    sprites.clear();

    emit clearedMemory();
}

Agent *VirtualMemory::getAgentByName(QString agentName){
    if(agentsMap.contains(agentName))
        return agentsMap.value(agentName);
    return NULL;
}
