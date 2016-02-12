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
        bool started;
        float speed;
    protected:
        QPropertyAnimation *animation;
        QSize windowSize;
        QSize objectSize;
        bool goingUp;
        bool goingDown;
        bool goingLeft;
        bool goingRight;
    public:
        explicit Movable(QSize windowSize,
                         QSize objectSize);
        bool isLooping();
        bool hasStarted();
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
