#ifndef MOVABLE_H
#define MOVABLE_H

#include <QSize>
#include <QPointF>
#include <QObject>
#include <QGraphicsItem>

class Movable : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    private:
        bool looping;
        //QPointF _pos;
    protected:
        QSize windowSize;
        QSize objectSize;
    public:
        Movable(QSize windowSize=QSize(1, 1),
                QSize objectSize=QSize(1, 1));
        bool isLooping();
        void goUp();
        void goDown();
        void goLeft();
        void goRight();
        void toggleLooping();
        /*QPointF pos() const;
        void setPos(QPointF newpos);*/
};

#endif // MOVABLE_H
