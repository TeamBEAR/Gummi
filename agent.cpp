#include "agent.h"

#include <QBrush>
#include <QPen>
#include <unistd.h>

Agent::Agent(QSize windowSize, QSize agentSize):
    Movable(windowSize, agentSize)
{
    penWidth=2;
    setPos(QPointF(0, 0));
}

QRectF Agent::boundingRect() const
{
    // Get agent's bounding rectangle
    // in item's coordinate system
    return QRectF(-objectSize.width()/2 - penWidth/2,
                  -objectSize.height()/2 - penWidth/2,
                  objectSize.width() + penWidth,
                  objectSize.height() + penWidth);
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
    painter->drawRect(QRectF(pos().x()-objectSize.width()/2 - penWidth/2,
                             pos().y()-objectSize.height()/2 - penWidth/2,
                             objectSize.width(),
                             objectSize.height())
                      );
}


