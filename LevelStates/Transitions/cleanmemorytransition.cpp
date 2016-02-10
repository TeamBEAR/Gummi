#include "cleanmemorytransition.h"
#include <iostream>

bool CleanMemoryTransition::eventTest(QEvent *e){
    if (e->type() != QEvent::Type(QEvent::User+2)) // CleanMemoryEvent
        return false;
    return true;
}

void CleanMemoryTransition::onTransition(QEvent *e){
    std::cout<<"executed memoryclean"<<std::endl;
}
