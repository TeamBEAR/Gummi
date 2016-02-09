#include "level.h"

Level::Level(string name, string displayBuffer) :
    QState()
{
    this->name = name;
    this->displayBuffer = displayBuffer;
    levelWorkflow = new QStateMachine();
    finalState = new QFinalState();
    levelWorkflow->addState(finalState);

    // If no other internal state exists, the
    // final state is also the initial state
    levelWorkflow->setInitialState(finalState);

    // When entering final state, level emits
    // solve to change level
    QObject::connect(finalState,
                     SIGNAL(entered()),
                     this,
                     SLOT(changeLevel())
                     );
}

QList<Agent*> Level::getAgents(){
    return agents;
}

string Level::getName(){
    return name;
}

string Level::getDisplayBuffer(){
    return displayBuffer;
}

void Level::setDisplayBuffer(string newBufferContents){
    displayBuffer = newBufferContents;
    emit displayContentsChanged();
}

Agent *Level::createAgent(string agentName){
    // TODO: Get size dynamically
    Agent *newAgent = new Agent(agentName, QSize(800, 600));
    agents.append(newAgent);
    return newAgent;
}

void Level::changeLevel(){
    emit solved();
}
