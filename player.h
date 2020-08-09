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

    void move(bool direction);

public slots:
    void setXProperty(qreal x);

signals:

private:
    qreal m_x;

    QPropertyAnimation * xAnimation;

    qreal a, b;

    QVector2D * getTangentVectorAt(qreal x0, qreal y0);

};

#endif // PLAYER_H
