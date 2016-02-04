#include "movable.h"
#include <QPropertyAnimation>

Movable::Movable(QSize windowSize,
                 QSize objectSize) :
    QObject(), QGraphicsItem()
{
    looping = true;
    this->windowSize = windowSize;
    this->objectSize = objectSize;
}

bool Movable::isLooping(){
    return looping;
}

void Movable::toggleLooping(){
    isLooping() ? looping = false : looping = true;
}

void Movable::goUp(){
    double x = pos().x();

    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
    animation->setDuration(1000);
    animation->setStartValue(pos());
    animation->setEndValue(QPointF(x,
                                   -100));
    animation->start();
}

void Movable::goDown(){

}

void Movable::goLeft(){

}

void Movable::goRight(){

}

/*QPointF Movable::pos() const{
    return _pos;
}

void Movable::setPos(QPointF newpos){
    _pos = newpos;
}*/
