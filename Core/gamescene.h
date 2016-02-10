#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QObject>

class GameScene : public QGraphicsScene
{
    public:
        explicit GameScene(QObject *parent = 0);
};

#endif // GAMESCENE_H
