#include "createagenttransition.h"
#include "levelstate.h"
#include <iostream>

bool CreateAgentTransition::eventTest(QEvent *e){
    if (e->type() != QEvent::Type(QEvent::User+1)) // StringEvent
        return false;
    return true;
}

void CreateAgentTransition::onTransition(QEvent *e){
    std::cout<<"executed createagent"<<std::endl;
    //TODO:Create agent to memory
}
