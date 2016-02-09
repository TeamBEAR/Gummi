#include "level.h"

Level::Level(string name) :
    QState()
{
    this->name = name;
    levelWorkflow = new QStateMachine();
}

QList<Agent*> Level::getAgents(){
    return agents;
}

string Level::getName(){
    return name;
}

Agent *Level::createAgent(string agentName){
    // TODO: Get size dynamically
    Agent *newAgent = new Agent(agentName, QSize(800, 600));
    agents.append(newAgent);
    return newAgent;
}

