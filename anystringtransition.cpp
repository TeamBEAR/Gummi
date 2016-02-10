#include "anystringtransition.h"

bool AnyStringTransition::eventTest(QEvent *e) const{
    if (e->type() != QEvent::Type(QEvent::User+1)) // StringEvent
        return false;
    return true;
}
