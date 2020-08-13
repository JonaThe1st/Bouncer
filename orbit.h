#ifndef ORBIT_H
#define ORBIT_H

#include <QVector2D>

class Orbit
{
public:
    Orbit();
    void initNew(qreal gravity, QPointF *startingPoint);
    QPointF getPos(qreal t);

    QVector2D *getV(qreal t);

private:

    QVector2D *v;
    qreal gravity;

    qreal x(qreal t);
    qreal y(qreal t);

    qreal x0;
    qreal y0;
};

#endif // ORBIT_H
