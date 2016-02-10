#include "stringmatchtransition.h"

bool StringMatchTransition::eventTest(QEvent *e) const
{
    if (e->type() != QEvent::Type(QEvent::User+1)) // StringMatchEvent
        return false;
    StringMatchEvent *sm_event = static_cast<StringMatchEvent*>(e);
    return (m_value == sm_event->value);
}
