#include "agent.h"

#include <QBrush>
#include <QPen>
#include <unistd.h>

Agent::Agent(QSize windowSize, QSize agentSize):
    Movable(windowSize, agentSize)
{
    penWidth=2;
    setPos(windowSize.width()/2-objectSize.width()/2,
           windowSize.height()/2-objectSize.height()/2);
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


