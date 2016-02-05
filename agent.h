#ifndef AGENT_H
#define AGENT_H

#include "movable.h"
#include <QSize>
#include <QRectF>
#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

class Agent : public Movable
{
    private:
        int penWidth;
    public:
        Agent(QSize windowSize,
              QSize agentSize=QSize(100, 100));
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        QRectF boundingRect() const;
};

#endif // AGENT_H
