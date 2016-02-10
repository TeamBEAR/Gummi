#include "anystringtransition.h"

bool AnyStringTransition::eventTest(QEvent *e) const{
    if (e->type() != QEvent::Type(QEvent::User+2)) // AnyStringEvent
        return false;
    return true;
}
