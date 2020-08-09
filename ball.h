#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Ball : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Ball();

    void start();

signals:

private:
    const qreal r;
};

#endif // BALL_H
