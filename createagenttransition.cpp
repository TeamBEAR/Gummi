#include "createagenttransition.h"
#include "customevents.h"
#include "levelstate.h"
#include "globals.h"
#include <iostream>

bool CreateAgentTransition::eventTest(QEvent *e){
    if (e->type() != QEvent::Type(QEvent::User+1)) // StringEvent
        return false;
    return true;
}

void CreateAgentTransition::onTransition(QEvent *e){
    std::cout<<"executed createagent"<<std::endl;
    StringEvent *sm_event = static_cast<StringEvent*>(e);
    gameMemory->createAgent(sm_event->value);
}
