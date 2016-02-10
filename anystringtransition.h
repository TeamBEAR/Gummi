#ifndef ANYSTRINGTRANSITION_H
#define ANYSTRINGTRANSITION_H

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
        virtual bool eventTest(QEvent *event) const;
        virtual void onTransition(QEvent *event){}
};

#endif // ANYSTRINGTRANSITION_H
