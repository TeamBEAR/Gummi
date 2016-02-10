#ifndef LEVELSTATE_H
#define LEVELSTATE_H

#include <QObject>
#include <QState>
#include <QString>
#include <QAbstractTransition>
#include <QAbstractState>

class LevelState : public QState
{
    Q_OBJECT
    private:
        QString displayBuffer;
    protected:
        QAbstractTransition *guardedTransition;
    public:
        LevelState(QString displayBuffer);
        QString getDisplayBuffer();
        void setDisplayBuffer(QString newDisplayBuffer);
        void connectTo(QAbstractState *nextState);
        virtual bool test(QString testInput){return false;}

    signals:
        void succeded();
        void failed();

    public slots:
        void changeState();
};

#endif // LEVELSTATE_H
