#ifndef CLEANMEMORYTRANSITION_H
#define CLEANMEMORYTRANSITION_H

#include <QEvent>
#include <QAbstractTransition>

class CleanMemoryTransition : public QAbstractTransition
{
    public:
        CleanMemoryTransition(){}

    protected:
        virtual bool eventTest(QEvent *e);
        virtual void onTransition(QEvent *e);
};

#endif // CLEANMEMORYTRANSITION_H
