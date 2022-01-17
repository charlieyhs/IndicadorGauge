#include "gindicator.h"
#include "gscene.h"
#include "garrow.h"
#include "gneedle.h"
#include <QPainter>
#include <QtMath>

static QPointF getFirstPoint()
{
    const double sWidth = GScene::sceneWidth();
    const double sHeight = GScene::sceneHeight();
    const double x = sWidth / 2.0;
    const double y = sHeight / 2.0;
    return QPointF(x, y);
}

QPointF GIndicator::sFirstPoint = getFirstPoint();

GIndicator::GIndicator(QGraphicsItem *parent) : QGraphicsObject { parent }
{
    mNeedle = new GNeedle(this);
    mArrow = new GArrow(this);
    mPosition = FIRST_POS;
}

void GIndicator::incrementPosition(int steps)
{
    mPosition += steps;
    if (mPosition > TENTH_POS)
    {
        mPosition = TENTH_POS;
    }
}

void GIndicator::decrementPosition(int steps)
{
    mPosition -= steps;
    if (mPosition < FIRST_POS)
    {
        mPosition = FIRST_POS;
    }
}

void GIndicator::fillCircle(QPainter *painter)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(sFirstPoint, 20.0, 20.0);
}

QColor GIndicator::getArrowColor()
{
    switch (mPosition)
    {
        case FIRST_POS:
        {
            return Qt::green;
        }
        case SECOND_POS:
        {
            return Qt::green;
        }
        case THIRD_POS:
        {
            return Qt::green;
        }
        case FOURTH_POS:
        {
            return Qt::green;
        }
        case FIFTH_POS:
        {
            return Qt::yellow;
        }
        case SIXTH_POS:
        {
            return QColor("#FFA500");
        }
        case SEVENTH_POS:
        {
            return QColor("#FFA500");
        }
        case EIGHTH_POS:
        {
            return Qt::red;
        }
        case NINETH_POS:
        {
            return Qt::red;
        }
        case TENTH_POS:
        {
            return Qt::red;
        }
    }
    return QColor();
}

void GIndicator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void) option;
    (void) widget;
    fillCircle(painter);
    QPointF secondPoint = getSecondPoint();
    mNeedle->setWidth(8);
    mNeedle->setColor(Qt::white);
    mNeedle->setFirstPoint(sFirstPoint);
    mNeedle->setSecondPoint(secondPoint);
    mArrow->setSize(40.0);
    mArrow->setColor(getArrowColor());
    mArrow->setFirstPoint(sFirstPoint);
    mArrow->setSecondPoint(secondPoint);
}

QRectF GIndicator::boundingRect() const
{
    return QRectF();
}

QPointF GIndicator::getSecondPoint() const
{
    switch (mPosition)
    {
        case FIRST_POS:
        {
            return QPointF(142,457);
        }
        case SECOND_POS:
        {
            return QPointF(84,358);
        }
        case THIRD_POS:
        {
            return QPointF(83,242);
        }
        case FOURTH_POS:
        {
            return QPointF(141,142);
        }
        case FIFTH_POS:
        {
            return QPointF(241,84);
        }
        case SIXTH_POS:
        {
            return QPointF(357,84);
        }
        case SEVENTH_POS:
        {
            return QPointF(457,142);
        }
        case EIGHTH_POS:
        {
            return QPointF(514,242);
        }
        case NINETH_POS:
        {
            return QPointF(515,358);
        }
        case TENTH_POS:
        {
            return QPointF(457,456);
        }
    }
    return QPointF();
}
