#include "radar.h"

Radar::Radar(QSizeF objectSize,
             int factor):
    Growable(objectSize, factor)
{
    penWidth=2;
}

float Radar::width(){
    return objectSize.width();
}

void Radar::setWidth(float newWidth){
    prepareGeometryChange();
    objectSize.setWidth(newWidth);
}

float Radar::height(){
    return objectSize.height();
}

void Radar::setHeight(float newHeight){
    prepareGeometryChange();
    objectSize.setHeight(newHeight);
}

QRectF Radar::boundingRect() const{
    return QRectF(-objectSize.width()/2,
                  -objectSize.height()/2,
                  objectSize.width(),
                  objectSize.height());
}

void Radar::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget){

    // Add a custom brush and pen to painter
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(penWidth);

    painter->setPen(outlinePen);

    // Draw agent as a rectangle in item's coordinate system
    painter->drawEllipse(boundingRect());
}
