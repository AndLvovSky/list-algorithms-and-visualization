#ifndef ARROW_H
#define ARROW_H

#include "point.h"
#include <QtGui>
#include <QtWidgets>

class Arrow
{
private:
    Point *p1, *p2;
    QGraphicsLineItem *main, *side1, *side2;

public:
    Arrow(Point *p1, Point *p2);

    /**
     * @brief draw draw arrow to QGraphicsScene according to start and finish points
     * @param scene QGraphicsScene where arrow will be drawn
     */
    void draw();

    /**
     * @brief change change Arrow points coordinates
     * @param p1 start point
     * @param p2 finish point
     */
    void change(Point *p1, Point *p2);

    void moveRightByOne();

private:
    std::array<Point*, 4> calculatePointsPosition();
};

#endif // ARROW_H
