#include "util.h"
#include <QVector2D>
#include "math.h"


QVector2D* getOrbitVector(QVector2D *mirror, QVector2D *orbit)
{

    qreal angle = acos(QVector2D::dotProduct((*mirror) , (*orbit)) / mirror->length() * orbit->length());
    qDebug() << angle;

    //TODO: calculate result Vector
    return new QVector2D();

}
