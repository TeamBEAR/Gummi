#include "gameflow.h"

GameFlow::GameFlow():
    QStateMachine()
{
    finalState = new QFinalState();
    finalTransition = NULL;
}

void GameFlow::insertToGameFlow(Level *newState){
    this->addState(newState);

    // Check if it is the first inserted state
    if(flow.isEmpty()){
        this->setInitialState(newState);
    }else{
        Level *prevLevel = flow.last();

        // Disconnect from final state
        prevLevel->removeTransition(finalTransition);

        // Connect new state to previous level
        prevLevel->addTransition(prevLevel, SIGNAL(solved()), newState);

        // Connect new state to itself
        newState->addTransition(newState, SIGNAL(unsolved()), newState);
    }

    // Connect final state
    finalTransition = newState->addTransition(newState,
                                              SIGNAL(solved()),
                                              finalState);
    // Add pointer to the list
    flow.append(newState);
}

void GameFlow::closeGame(){
    emit gameFinished();
}
