#ifndef STRINGMATCHTRANSITION_H
#define STRINGMATCHTRANSITION_H

#include <QEvent>
#include <QAbstractTransition>

struct StringMatchEvent : public QEvent
{
    StringMatchEvent(const QString &val)
    : QEvent(QEvent::Type(QEvent::User+1)),
      value(val) {}

    QString value;
};

class StringMatchTransition : public QAbstractTransition
{
    private:
        QString m_value;
    public:
        StringMatchTransition(const QString &value):
            m_value(value){}
    protected:
        virtual bool eventTest(QEvent *e) const;
        virtual void onTransition(QEvent *e){}
};

#endif // STRINGMATCHTRANSITION_H
