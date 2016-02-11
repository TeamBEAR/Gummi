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
#include <QString>

class Agent : public Movable
{
    private:
        QString name;
        int penWidth;
        Radar *radar;
    public:
        Agent(QString name,
              QSize windowSize,
              QSize agentSize=QSize(50, 50));
        ~Agent();
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        QRectF boundingRect() const;
        QString getName();
        void toggleRadar();
};

#endif // AGENT_H
