#ifndef ANYSTRINGTRANSITION_H
#define ANYSTRINGTRANSITION_H

#include <QEvent>
#include <QAbstractTransition>

class AnyStringTransition : public QAbstractTransition
{
    public:
        AnyStringTransition(const QString &value){}

    protected:
        virtual bool eventTest(QEvent *e) const;
        virtual void onTransition(QEvent *e){}
};

#endif // ANYSTRINGTRANSITION_H
