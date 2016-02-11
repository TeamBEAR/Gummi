#include "growable.h"

Growable::Growable(QSizeF objectSize,
                   int factor) :
    QObject(), QGraphicsItem()
{
    looping = true;
    started = false;

    // Create animation container
    animation = new QParallelAnimationGroup();

    widthAnimation = new QPropertyAnimation(this, "width");
    // 2 seconds
    widthAnimation->setDuration(1000);
    animation->addAnimation(widthAnimation);

    heightAnimation = new QPropertyAnimation(this, "height");
    // 2 seconds
    heightAnimation->setDuration(1000);
    animation->addAnimation(heightAnimation);

    animation->setLoopCount(-1);

    // Ensure that the object is not moving
    stop();

    this->objectSize = objectSize;
    this->factor = factor;
}

void Growable::setDuration(int mseconds){
    widthAnimation->setDuration(mseconds);
    heightAnimation->setDuration(mseconds);
}

bool Growable::hasStarted(){
    return started;
}

void Growable::stop(){
    animation->stop();
    started = false;
}

void Growable::start(){
    if(animation->state() != QAbstractAnimation::Running){
        widthAnimation->setStartValue(width());
        widthAnimation->setEndValue(width() * factor);
        heightAnimation->setStartValue(height());
        heightAnimation->setEndValue(height() * factor);
        started = true;
        animation->start();
    }
}

bool Growable::isLooping(){
    return looping;
}

void Growable::toggleLooping(){
    if(looping){
        looping = false;
        animation->setLoopCount(1);
    }else{
        looping = true;
        animation->setLoopCount(-1);
    }
}
