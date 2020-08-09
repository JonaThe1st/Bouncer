#include "scene.h"

#include <QKeyEvent>
#include <QDebug>

Scene::Scene(QObject *parent) : QGraphicsScene(parent),
    gameState{GameState::start},
p{new Player()},
b{new Ball()}
{

    //add border to scene
    borderLeft = new QGraphicsPixmapItem(QPixmap(":/images/border.png"));
    borderRight = new QGraphicsPixmapItem(QPixmap(":/images/border.png"));
    borderLeft->setY(-700);
    borderRight->setPos(QPointF(500-borderRight->boundingRect().width(), -700));

    addItem(borderLeft);
    addItem(borderRight);

    //add player to the screen
    addItem(p);

    //add Ball to the screen
    addItem(b);

}

Scene::~Scene()
{
    delete borderLeft;
    delete borderRight;
}

void Scene::keyPressed(QKeyEvent *event)
{

    switch (event->key()) {
        case Qt::Key_A:
            qDebug() << "moving left";
            p->move(false);
            break;
        case Qt::Key_D:
            qDebug() << "moving right";
            p->move(true);
            break;
    }

}

Scene::GameState Scene::getCurrentGamestate()
{
    return gameState;
}

void Scene::nextState()
{
    switch (gameState) {


    //Start the game
    case start:

        b->start();

        gameState = GameState::ingame;
        break;
    // end the game
    case ingame:
        break;
    //clean game up
    case end:
        break;

    }
}
