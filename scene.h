#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

#include "player.h"
#include "ball.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    ~Scene();

    enum GameState {
        start,
        ingame,
        end
    };

    void keyPressed(QKeyEvent *event);

    GameState getCurrentGamestate();
    void nextState();

public slots:

signals:

private:
    GameState gameState;

    QGraphicsPixmapItem *borderLeft, *borderRight;

    Player *p;
    Ball *b;
};

#endif // SCENE_H
