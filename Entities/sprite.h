#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QList>
#include <QPixmap>
#include <QString>
#include <QSize>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

#include "Entities/movable.h"

class Sprite : public Movable
{
    Q_OBJECT
    Q_PROPERTY(int frameNumber READ frameNumber WRITE setFrameNumber)
    private:
        int numberOfFrames;
        int _frameNumber;
        QList<QPixmap *> upFrames;
        QList<QPixmap *> downFrames;
        QList<QPixmap *> leftFrames;
        QList<QPixmap *> rightFrames;
        QPixmap *stoppedImage;
        QPixmap *currentFrame;
        QPropertyAnimation *spriteAnimation;
    public:
        Sprite(QSize windowSize, QSize spriteSize);
        virtual ~Sprite(){}
        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
        QRectF boundingRect() const;
        int frameNumber();
        void setFrameNumber(int newFrameNumber);
};

#endif // SPRITE_H
