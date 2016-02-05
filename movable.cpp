#include "movable.h"
#include <QPropertyAnimation>

Movable::Movable(QSize windowSize,
                 QSize objectSize) :
    QObject(), QGraphicsItem()
{
    looping = true;
    speed = 10;
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

    QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");

    // 25fps
    animation->setDuration(40);

    //Move one pixel in 1 frame
    animation->setStartValue(pos());
    animation->setEndValue(QPointF(pos().x(),
                                   pos().y()-speed));
    QObject::connect(animation,
                     SIGNAL(finished()),
                     this,
                     SLOT(refreshPos()));
    animation->start();
}

void Movable::goDown(){

}

void Movable::goLeft(){

}

void Movable::goRight(){

}

void Movable::refreshPos(){
    QPropertyAnimation *animation = (QPropertyAnimation*)sender();
    animation->setStartValue(pos());
    animation->setEndValue(QPointF(pos().x(),
                                   pos().y()-speed));
    animation->start();
}
