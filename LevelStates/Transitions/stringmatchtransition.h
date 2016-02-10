#ifndef STRINGMATCHTRANSITION_H
#define STRINGMATCHTRANSITION_H

#include <QEvent>
#include <QAbstractTransition>
#include "LevelStates/customevents.h"

class StringMatchTransition : public QAbstractTransition
{
    private:
        QString m_value;
    public:
        StringMatchTransition(const QString &value);
    protected:
        virtual bool eventTest(QEvent *e);
        virtual void onTransition(QEvent *e);
};

#endif // STRINGMATCHTRANSITION_H
