#include "orbit.h"

#include <QDebug>

Orbit::Orbit():
    gravity{0}
{
    gravity = 10;
}

void Orbit::initNew(qreal g, QPointF *startingPoint)
{
    gravity = g;
    v = new QVector2D();

    x0 = startingPoint->x();
    y0 = startingPoint->y();

}

qreal Orbit::x(qreal t)
{
    return x0 + v->x() * t;

}

qreal Orbit::y(qreal t)
{
    return y0 + v->y()*t + 0.5 * gravity * t*t;
}

QPointF Orbit::getPos(qreal t)
{
    qDebug() << "x(t): " << x(t) << " y(t): " << y(t);
    return QPointF(x(t), y(t));
}

QVector2D *Orbit::getV(qreal t)
{
    return new QVector2D(v->x(), v->y() + gravity*t);
}

