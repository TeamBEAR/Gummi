#include "movable.h"
#include <QAbstractAnimation>

Movable::Movable(QSize windowSize,
                 QSize objectSize) :
    QObject(), QGraphicsItem()
{
    looping = true;
    started = false;
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

bool Movable::hasStarted(){
    return started;
}

void Movable::stop(){
    goingUp = false;
    goingDown = false;
    goingLeft = false;
    goingRight = false;
    started = false;
    animation->stop();
}

void Movable::start(){
    if(animation->state() != QAbstractAnimation::Running){
        started = true;
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

    // Vertical movement
    if(goingUp){
        // Check lower limits

        if(result.y() + objectSize.height() < 0){
            if(looping){
                setY(windowSize.height());
                result.setY(windowSize.height() - speed);
            }else{
                stop();
            }
        }else{
            result.setY(result.y() - speed);
        }
    }else if(goingDown){
        // Check upper limits

        if(result.y() > windowSize.height()){
            if(looping){
                setY(-objectSize.height());
                result.setY(-objectSize.height() + speed);
            }else{
                stop();
            }
        }else{
            result.setY(result.y() + speed);
        }
    }

    // Horizontal movement
    if(goingLeft){
        // Check lower limits
        if(result.x() + objectSize.width() < 0){
            if(looping){
                setX(windowSize.width());
                result.setX(windowSize.width() - speed);
            }else{
                stop();
            }
        }else{
            result.setX(result.x() - speed);
        }

    }else if(goingRight){
        // Check upper limits
        if(result.x() > windowSize.width()){
            if(looping){
                setX(-objectSize.width());
                result.setX(-objectSize.width() + speed);
            }else{
                stop();
            }
        }else{
            result.setX(result.x() + speed);
        }
    }
    return result;
}

void Movable::refreshPos(){
    if(goingUp || goingDown || goingLeft || goingRight){
        QPointF nextPos = getNextPos();
        animation->setStartValue(pos());
        animation->setEndValue(nextPos);
        animation->start();
    }
}
