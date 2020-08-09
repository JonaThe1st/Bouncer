#include "ball.h"

Ball::Ball() :
    r{40}
{

    setPixmap(QPixmap(":/images/ball.png"));
    setPos(250-r/2, -600);
    setVisible(false);

}

void Ball::start()
{
    setVisible(true);
}
