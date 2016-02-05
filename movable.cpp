#include "movable.h"
#include <QAbstractAnimation>

Movable::Movable(QSize windowSize,
                 QSize objectSize) :
    QObject(), QGraphicsItem()
{
    looping = true;
    speed = 10;

    // Create animation container
    animation = new QPropertyAnimation(this, "pos");

    // 25fps
    animation->setDuration(40);

    // Create animation loop
    QObject::connect(animation,
                     SIGNAL(finished()),
                     this,
                     SLOT(refreshPos()));

    // Ensure that the object is not moving
    stop();

    this->windowSize = windowSize;
    this->objectSize = objectSize;
}

bool Movable::isLooping(){
    return looping;
}

void Movable::toggleLooping(){
    isLooping() ? looping = false : looping = true;
}

void Movable::stop(){
    goingUp = false;
    goingDown = false;
    goingLeft = false;
    goingRight = false;
    animation->stop();
}

void Movable::start(){
    if(animation->state() != QAbstractAnimation::Running){
        refreshPos();
    }
}

void Movable::goUp(){
    goingUp = true;
    goingDown = false;
    start();
}

void Movable::goDown(){
    goingUp = false;
    goingDown = true;
    start();
}

void Movable::goLeft(){
    goingLeft = true;
    goingRight = false;
    start();
}

void Movable::goRight(){
    goingLeft = false;
    goingRight = true;
    start();
}

QPointF Movable::getNextPos(){
    QPointF result(pos());
    float newY;
    float newX;

    // Vertical movement
    if(goingUp){
        newY = result.y() - speed;
        // Check lower limits
        // TODO: Take in account object boundingRectangle
        if(newY < 0){
            if(looping){
                result.setY(windowSize.height());
            }else{
                stop();
            }
        }else{
            result.setY(newY);
        }
    }else if(goingDown){
        newY = result.y() + speed;
        // Check upper limits
        // TODO: Take in account object boundingRectangle
        if(newY > windowSize.height()){
            if(looping){
                result.setY(0);
            }else{
                stop();
            }
        }else{
            result.setY(newY);
        }
    }

    // Horizontal movement
    if(goingLeft){
        newX = result.x() - speed;
        // Check lower limits
        // TODO: Take in account object boundingRectangle
        if(newX < 0){
            if(looping){
                result.setX(windowSize.width());
            }else{
                stop();
            }
        }else{
            result.setX(newX);
        }

    }else if(goingRight){
        newX = result.x() + speed;
        // Check upper limits
        // TODO: Take in account object boundingRectangle
        if(newX > windowSize.width()){
            if(looping){
                result.setX(0);
            }else{
                stop();
            }
        }else{
            result.setX(newX);
        }
    }
    return result;
}

void Movable::refreshPos(){
    if(goingUp || goingDown || goingLeft || goingRight){
        animation->setStartValue(pos());
        animation->setEndValue(getNextPos());
        animation->start();
    }
}
