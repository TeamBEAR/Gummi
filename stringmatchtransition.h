#ifndef STRINGMATCHTRANSITION_H
#define STRINGMATCHTRANSITION_H

#include <QEvent>
#include <QAbstractTransition>

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
