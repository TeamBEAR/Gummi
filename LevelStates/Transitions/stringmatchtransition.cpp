#include "LevelStates/Transitions/stringmatchtransition.h"
#include "LevelStates/customevents.h"
#include <iostream>

StringMatchTransition::StringMatchTransition(const QString &value):
    m_value(value){

}

bool StringMatchTransition::eventTest(QEvent *e)
{
    if (e->type() != QEvent::Type(QEvent::User+1)) // StringMatchEvent
        return false;
    StringEvent *sm_event = static_cast<StringEvent*>(e);
    return (m_value == sm_event->value);
}

void StringMatchTransition::onTransition(QEvent *e){
    std::cout<<"executed stringmatch"<<std::endl;
}
