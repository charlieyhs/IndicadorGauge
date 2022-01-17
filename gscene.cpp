#include "gscene.h"
#include "gindicator.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneMouseEvent>

#define XSIZE 600
#define YSIZE 600

double GScene::sWidth = XSIZE;
double GScene::sHeight = YSIZE;

GScene::GScene(QObject *parent) : QGraphicsScene { 0.0, 0.0, XSIZE, YSIZE, parent }
{
    mGauge = addPixmap(QPixmap(":/gauge.png"));
    mIndicator = new GIndicator;
    addItem(mIndicator);
}

void GScene::wheelEvent(QGraphicsSceneWheelEvent *e)
{
    if (e->delta() < 0)
    {
        mIndicator->decrementPosition();
    }
    else if (e->delta() > 0)
    {
        mIndicator->incrementPosition();
    }
    update();
    e->accept();
}
