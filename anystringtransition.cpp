#include "anystringtransition.h"
#include <iostream>

bool AnyStringTransition::eventTest(QEvent *e){
    if (e->type() != QEvent::Type(QEvent::User+1)) // StringEvent
        return false;
    return true;
}

void AnyStringTransition::onTransition(QEvent *e){
    std::cout<<"executed anystring"<<std::endl;
}
