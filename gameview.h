#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>

class GameView : public QGraphicsView
{
    public:
        explicit GameView(QGraphicsScene * scene,
                          QWidget * parent = 0);
};

#endif // GAMEVIEW_H
