#include "virtualmemory.h"

VirtualMemory::VirtualMemory(QObject *parent) :
    QObject(parent)
{

}

QList<Agent*> VirtualMemory::getAgents(){
    return agents;
}

Agent *VirtualMemory::newAgent(QString agentName){
    // TODO: Get size dynamically
    Agent *newAgent = new Agent(agentName, QSize(800, 600));
    agents.append(newAgent);
    newAgent->show();
    return newAgent;
}

void VirtualMemory::createAgent(QString agentName){
    newAgent(agentName);
    emit addedAgent();
}

void VirtualMemory::clear(){
    foreach(Agent *agent, agents){
        delete agent;
    }
    agents.clear();
    emit clearedMemory();
}
