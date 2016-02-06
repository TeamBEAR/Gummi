#ifndef GROWABLE_H
#define GROWABLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QSizeF>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

class Growable : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(float width READ width WRITE setWidth)
    Q_PROPERTY(float height READ height WRITE setHeight)
    protected:
        QSizeF objectSize;
        int factor;
        bool looping;
        int penWidth;
        QParallelAnimationGroup *animation;
        QPropertyAnimation *widthAnimation;
        QPropertyAnimation *heightAnimation;
    public:
        explicit Growable(QSizeF objectSize,
                          int factor);
        bool isLooping();
        void toggleLooping();
        void start();
        void stop();
        virtual float width(){return 0.0;}
        virtual void setWidth(float newWidth){}
        virtual float height(){return 0.0;}
        virtual void setHeight(float newHeight){}
};

#endif // GROWABLE_H
