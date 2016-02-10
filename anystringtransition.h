#ifndef ANYSTRINGTRANSITION_H
#define ANYSTRINGTRANSITION_H

#include <QEvent>
#include <QAbstractTransition>

struct AnyStringEvent : public QEvent
{
    AnyStringEvent(const QString &val)
    : QEvent(QEvent::Type(QEvent::User+2)),
      value(val) {}

    QString value;
};

class AnyStringTransition : public QAbstractTransition
{
    public:
        AnyStringTransition(const QString &value){}

    protected:
        virtual bool eventTest(QEvent *e) const;
        virtual void onTransition(QEvent *e){}
};

#endif // ANYSTRINGTRANSITION_H
