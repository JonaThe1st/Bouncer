#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QVector2D>

class Player : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
Q_PROPERTY(qreal x READ x WRITE setXProperty)

public:
    explicit Player();
    ~Player();

    qreal x() const;
    qreal f(qreal x);

    void move(bool direction);

    QVector2D * getTangentVectorAt(qreal x0, qreal y0, qreal r);

public slots:
    void setXProperty(qreal x);

signals:

private:
    qreal m_x;

    QPropertyAnimation * xAnimation;

    qreal a, b;


};

#endif // PLAYER_H
