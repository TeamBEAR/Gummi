#ifndef AGENT_H
#define AGENT_H

#include "movable.h"
#include "radar.h"
#include <QSize>
#include <QRectF>
#include <QPainter>
#include <QPointF>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <iostream>

using namespace std;

class Agent : public Movable
{
    private:
        string name;
        int penWidth;
        Radar *radar;
    public:
        Agent(string name,
              QSize windowSize,
              QSize agentSize=QSize(50, 50));
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        QRectF boundingRect() const;
};

#endif // AGENT_H
