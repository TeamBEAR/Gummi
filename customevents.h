#ifndef CUSTOMEVENTS_H
#define CUSTOMEVENTS_H

struct StringMatchEvent : public QEvent
{
    StringMatchEvent(const QString &val)
    : QEvent(QEvent::Type(QEvent::User+1)),
      value(val) {}

    QString value;
};

#endif // CUSTOMEVENTS_H
