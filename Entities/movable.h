#ifndef MOVABLE_H
#define MOVABLE_H

#include <QSize>
#include <QPointF>
#include <QObject>
#include <QGraphicsItem>
#include <QPropertyAnimation>

class Movable : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    private:
        bool looping;
        bool goingUp;
        bool goingDown;
        bool goingLeft;
        bool goingRight;
        float speed;
    protected:
        QPropertyAnimation *animation;
        QSize windowSize;
        QSize objectSize;
    public:
        explicit Movable(QSize windowSize,
                         QSize objectSize);
        bool isLooping();
        void goUp();
        void goDown();
        void goLeft();
        void goRight();
        void stop();
        void start();
        void toggleLooping();
        QPointF getNextPos();

    public slots:
        void refreshPos();
};

#endif // MOVABLE_H
