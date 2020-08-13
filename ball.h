#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

#include "orbit.h"


class Ball : public QObject, public QGraphicsPixmapItem
{
    Q_PROPERTY(qreal time READ time WRITE getTime)
    Q_OBJECT
public:
    explicit Ball();
    ~Ball();

    void start();

    qreal time() const;

public slots:

    void getTime(qreal time);

signals:

private:
    const qreal r;
    Orbit *o;
    qreal gravity;

    qreal m_time;
    QPropertyAnimation *timeAnimation;
};

#endif // BALL_H
