#include "agent.h"

#include <QBrush>
#include <QPen>

Agent::Agent(QSize windowSize, QSize agentSize):
    Movable(windowSize, agentSize)
{
    setPos(QPointF(
               windowSize.width()/2,
               windowSize.height()/2)
           );
}

QRectF Agent::boundingRect() const
{
    return QRectF(pos().x(), pos().y(),
                  objectSize.width(),
                  objectSize.height());
}

void Agent::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    QBrush greenBrush(Qt::green);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    painter->setBrush(greenBrush);
    painter->setPen(outlinePen);

    painter->drawRect(QRectF(pos().x(), pos().y(),
                             objectSize.width(),
                             objectSize.height()));
}


