#include "stringmatchtransition.h"
#include "customevents.h"

bool StringMatchTransition::eventTest(QEvent *e) const
{
    if (e->type() != QEvent::Type(QEvent::User+1)) // StringMatchEvent
        return false;
    StringEvent *sm_event = static_cast<StringEvent*>(e);
    return (m_value == sm_event->value);
}
