#include "gamescene.h"

GameScene::GameScene(QObject *parent):
    QGraphicsScene(parent)
{
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    this->addRect(100, 0, 80, 100, outlinePen, blueBrush);
}
