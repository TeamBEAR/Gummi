#include "anystringtransition.h"

void AnyStringTransition::eventTest(QEvent *event) const{
    if (e->type() != QEvent::Type(QEvent::User+2)) // AnyStringEvent
        return false;
    return true;
}
