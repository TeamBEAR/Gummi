#ifndef ANYSTRINGTRANSITION_H
#define ANYSTRINGTRANSITION_H

#include <QEvent>
#include <QAbstractTransition>

class AnyStringTransition : public QAbstractTransition
{
    public:
        AnyStringTransition(){}

    protected:
        virtual bool eventTest(QEvent *e);
        virtual void onTransition(QEvent *e);
};

#endif // ANYSTRINGTRANSITION_H
