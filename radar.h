#ifndef RADAR_H
#define RADAR_H

#include "growable.h"
#include <QSizeF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>


class Radar : public Growable
{
    public:
        Radar(QSizeF objectSize,
              int percentage);
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        QRectF boundingRect() const;
        void setWidth(float newWidth);
        float width();
        void setHeight(float newHeight);
        float height();
};

#endif // RADAR_H
