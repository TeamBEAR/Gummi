#ifndef CUSTOMEVENTS_H
#define CUSTOMEVENTS_H

#include <QEvent>
#include <QString>

struct StringEvent : public QEvent
{
    StringEvent(const QString &val)
    : QEvent(QEvent::Type(QEvent::User+1)),
      value(val) {}

    QString value;
};

struct CleanMemoryEvent : public QEvent
{
    CleanMemoryEvent()
    : QEvent(QEvent::Type(QEvent::User+2)){}
};


#endif // CUSTOMEVENTS_H
