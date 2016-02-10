#ifndef LEVELSTATE_H
#define LEVELSTATE_H

#include <QObject>
#include <QState>
#include <iostream>

using namespace std;

class LevelState : public QState
{
    Q_OBJECT
    public:
        LevelState();
        virtual bool test(string testInput){return false;}

    signals:
        void succeded();
        void failed();

    public slots:
        void changeState();
};

#endif // LEVELSTATE_H
