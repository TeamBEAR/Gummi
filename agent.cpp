#include "agent.h"

#include <QBrush>
#include <QPen>
#include <unistd.h>

Agent::Agent(string name, QSize windowSize, QSize agentSize):
    Movable(windowSize, agentSize)
{
    this->name = name;
    penWidth=2;
    setPos(windowSize.width()/2-objectSize.width()/2,
           windowSize.height()/2-objectSize.height()/2);

    radar = new Radar(QSizeF(agentSize.width(),
                             agentSize.height()), 3);

    // Sets Agent as parent item
    radar->setParentItem(this);
    // Centers radar within agent
    radar->setPos(agentSize.width()/2,agentSize.height()/2);

    // DEMO radar
    radar->start();
}

QRectF Agent::boundingRect() const
{
    // Get agent's bounding rectangle
    // in item's coordinate system
    return QRectF(0,
                  0,
                  objectSize.width(),
                  objectSize.height());
}

void Agent::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    // Add a custom brush and pen to painter
    QBrush greenBrush(Qt::green);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(penWidth);

    painter->setBrush(greenBrush);
    painter->setPen(outlinePen);

    // Draw agent as a rectangle in item's coordinate system
    painter->drawRect(boundingRect());
}


