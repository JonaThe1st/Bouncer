#include "ball.h"

#include <QPointF>
#include <QList>
#include <QDebug>
#include <QVector2D>

#include "player.h"
#include "util.h"

Ball::Ball() :
    r{40},
    gravity{0.001}
{

    setPixmap(QPixmap(":/images/ball.png"));
    setPos(250-r/2, -600);
    setVisible(false);

    o = new Orbit();

    timeAnimation = new QPropertyAnimation(this, "time", this);
}

Ball::~Ball()
{
    delete o;
    delete timeAnimation;
}

void Ball::start()
{
    setVisible(true);

    QPointF *pos = new QPointF(x(), y());

    o->initNew(gravity, pos);

    timeAnimation->setStartValue(0);
    timeAnimation->setEndValue(2000);
    timeAnimation->setEasingCurve(QEasingCurve::Linear);
    timeAnimation->setDuration(2000);
    timeAnimation->start();

    delete pos;
}

qreal Ball::time() const
{
    return m_time;
}

void Ball::getTime(qreal time)
{
    QList<QGraphicsItem*> c = collidingItems();
    foreach(QGraphicsItem* item, c) {
        Player* p = dynamic_cast<Player*>(item);
        if (p) {
            timeAnimation->stop();

            QVector2D* tangent = p->getTangentVectorAt(x()+boundingRect().width()/2,
                                                       y()-boundingRect().height()/2, r);

            qDebug() << "tangentVector: x: " << tangent->x() << " y: " << tangent->y();

            QVector2D *orbitVector = o->getV(time);

            //TODO: write this function
            getOrbitVector(tangent, orbitVector);

            return;
        }
    }
    qDebug() << time;
    setPos(o->getPos(time));
    m_time = time;
}
