#include "sprite.h"

Sprite::Sprite(QSize windowSize, QSize spriteSize) :
    Movable(windowSize, spriteSize)
{
    setPos(windowSize.width()/2-objectSize.width()/2,
           windowSize.height()/2-objectSize.height()/2);

    upFrames.append(new QPixmap("Res/1.png"));
    upFrames.append(new QPixmap("Res/10.png"));

    leftFrames.append(new QPixmap("Res/3.png"));
    leftFrames.append(new QPixmap("Res/11.png"));

    rightFrames.append(new QPixmap("Res/2.png"));
    rightFrames.append(new QPixmap("Res/12.png"));

    downFrames.append(new QPixmap("Res/4.png"));
    downFrames.append(new QPixmap("Res/6.png"));

    stoppedImage = new QPixmap("Res/5.png");

    setFrameNumber(0);

    // Create animation container
    spriteAnimation = new QPropertyAnimation(this, "frameNumber");

    // 25fps
    spriteAnimation->setDuration(160);
    spriteAnimation->setStartValue(0);
    spriteAnimation->setEndValue(2);
    spriteAnimation->setLoopCount(-1);
    spriteAnimation->start();

}

QRectF Sprite::boundingRect() const
{
    // Get agent's bounding rectangle
    // in item's coordinate system
    return QRectF(0,
                  0,
                  objectSize.width(),
                  objectSize.height());
}

void Sprite::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    // Draw agent as a rectangle in item's coordinate system
    painter->drawPixmap(boundingRect(),
                        *currentFrame,
                        boundingRect());
}

int Sprite::frameNumber(){
    return _frameNumber;
}

void Sprite::setFrameNumber(int newFrameNumber){
    if(goingUp){
        currentFrame = upFrames[newFrameNumber];
    }else if(goingDown){
        currentFrame = downFrames[newFrameNumber];
    }else if(goingLeft){
        currentFrame = leftFrames[newFrameNumber];
    }else if(goingRight){
        currentFrame = rightFrames[newFrameNumber];
    }else{
        currentFrame = stoppedImage;
    }
    _frameNumber = newFrameNumber;
}
