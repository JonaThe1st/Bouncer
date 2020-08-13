#include "player.h"

#include <QDebug>
#include "math.h"

Player::Player():
m_x{50}
{

    setPixmap(QPixmap(":/images/player.png"));

    a = boundingRect().width()/2;
    b = boundingRect().height()/2;

    setY(-b);
    setXProperty(50);

    xAnimation = new QPropertyAnimation(this, "x", this);

}

Player::~Player()
{
    delete xAnimation;
}

qreal Player::x() const
{
    return m_x;
}

qreal Player::f(qreal x)
{
    return b/a * sqrt(a*a-x*x);
}

// true = right; false = left
void Player::move(bool direction)
{
    qreal endValue = direction ? 450-boundingRect().width(): 50;

    qDebug() << endValue << " : " << x();

    if(x()!= endValue) {
        xAnimation->stop();

        xAnimation->setStartValue(x());
        xAnimation->setEndValue(endValue);
        xAnimation->setEasingCurve(QEasingCurve::Linear);
        xAnimation->setDuration(500);

        xAnimation->start();
    }

}

void Player::setXProperty(qreal x)
{
    if(!(x < 50 or x>450)) {
        m_x = x;
        setX(x);
    }
}

QVector2D * Player::getTangentVectorAt(qreal x0, qreal y0, qreal r)
{

    return new QVector2D((-(a+r)*y0)/(b+r), (b+r)*x0/(a+r));
}
