#ifndef CREATEAGENTTRANSITION_H
#define CREATEAGENTTRANSITION_H

#include <QEvent>
#include <QAbstractTransition>

class CreateAgentTransition : public QAbstractTransition
{
    public:
        CreateAgentTransition(){}

    protected:
        virtual bool eventTest(QEvent *e);
        virtual void onTransition(QEvent *e);
};

#endif // CREATEAGENTTRANSITION_H
